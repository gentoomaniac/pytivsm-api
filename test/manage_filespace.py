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

if len(sys.argv) > 1:
    fsname = sys.argv[1]
else:
    fsname = "/test/filespace"

regFSData={
    'fsName':fsname,
    'fsType':'some_type',
    'occupancy':922337203685,
    'capacity':9223372036854778,
    'fsAttr':{
        'netwareFSAttr': {
            'fsInfoLength':9,
            'fsInfo':'rwxrwxrwx'
            },
        'unixFSAttr':{
            'fsInfoLength':9,
            'fsInfo':'rwxrwxrwx'
            },
        'dosFSAttr':{
            'driveLetter':'',
            'fsInfoLength':0,
            'fsInfo':''
            }
        }
    }
LOG.info("dsmRegisterFS(%i, %s)", sess, regFSData)
rc = dsmRegisterFS(sess, regFSData)
LOG.debug(dsmRCMsg(sess, rc)[1])


updFSData={
    'fsType': '',
    'occupancy': 0,
    'capacity': 9223372036854775800,            # field to update
    'fsAttr':{
        'netwareFSAttr': {
            'fsInfoLength': 0,
            'fsInfo': ''
            },
        'unixFSAttr':{
            'fsInfoLength': 0,
            'fsInfo': ''
            },
        'dosFSAttr':{
            'driveLetter': '',
            'fsInfoLength': 0,
            'fsInfo': ''
            }
        }
    }

LOG.info("dsmUpdateFS(%i, %s, %s, 64)", sess, fsname, updFSData)
rc = dsmUpdateFS(sess, fsname, updFSData, 64)   # 64 is the bitmask to update the capacity field
LOG.debug(dsmRCMsg(sess, rc)[1])

LOG.info("dsmDeleteFS(%i, %s, 1)", sess, fsname)
rc = dsmDeleteFS(sess, fsname, 1)   # 1 specifies to delete both Archive and Backup filespaces
LOG.debug(dsmRCMsg(sess, rc)[1])

LOG.info("dsmTerminate(%i)", sess)
dsmTerminate(sess)

