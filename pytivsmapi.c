#include <Python.h>
#include <stdio.h>
#include <string.h>

#include "dsmapitd.h"      /* Tivoli Storage Manager API type definitions                */
#include "dsmapifp.h"      /* Tivoli Storage Manager API function prototypes.            */
#include "dsmrc.h"         /* Tivoli Storage Manager API return codes.                   */

#define ERR_MAX 100

PyObject * TivsmAPIError = NULL;

void setError(int rc) {
    char errorMessage[ERR_MAX];
    switch(rc){
        case DSM_RC_ACCESS_DENIED:
            sprintf(errorMessage, "API Error: DSM_RC_ACCESS_DENIED (%i)", rc);
            break;

        case DSM_RC_BAD_HOST_NAME:
            sprintf(errorMessage, "API Error: DSM_RC_BAD_HOST_NAME (%i)", rc); break;

        case DSM_RC_REJECT_NO_RESOURCES:
            sprintf(errorMessage, "API Error: DSM_RC_REJECT_NO_RESOURCES (%i)", rc); break;

        case DSM_RC_INVALID_OPT:
            sprintf(errorMessage, "API Error: DSM_RC_INVALID_OPT (%i)", rc); break;
        case DSM_RC_NO_HOST_ADDR:
            sprintf(errorMessage, "API Error: DSM_RC_NO_HOST_ADDR (%i)", rc); break;
        case DSM_RC_NO_OPT_FILE:
            sprintf(errorMessage, "API Error: DSM_RC_NO_OPT_FILE (%i)", rc); break;
        case DSM_RC_MACHINE_SAME:
            sprintf(errorMessage, "API Error: DSM_RC_MACHINE_SAME (%i)", rc); break;
        case DSM_RC_INVALID_SERVER:
            sprintf(errorMessage, "API Error: DSM_RC_INVALID_SERVER (%i)", rc); break;
        case DSM_RC_INVALID_KEYWORD:
            sprintf(errorMessage, "API Error: DSM_RC_INVALID_KEYWORD (%i)", rc); break;
        case DSM_RC_PATTERN_TOO_COMPLEX:
            sprintf(errorMessage, "API Error: DSM_RC_PATTERN_TOO_COMPLEX (%i)", rc); break;
        case DSM_RC_NO_CLOSING_BRACKET:
            sprintf(errorMessage, "API Error: DSM_RC_NO_CLOSING_BRACKET (%i)", rc); break;
        case DSM_RC_NLS_CANT_OPEN_TXT:
            sprintf(errorMessage, "API Error: DSM_RC_NLS_CANT_OPEN_TXT (%i)", rc); break;
        case DSM_RC_NLS_INVALID_CNTL_REC:
            sprintf(errorMessage, "API Error: DSM_RC_NLS_INVALID_CNTL_REC (%i)", rc); break;
        case DSM_RC_NOT_ADSM_AUTHORIZED:
            sprintf(errorMessage, "API Error: DSM_RC_NOT_ADSM_AUTHORIZED (%i)", rc); break;
        case DSM_RC_NO_INCLEXCL_FILE:
            sprintf(errorMessage, "API Error: DSM_RC_NO_INCLEXCL_FILE (%i)", rc); break;
        case DSM_RC_NO_SYS_OR_INCLEXCL:
            sprintf(errorMessage, "API Error: DSM_RC_NO_SYS_OR_INCLEXCL (%i)", rc); break;

        case DSM_RC_NO_NODE_REQD:
            sprintf(errorMessage, "API Error: DSM_RC_NO_NODE_REQD (%i)", rc); break;
        default:
            sprintf(errorMessage, "API Error: %i", rc);
    }

    PyErr_SetString(TivsmAPIError, errorMessage);
}

