#ifndef HELPER_H
#define HELPER_H

#include <Python.h>
#include <string.h>

#include "dsmapips.h"
#include "dsmapitd.h"
#include "dsmapifp.h"
#include "dsmrc.h"

#define DATE_FORMAT "%04i-%02i-%02iT%02i:%02i:%02i"
PyObject* dsmDateToPyString(const dsmDate date);

void pyIntToDsStruct64(unsigned long int cInt, dsStruct64_t* struct64);
PyObject* dsStruct64ToPyInt(const dsStruct64_t struct64);

PyObject* returnTouple(int rc, PyObject* dataObj);

#endif
