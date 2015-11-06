#include "generators.h"

/*
 * PyObject to C generators
 *
 * All functions below convert PyDicts into C structs
 *
 */

void pyDictToQryFSData(PyObject* dict, qryFSData* data) {
    data->stVersion = qryFSDataVersion;
    data->fsName = PyString_AsString(PyDict_GetItemString(dict, "fsName"));
}

void pyDictToUpdFSData(PyObject* dict, dsmFSUpd* updData) {
    updData->stVersion = dsmFSUpdVersion;
    updData->fsType = PyString_AsString(PyDict_GetItemString(dict, "fsType"));
    pyIntToDsStruct64(PyInt_AsLong(PyDict_GetItemString(dict, "occupancy")), &updData->occupancy);
    pyIntToDsStruct64(PyInt_AsLong(PyDict_GetItemString(dict, "capacity")), &updData->capacity);
    pyDictToFSAttr(PyDict_GetItemString(dict, "fsAttr"), &updData->fsAttr);
}

void pyDictToFSAttr(PyObject* dict, dsmFSAttr* attrObj) {
    pyDictToNetwareFSAttr(PyDict_GetItemString(dict, "netwareFSAttr"), &attrObj->netwareFSAttr);
    pyDictToUnixFSAttr(PyDict_GetItemString(dict, "unixFSAttr"), &attrObj->unixFSAttr);
    pyDictToDosFSAttr(PyDict_GetItemString(dict, "dosFSAttr"), &attrObj->dosFSAttr);
}
void pyDictToNetwareFSAttr(PyObject* dict, dsmNetwareFSAttrib* attrObj) {
    attrObj->fsInfoLength = PyInt_AsLong(PyDict_GetItemString(dict, "fsInfoLength"));
    strncpy(attrObj->fsInfo, PyString_AsString(PyDict_GetItemString(dict, "fsInfo")), DSM_MAX_FSINFO_LENGTH);
}
void pyDictToUnixFSAttr(PyObject* dict, dsmUnixFSAttrib* attrObj) {
    attrObj->fsInfoLength = PyInt_AsLong(PyDict_GetItemString(dict, "fsInfoLength"));
    strncpy(attrObj->fsInfo, PyString_AsString(PyDict_GetItemString(dict, "fsInfo")), DSM_MAX_FSINFO_LENGTH);
}
void pyDictToDosFSAttr(PyObject* dict, dsmDosFSAttrib* attrObj) {
    strncpy(&attrObj->driveLetter, PyString_AsString(PyDict_GetItemString(dict, "driveLetter")), sizeof(char));
    attrObj->fsInfoLength = PyInt_AsLong(PyDict_GetItemString(dict, "fsInfoLength"));
    strncpy(attrObj->fsInfo, PyString_AsString(PyDict_GetItemString(dict, "fsInfo")), DSM_MAX_FSINFO_LENGTH);
}
void pyDictToRegFSData(PyObject* dict, regFSData* fsData) {
    fsData->stVersion = regFSDataVersion;
    fsData->fsName = PyString_AsString(PyDict_GetItemString(dict, "fsName"));
    fsData->fsType = PyString_AsString(PyDict_GetItemString(dict, "fsType"));
    pyIntToDsStruct64(PyInt_AsLong(PyDict_GetItemString(dict, "occupancy")), &fsData->occupancy);
    pyIntToDsStruct64(PyInt_AsLong(PyDict_GetItemString(dict, "capacity")), &fsData->capacity);
    pyDictToFSAttr(PyDict_GetItemString(dict, "fsAttr"), &fsData->fsAttr);
}

