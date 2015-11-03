#include "helper.h"

PyObject* returnTouple(int rc, PyObject* dataObj) {
    PyObject* result = PyTuple_New(2);

    PyTuple_SetItem(result, 0, Py_BuildValue("I", rc));
    PyTuple_SetItem(result, 1, dataObj);

    return result;
}
