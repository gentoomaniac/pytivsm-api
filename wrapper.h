#ifndef WRAPPER_H
#define WRAPPER_H

#include <Python.h>
#include <stdio.h>
#include <string.h>

#include "dsmapitd.h"      /* Tivoli Storage Manager API type definitions                */
#include "dsmapifp.h"      /* Tivoli Storage Manager API function prototypes.            */
#include "dsmrc.h"         /* Tivoli Storage Manager API return codes.                   */

#include "generators.h"
#include "helper.h"

PyObject* dsmChangePW_wrapper(PyObject * self, PyObject * args);
PyObject* dsmInit_wrapper(PyObject * self, PyObject * args, PyObject * keywds);
PyObject* dsmLogEvent_wrapper(PyObject * self, PyObject * args);
PyObject* dsmLogEventEx_wrapper(PyObject * self, PyObject * args);
PyObject* dsmQueryApiVersion_wrapper(PyObject* self);
PyObject* dsmQueryApiVersionEx_wrapper(PyObject* self);
PyObject* dsmQueryCliOptions_wrapper(PyObject* self);
PyObject* dsmQuerySessInfo_wrapper(PyObject* self, PyObject * args);
PyObject* dsmQuerySessOptions_wrapper(PyObject* self, PyObject * args);
PyObject* dsmRCMsg_wrapper(PyObject * self, PyObject * args);
PyObject* dsmRegisterFS_wrapper(PyObject * self, PyObject * args);
PyObject* dsmSetUp_wrapper(PyObject * self, PyObject * args, PyObject * keywds);
PyObject* dsmTerminate_wrapper(PyObject * self, PyObject * args);
PyObject* dsmUpdateFS_wrapper(PyObject * self, PyObject * args);

#endif
