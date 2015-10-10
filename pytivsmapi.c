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
        case DSM_RC_NO_OPT_FILE:
            sprintf(errorMessage, "API Error: DSM_RC_NO_OPT_FILE (%i)", rc);
            break;
        default:
            sprintf(errorMessage, "API Error: %i", rc);
    }

    PyErr_SetString(TivsmAPIError, errorMessage);
}

static PyObject * dsmInit_wrapper(PyObject * self, PyObject * args, PyObject * keywds)
{
    dsUint32_t dsmHandle;;
    dsmApiVersion dsmApiVersion;
    PyObject * apiVersion = NULL;
    char* clientNodeName;
    char* clientOwnerName;
    char* clientPassword;
    char* applicationType;
    char* configfile;
    char* options;

    int rc;

    static char *kwlist[] = {"dsmApiVersion", "clientNodeName", "clientOwnerName", "clientPassword",
        "applicationType", "configfile", "options"};

    // parse arguments
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "Ossssss", kwlist, &apiVersion, &clientNodeName, &clientOwnerName,
        &clientPassword, &applicationType, &configfile, &options)) {
    return NULL;
    }
    dsmApiVersion.version = PyInt_AsLong(PyDict_GetItemString(apiVersion, "version"));
    dsmApiVersion.release = PyInt_AsLong(PyDict_GetItemString(apiVersion, "release"));
    dsmApiVersion.level = PyInt_AsLong(PyDict_GetItemString(apiVersion, "level"));

    rc = dsmInit(&dsmHandle, &dsmApiVersion, clientNodeName, NULL, clientPassword,
            applicationType, NULL, NULL);

    // TODO: pass actual values or NULL if empty strings
    //rc = dsmInit(dsmHandle, &dsmApiVersion, clientNodeName, clientOwnerName, clientPassword,
    //        applicationType, configfile, options);
    if(rc) {
        setError(rc);
        return NULL;
    }

    return Py_BuildValue("i", dsmHandle);
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

static PyMethodDef TIVsmAPIMethods[] = {
     { "dsmInit", (PyCFunction)dsmInit_wrapper, METH_KEYWORDS, "Init TSM environment" },
     { "dsmQueryApiVersion", dsmQueryApiVersion_wrapper, METH_NOARGS, "Query TSM API version" },
     { "dsmQueryApiVersionEx", dsmQueryApiVersionEx_wrapper, METH_NOARGS, "Query TSM API version" },
     { "dsmSetUp", (PyCFunction)dsmSetUp_wrapper, METH_KEYWORDS, "Set up TSM environment" },
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

