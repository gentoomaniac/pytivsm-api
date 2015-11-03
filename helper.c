#include "helper.h"

PyObject* optSTructToPyDict(optStruct optstruct) {
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
