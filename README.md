# pytivsm-api
Python wrapper for Tivoli Storage Manager API

## setting up environment
```
DSMI_DIR=/opt/tivoli/tsm/client/api/bin64
DSMI_CONFIG=/opt/tivoli/tsm/client/api/bin64/dsm.sys
DSMI_LOG=/tmp/dsmapi.log
```

## first example
```python
>>> import pytivsmapi
>>> pytivsmapi.dsmQueryCliOptions()
(0, {'commMethod': 1, 'serverAddresss': 'tsmserver.domain.net', 'nodeName': 'CLIENT_NODENAME', 'serverName': 'TSMSERVER.DOMAIN.NET', 'dsmDir': '/opt/tivoli/tsm/client/api/bin64', 'compressalways': True, 'passwordAccess': True, 'dsmiConfig': '/opt/tivoli/tsm/client/api/bin64/dsm.opt', 'compression': False})

>>> (rc, sess) = pytivsmapi.dsmInit(dsmApiVersion=pytivsmapi.dsmQueryApiVersion())
>>> (rc, msg) = pytivsmapi.dsmRCMsg(sess, rc)
>>> msg
'ANS0302I (RC0)    Successfully done.\n'

>>> pytivsmapi.dsmQuerySessOptions(sess)
(0, {'commMethod': 1, 'serverAddresss': 'tsmserver.domain.net', 'nodeName': 'CLIENT_NODENAME', 'serverName': 'TSMSERVER.DOMAIN.NET', 'dsmDir': '/opt/tivoli/tsm/client/api/bin64', 'compressalways': True, 'passwordAccess': True, 'dsmiConfig': '/opt/tivoli/tsm/client/api/bin64/dsm.opt', 'compression': False})

>>> pytivsmapi.dsmQuerySessInfo(sess)
(0, {'backDel': 2, 'maxObjPerTxn': 4096L, 'policySetName': 'STANDARD', 'opNoTrace': 0, 'replServerName': '', 'serverDate': '2015-11-03 05:22:53', 'hldelim': '/', 'serverPort': 1500, 'owner': 'marco', 'replServerHost': '', 'id': 'CLIENT_NODENAME', 'adsmServerName': '', 'compression': 3, 'archDel': 1, 'stVersion': 0, 'serverType': 'Linux/x86_64', 'gpArchRetn': 4266015752, 'serverVer': 7, 'homeServerName': '', 'confFile': '', 'dfltMCName': 'STANDARD', 'accessNode': '', 'nodeType': 'Linux x86-64', 'maxBytesPerTxn_64': 0L, 'serverHost': 'tsmserver.domain.net', 'replServerPort': 0, 'polActDate': None, 'maxBytesPerTxn': 26214400L, 'gpBackRetn': 30, 'fsdelim': '/', 'domainName': 'STANDARD', 'archiveRetentionProtection': False, 'lanFreeEnabled': False, 'serverRel': 1, 'serverSubLev': 300, 'serverLev': 1})

>>> rc = pytivsmapi.dsmLogEvent(sess, 2, "Hello to both of you!! :)")
>>> rc = pytivsmapi.dsmLogEventEx(sess, 3, "ABC12345678", 2, "I'm sent by dsmLogEventEx()")

>>> regFSData={'fsName':'/my_path/some/where','fsType':'some_type','occupancy':1024, 'capacity':4096, 'fsAttr':{'netwareFSAttr': {'fsInfoLength':9,'fsInfo':'rwxrwxrwx'}, 'unixFSAttr':{'fsInfoLength':9, 'fsInfo':'rwxrwxrwx'}, 'dosFSAttr':{'driveLetter':'', 'fsInfoLength':0, 'fsInfo':''}}}
>>> rc = pytivsmapi.dsmRegisterFS(sess, regFSData)

>>> rc = pytivsmapi.dsmChangePW(sess, "old", "new")
>>> pytivsmapi.dsmRCMsg(sess, rc)[1]
'ANS0264E (RC2300) Only a UNIX root user can execute dsmChangePW or dsmDeleteFS.'

>>> pytivsmapi.dsmTerminate(sess)
0

```

## implemented functions
- dsmChangePW()
- dsmInit()
- dsmInitEx() [wip]
- dsmLogEvent()
- dsmLogEventEx()
- dsmQueryApiVersion()
- dsmQueryApiVersionEx()
- dsmQueryCliOptions()
- dsmQuerySessInfo()
- dsmQuerySessOptions()
- dsmRCMsg()
- dsmRegisterFS [review]
- dsmSetUp() [wip]
- dsmTerminate()

## further reading
https://www-01.ibm.com/support/knowledgecenter/SSGSG7_7.1.3/api/c_functioncalls.html

## functions left to do
dsmBeginGetData
dsmBeginQuery
dsmBeginTxn
dsmBindMC
dsmCleanUp
dsmDeleteAccess
dsmDeleteFS
dsmDeleteObj
dsmEndGetData
dsmEndGetDataEx
dsmEndGetObj
dsmEndQuery
dsmEndSendObj
dsmEndSendObjEx
dsmEndTxn
dsmEndTxnEx
dsmGetData
dsmGetBufferData
dsmGetNextQObj
dsmGetObj
dsmGroupHandler
dsmQueryAccess
dsmQueryApiVersion
dsmQueryApiVersionEx
dsmReleaseBuffer
dsmRenameObj
dsmRequestBuffer
dsmRetentionEvent
dsmSendBufferData
dsmSendData
dsmSendObj
dsmSetAccess
dsmUpdateFS
dsmUpdateObj
dsmUpdateObjEx
