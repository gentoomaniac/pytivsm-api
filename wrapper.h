#ifndef WRAPPER_H
#define WRAPPER_H

#include <Python.h>
#include <stdio.h>
#include <string.h>

#include "dsmapitd.h"      /* Tivoli Storage Manager API type definitions                */
#include "dsmapifp.h"      /* Tivoli Storage Manager API function prototypes.            */
#include "dsmrc.h"         /* Tivoli Storage Manager API return codes.                   */

#include "helper.h"

#define DATE_FORMAT "%i-%02i-%02i %02i:%02i:%02i"

PyObject* dsmInit_wrapper(PyObject * self, PyObject * args, PyObject * keywds);
PyObject* dsmQueryApiVersion_wrapper(PyObject* self);
PyObject* dsmQueryApiVersionEx_wrapper(PyObject* self);
PyObject* dsmQuerySessInfo_wrapper(PyObject* self, PyObject * args);
PyObject* dsmQuerySessOptions_wrapper(PyObject* self, PyObject * args);
PyObject* dsmRCMsg_wrapper(PyObject * self, PyObject * args, PyObject * keywds);
void dsmSetUp_wrapper(PyObject * self, PyObject * args, PyObject * keywds);
PyObject * dsmTerminate_wrapper(PyObject * self, PyObject * args);

#endif
