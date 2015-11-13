#include "helper.h"

void cStringToDsmDate(const char* dateString, dsmDate* date) {
    sscanf(dateString, DATE_FORMAT, (int*)&date->year, (int*)&date->month, (int*)&date->day, (int*)&date->hour, (int*)&date->minute, (int*)&date->second);
}

PyObject* dsmDateToPyString(const dsmDate date) {
    char* dateString; // "2015-10-20T17:30:15"
    PyObject* pyString = NULL;

    dateString = malloc(sizeof(char)*strlen(DATE_FORMAT));
    if(!dateString)
        return Py_None;

    sprintf(dateString, DATE_FORMAT, date.year, date.month, date.day, date.hour, date.minute, date.second);

    pyString = Py_BuildValue("s", dateString);
    free(dateString);

    return pyString;
}

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

    return Py_BuildValue("K", cInt);
}

PyObject* returnTouple(int rc, PyObject* dataObj) {
    PyObject* result = PyTuple_New(2);

    PyTuple_SetItem(result, 0, Py_BuildValue("I", rc));
    PyTuple_SetItem(result, 1, dataObj);

    return result;
}
