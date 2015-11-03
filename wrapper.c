#include "wrapper.h"

PyObject * dsmInit_wrapper(PyObject * self, PyObject * args, PyObject * keywds)
{
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
    dsmApiVersion.version = PyInt_AsLong(PyDict_GetItemString(apiVersion, "version"));
    dsmApiVersion.release = PyInt_AsLong(PyDict_GetItemString(apiVersion, "release"));
    dsmApiVersion.level = PyInt_AsLong(PyDict_GetItemString(apiVersion, "level"));

    rc = dsmInit(&dsmHandle, &dsmApiVersion, clientNodeName, clientOwnerName, clientPassword,
            applicationType, configfile, options);
    if(rc) {
        setError(rc);
        return NULL;
    }

    return Py_BuildValue("K", dsmHandle);
}

// http://www-304.ibm.com/support/knowledgecenter/SSGSG7_7.1.0/com.ibm.itsm.client.develop.doc/r_cmd_dsmqueryapiversion.html
PyObject* dsmQueryApiVersion_wrapper(PyObject* self) {
    dsmApiVersion apiVer;

    memset(&apiVer,0x00,sizeof(dsmApiVersion));
    dsmQueryApiVersion(&apiVer);

    return dsmApiVersionToPyDict(apiVer);
}

// http://www-304.ibm.com/support/knowledgecenter/SSGSG7_7.1.0/com.ibm.itsm.client.develop.doc/r_cmd_dsmqueryapiversionex.html
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

    if((rc = dsmQueryCliOptions(&optstruct)) != DSM_RC_OK) {
       setError(rc);
       return NULL;
    }

    return optStructToPyDict(optstruct);
}

PyObject* dsmQuerySessInfo_wrapper(PyObject* self, PyObject * args) {
    ApiSessInfo sessInfo;
    dsUint32_t dsmHandle;
    int rc;

    memset(&sessInfo,0x00,sizeof(ApiSessInfo));
    sessInfo.stVersion = ApiSessInfoVersion;

    if (!PyArg_ParseTuple(args, "K", &dsmHandle)) {
    return NULL;
    }

    if((rc = dsmQuerySessInfo(dsmHandle, &sessInfo)) != DSM_RC_OK) {
       setError(rc);
       return NULL;
    }

    return apiSessInfoStructToPyDict(sessInfo);
}

PyObject* dsmQuerySessOptions_wrapper(PyObject* self, PyObject * args) {
    dsUint32_t dsmHandle;
    optStruct optstruct;
    int rc;

    memset(&optstruct,0x00,sizeof(optStruct));

    if (!PyArg_ParseTuple(args, "K", &dsmHandle)) {
    return NULL;
    }

    if((rc = dsmQuerySessOptions(dsmHandle, &optstruct)) != DSM_RC_OK) {
       setError(rc);
       return NULL;
    }

    return optStructToPyDict(optstruct);
}

PyObject* dsmRCMsg_wrapper(PyObject * self, PyObject * args, PyObject * keywds) {
    dsUint32_t dsmHandle;
    dsInt16_t dsmRC;
    char msg[DSM_MAX_RC_MSG_LENGTH];
    int rc;

    PyObject * py_msg = NULL;

    if (!PyArg_ParseTuple(args, "KK", &dsmHandle, &dsmRC)) {
        return NULL;
    }

    rc = dsmRCMsg(dsmHandle, dsmRC, msg);
    if(rc) {
        setError(rc);
        return NULL;
    }

    py_msg = Py_BuildValue("s", msg);

    return py_msg;
}

void dsmSetUp_wrapper(PyObject * self, PyObject * args, PyObject * keywds)
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
    return;
    }

    rc = dsmSetUp(PyObject_IsTrue(mtFlag), NULL);

    if(rc) {
        setError(rc);
        return;
    }
}

PyObject * dsmTerminate_wrapper(PyObject * self, PyObject * args)
{
    dsUint32_t dsmHandle;
    int rc;

    // parse arguments
    if (!PyArg_ParseTuple(args, "K", &dsmHandle)) {
    return NULL;
    }

    rc = dsmTerminate(dsmHandle);

    if(rc) {
        setError(rc);
        return NULL;
    }

    return Py_True;
}
