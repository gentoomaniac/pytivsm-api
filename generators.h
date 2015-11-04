#ifndef GENERATORS_H
#define GENERATORS_H

#include <Python.h>
#include <string.h>

#include "dsmapitd.h"      /* Tivoli Storage Manager API type definitions                */
#include "dsmapifp.h"      /* Tivoli Storage Manager API function prototypes.            */
#include "dsmrc.h"         /* Tivoli Storage Manager API return codes.                   */

#define ERR_MAX 100
#define DATE_FORMAT "%i-%02i-%02i %02i:%02i:%02i"

void pyDictToQryFSData(PyObject* dict, qryFSData* data);

void pyDictToFSAttr(PyObject* dict, dsmFSAttr* attrObj);
void pyDictToNetwareFSAttr(PyObject* dict, dsmNetwareFSAttrib* attrObj);
void pyDictToUnixFSAttr(PyObject* dict, dsmUnixFSAttrib* attrObj);
void pyDictToDosFSAttr(PyObject* dict, dsmDosFSAttrib* attrObj);

void pyDictToRegFSData(PyObject* dict, regFSData* fsData);
void pyDictToUpdFSData(PyObject* dict, dsmFSUpd* updData);

void pyDictToDsmInitExInT(PyObject* dict, dsmInitExIn_t* dsmInitExInt);
void pyDictToDsmAppVersion(PyObject* dict, dsmAppVersion* app);
void pyDictToDsmApiVersion(PyObject* apiVersion, dsmApiVersion* dsmApiVersion);
void pyDictToDsmApiVersionEx(PyObject* apiVersion, dsmApiVersionEx* dsmApiVersion);

PyObject* dsmApiVersionToPyDict(dsmApiVersion apiVer);
PyObject* dsmApiVersionExToPyDict(dsmApiVersionEx apiVerEx);

PyObject* optStructToPyDict(optStruct optstruct);
PyObject* apiSessInfoStructToPyDict(ApiSessInfo sessInfo);

#endif
