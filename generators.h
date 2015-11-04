#ifndef GENERATORS_H
#define GENERATORS_H

#include <Python.h>
#include <string.h>

#include "dsmapitd.h"      /* Tivoli Storage Manager API type definitions                */
#include "dsmapifp.h"      /* Tivoli Storage Manager API function prototypes.            */
#include "dsmrc.h"         /* Tivoli Storage Manager API return codes.                   */

#define ERR_MAX 100
#define DATE_FORMAT "%i-%02i-%02i %02i:%02i:%02i"

void pyDictToDsmInitExInT(PyObject* dict, dsmInitExIn_t* dsmInitExInt);
void PyDictToDsmAppVersion(PyObject* dict, dsmAppVersion* app);
void pyDictToDsmApiVersion(PyObject* apiVersion, dsmApiVersion* dsmApiVersion);
void pyDictToDsmApiVersionEx(PyObject* apiVersion, dsmApiVersionEx* dsmApiVersion);

PyObject* dsmApiVersionToPyDict(dsmApiVersion apiVer);
PyObject* dsmApiVersionExToPyDict(dsmApiVersionEx apiVerEx);

PyObject* optStructToPyDict(optStruct optstruct);
PyObject* apiSessInfoStructToPyDict(ApiSessInfo sessInfo);

#endif