static PyObject * dsmInit_wrapper(PyObject * self, PyObject * args, PyObject * keywds)
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
static PyObject* dsmQueryApiVersion_wrapper(PyObject* self) {
    PyObject* dict = PyDict_New();
    dsmApiVersion apiVer;

    memset(&apiVer,0x00,sizeof(dsmApiVersion));
    dsmQueryApiVersion(&apiVer);

    PyDict_SetItemString(dict, "version", Py_BuildValue("i", apiVer.version));
    PyDict_SetItemString(dict, "release", Py_BuildValue("i", apiVer.release));
    PyDict_SetItemString(dict, "level", Py_BuildValue("i", apiVer.level));

    return dict;
}

// http://www-304.ibm.com/support/knowledgecenter/SSGSG7_7.1.0/com.ibm.itsm.client.develop.doc/r_cmd_dsmqueryapiversionex.html
static PyObject* dsmQueryApiVersionEx_wrapper(PyObject* self) {
    PyObject* dict = PyDict_New();
    dsmApiVersionEx apiVerEx;

    memset(&apiVerEx,0x00,sizeof(dsmApiVersionEx));
    dsmQueryApiVersionEx(&apiVerEx);

    PyDict_SetItemString(dict, "version", Py_BuildValue("i", apiVerEx.version));
    PyDict_SetItemString(dict, "release", Py_BuildValue("i", apiVerEx.release));
    PyDict_SetItemString(dict, "level", Py_BuildValue("i", apiVerEx.level));
    PyDict_SetItemString(dict, "sublevel", Py_BuildValue("i", apiVerEx.subLevel));

    return dict;
}

static PyObject* dsmQuerySessInfo_wrapper(PyObject* self, PyObject * args) {
    PyObject* dict = PyDict_New();
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

    // TODO: implement remaining fields
    PyDict_SetItemString(dict, "stVersion", Py_BuildValue("I", sessInfo.stVersion));
    PyDict_SetItemString(dict, "serverHost", Py_BuildValue("s", sessInfo.serverHost));
    PyDict_SetItemString(dict, "serverPort", Py_BuildValue("I", sessInfo.serverPort));
    //PyDict_SetItemString(dict, "dsmDate", Py_BuildValue("", sessInfo));
    PyDict_SetItemString(dict, "serverType", Py_BuildValue("s", sessInfo.serverType));
    PyDict_SetItemString(dict, "serverVer", Py_BuildValue("I", sessInfo.serverVer));
    PyDict_SetItemString(dict, "serverRel", Py_BuildValue("I", sessInfo.serverRel));
    PyDict_SetItemString(dict, "serverLev", Py_BuildValue("I", sessInfo.serverLev));
    PyDict_SetItemString(dict, "serverSubLev", Py_BuildValue("I", sessInfo.serverSubLev));
    PyDict_SetItemString(dict, "nodeType", Py_BuildValue("s", sessInfo.nodeType));
    PyDict_SetItemString(dict, "fsdelim", Py_BuildValue("c", sessInfo.fsdelim));
    PyDict_SetItemString(dict, "hldelim", Py_BuildValue("c", sessInfo.hldelim));
    PyDict_SetItemString(dict, "compression", Py_BuildValue("I", sessInfo.compression));
    PyDict_SetItemString(dict, "archDel", Py_BuildValue("I", sessInfo.archDel));
    PyDict_SetItemString(dict, "backDel", Py_BuildValue("I", sessInfo.backDel));
    PyDict_SetItemString(dict, "maxBytesPerTxn", Py_BuildValue("K", sessInfo.maxBytesPerTxn));
    PyDict_SetItemString(dict, "maxObjPerTxn", Py_BuildValue("K", sessInfo.maxObjPerTxn));
    PyDict_SetItemString(dict, "id", Py_BuildValue("s", sessInfo.id));
    PyDict_SetItemString(dict, "owner", Py_BuildValue("s", sessInfo.owner));
    PyDict_SetItemString(dict, "confFile", Py_BuildValue("s", sessInfo.confFile));
    PyDict_SetItemString(dict, "opNoTrace", Py_BuildValue("I", sessInfo.opNoTrace));
    PyDict_SetItemString(dict, "domainName", Py_BuildValue("s", sessInfo.domainName));
    PyDict_SetItemString(dict, "policySetName", Py_BuildValue("s", sessInfo.policySetName));
    //PyDict_SetItemString(dict, "polActDate", Py_BuildValue("", sessInfo));
    PyDict_SetItemString(dict, "dfltMCName", Py_BuildValue("s", sessInfo.dfltMCName));
    PyDict_SetItemString(dict, "gpBackRetn", Py_BuildValue("I", sessInfo.gpBackRetn));
    PyDict_SetItemString(dict, "gpArchRetn", Py_BuildValue("I", sessInfo));
    PyDict_SetItemString(dict, "adsmServerName", Py_BuildValue("s", sessInfo.adsmServerName));
    PyDict_SetItemString(dict, "archiveRetentionProtection", sessInfo.archiveRetentionProtection ? Py_True : Py_False);
    PyDict_SetItemString(dict, "maxBytesPerTxn_64", Py_BuildValue("K", sessInfo.maxBytesPerTxn_64));
    PyDict_SetItemString(dict, "lanFreeEnabled", sessInfo.lanFreeEnabled ? Py_True : Py_False);
    //PyDict_SetItemString(dict, "dedupType", Py_BuildValue("", sessInfo));
    PyDict_SetItemString(dict, "accessNode", Py_BuildValue("s", sessInfo.accessNode));
    //PyDict_SetItemString(dict, "failOverCfgType", Py_BuildValue("", sessInfo));
    PyDict_SetItemString(dict, "replServerName", Py_BuildValue("s", sessInfo.replServerName));
    PyDict_SetItemString(dict, "homeServerName", Py_BuildValue("s", sessInfo.homeServerName));
    PyDict_SetItemString(dict, "replServerHost", Py_BuildValue("s", sessInfo.replServerHost));
    PyDict_SetItemString(dict, "replServerPort", Py_BuildValue("I", sessInfo.replServerPort));
    return dict;
}

