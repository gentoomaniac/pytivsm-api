 pytivsm-api
Python wrapper for Tivoli Storage Manager API

# setting up environment
```
#
# TIVOLI STORAGE MANAGER (TSM) CONFIGURATION FILE LOCATIONS
DSMI_DIR=/opt/tivoli/tsm/client/api/bin64
DSMI_CONFIG=/opt/tivoli/tsm/client/api/bin64/dsm.sys
DSMI_LOG=/tmp/dsmapi.log
```

# first example
```python
import pytivsmapi
sess = pytivsmapi.dsmInit(dsmApiVersion=pytivsmapi.dsmQueryApiVersion())
ANS0102W Unable to open the message repository /opt/tivoli/tsm/client/api/bin64/EN_GB/dsmclientV3.cat. The American English repository will be used instead.
ANS0102W Unable to open the message repository /opt/tivoli/tsm/client/api/bin64/EN_GB/dsmclientV3.cat. The American English repository will be used instead.
ANS0102W Unable to open the message repository /opt/tivoli/tsm/client/api/bin64/EN_GB/dsmclientV3.cat. The American English repository will be used instead.
```
