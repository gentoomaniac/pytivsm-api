#include "helper.h"

void pyIntToDsStruct64(unsigned long int cInt, dsStruct64_t* struct64) {

    struct64->lo = cInt;
    cInt = cInt>>32;
    struct64->hi = cInt;
}
PyObject* dsStruct64ToPyInt(const dsStruct64_t struct64) {
    unsigned long int cInt = 0;

    cInt = struct64.hi;
    cInt = cInt<<32;
    cInt = cInt|struct64.lo;

    return Py_BuildValue("L", cInt);
}

PyObject* returnTouple(int rc, PyObject* dataObj) {
    PyObject* result = PyTuple_New(2);

    PyTuple_SetItem(result, 0, Py_BuildValue("I", rc));
    PyTuple_SetItem(result, 1, dataObj);

    return result;
}