static void dsmSetUp_wrapper(PyObject * self, PyObject * args, PyObject * keywds)
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

static PyObject * dsmTerminate_wrapper(PyObject * self, PyObject * args)
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

static PyMethodDef TIVsmAPIMethods[] = {
     { "dsmInit", (PyCFunction)dsmInit_wrapper, METH_KEYWORDS, "Init TSM session" },
     { "dsmQueryApiVersion", dsmQueryApiVersion_wrapper, METH_NOARGS, "Query TSM API version" },
     { "dsmQueryApiVersionEx", dsmQueryApiVersionEx_wrapper, METH_NOARGS, "Query TSM API version" },
     { "dsmQuerySessInfo", dsmQuerySessInfo_wrapper, METH_VARARGS, "Query TSM session info" },
     { "dsmSetUp", (PyCFunction)dsmSetUp_wrapper, METH_KEYWORDS, "Set up TSM environment" },
     { "dsmTerminate", dsmTerminate_wrapper, METH_VARARGS, "Terminate TSM session" },
      { NULL, NULL, 0, NULL }
};

static void defConstants(PyObject *m) {
    PyModule_AddIntConstant (m, "DSM_RC_NO_OPT_FILE", DSM_RC_NO_OPT_FILE);
}

static void setupExceptions(PyObject *m) {
    TivsmAPIError = PyErr_NewException("pytivsmapi.TivsmAPIError", NULL, NULL);
    Py_INCREF(TivsmAPIError);
    PyModule_AddObject(m, "TivsmAPIError", TivsmAPIError);
}

DL_EXPORT(void) initpytivsmapi(void)
{
    PyObject *m;
    m = Py_InitModule("pytivsmapi", TIVsmAPIMethods);
    if(m == NULL)
        return;

    defConstants(m);
    setupExceptions(m);
}

