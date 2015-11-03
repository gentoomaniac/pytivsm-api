#include "helper.h"

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

void setError(int rc) {
    char errorMessage[ERR_MAX];
    switch(rc){
        case DSM_RC_ACCESS_DENIED:
            sprintf(errorMessage, "API Error: DSM_RC_ACCESS_DENIED (%i)", rc);
            break;

        case DSM_RC_BAD_HOST_NAME:
            sprintf(errorMessage, "API Error: DSM_RC_BAD_HOST_NAME (%i)", rc); break;

        case DSM_RC_REJECT_NO_RESOURCES:
            sprintf(errorMessage, "API Error: DSM_RC_REJECT_NO_RESOURCES (%i)", rc); break;

        case DSM_RC_INVALID_OPT:
            sprintf(errorMessage, "API Error: DSM_RC_INVALID_OPT (%i)", rc); break;
        case DSM_RC_NO_HOST_ADDR:
            sprintf(errorMessage, "API Error: DSM_RC_NO_HOST_ADDR (%i)", rc); break;
        case DSM_RC_NO_OPT_FILE:
            sprintf(errorMessage, "API Error: DSM_RC_NO_OPT_FILE (%i)", rc); break;
        case DSM_RC_MACHINE_SAME:
            sprintf(errorMessage, "API Error: DSM_RC_MACHINE_SAME (%i)", rc); break;
        case DSM_RC_INVALID_SERVER:
            sprintf(errorMessage, "API Error: DSM_RC_INVALID_SERVER (%i)", rc); break;
        case DSM_RC_INVALID_KEYWORD:
            sprintf(errorMessage, "API Error: DSM_RC_INVALID_KEYWORD (%i)", rc); break;
        case DSM_RC_PATTERN_TOO_COMPLEX:
            sprintf(errorMessage, "API Error: DSM_RC_PATTERN_TOO_COMPLEX (%i)", rc); break;
        case DSM_RC_NO_CLOSING_BRACKET:
            sprintf(errorMessage, "API Error: DSM_RC_NO_CLOSING_BRACKET (%i)", rc); break;
        case DSM_RC_NLS_CANT_OPEN_TXT:
            sprintf(errorMessage, "API Error: DSM_RC_NLS_CANT_OPEN_TXT (%i)", rc); break;
        case DSM_RC_NLS_INVALID_CNTL_REC:
            sprintf(errorMessage, "API Error: DSM_RC_NLS_INVALID_CNTL_REC (%i)", rc); break;
        case DSM_RC_NOT_ADSM_AUTHORIZED:
            sprintf(errorMessage, "API Error: DSM_RC_NOT_ADSM_AUTHORIZED (%i)", rc); break;
        case DSM_RC_NO_INCLEXCL_FILE:
            sprintf(errorMessage, "API Error: DSM_RC_NO_INCLEXCL_FILE (%i)", rc); break;
        case DSM_RC_NO_SYS_OR_INCLEXCL:
            sprintf(errorMessage, "API Error: DSM_RC_NO_SYS_OR_INCLEXCL (%i)", rc); break;

        case DSM_RC_NO_NODE_REQD:
            sprintf(errorMessage, "API Error: DSM_RC_NO_NODE_REQD (%i)", rc); break;
        default:
            sprintf(errorMessage, "API Error: %i", rc);
    }

//    PyErr_SetString(TivsmAPIError, errorMessage);
}