void pyDictToDsmInitExInT(PyObject* dict, dsmInitExIn_t* dsmInitExInt) {
    dsmInitExInt->stVersion = dsmInitExInVersion;
    pyDictToDsmApiVersionEx(PyDict_GetItemString(dict, "dsmApiVersion"), dsmInitExInt->apiVersionExP);
    dsmInitExInt->clientNodeNameP = PyString_AsString(PyDict_GetItemString(dict, "clientNodeName"));
    dsmInitExInt->clientOwnerNameP = PyString_AsString(PyDict_GetItemString(dict, "clientOwnerName"));
    dsmInitExInt->clientPasswordP = PyString_AsString(PyDict_GetItemString(dict, "clientPassword"));
    dsmInitExInt->userNameP = PyString_AsString(PyDict_GetItemString(dict, "userName"));
    dsmInitExInt->userPasswordP = PyString_AsString(PyDict_GetItemString(dict, "userPassword"));
    dsmInitExInt->applicationTypeP = PyString_AsString(PyDict_GetItemString(dict, "applicationType"));
    dsmInitExInt->configfile = PyString_AsString(PyDict_GetItemString(dict, "configfile"));
    dsmInitExInt->options = PyString_AsString(PyDict_GetItemString(dict, "options"));
    strncpy(&dsmInitExInt->dirDelimiter, PyString_AsString(PyDict_GetItemString(dict, "dirDelimiter")), sizeof(char));
    dsmInitExInt->useUnicode = (PyDict_GetItemString(dict, "useUnicode") == Py_True) ? 1 : 0;
    dsmInitExInt->bCrossPlatform = (PyDict_GetItemString(dict, "bCrossPlatform") == Py_True) ? 1 : 0;
    dsmInitExInt->bService = (PyDict_GetItemString(dict, "bService") == Py_True) ? 1 : 0;
    dsmInitExInt->bEncryptKeyEnabled = (PyDict_GetItemString(dict, "bEncryptKeyEnabled") == Py_True) ? 1 : 0;
    dsmInitExInt->encryptionPasswordP = PyString_AsString(PyDict_GetItemString(dict, "encryptionPassword"));
    dsmInitExInt->useTsmBuffers = (PyDict_GetItemString(dict, "useTsmBuffers") == Py_True) ? 1 : 0;
    dsmInitExInt->numTsmBuffers = PyInt_AsLong(PyDict_GetItemString(dict, "numTsmBuffers"));
    pyDictToDsmAppVersion(PyDict_GetItemString(dict, "dsmAppVersion"), dsmInitExInt->appVersionP);
}

void pyDictToDsmAppVersion(PyObject* dict, dsmAppVersion* app) {
    app->stVersion = appVersionVer;
    app->applicationVersion = PyInt_AsLong(PyDict_GetItemString(dict, "applicationVersion"));
    app->applicationRelease = PyInt_AsLong(PyDict_GetItemString(dict, "applicationRelease"));
    app->applicationLevel = PyInt_AsLong(PyDict_GetItemString(dict, "applicationLevel"));
    app->applicationSubLevel = PyInt_AsLong(PyDict_GetItemString(dict, "applicationSubLevel"));
}

void pyDictToDsmApiVersion(PyObject* apiVersion, dsmApiVersion* dsmApiVersion) {
    dsmApiVersion->version = PyInt_AsLong(PyDict_GetItemString(apiVersion, "version"));
    dsmApiVersion->release = PyInt_AsLong(PyDict_GetItemString(apiVersion, "release"));
    dsmApiVersion->level = PyInt_AsLong(PyDict_GetItemString(apiVersion, "level"));
}

void pyDictToDsmApiVersionEx(PyObject* apiVersionEx, dsmApiVersionEx* dsmApiVersionEx) {
    dsmApiVersionEx->stVersion = apiVersionExVer;
    dsmApiVersionEx->version = PyInt_AsLong(PyDict_GetItemString(apiVersionEx, "version"));
    dsmApiVersionEx->release = PyInt_AsLong(PyDict_GetItemString(apiVersionEx, "release"));
    dsmApiVersionEx->level = PyInt_AsLong(PyDict_GetItemString(apiVersionEx, "level"));
    dsmApiVersionEx->subLevel = PyInt_AsLong(PyDict_GetItemString(apiVersionEx, "subLevel"));
    dsmApiVersionEx->unicode = (PyDict_GetItemString(apiVersionEx, "unicode") == Py_True) ? 1 : 0;
}


/*
 * C to PyObject generators
 *
 * All functions below convert C structs into PyDicts
 *
 */

