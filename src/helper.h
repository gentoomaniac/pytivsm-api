#ifndef HELPER_H
#define HELPER_H

#include <Python.h>

#include "dsmapips.h"

void pyIntToDsStruct64(unsigned long int cInt, dsStruct64_t* struct64);
PyObject* dsStruct64ToPyInt(const dsStruct64_t struct64);

PyObject* returnTouple(int rc, PyObject* dataObj);

#endif
