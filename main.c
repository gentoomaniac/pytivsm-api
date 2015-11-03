#include <Python.h>

#include "wrapper.h"

//PyObject * TivsmAPIError = NULL;

PyMethodDef TIVsmAPIMethods[] = {
     { "dsmInit", (PyCFunction)dsmInit_wrapper, METH_KEYWORDS, "Init TSM session" },
     { "dsmQueryApiVersion", dsmQueryApiVersion_wrapper, METH_NOARGS, "Query TSM API version" },
     { "dsmQueryApiVersionEx", dsmQueryApiVersionEx_wrapper, METH_NOARGS, "Query TSM API version" },
     { "dsmQuerySessInfo", dsmQuerySessInfo_wrapper, METH_VARARGS, "Query TSM session info" },
     { "dsmQuerySessOptions", dsmQuerySessOptions_wrapper, METH_VARARGS, "queries important option values that are valid in the specified session" },
     { "dsmRCMsg", dsmRCMsg_wrapper, METH_VARARGS, "obtains the message text that is associated with an API return code" },
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

