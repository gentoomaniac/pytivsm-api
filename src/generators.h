#ifndef GENERATORS_H
#define GENERATORS_H

#include <Python.h>
#include <string.h>

#include "dsmapitd.h"      /* Tivoli Storage Manager API type definitions                */
#include "dsmapifp.h"      /* Tivoli Storage Manager API function prototypes.            */
#include "dsmrc.h"         /* Tivoli Storage Manager API return codes.                   */

#include "helper.h"

#define ERR_MAX 100

void pyDictToQryABackupData(PyObject* dict, qryABackupData* data);
void pyDictToQryBackupData(PyObject* dict, qryBackupData* data);
void pyDictToDsmObjName(PyObject* dict, dsmObjName* data);

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

PyObject* qryARespBackupDataToPyDict(const qryARespBackupData respData);
PyObject* qryRespBackupDataToPyDict(const qryRespBackupData respData);
PyObject* dsmObjNameToPyDict(const dsmObjName objName);

PyObject* qryRespFSDataToPyDict(const qryRespFSData respData);

PyObject* dsmFSAttrToPyDict(const dsmFSAttr attr);
PyObject* dosFSAttribToPyDict(const dsmDosFSAttrib attr);
PyObject* unixFSAttribToPyDict(const dsmUnixFSAttrib attr);
PyObject* netwareFSAttribToPyDict(const dsmNetwareFSAttrib attr);

PyObject* dsmApiVersionToPyDict(const dsmApiVersion apiVer);
PyObject* dsmApiVersionExToPyDict(const dsmApiVersionEx apiVerEx);

PyObject* optStructToPyDict(const optStruct optstruct);
PyObject* apiSessInfoStructToPyDict(const ApiSessInfo sessInfo);

#endif
