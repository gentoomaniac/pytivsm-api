#include <Python.h>

#include "wrapper.h"

//PyObject * TivsmAPIError = NULL;

PyMethodDef TIVsmAPIMethods[] = {
     { "dsmChangePW", dsmChangePW_wrapper, METH_VARARGS, "changes a Tivoli Storage Manager password" },
     { "dsmInit", (PyCFunction)dsmInit_wrapper, METH_KEYWORDS, "Init TSM session" },
     { "dsmInitEx", dsmInit_wrapper, METH_VARARGS, "starts an API session by using the additional parameters for extended verification" },
     { "dsmLogEvent", dsmLogEvent_wrapper, METH_VARARGS, "logs a user message (ANE4991 I) to the server log file, to the local error log, or to both" },
     { "dsmLogEventEx", dsmLogEventEx_wrapper, METH_VARARGS, "logs a user message to the server log file, to the local error log, or to both" },
     { "dsmQueryApiVersion", (PyCFunction)dsmQueryApiVersion_wrapper, METH_NOARGS, "Query TSM API version" },
     { "dsmQueryApiVersionEx", (PyCFunction)dsmQueryApiVersionEx_wrapper, METH_NOARGS, "Query TSM API version" },
     { "dsmQueryCliOptions", (PyCFunction)dsmQueryCliOptions_wrapper, METH_NOARGS, "queries important option values in the user's option files" },
     { "dsmQuerySessInfo", dsmQuerySessInfo_wrapper, METH_VARARGS, "Query TSM session info" },
     { "dsmQuerySessOptions", dsmQuerySessOptions_wrapper, METH_VARARGS, "queries important option values that are valid in the specified session" },
     { "dsmRCMsg", (PyCFunction)dsmRCMsg_wrapper, METH_VARARGS, "obtains the message text that is associated with an API return code" },
     { "dsmRegisterFS", (PyCFunction)dsmRegisterFS_wrapper, METH_VARARGS, "registers a new file space with the Tivoli Storage Manager server" },
     { "dsmSetUp", (PyCFunction)dsmSetUp_wrapper, METH_KEYWORDS, "Set up TSM environment" },
     { "dsmTerminate", dsmTerminate_wrapper, METH_VARARGS, "Terminate TSM session" },
      { NULL, NULL, 0, NULL }
};

//    PyModule_AddIntConstant (m, "DSM_RC_NO_OPT_FILE", DSM_RC_NO_OPT_FILE);

//static void setupExceptions(PyObject *m) {
//    TivsmAPIError = PyErr_NewException("pytivsmapi.TivsmAPIError", NULL, NULL);
//    Py_INCREF(TivsmAPIError);
//    PyModule_AddObject(m, "TivsmAPIError", TivsmAPIError);
//}

DL_EXPORT(void) initpytivsmapi(void)
{
    PyObject *m;
    m = Py_InitModule("pytivsmapi", TIVsmAPIMethods);
    if(m == NULL)
        return;

//    setupExceptions(m);
}

