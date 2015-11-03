#ifndef HELPER_H
#define HELPER_H

#include <Python.h>
#include <string.h>

#include "dsmapitd.h"      /* Tivoli Storage Manager API type definitions                */
#include "dsmapifp.h"      /* Tivoli Storage Manager API function prototypes.            */
#include "dsmrc.h"         /* Tivoli Storage Manager API return codes.                   */

#define ERR_MAX 100

void setError(int rc);
PyObject* optSTructToPyDict(optStruct optstruct);

#endif
