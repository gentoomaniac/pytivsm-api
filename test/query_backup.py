#!/usr/bin/env python
# -*- coding: utf-8 -*-

import datetime
import json
import logging
import sys

from tivsmapi import *

FORMAT = '%(asctime)-15s - %(filename)s - %(levelname)s - %(message)s'
LOG = logging.getLogger(__name__)
LOG.setLevel(logging.DEBUG)
ch = logging.StreamHandler()
ch.setFormatter(logging.Formatter(FORMAT))
LOG.addHandler(ch)

def jsonize(data):
    LOG.debug(json.dumps(data, sort_keys=True, indent=2, separators=(',', ': ')))

if len(sys.argv) < 3:
    print "To few arguments."
    sys.exit(1)

LOG.info("dsmInit()")
(rc, sess) = dsmInit(dsmApiVersion=dsmQueryApiVersion())
LOG.debug(dsmRCMsg(sess, rc)[1])

qryBackupData = {
        'objName': {
            'fs': sys.argv[1],
            'hl': sys.argv[2],
            'll': sys.argv[3],
            'objType': 1     # DSM_OBJ_FILE
        },
        'owner': 'root',
        'objState': 255,       # DSM_ANY_MATCH
        'pitDate': datetime.datetime.today().isoformat()
    }
LOG.info("dsmBeginQuery(%i, 2, %s)", sess, qryBackupData)
rc = dsmBeginQuery(sess, 2, qryBackupData)      # qtBackupActive
LOG.debug(dsmRCMsg(sess, rc)[1])

while True:
    LOG.info("dsmGetNextQObj(%i, 2)", sess)
    (rc, data) = dsmGetNextQObj(sess, 2)
    LOG.debug( dsmRCMsg(sess, rc)[1])
    if rc != 2200:
        break
    LOG.info("result: %s", data)

LOG.info("dsmEndQuery(%i)", sess)
rc = dsmEndQuery(sess)
LOG.debug(dsmRCMsg(sess, rc)[1])

LOG.info("dsmTerminate(%i)", sess)
dsmTerminate(sess)

