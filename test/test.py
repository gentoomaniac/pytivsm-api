#!/usr/bin/env python
# -*- coding: utf-8 -*-

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

LOG.info("dsmInit()")
(rc, sess) = dsmInit(dsmApiVersion=dsmQueryApiVersion())
LOG.debug(dsmRCMsg(sess, rc)[1])

#LOG.info("dsmQuerySessInfo()")
#(rc, sess_info) = dsmQuerySessInfo(sess)
#LOG.debug(dsmRCMsg(sess, rc)[0])
#jsonize(sess_info)

if len(sys.argv) > 1:
    qryFSData = {'fsName': sys.argv[1]}
else:
    qryFSData = {'fsName': '*'}
LOG.info("dsmBeginQuery(%i, %s)", sess, qryFSData)
rc = dsmBeginQuery(sess, 3, qryFSData)
LOG.debug(dsmRCMsg(sess, rc)[1])

LOG.info("dsmGetNextQObj(%i, 3)", sess)
while True:
    (rc, data) = dsmGetNextQObj(sess, 3)
    LOG.debug(dsmRCMsg(sess, rc)[1])
    if rc != 2200:
        break
    LOG.info(data)

LOG.info("dsmEndQuery(%i)", sess)
rc = dsmEndQuery(sess)
LOG.debug(dsmRCMsg(sess, rc)[1])

LOG.info("dsmTerminate(%i)", sess)
dsmTerminate(sess)

