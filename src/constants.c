#include "constants.h"

void registerConstants(PyObject *m){
    if(m == NULL)
        return;
    /*-------------------------------------------------------------------------+
    |  API Version, Release, and Level to use in dsmApiVersion on dsmInit()    |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_API_VERSION", DSM_API_VERSION);
    PyModule_AddIntConstant(m, "DSM_API_RELEASE", DSM_API_RELEASE);
    PyModule_AddIntConstant(m, "DSM_API_LEVEL", DSM_API_LEVEL);
    PyModule_AddIntConstant(m, "DSM_API_SUBLEVEL", DSM_API_SUBLEVEL);
    
    /*-------------------------------------------------------------------------+
    | Maximum field lengths                                                    |
    +-------------------------------------------------------------------------*/
     PyModule_AddIntConstant(m, "DSM_MAX_CG_DEST_LENGTH", DSM_MAX_CG_DEST_LENGTH);         /* copy group destination */
     PyModule_AddIntConstant(m, "DSM_MAX_CG_NAME_LENGTH", DSM_MAX_CG_NAME_LENGTH);         /* copy group name        */
     PyModule_AddIntConstant(m, "DSM_MAX_DESCR_LENGTH", DSM_MAX_DESCR_LENGTH);             /* archive description    */
     PyModule_AddIntConstant(m, "DSM_MAX_DOMAIN_LENGTH", DSM_MAX_DOMAIN_LENGTH);           /* policy domain name     */
     PyModule_AddIntConstant(m, "DSM_MAX_FSINFO_LENGTH", DSM_MAX_FSINFO_LENGTH);           /* filespace info         */
     PyModule_AddIntConstant(m, "DSM_MAX_USER_FSINFO_LENGTH", DSM_MAX_USER_FSINFO_LENGTH); /* max user filespace info*/
     PyModule_AddIntConstant(m, "DSM_MAX_FSNAME_LENGTH", DSM_MAX_FSNAME_LENGTH);           /* filespace name         */
     PyModule_AddIntConstant(m, "DSM_MAX_FSTYPE_LENGTH", DSM_MAX_FSTYPE_LENGTH);           /* filespace type         */
     PyModule_AddIntConstant(m, "DSM_MAX_HL_LENGTH", DSM_MAX_HL_LENGTH);                   /* object high level name */
     PyModule_AddIntConstant(m, "DSM_MAX_ID_LENGTH",DSM_MAX_ID_LENGTH);                    /* session node name      */
     PyModule_AddIntConstant(m, "DSM_MAX_LL_LENGTH",DSM_MAX_LL_LENGTH);                    /* object low level name  */
     PyModule_AddIntConstant(m, "DSM_MAX_MC_NAME_LENGTH", DSM_MAX_MC_NAME_LENGTH);         /* management class name  */
     PyModule_AddIntConstant(m, "DSM_MAX_OBJINFO_LENGTH", DSM_MAX_OBJINFO_LENGTH);         /* object info            */
     PyModule_AddIntConstant(m, "DSM_MAX_EXT_OBJINFO_LENGTH", DSM_MAX_EXT_OBJINFO_LENGTH); /* Extended object info   */
     PyModule_AddIntConstant(m, "DSM_MAX_OWNER_LENGTH", DSM_MAX_OWNER_LENGTH);             /* object owner name      */
     PyModule_AddIntConstant(m, "DSM_MAX_PLATFORM_LENGTH", DSM_MAX_PLATFORM_LENGTH);       /* application type       */
     PyModule_AddIntConstant(m, "DSM_MAX_PS_NAME_LENGTH", DSM_MAX_PS_NAME_LENGTH);         /* policy set name        */
     PyModule_AddIntConstant(m, "DSM_MAX_SERVERTYPE_LENGTH", DSM_MAX_SERVERTYPE_LENGTH);   /* server platform type   */
     PyModule_AddIntConstant(m, "DSM_MAX_VERIFIER_LENGTH", DSM_MAX_VERIFIER_LENGTH);       /* password               */
     PyModule_AddIntConstant(m, "DSM_PATH_MAX", DSM_PATH_MAX);                             /* API config file path   */
     PyModule_AddIntConstant(m, "DSM_NAME_MAX", DSM_NAME_MAX);                             /* API config file name   */
     PyModule_AddIntConstant(m, "DSM_MAX_NODE_LENGTH",DSM_MAX_NODE_LENGTH);                /* node/machine name      */
     PyModule_AddIntConstant(m, "DSM_MAX_RC_MSG_LENGTH", DSM_MAX_RC_MSG_LENGTH);           /* msg parm for dsmRCMsg  */
     PyModule_AddIntConstant(m, "DSM_MAX_SERVER_ADDRESS", DSM_MAX_SERVER_ADDRESS);         /* server address         */

     PyModule_AddIntConstant(m, "DSM_MAX_MC_DESCR_LENGTH", DSM_MAX_MC_DESCR_LENGTH);         /* mgmt class  */
     PyModule_AddIntConstant(m, "DSM_MAX_SERVERNAME_LENGTH", DSM_MAX_SERVERNAME_LENGTH);     /* server name    */
     PyModule_AddIntConstant(m, "DSM_MAX_GET_OBJ", DSM_MAX_GET_OBJ);                         /* max objs on BeginGetData */
     PyModule_AddIntConstant(m, "DSM_MAX_PARTIAL_GET_OBJ", DSM_MAX_PARTIAL_GET_OBJ);         /* max partial objs on BeginGetData */
     PyModule_AddIntConstant(m, "DSM_MAX_COMPRESSTYPE_LENGTH", DSM_MAX_COMPRESSTYPE_LENGTH); /* max compression algorithm name */
     
    /*-------------------------------------------------------------------------+
    | Minimum field lengths                                                    |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_MIN_COMPRESS_SIZE", DSM_MIN_COMPRESS_SIZE);  /* minimum number of bytes an object needs before compression is allowed*/
    
    /*-------------------------------------------------------------------------+
    |  Values for mtFlag in dsmSetup call                                      |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_MULTITHREAD", DSM_MULTITHREAD);
    PyModule_AddIntConstant(m, "DSM_SINGLETHREAD", DSM_SINGLETHREAD);
    
    /*-------------------------------------------------------------------------+
    |  Values for object type in dsmObjName structure                          |
    |  Note: These values must be kept in sync with dsmcomm.h                  |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_OBJ_FILE", DSM_OBJ_FILE);           /*object has attrib info & data*/
    PyModule_AddIntConstant(m, "DSM_OBJ_DIRECTORY", DSM_OBJ_DIRECTORY); /*obj has only attribute info  */
    PyModule_AddIntConstant(m, "DSM_OBJ_RESERVED1", DSM_OBJ_RESERVED1); /* for future use              */
    PyModule_AddIntConstant(m, "DSM_OBJ_RESERVED2", DSM_OBJ_RESERVED2); /* for future use              */
    PyModule_AddIntConstant(m, "DSM_OBJ_RESERVED3", DSM_OBJ_RESERVED3); /* for future use              */
    PyModule_AddIntConstant(m, "DSM_OBJ_WILDCARD", DSM_OBJ_WILDCARD);   /* Any object type             */
    PyModule_AddIntConstant(m, "DSM_OBJ_ANY_TYPE", DSM_OBJ_ANY_TYPE);   /* for future use              */
    
    /*-------------------------------------------------------------------------+
    | Type definition for compressedState in QryResp                           |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_OBJ_COMPRESSED_UNKNOWN", DSM_OBJ_COMPRESSED_UNKNOWN);
    PyModule_AddIntConstant(m, "DSM_OBJ_COMPRESSED_YES", DSM_OBJ_COMPRESSED_YES);
    PyModule_AddIntConstant(m, "DSM_OBJ_COMPRESSED_NO", DSM_OBJ_COMPRESSED_NO);

    /*---------------------------------------------------------------------+
    | Definitions for "group type" field in tsmGrouphandlerIn_t            |
    +---------------------------------------------------------------------*/

    PyModule_AddIntConstant(m, "DSM_GROUPTYPE_NONE", DSM_GROUPTYPE_NONE);           /* Not a group member            */
    PyModule_AddIntConstant(m, "DSM_GROUPTYPE_RESERVED1", DSM_GROUPTYPE_RESERVED1); /* for future use                */
    PyModule_AddIntConstant(m, "DSM_GROUPTYPE_PEER", DSM_GROUPTYPE_PEER);           /* Peer group                    */
    PyModule_AddIntConstant(m, "DSM_GROUPTYPE_RESERVED2", DSM_GROUPTYPE_RESERVED2); /* for future use                */

    /*---------------------------------------------------------------------+
    | Definitions for "member type" field in tsmGrouphandlerIn_t           |
    +---------------------------------------------------------------------*/

    PyModule_AddIntConstant(m, "DSM_MEMBERTYPE_LEADER", DSM_MEMBERTYPE_LEADER); /* group leader  */
    PyModule_AddIntConstant(m, "DSM_MEMBERTYPE_MEMBER", DSM_MEMBERTYPE_MEMBER); /* group member  */

    /*---------------------------------------------------------------------+
    | Definitions for "operation type" field in tsmGrouphandlerIn_t         |
    +---------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_GROUP_ACTION_BEGIN", DSM_GROUP_ACTION_BEGIN);
    PyModule_AddIntConstant(m, "DSM_GROUP_ACTION_OPEN", DSM_GROUP_ACTION_OPEN);         /* create new group             */
    PyModule_AddIntConstant(m, "DSM_GROUP_ACTION_CLOSE", DSM_GROUP_ACTION_CLOSE);       /* commit and save an open group */
    PyModule_AddIntConstant(m, "DSM_GROUP_ACTION_ADD", DSM_GROUP_ACTION_ADD);           /* Append to a group */
    PyModule_AddIntConstant(m, "DSM_GROUP_ACTION_ASSIGNTO", DSM_GROUP_ACTION_ASSIGNTO); /* Assign to a another group */
    PyModule_AddIntConstant(m, "DSM_GROUP_ACTION_REMOVE", DSM_GROUP_ACTION_REMOVE);     /* remove a member from a group */

    /*-------------------------------------------------------------------------+
    | Values for copySer in DetailCG structures for Query Mgmt Class response  |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "Copy_Serial_Static", Copy_Serial_Static);                 /*Copy Serialization Static       */
    PyModule_AddIntConstant(m, "Copy_Serial_Shared_Static", Copy_Serial_Shared_Static);   /*Copy Serialization Shared Static*/
    PyModule_AddIntConstant(m, "Copy_Serial_Shared_Dynamic", Copy_Serial_Shared_Dynamic); /*Copy Serialization Shared Dynamic*/
    PyModule_AddIntConstant(m, "Copy_Serial_Dynamic", Copy_Serial_Dynamic);               /*Copy Serialization Dynamic      */

    /*-------------------------------------------------------------------------+
    | Values for copyMode in DetailCG structures for Query Mgmt Class response |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "Copy_Mode_Modified", Copy_Mode_Modified); /*Copy Mode Modified              */
    PyModule_AddIntConstant(m, "Copy_Mode_Absolute", Copy_Mode_Absolute); /*Copy Mode Absolute              */

    /*-------------------------------------------------------------------------+
    |  Values for objState in qryBackupData structure                          |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_ACTIVE", DSM_ACTIVE);       /* query only active objects      */
    PyModule_AddIntConstant(m, "DSM_INACTIVE", DSM_INACTIVE);   /* query only inactive objects    */
    PyModule_AddIntConstant(m, "DSM_ANY_MATCH", DSM_ANY_MATCH); /* query all backup objects       */

    /*-------------------------------------------------------------------------+
    | Boundary values for dsmDate.year field in qryArchiveData structure       |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DATE_MINUS_INFINITE", DATE_MINUS_INFINITE); /* lowest boundary        */
    PyModule_AddIntConstant(m, "DATE_PLUS_INFINITE", DATE_PLUS_INFINITE);   /* highest upper boundary */

    /*-------------------------------------------------------------------------+
    | Bits masks for update action parameter on dsmUpdateFS()                  |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_FSUPD_FSTYPE", DSM_FSUPD_FSTYPE);
    PyModule_AddIntConstant(m, "DSM_FSUPD_FSINFO", DSM_FSUPD_FSINFO);
    PyModule_AddIntConstant(m, "DSM_FSUPD_BACKSTARTDATE", DSM_FSUPD_BACKSTARTDATE);
    PyModule_AddIntConstant(m, "DSM_FSUPD_BACKCOMPLETEDATE", DSM_FSUPD_BACKCOMPLETEDATE);
    PyModule_AddIntConstant(m, "DSM_FSUPD_OCCUPANCY", DSM_FSUPD_OCCUPANCY);
    PyModule_AddIntConstant(m, "DSM_FSUPD_CAPACITY", DSM_FSUPD_CAPACITY);
    PyModule_AddIntConstant(m, "DSM_FSUPD_RESERVED1", DSM_FSUPD_RESERVED1);

    /*-------------------------------------------------------------------------+
    | Bits mask  for backup update action parameter on dsmUpdateObj()          |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_BACKUPD_OWNER", DSM_BACKUPD_OWNER);
    PyModule_AddIntConstant(m, "DSM_BACKUPD_OBJINFO", DSM_BACKUPD_OBJINFO);
    PyModule_AddIntConstant(m, "DSM_BACKUPD_MC", DSM_BACKUPD_MC);

    PyModule_AddIntConstant(m, "DSM_ARCHUPD_OWNER", DSM_ARCHUPD_OWNER);
    PyModule_AddIntConstant(m, "DSM_ARCHUPD_OBJINFO", DSM_ARCHUPD_OBJINFO);
    PyModule_AddIntConstant(m, "DSM_ARCHUPD_DESCR", DSM_ARCHUPD_DESCR);

    /*-------------------------------------------------------------------------+
    |  Values for repository parameter on dsmDeleteFS()                        |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_ARCHIVE_REP", DSM_ARCHIVE_REP); /* archive repository             */
    PyModule_AddIntConstant(m, "DSM_BACKUP_REP", DSM_BACKUP_REP);   /* backup repository              */
    PyModule_AddIntConstant(m, "DSM_REPOS_ALL", DSM_REPOS_ALL);     /* all respository types          */

    /*-------------------------------------------------------------------------+
    |  Values for vote parameter on dsmEndTxn()                                |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_VOTE_COMMIT", DSM_VOTE_COMMIT); /* commit current transaction      */
    PyModule_AddIntConstant(m, "DSM_VOTE_ABORT", DSM_VOTE_ABORT);   /* roll back current transaction   */

    /*-------------------------------------------------------------------------+
    |  Values for various flags returned in ApiSessInfo structure.             |
    +-------------------------------------------------------------------------*/
    /* Client compression field codes */
    PyModule_AddIntConstant(m, "COMPRESS_YES", COMPRESS_YES); /* client must compress data             */
    PyModule_AddIntConstant(m, "COMPRESS_NO", COMPRESS_NO);   /* client must NOT compress data         */
    PyModule_AddIntConstant(m, "COMPRESS_CD", COMPRESS_CD);   /* client determined                     */

    /* Archive delete permission codes. */
    PyModule_AddIntConstant(m, "ARCHDEL_YES", ARCHDEL_YES); /* archive delete allowed                */
    PyModule_AddIntConstant(m, "ARCHDEL_NO", ARCHDEL_NO);   /* archive delete NOT allowed            */

    /* Backup delete permission codes. */
    PyModule_AddIntConstant(m, "BACKDEL_YES", BACKDEL_YES); /* backup delete allowed                 */
    PyModule_AddIntConstant(m, "BACKDEL_NO", BACKDEL_NO);   /* backup delete NOT allowed             */


    /*-------------------------------------------------------------------------+
    Values for various flags returned in optStruct structure.             |
    -------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_PASSWD_GENERATE", DSM_PASSWD_GENERATE);
    PyModule_AddIntConstant(m, "DSM_PASSWD_PROMPT", DSM_PASSWD_PROMPT);

    PyModule_AddIntConstant(m, "DSM_COMM_TCP", DSM_COMM_TCP);             /* tcpip         */ 
    PyModule_AddIntConstant(m, "DSM_COMM_NAMEDPIPE", DSM_COMM_NAMEDPIPE); /* Named pipes   */
    PyModule_AddIntConstant(m, "DSM_COMM_SHM", DSM_COMM_SHM);             /* Shared Memory */

    /* obsolete commmethods */
    PyModule_AddIntConstant(m, "DSM_COMM_PVM_IUCV", DSM_COMM_PVM_IUCV);
    PyModule_AddIntConstant(m, "DSM_COMM_3270", DSM_COMM_3270);
    PyModule_AddIntConstant(m, "DSM_COMM_IUCV", DSM_COMM_IUCV);
    PyModule_AddIntConstant(m, "DSM_COMM_PWSCS", DSM_COMM_PWSCS);
    PyModule_AddIntConstant(m, "DSM_COMM_SNA_LU6_2", DSM_COMM_SNA_LU6_2);
    PyModule_AddIntConstant(m, "DSM_COMM_IPXSPX", DSM_COMM_IPXSPX);       /* For IPX/SPX support */
    PyModule_AddIntConstant(m, "DSM_COMM_NETBIOS", DSM_COMM_NETBIOS);     /* NETBIOS */
    PyModule_AddIntConstant(m, "DSM_COMM_400COMM", DSM_COMM_400COMM);
    PyModule_AddIntConstant(m, "DSM_COMM_CLIO", DSM_COMM_CLIO);           /* CLIO/S */
    /*-------------------------------------------------------------------------+
    |  Values for userNameAuthorities in dsmInitEx for future use              |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_USERAUTH_NONE", DSM_USERAUTH_NONE);
    PyModule_AddIntConstant(m, "DSM_USERAUTH_ACCESS", DSM_USERAUTH_ACCESS);
    PyModule_AddIntConstant(m, "DSM_USERAUTH_OWNER", DSM_USERAUTH_OWNER);
    PyModule_AddIntConstant(m, "DSM_USERAUTH_POLICY", DSM_USERAUTH_POLICY);
    PyModule_AddIntConstant(m, "DSM_USERAUTH_SYSTEM", DSM_USERAUTH_SYSTEM);

    /*-------------------------------------------------------------------------+
    |  Values for encryptionType on dsmEndSendObjEx, queryResp                 |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "DSM_ENCRYPT_NO", DSM_ENCRYPT_NO);
    PyModule_AddIntConstant(m, "DSM_ENCRYPT_USER", DSM_ENCRYPT_USER);
    PyModule_AddIntConstant(m, "DSM_ENCRYPT_CLIENTENCRKEY", DSM_ENCRYPT_CLIENTENCRKEY);
    PyModule_AddIntConstant(m, "DSM_ENCRYPT_DES_56BIT", DSM_ENCRYPT_DES_56BIT);
    PyModule_AddIntConstant(m, "DSM_ENCRYPT_AES_128BIT", DSM_ENCRYPT_AES_128BIT);
    PyModule_AddIntConstant(m, "DSM_ENCRYPT_AES_256BIT", DSM_ENCRYPT_AES_256BIT);

    /*---------------------------------------------------------------------+
    | Definitions for mediaClass field.                                    |
    +---------------------------------------------------------------------*/
    /*
    *  The following constants define a hierarchy of media access classes.
    *  Lower numbers indicate media which can supply faster access to data.
    */
    /* Fixed: represents the class of on-line, fixed media (such as hard disks). */
    PyModule_AddIntConstant(m, "MEDIA_FIXED", MEDIA_FIXED);
    /* Library: represents the class of mountable media accessible through a mechanical mounting device. */
    PyModule_AddIntConstant(m, "MEDIA_LIBRARY", MEDIA_LIBRARY);
    /* future use */
    PyModule_AddIntConstant(m, "MEDIA_NETWORK", MEDIA_NETWORK);
    /* future use */
    PyModule_AddIntConstant(m, "MEDIA_SHELF", MEDIA_SHELF);
    /* future use */
    PyModule_AddIntConstant(m, "MEDIA_OFFSITE", MEDIA_OFFSITE);
    /* future use */
    PyModule_AddIntConstant(m, "MEDIA_UNAVAILABLE", MEDIA_UNAVAILABLE);
    
    /*-------------------------------------------------------------------------+
    | data structure versions                                                  |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "PartialObjDataVersion", PartialObjDataVersion); /*                                       */
    PyModule_AddIntConstant(m, "apiVersionExVer", apiVersionExVer);
    PyModule_AddIntConstant(m, "appVersionVer", appVersionVer);
    PyModule_AddIntConstant(m, "delBackVersion", delBackVersion);
    PyModule_AddIntConstant(m, "delArchVersion", delArchVersion);
    PyModule_AddIntConstant(m, "delBackIDVersion", delBackIDVersion);
    PyModule_AddIntConstant(m, "ObjAttrVersion", ObjAttrVersion);
    PyModule_AddIntConstant(m, "mcBindKeyVersion", mcBindKeyVersion);
    PyModule_AddIntConstant(m, "dsmGetListVersion", dsmGetListVersion);         /* default if not using Partial Obj data */
    PyModule_AddIntConstant(m, "dsmGetListPORVersion", dsmGetListPORVersion);   /* version if using Partial Obj data     */
    PyModule_AddIntConstant(m, "DataBlkVersion", DataBlkVersion);
    PyModule_AddIntConstant(m, "qryMCDataVersion", qryMCDataVersion);
    PyModule_AddIntConstant(m, "qryRespMCDetailDataVersion", qryRespMCDetailDataVersion);
    PyModule_AddIntConstant(m, "qryRespMCDataVersion", qryRespMCDataVersion);
    PyModule_AddIntConstant(m, "qryArchiveDataVersion", qryArchiveDataVersion);
    PyModule_AddIntConstant(m, "qryRespArchiveDataVersion", qryRespArchiveDataVersion);
    PyModule_AddIntConstant(m, "sndArchiveDataVersion", sndArchiveDataVersion);
    PyModule_AddIntConstant(m, "qryBackupDataVersion", qryBackupDataVersion);
    PyModule_AddIntConstant(m, "qryRespBackupDataVersion", qryRespBackupDataVersion);
    PyModule_AddIntConstant(m, "qryABackupDataVersion", qryABackupDataVersion);
    PyModule_AddIntConstant(m, "qryARespBackupDataVersion", qryARespBackupDataVersion);
    PyModule_AddIntConstant(m, "qryBackupGroupsVersion", qryBackupGroupsVersion);
    PyModule_AddIntConstant(m, "qryProxyNodeDataVersion",qryProxyNodeDataVersion);
    PyModule_AddIntConstant(m, "qryRespProxyNodeDataVersion", qryRespProxyNodeDataVersion);
    PyModule_AddIntConstant(m, "dsmFSUpdVersion", dsmFSUpdVersion);
    PyModule_AddIntConstant(m, "qryFSDataVersion", qryFSDataVersion);
    PyModule_AddIntConstant(m, "qryRespFSDataVersion", qryRespFSDataVersion);
    PyModule_AddIntConstant(m, "regFSDataVersion", regFSDataVersion);
    PyModule_AddIntConstant(m, "ApiSessInfoVersion", ApiSessInfoVersion);
    PyModule_AddIntConstant(m, "qryRespAccessDataVersion", qryRespAccessDataVersion);
    PyModule_AddIntConstant(m, "envSetUpVersion", envSetUpVersion);
    PyModule_AddIntConstant(m, "dsmInitExInVersion", dsmInitExInVersion);
    PyModule_AddIntConstant(m, "dsmInitExOutVersion", dsmInitExOutVersion);
    PyModule_AddIntConstant(m, "dsmLogExInVersion", dsmLogExInVersion);
    PyModule_AddIntConstant(m, "dsmLogExOutVersion", dsmLogExOutVersion);
    PyModule_AddIntConstant(m, "dsmRenameInVersion", dsmRenameInVersion);
    PyModule_AddIntConstant(m, "dsmRenameOutVersion", dsmRenameOutVersion);
    PyModule_AddIntConstant(m, "dsmEndSendObjExInVersion", dsmEndSendObjExInVersion);
    PyModule_AddIntConstant(m, "dsmEndSendObjExOutVersion", dsmEndSendObjExOutVersion);
    PyModule_AddIntConstant(m, "dsmGroupHandlerInVersion", dsmGroupHandlerInVersion);
    PyModule_AddIntConstant(m, "dsmGroupHandlerOutVersion", dsmGroupHandlerOutVersion);
    PyModule_AddIntConstant(m, "dsmEndTxnExInVersion", dsmEndTxnExInVersion);
    PyModule_AddIntConstant(m, "dsmEndTxnExOutVersion", dsmEndTxnExOutVersion);
    PyModule_AddIntConstant(m, "dsmEndGetDataExInVersion", dsmEndGetDataExInVersion);
    PyModule_AddIntConstant(m, "dsmEndGetDataExOutVersion", dsmEndGetDataExOutVersion);
    PyModule_AddIntConstant(m, "dsmObjlistVersion", dsmObjlistVersion);
    PyModule_AddIntConstant(m, "dsmRetentionEventInVersion", dsmRetentionEventInVersion);
    PyModule_AddIntConstant(m, "dsmRetentionEventOutVersion", dsmRetentionEventOutVersion);
    PyModule_AddIntConstant(m, "requestBufferInVersion", requestBufferInVersion);
    PyModule_AddIntConstant(m, "requestBufferOutVersion", requestBufferOutVersion);
    PyModule_AddIntConstant(m, "releaseBufferInVersion", releaseBufferInVersion);
    PyModule_AddIntConstant(m, "releaseBufferOutVersion", releaseBufferOutVersion);
    PyModule_AddIntConstant(m, "getBufferDataInVersion", getBufferDataInVersion);
    PyModule_AddIntConstant(m, "getBufferDataOutVersion", getBufferDataOutVersion);
    PyModule_AddIntConstant(m, "sendBufferDataInVersion", sendBufferDataInVersion);
    PyModule_AddIntConstant(m, "sendBufferDataOutVersion", sendBufferDataOutVersion);
    PyModule_AddIntConstant(m, "dsmUpdateObjExInVersion", dsmUpdateObjExInVersion);
    PyModule_AddIntConstant(m, "dsmUpdateObjExOutVersion", dsmUpdateObjExOutVersion);
    
    /*-------------------------------------------------------------------------+
    | Type definition for dsmGetType parameter on dsmBeginGetData()            |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "gtBackup", gtBackup);   /* Backup processing type    */
    PyModule_AddIntConstant(m, "gtArchive", gtArchive); /* Archive processing type   */
    
    /*-------------------------------------------------------------------------+
    |  Type definition for dsmQueryType parameter on dsmBeginQuery()           |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "qtArchive", qtArchive);             /* Archive query type                 */
    PyModule_AddIntConstant(m, "qtBackup", qtBackup);               /* Backup query type                  */
    PyModule_AddIntConstant(m, "qtBackupActive", qtBackupActive);   /* Fast query for active backup files */
    PyModule_AddIntConstant(m, "qtFilespace", qtFilespace);         /* Filespace query type               */
    PyModule_AddIntConstant(m, "qtMC", qtMC);                       /* Mgmt. class query type             */
    PyModule_AddIntConstant(m, "qtReserved1", qtReserved1);         /* future use                         */
    PyModule_AddIntConstant(m, "qtReserved2", qtReserved2);         /* future use                         */
    PyModule_AddIntConstant(m, "qtReserved3", qtReserved3);         /* future use                         */
    PyModule_AddIntConstant(m, "qtReserved4", qtReserved4);         /* future use                         */
    PyModule_AddIntConstant(m, "qtBackupGroups", qtBackupGroups);   /* group leaders in a specific fs     */
    PyModule_AddIntConstant(m, "qtOpenGroups", qtOpenGroups);       /* Open groups in a specific fs       */
    PyModule_AddIntConstant(m, "qtReserved5", qtOpenGroups);        /* future use                         */
    PyModule_AddIntConstant(m, "qtProxyNodeAuth", qtProxyNodeAuth); /* nodes that his node can proxy to   */ 
    PyModule_AddIntConstant(m, "qtProxyNodePeer", qtProxyNodePeer); /* Peer nodes with the same target    */ 
    PyModule_AddIntConstant(m, "qtReserved6", qtProxyNodePeer);     /* future use                         */ 
    PyModule_AddIntConstant(m, "qtReserved7", qtReserved7);         /* future use                         */ 
    PyModule_AddIntConstant(m, "qtReserved8", qtReserved8);         /* future use                         */ 
    
    /*-------------------------------------------------------------------------+
    |  Type definition sendType parameter on dsmBindMC() and dsmSendObj()      |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "stBackup", stBackup);                     /* Backup processing type    */
    PyModule_AddIntConstant(m, "stArchive", stArchive);                   /* Archive processing type   */
    PyModule_AddIntConstant(m, "stBackupMountWait", stBackupMountWait);   /* Backup processing with mountwait on   */
    PyModule_AddIntConstant(m, "stArchiveMountWait", stArchiveMountWait); /* Archive processing with mountwait on  */

    /*-------------------------------------------------------------------------+
    |  Type definition for delType parameter on dsmDeleteObj()                 |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "dtArchive", dtArchive);   /* Archive delete type */
    PyModule_AddIntConstant(m, "dtBackup", dtBackup);     /* Backup delete (deactivate) type */
    PyModule_AddIntConstant(m, "dtBackupID", dtBackupID); /* Backup delete (remove)     type */

    /*-------------------------------------------------------------------------+
    |  Type definition sendType parameter on dsmSetAccess()                    |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "atBackup", atBackup);   /* Backup processing type    */
    PyModule_AddIntConstant(m, "atArchive", atArchive); /* Archive processing type   */
    
    /*-------------------------------------------------------------------------+
    | Type definition for dedupType used in apisessInfo                        |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "dedupServerOnly", dedupServerOnly);         /* dedup only done on server    */
    PyModule_AddIntConstant(m, "dedupClientOrServer", dedupClientOrServer); /* dedup can be done on client or server */

    /*-------------------------------------------------------------------------+
    | Type definition for fail over configuration and status                   |
    --------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "failOvrNotConfigured", failOvrNotConfigured);
    PyModule_AddIntConstant(m, "failOvrConfigured", failOvrConfigured);
    PyModule_AddIntConstant(m, "failOvrConnectedToReplServer", failOvrConnectedToReplServer);
    
    /*-------------------------------------------------------------------------+
    | Type definition for LogType used in logInfo                              |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "logServer", logServer); /* log msg only to server    */
    PyModule_AddIntConstant(m, "logLocal", logLocal);   /* log msg only to local error log */
    PyModule_AddIntConstant(m, "logBoth", logBoth);     /* log msg to server and to local error log */
    PyModule_AddIntConstant(m, "logNone", logNone);
    
    /*-------------------------------------------------------------------------+
    | Type definition for LogType used in logInfo                              |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "logSevInfo", logSevInfo);       /* information ANE4991 */
    PyModule_AddIntConstant(m, "logSevWarning", logSevWarning); /* warning     ANE4992 */
    PyModule_AddIntConstant(m, "logSevError", logSevError);     /* Error       ANE4993 */
    PyModule_AddIntConstant(m, "logSevSevere", logSevSevere);   /* severe      ANE4994 */
    PyModule_AddIntConstant(m, "logSevLicense", logSevLicense); /* License     ANE4995 */
    PyModule_AddIntConstant(m, "logSevTryBuy", logSevTryBuy);   /* try Buy     ANE4996 */
    
    /*-------------------------------------------------------------------------+
    | Type definition eventType used on dsmRetentionEvent                      |
    +-------------------------------------------------------------------------*/
    PyModule_AddIntConstant(m, "eventRetentionActivate", eventRetentionActivate); /* signal the server that the event has occured */
    PyModule_AddIntConstant(m, "eventHoldObj", eventHoldObj);                     /* suspend delete/expire of the object          */
    PyModule_AddIntConstant(m, "eventReleaseObj", eventReleaseObj);               /* Resume normal delete/expire processing       */
}