PyObject* qryRespFSDataToPyDict(qryRespFSData respData) {
    PyObject* dict = PyDict_New();

    PyDict_SetItemString(dict, "stVersion", Py_BuildValue("i", respData.stVersion));
    PyDict_SetItemString(dict, "fsName", Py_BuildValue("s", respData.fsName));
    PyDict_SetItemString(dict, "fsType", Py_BuildValue("s", respData.fsType));
    PyDict_SetItemString(dict, "occupancy", dsStruct64ToPyInt(respData.occupancy));
    PyDict_SetItemString(dict, "capacity", dsStruct64ToPyInt(respData.capacity));

    // TODO

    return dict;
}

PyObject* dsmApiVersionToPyDict(dsmApiVersion apiVer) {
    PyObject* dict = PyDict_New();

    PyDict_SetItemString(dict, "version", Py_BuildValue("i", apiVer.version));
    PyDict_SetItemString(dict, "release", Py_BuildValue("i", apiVer.release));
    PyDict_SetItemString(dict, "level", Py_BuildValue("i", apiVer.level));

    return dict;
}

PyObject* dsmApiVersionExToPyDict(dsmApiVersionEx apiVerEx) {
    PyObject* dict = PyDict_New();

    PyDict_SetItemString(dict, "stVersion", Py_BuildValue("i", apiVerEx.stVersion));
    PyDict_SetItemString(dict, "version", Py_BuildValue("i", apiVerEx.version));
    PyDict_SetItemString(dict, "release", Py_BuildValue("i", apiVerEx.release));
    PyDict_SetItemString(dict, "level", Py_BuildValue("i", apiVerEx.level));
    PyDict_SetItemString(dict, "sublevel", Py_BuildValue("i", apiVerEx.subLevel));
    PyDict_SetItemString(dict, "unicode", apiVerEx.unicode ? Py_True : Py_False);

    return dict;
}

PyObject* optStructToPyDict(optStruct optstruct) {
    PyObject* dict = PyDict_New();

    PyDict_SetItemString(dict, "dsmDir", Py_BuildValue("s", optstruct.dsmiDir));
    PyDict_SetItemString(dict, "dsmiConfig", Py_BuildValue("s", optstruct.dsmiConfig));
    PyDict_SetItemString(dict, "serverName", Py_BuildValue("s", optstruct.serverName));
    PyDict_SetItemString(dict, "commMethod", Py_BuildValue("I", optstruct.commMethod));
    PyDict_SetItemString(dict, "serverAddresss", Py_BuildValue("s", optstruct.serverAddress));
    PyDict_SetItemString(dict, "nodeName", Py_BuildValue("s", optstruct.nodeName));
    PyDict_SetItemString(dict, "compression", optstruct.compression ? Py_True : Py_False);
    PyDict_SetItemString(dict, "compressalways", optstruct.compressalways ? Py_True : Py_False);
    PyDict_SetItemString(dict, "passwordAccess", optstruct.passwordAccess ? Py_True : Py_False);

    return dict;
}

