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
>>> sess = pytivsmapi.dsmInit(dsmApiVersion=pytivsmapi.dsmQueryApiVersion())
>>> pytivsmapi.dsmQuerySessOptions(sess)
{'commMethod': 1, 'serverAddresss': 'tsmserver.domain.net', 'nodeName': 'CLIENT_NODENAME', 'serverName': 'TSMSERVER.DOMAIN.NET', 'dsmDir': '/opt/tivoli/tsm/client/api/bin64', 'compressalways': True, 'passwordAccess': True, 'dsmiConfig': '/opt/tivoli/tsm/client/api/bin64/dsm.opt', 'compression': False}
>>> pytivsmapi.dsmQuerySessInfo(sess)
{'backDel': 2, 'maxObjPerTxn': 4096L, 'serverPort': 1500, 'opNoTrace': 0, 'replServerName': '', 'hldelim': '/', 'policySetName': 'STANDARD', 'owner': 'marco', 'replServerHost': '', 'id': 'CLIENT.DEEPTHOUGHT', 'adsmServerName': '', 'compression': 3, 'archDel': 1, 'stVersion': 0, 'serverType': 'Linux/x86_64', 'gpArchRetn': 2718571464, 'serverVer': 7, 'homeServerName': '', 'confFile': '', 'dfltMCName': 'STANDARD', 'accessNode': '', 'nodeType': 'Linux x86-64', 'maxBytesPerTxn_64': 0L, 'serverHost': 'tsmserver.domain.comt', 'replServerPort': 0, 'maxBytesPerTxn': 26214400L, 'gpBackRetn': 30, 'fsdelim': '/', 'domainName': 'TEST', 'archiveRetentionProtection': False, 'lanFreeEnabled': False, 'serverRel': 1, 'serverSubLev': 300, 'serverLev': 1}
>>> pytivsmapi.dsmRCMsg(sess,2014)
'ANS0221E (RC2014) There was an error in the TSM API internals.'
>>> pytivsmapi.dsmTerminate(sess)
True

```

## implemented functions
- dsmInit()
- dsmQueryApiVersion()
- dsmQueryApiVersionEx()
- dsmQuerySessInfo() [wip]
- dsmQuerySessOptions()
- dsmRCMsg()
- dsmSetUp() [wip]
- dsmTerminate()
