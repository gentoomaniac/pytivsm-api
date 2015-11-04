#include "wrapper.h"

PyObject* dsmChangePW_wrapper(PyObject * self, PyObject * args) {
    dsUint32_t dsmHandle;
    char* oldPW = NULL;
    char* newPW = NULL;
    int rc = 0;

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

    int rc = 0;

    static char *kwlist[] = {"dsmApiVersion", "clientNodeName", "clientOwnerName", "clientPassword",
        "applicationType", "configfile", "options"};

    if (!PyArg_ParseTupleAndKeywords(args, keywds, "O|ssssss", kwlist, &apiVersion, &clientNodeName, &clientOwnerName,
        &clientPassword, &applicationType, &configfile, &options)) {
    return NULL;
    }
    pyDictToDsmApiVersion(apiVersion, &dsmApiVersion);

    rc = dsmInit(&dsmHandle, &dsmApiVersion, clientNodeName, clientOwnerName, clientPassword,
            applicationType, configfile, options);

    return returnTouple(rc, Py_BuildValue("I", dsmHandle));
}

PyObject* dsmInitEx_wrapper(PyObject * self, PyObject * args) {
    dsUint32_t dsmHandle;
    dsmInitExIn_t initExIn;
    dsmApiVersionEx apiVersion;
    dsmAppVersion appVersion;
    dsmInitExOut_t initExOut;
    int rc = 0;
    PyObject* pyInitExIn = NULL;
    PyObject* pyInitExOut = NULL;

    memset(&initExIn,0x00,sizeof(dsmInitExIn_t));
    memset(&apiVersion,0x00,sizeof(dsmApiVersionEx));
    memset(&appVersion,0x00,sizeof(dsmAppVersion));
    memset(&initExOut,0x00,sizeof(dsmInitExOut_t));

    if (!PyArg_ParseTuple(args, "OO", &pyInitExIn, &pyInitExOut)) {
        return NULL;
    }

    initExIn.apiVersionExP = &apiVersion;
    initExIn.appVersionP = &appVersion;
    pyDictToDsmInitExInT(pyInitExIn, &initExIn);

    // TODO: dsmInitExOut_t construction and actual calling of C function

    return returnTouple(rc, Py_BuildValue("I", dsmHandle));
}

PyObject* dsmLogEvent_wrapper(PyObject * self, PyObject * args) {
    dsUint32_t dsmHandle;
    logInfo loginfo;
    int iLogType = 0;
    int rc = 0;

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
    int rc = 0;

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
    int rc = 0;

    memset(&optstruct,0x00,sizeof(optStruct));

    rc = dsmQueryCliOptions(&optstruct);

    return returnTouple(rc, optStructToPyDict(optstruct));
}

PyObject* dsmQuerySessInfo_wrapper(PyObject* self, PyObject * args) {
    ApiSessInfo sessInfo;
    dsUint32_t dsmHandle;
    int rc = 0;

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
    int rc = 0;

    memset(&optstruct,0x00,sizeof(optStruct));

    if (!PyArg_ParseTuple(args, "I", &dsmHandle)) {
    return NULL;
    }

    rc = dsmQuerySessOptions(dsmHandle, &optstruct);

    return returnTouple(rc, optStructToPyDict(optstruct));
}

PyObject* dsmRCMsg_wrapper(PyObject * self, PyObject * args) {
    dsUint32_t dsmHandle;
    dsInt16_t dsmRC;
    char msg[DSM_MAX_RC_MSG_LENGTH];
    int rc = 0;

    if (!PyArg_ParseTuple(args, "II", &dsmHandle, &dsmRC)) {
        return NULL;
    }

    rc = dsmRCMsg(dsmHandle, dsmRC, msg);

    return returnTouple(rc, Py_BuildValue("s", msg));
}

PyObject* dsmRegisterFS_wrapper(PyObject * self, PyObject * args) {
    dsUint32_t dsmHandle;
    regFSData regfsdata;
    int rc = 0;
    PyObject* fsData = NULL;
    /*
     * Example dict:
     * {'fsName':'/my/path','fsType':'some_type','occupancy':1024, 'capacity':4096, 'fsAttr':{
     *      'netwareFSAttr': {'fsInfoLength':9,'fsInfo':'rwxrwxrwx'},
     *      'unixFSAttr':{'fsInfoLength':9, 'fsInfo':'rwxrwxrwx'},
     *      'dosFSAttr':{'driveLetter':'', 'fsInfoLength':0, 'fsInfo':''}}
     * }
    */
    memset(&regfsdata,0x00,sizeof(regFSData));

    if (!PyArg_ParseTuple(args, "IO", &dsmHandle, &fsData)) {
        return NULL;
    }
    pyDictToRegFSData(fsData, &regfsdata);

    rc = dsmRegisterFS(dsmHandle, &regfsdata);

    return Py_BuildValue("I", rc);
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
    int rc = 0;

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
    int rc = 0;

    // parse arguments
    if (!PyArg_ParseTuple(args, "I", &dsmHandle)) {
        return NULL;
    }

    rc = dsmTerminate(dsmHandle);

    return Py_BuildValue("I", rc);
}

PyObject* dsmUpdateFS_wrapper(PyObject * self, PyObject * args) {
    dsUint32_t dsmHandle;
    char* fsname = NULL;
    dsmFSUpd updfsdata;
    dsUint32_t fsUpdAct;
    int rc = 0;
    PyObject* fsUpdData = NULL;
    /*
     * Example dict:
     * {'fsType':'some_type','occupancy':1024, 'capacity':4096, 'fsAttr':{
     *      'netwareFSAttr': {'fsInfoLength':9,'fsInfo':'rwxrwxrwx'},
     *      'unixFSAttr':{'fsInfoLength':9, 'fsInfo':'rwxrwxrwx'},
     *      'dosFSAttr':{'driveLetter':'', 'fsInfoLength':0, 'fsInfo':''}}
     * }
    */
    memset(&updfsdata,0x00,sizeof(dsmFSUpd));

    if (!PyArg_ParseTuple(args, "IsOI", &dsmHandle, &fsname, &fsUpdData, &fsUpdAct)) {
        return NULL;
    }
    pyDictToUpdFSData(fsUpdData, &updfsdata);

    rc = dsmUpdateFS(dsmHandle, fsname, &updfsdata, fsUpdAct);

    return Py_BuildValue("I", rc);
}

