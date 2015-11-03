#include "wrapper.h"

PyObject* dsmChangePW_wrapper(PyObject * self, PyObject * args) {
    dsUint32_t dsmHandle;
    char* oldPW = NULL;
    char* newPW = NULL;
    int rc;

    if (!PyArg_ParseTuple(args, "Iss", &dsmHandle, &oldPW, &newPW)) {
        return NULL;
    }

    rc = dsmChangePW(dsmHandle, oldPW, newPW);

    return Py_BuildValue("I", rc);
}

PyObject* dsmInit_wrapper(PyObject * self, PyObject * args, PyObject * keywds) {
    dsUint32_t dsmHandle;
    dsmApiVersion dsmApiVersion;
    PyObject * apiVersion = NULL;
    char* clientNodeName = NULL;
    char* clientOwnerName = NULL;
    char* clientPassword = NULL;
    char* applicationType = NULL;
    char* configfile = NULL;
    char* options = NULL;

    int rc;

    static char *kwlist[] = {"dsmApiVersion", "clientNodeName", "clientOwnerName", "clientPassword",
        "applicationType", "configfile", "options"};

    // parse arguments
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "O|ssssss", kwlist, &apiVersion, &clientNodeName, &clientOwnerName,
        &clientPassword, &applicationType, &configfile, &options)) {
    return NULL;
    }
    pyDictToDsmApiVersion(apiVersion, &dsmApiVersion);

    rc = dsmInit(&dsmHandle, &dsmApiVersion, clientNodeName, clientOwnerName, clientPassword,
            applicationType, configfile, options);

    return returnTouple(rc, Py_BuildValue("I", dsmHandle));
}

PyObject* dsmLogEvent_wrapper(PyObject * self, PyObject * args) {
    dsUint32_t dsmHandle;
    logInfo loginfo;
    int iLogType = 0;
    int rc;

    memset(&loginfo,0x00,sizeof(loginfo));

    if (!PyArg_ParseTuple(args, "IIs", &dsmHandle, &iLogType, &loginfo.message)) {
        return NULL;
    }
    loginfo.logType = (dsmLogType) iLogType;

    rc = dsmLogEvent(dsmHandle, &loginfo);

    return Py_BuildValue("I", rc);
}

PyObject* dsmLogEventEx_wrapper(PyObject * self, PyObject * args) {
    dsUint32_t dsmHandle;
    dsmLogExIn_t dsmLogExIn;
    dsmLogExOut_t dsmLogExOut;

    int iLogSeverity = 0;
    char* appMsgID = NULL;
    int iLogType = 0;
    int rc;

    memset(&dsmLogExIn,0x00,sizeof(dsmLogExIn));
    memset(&dsmLogExOut,0x00,sizeof(dsmLogExOut));

    if (!PyArg_ParseTuple(args, "IIsIs", &dsmHandle, &iLogSeverity, &appMsgID,
                &iLogType, &dsmLogExIn.message)) {
        return NULL;
    }

    dsmLogExIn.stVersion = dsmLogExInVersion;
    dsmLogExIn.severity = (dsmLogSeverity) iLogSeverity;
    dsmLogExIn.logType = (dsmLogType) iLogType;
    strncpy(dsmLogExIn.appMsgID, appMsgID, sizeof(dsmLogExIn.appMsgID));

    dsmLogExOut.stVersion = dsmLogExOutVersion;

    rc = dsmLogEventEx(dsmHandle, &dsmLogExIn, &dsmLogExOut);

    return Py_BuildValue("I", rc);
}

PyObject* dsmQueryApiVersion_wrapper(PyObject* self) {
    dsmApiVersion apiVer;

    memset(&apiVer,0x00,sizeof(dsmApiVersion));
    dsmQueryApiVersion(&apiVer);

    return dsmApiVersionToPyDict(apiVer);
}

PyObject* dsmQueryApiVersionEx_wrapper(PyObject* self) {
    dsmApiVersionEx apiVerEx;

    memset(&apiVerEx,0x00,sizeof(dsmApiVersionEx));
    dsmQueryApiVersionEx(&apiVerEx);

    return dsmApiVersionExToPyDict(apiVerEx);
}

PyObject* dsmQueryCliOptions_wrapper(PyObject* self) {
    optStruct optstruct;
    int rc;

    memset(&optstruct,0x00,sizeof(optStruct));

    rc = dsmQueryCliOptions(&optstruct);

    return returnTouple(rc, optStructToPyDict(optstruct));
}

PyObject* dsmQuerySessInfo_wrapper(PyObject* self, PyObject * args) {
    ApiSessInfo sessInfo;
    dsUint32_t dsmHandle;
    int rc;

    memset(&sessInfo,0x00,sizeof(ApiSessInfo));
    sessInfo.stVersion = ApiSessInfoVersion;

    if (!PyArg_ParseTuple(args, "I", &dsmHandle)) {
        return NULL;
    }

    rc = dsmQuerySessInfo(dsmHandle, &sessInfo);

    return returnTouple(rc, apiSessInfoStructToPyDict(sessInfo));
}

PyObject* dsmQuerySessOptions_wrapper(PyObject* self, PyObject * args) {
    dsUint32_t dsmHandle;
    optStruct optstruct;
    int rc;

    memset(&optstruct,0x00,sizeof(optStruct));

    if (!PyArg_ParseTuple(args, "I", &dsmHandle)) {
    return NULL;
    }

    rc = dsmQuerySessOptions(dsmHandle, &optstruct);

    return returnTouple(rc, optStructToPyDict(optstruct));
}

PyObject* dsmRCMsg_wrapper(PyObject * self, PyObject * args, PyObject * keywds) {
    dsUint32_t dsmHandle;
    dsInt16_t dsmRC;
    char msg[DSM_MAX_RC_MSG_LENGTH];
    int rc;

    if (!PyArg_ParseTuple(args, "II", &dsmHandle, &dsmRC)) {
        return NULL;
    }

    rc = dsmRCMsg(dsmHandle, dsmRC, msg);

    return returnTouple(rc, Py_BuildValue("s", msg));
}

PyObject* dsmSetUp_wrapper(PyObject * self, PyObject * args, PyObject * keywds)
{
    // TODO: parse envDict and pass it to dsmSetUp()
    /*
    dsUint16_t stVersion;
    char* dsmiDir;
    char* dsmiConfig;
    char* dsmiLog;
    char** argv;
    char* logName;
    char* options;
    bool reserved1 = false;
    bool reserved2 = false;
    */
    PyObject * mtFlag = NULL;
    PyObject * envDict = NULL;
    int rc;

    static char *kwlist[] = {"mtFlag", "envSetup"};

    // parse arguments
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "OO", kwlist, &mtFlag, &envDict)) {
        return NULL;
    }

    rc = dsmSetUp(PyObject_IsTrue(mtFlag), NULL);

    return Py_BuildValue("I", rc);
}

PyObject* dsmTerminate_wrapper(PyObject * self, PyObject * args)
{
    dsUint32_t dsmHandle;
    int rc;

    // parse arguments
    if (!PyArg_ParseTuple(args, "I", &dsmHandle)) {
        return NULL;
    }

    rc = dsmTerminate(dsmHandle);

    return Py_BuildValue("I", rc);
}