PyObject* apiSessInfoStructToPyDict(ApiSessInfo sessInfo) {
    PyObject* dict = PyDict_New();
    char * date; // "2015-10-20 17:30:15"

    date = malloc(sizeof(char)*strlen(DATE_FORMAT));
    if(!date)
        return Py_None;

    // TODO: implement remaining fields
    PyDict_SetItemString(dict, "stVersion", Py_BuildValue("I", sessInfo.stVersion));
    PyDict_SetItemString(dict, "serverHost", Py_BuildValue("s", sessInfo.serverHost));
    PyDict_SetItemString(dict, "serverPort", Py_BuildValue("I", sessInfo.serverPort));
    sprintf(date, DATE_FORMAT, sessInfo.serverDate.year, sessInfo.serverDate.month, sessInfo.serverDate.day,
            sessInfo.serverDate.hour, sessInfo.serverDate.minute, sessInfo.serverDate.second);
    PyDict_SetItemString(dict, "serverDate", Py_BuildValue("s", date));
    PyDict_SetItemString(dict, "serverType", Py_BuildValue("s", sessInfo.serverType));
    PyDict_SetItemString(dict, "serverVer", Py_BuildValue("I", sessInfo.serverVer));
    PyDict_SetItemString(dict, "serverRel", Py_BuildValue("I", sessInfo.serverRel));
    PyDict_SetItemString(dict, "serverLev", Py_BuildValue("I", sessInfo.serverLev));
    PyDict_SetItemString(dict, "serverSubLev", Py_BuildValue("I", sessInfo.serverSubLev));
    PyDict_SetItemString(dict, "nodeType", Py_BuildValue("s", sessInfo.nodeType));
    PyDict_SetItemString(dict, "fsdelim", Py_BuildValue("c", sessInfo.fsdelim));
    PyDict_SetItemString(dict, "hldelim", Py_BuildValue("c", sessInfo.hldelim));
    PyDict_SetItemString(dict, "compression", Py_BuildValue("I", sessInfo.compression));
    PyDict_SetItemString(dict, "archDel", Py_BuildValue("I", sessInfo.archDel));
    PyDict_SetItemString(dict, "backDel", Py_BuildValue("I", sessInfo.backDel));
    PyDict_SetItemString(dict, "maxBytesPerTxn", Py_BuildValue("K", sessInfo.maxBytesPerTxn));
    PyDict_SetItemString(dict, "maxObjPerTxn", Py_BuildValue("K", sessInfo.maxObjPerTxn));
    PyDict_SetItemString(dict, "id", Py_BuildValue("s", sessInfo.id));
    PyDict_SetItemString(dict, "owner", Py_BuildValue("s", sessInfo.owner));
    PyDict_SetItemString(dict, "confFile", Py_BuildValue("s", sessInfo.confFile));
    PyDict_SetItemString(dict, "opNoTrace", Py_BuildValue("I", sessInfo.opNoTrace));
    PyDict_SetItemString(dict, "domainName", Py_BuildValue("s", sessInfo.domainName));
    PyDict_SetItemString(dict, "policySetName", Py_BuildValue("s", sessInfo.policySetName));
    if (sessInfo.polActDate.year) {
        sprintf(date, DATE_FORMAT,
            sessInfo.polActDate.year, sessInfo.polActDate.month, sessInfo.polActDate.day,
            sessInfo.polActDate.hour, sessInfo.polActDate.minute, sessInfo.polActDate.second);
        PyDict_SetItemString(dict, "polActDate", Py_BuildValue("s", date));
    } else {
        PyDict_SetItemString(dict, "polActDate", Py_None);
    }
    PyDict_SetItemString(dict, "dfltMCName", Py_BuildValue("s", sessInfo.dfltMCName));
    PyDict_SetItemString(dict, "gpBackRetn", Py_BuildValue("I", sessInfo.gpBackRetn));
    PyDict_SetItemString(dict, "gpArchRetn", Py_BuildValue("I", sessInfo));
    PyDict_SetItemString(dict, "adsmServerName", Py_BuildValue("s", sessInfo.adsmServerName));
    PyDict_SetItemString(dict, "archiveRetentionProtection", sessInfo.archiveRetentionProtection ? Py_True : Py_False);
    PyDict_SetItemString(dict, "maxBytesPerTxn_64", Py_BuildValue("K", sessInfo.maxBytesPerTxn_64));
    PyDict_SetItemString(dict, "lanFreeEnabled", sessInfo.lanFreeEnabled ? Py_True : Py_False);
    //PyDict_SetItemString(dict, "dedupType", Py_BuildValue("", sessInfo));
    PyDict_SetItemString(dict, "accessNode", Py_BuildValue("s", sessInfo.accessNode));
    //PyDict_SetItemString(dict, "failOverCfgType", Py_BuildValue("", sessInfo));
    PyDict_SetItemString(dict, "replServerName", Py_BuildValue("s", sessInfo.replServerName));
    PyDict_SetItemString(dict, "homeServerName", Py_BuildValue("s", sessInfo.homeServerName));
    PyDict_SetItemString(dict, "replServerHost", Py_BuildValue("s", sessInfo.replServerHost));
    PyDict_SetItemString(dict, "replServerPort", Py_BuildValue("I", sessInfo.replServerPort));

    if (date)
        free(date);

    return dict;
}
