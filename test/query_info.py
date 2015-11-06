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

#LOG.info("dsmQueryCliOptions()")
#(rc, res) = dsmQueryCliOptions()
#LOG.debug(dsmRCMsg(0, rc)[1])
#LOG.info("result: %s", res)

LOG.info("dsmInit()")
(rc, sess) = dsmInit(dsmApiVersion=dsmQueryApiVersion())
LOG.debug(dsmRCMsg(sess, rc)[1])

LOG.info("dsmQuerySessOptions(%s)", sess)
(rc, res) = dsmQuerySessOptions(sess)
LOG.debug(dsmRCMsg(sess, rc)[1])
LOG.info("result: %s", res)

LOG.info("dsmQuerySessInfo(%s)", sess)
(rc, res) = dsmQuerySessInfo(sess)
LOG.debug(dsmRCMsg(sess, rc)[1])
LOG.info("result: %s", res)

LOG.info("dsmTerminate(%i)", sess)
dsmTerminate(sess)

