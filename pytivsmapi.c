#include <Python.h>

#include "dsmapitd.h"      /* Tivoli Storage Manager API type definitions                */
#include "dsmapifp.h"      /* Tivoli Storage Manager API function prototypes.            */
#include "dsmrc.h"         /* Tivoli Storage Manager API return codes.                   */

static PyObject* dsmQueryApiVersion_wrapper(PyObject* self, PyObject* args) {
    PyObject* dict = PyDict_New();
    dsmApiVersion apiVer;

    memset(&apiVer,0x00,sizeof(dsmApiVersion));
    dsmQueryApiVersion(&apiVer);

    PyDict_SetItemString(dict, "version", Py_BuildValue("i", apiVer.version));
    PyDict_SetItemString(dict, "release", Py_BuildValue("i", apiVer.release));
    PyDict_SetItemString(dict, "level", Py_BuildValue("i", apiVer.level));

    return dict;
}



static PyMethodDef TIVsmAPIMethods[] = {
     { "dsmQueryApiVersion", dsmQueryApiVersion_wrapper, METH_VARARGS, "Query TSM API version" },
      { NULL, NULL, 0, NULL }
};

DL_EXPORT(void) initpytivsmapi(void)
{
      Py_InitModule("pytivsmapi", TIVsmAPIMethods);
}
