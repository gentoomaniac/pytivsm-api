#include <Python.h>

#include "constants.h"
#include "wrapper.h"

//PyObject * TivsmAPIError = NULL;

PyMethodDef TIVsmAPIMethods[] = {
     { "dsmBeginQuery", dsmBeginQuery_wrapper, METH_VARARGS, "starts a query request to the server for information about data, file spaces, and management classes" },
     { "dsmChangePW", dsmChangePW_wrapper, METH_VARARGS, "changes a Tivoli Storage Manager password" },
     { "dsmDeleteFS", dsmDeleteFS_wrapper, METH_VARARGS, "deletes a file space from storage" },
     { "dsmEndQuery", dsmEndQuery_wrapper, METH_VARARGS, "signifies the end of a dsmBeginQuery action" },
     { "dsmGetNextQObj", dsmGetNextQObj_wrapper, METH_VARARGS, "gets the next query response from a previous dsmBeginQuery call" },
     { "dsmInit", (PyCFunction)dsmInit_wrapper, METH_KEYWORDS, "Init TSM session" },
     { "dsmInitEx", (PyCFunction)dsmInit_wrapper, METH_VARARGS, "starts an API session by using the additional parameters for extended verification" },
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
     { "dsmUpdateFS", (PyCFunction)dsmUpdateFS_wrapper, METH_VARARGS, "updates a file space in Tivoli Storage Manager storage" },
      { NULL, NULL, 0, NULL }
};

//static void setupExceptions(PyObject *m) {
//    TivsmAPIError = PyErr_NewException("pytivsmapi.TivsmAPIError", NULL, NULL);
//    Py_INCREF(TivsmAPIError);
//    PyModule_AddObject(m, "TivsmAPIError", TivsmAPIError);
//}

DL_EXPORT(void) inittivsmapi(void)
{
    PyObject *m;
    m = Py_InitModule("tivsmapi", TIVsmAPIMethods);
    if(m == NULL)
        return;
    
    registerConstants(m);
}

