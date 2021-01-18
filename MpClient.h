/*++

    Copyright (c) 2020, pettro98 (github.com/pettro98)

Based on:

    UACME (github.com/hfiref0x/UACME):
        Copyright (c) 2014 - 2021, UACMe authors

    libmpclient (github.com/UldisRinkevichs/libmpclient):
        Copyright (c) 2018, libmpclient authors (github.com/UldisRinkevichs)

Module Name:

    MpClient

Abstract:

    Master include file for Windows Defender client interface.

Note:

    This file is built on official available Microsoft
    documentation with fixes and updates that actually
    make it work.
    It maybe different from Microsoft private version.

--*/

#pragma once

#ifndef _MPCLIENT_
#define _MPCLIENT_

typedef HANDLE *PMPHANDLE;
typedef HANDLE MPHANDLE;
typedef ULONG MPTHREAT_ID;
typedef ULONG MPRESOURCE_CLASS;

#define MP_RESOURCE_CLASS_UNKNOWN       0
#define MP_RESOURCE_CLASS_CONCRETE      0x0001
#define MP_RESOURCE_CLASS_LATENT        0x0002
#define MP_RESOURCE_CLASS_SAMPLE_FILE   0x0004
#define MP_RESOURCE_CLASS_SHARED        0x0100

#ifdef __midl
#define FAR
#define MP_MIDL_STRING [string, unique]
#else
#define MP_MIDL_STRING
#endif // __midl



typedef enum tagMPTHREAT_TYPE {
    MPTHREAT_TYPE_KNOWNBAD   = 0,
    MPTHREAT_TYPE_BEHAVIOR   = 1,
    MPTHREAT_TYPE_UNKNOWN    = 2,
    MPTHREAT_TYPE_KNOWNGOOD  = 3,
    MPTHREAT_TYPE_NIS        = 4,
    MPTHREAT_TYPE_MAXVALUE   = 4
} MPTHREAT_TYPE, *PMPTHREAT_TYPE;

typedef enum tagMPTHREAT_SEVERITY {
    MP_THREAT_SEVERITY_UNKNOWN   = 0,
    MP_THREAT_SEVERITY_LOW       = 1,
    MP_THREAT_SEVERITY_MODERATE  = 2,
    MP_THREAT_SEVERITY_HIGH      = 4,
    MP_THREAT_SEVERITY_SEVERE    = 5,
    MP_THREAT_SEVERITY_MAXVALUE  = 5
} MPTHREAT_SEVERITY, *PMPTHREAT_SEVERITY;

typedef enum tagMPTHREAT_CATEGORY {
    MP_THREAT_CATEGORY_INVALID                    = 0,
    MP_THREAT_CATEGORY_ADWARE                     = 1,
    MP_THREAT_CATEGORY_SPYWARE                    = 2,
    MP_THREAT_CATEGORY_PASSWORDSTEALER            = 3,
    MP_THREAT_CATEGORY_TROJANDOWNLOADER           = 4,
    MP_THREAT_CATEGORY_WORM                       = 5,
    MP_THREAT_CATEGORY_BACKDOOR                   = 6,
    MP_THREAT_CATEGORY_REMOTEACCESSTROJAN         = 7,
    MP_THREAT_CATEGORY_TROJAN                     = 8,
    MP_THREAT_CATEGORY_EMAILFLOODER               = 9,
    MP_THREAT_CATEGORY_KEYLOGGER                  = 10,
    MP_THREAT_CATEGORY_DIALER                     = 11,
    MP_THREAT_CATEGORY_MONITORINGSOFTWARE         = 12,
    MP_THREAT_CATEGORY_BROWSERMODIFIER            = 13,
    MP_THREAT_CATEGORY_COOKIE                     = 14,
    MP_THREAT_CATEGORY_BROWSERPLUGIN              = 15,
    MP_THREAT_CATEGORY_AOLEXPLOIT                 = 16,
    MP_THREAT_CATEGORY_NUKER                      = 17,
    MP_THREAT_CATEGORY_SECURITYDISABLER           = 18,
    MP_THREAT_CATEGORY_JOKEPROGRAM                = 19,
    MP_THREAT_CATEGORY_HOSTILEACTIVEXCONTROL      = 20,
    MP_THREAT_CATEGORY_SOFTWAREBUNDLER            = 21,
    MP_THREAT_CATEGORY_STEALTHNOTIFIER            = 22,
    MP_THREAT_CATEGORY_SETTINGSMODIFIER           = 23,
    MP_THREAT_CATEGORY_TOOLBAR                    = 24,
    MP_THREAT_CATEGORY_REMOTECONTROLSOFTWARE      = 25,
    MP_THREAT_CATEGORY_TROJANFTP                  = 26,
    MP_THREAT_CATEGORY_POTENTIALUNWANTEDSOFTWARE  = 27,
    MP_THREAT_CATEGORY_ICQEXPLOIT                 = 28,
    MP_THREAT_CATEGORY_TROJANTELNET               = 29,
    MP_THREAT_CATEGORY_EXPLOIT                    = 30,
    MP_THREAT_CATEGORY_FILESHARINGPROGRAM         = 31,
    MP_THREAT_CATEGORY_MALWARE_CREATION_TOOL      = 32,
    MP_THREAT_CATEGORY_REMOTE_CONTROL_SOFTWARE    = 33,
    MP_THREAT_CATEGORY_TOOL                       = 34,
    MP_THREAT_CATEGORY_TROJAN_DENIALOFSERVICE     = 36,
    MP_THREAT_CATEGORY_TROJAN_DROPPER             = 37,
    MP_THREAT_CATEGORY_TROJAN_MASSMAILER          = 38,
    MP_THREAT_CATEGORY_TROJAN_MONITORINGSOFTWARE  = 39,
    MP_THREAT_CATEGORY_TROJAN_PROXYSERVER         = 40,
    MP_THREAT_CATEGORY_VIRUS                      = 42,
    MP_THREAT_CATEGORY_KNOWN                      = 43,
    MP_THREAT_CATEGORY_UNKNOWN                    = 44,
    MP_THREAT_CATEGORY_SPP                        = 45,
    MP_THREAT_CATEGORY_BEHAVIOR                   = 46,
    MP_THREAT_CATEGORY_VULNERABILTIY              = 47,
    MP_THREAT_CATEGORY_POLICY                     = 48,
    MP_THREAT_CATEGORY_EUS                        = 49,
    MP_THREAT_CATEGORY_RANSOM                     = 50
} MPTHREAT_CATEGORY, *PMPTHREAT_CATEGORY;

typedef enum tagMPTHREAT_STATUS { 
    MP_THREAT_STATUS_UNKNOWN            = 0,
    MP_THREAT_STATUS_DETECTED           = 1,
    MP_THREAT_STATUS_CLEANED            = 2,
    MP_THREAT_STATUS_QUARANTINED        = 3,
    MP_THREAT_STATUS_REMOVED            = 4,
    MP_THREAT_STATUS_ALLOWED            = 5,
    MP_THREAT_STATUS_BLOCKED            = 6,
    MP_THREAT_STATUS_CLEAN_FAILED       = 102,
    MP_THREAT_STATUS_QUARANTINE_FAILED  = 103,
    MP_THREAT_STATUS_REMOVE_FAILED      = 104,
    MP_THREAT_STATUS_ALLOW_FAILED       = 105,
    MP_THREAT_STATUS_ABANDONED          = 106,
    MP_THREAT_STATUS_BLOCK_FAILED       = 107
} MPTHREAT_STATUS, *PMPTHREAT_STATUS;

typedef enum tagMPTHREAT_ACTION { 
    MP_THREAT_ACTION_UNKNOWN      = 0,
    MP_THREAT_ACTION_CLEAN        = 1,
    MP_THREAT_ACTION_QUARANTINE   = 2,
    MP_THREAT_ACTION_REMOVE       = 3,
    MP_THREAT_ACTION_ALLOW        = 6,
    MP_THREAT_ACTION_USERDEFINED  = 8,
    MP_THREAT_ACTION_NOACTION     = 9,
    MP_THREAT_ACTION_BLOCK        = 10,
    MP_THREAT_ACTION_MAX_VALUE    = 10
} MPTHREAT_ACTION, *PMPTHREAT_ACTION;

typedef enum tagMPSTATUS_FLAG { 
    MP_STATUS_FLAG_NONE                           = 0,
    MP_STATUS_FLAG_SERVICE_UNAVAILABLE            = 1 << 0,
    MP_STATUS_FLAG_MPENGINE_UNAVAILABLE           = 1 << 1,
    MP_STATUS_FLAG_THREAT_FULLSCAN_REQUIRED       = 1 << 2,
    MP_STATUS_FLAG_THREAT_REBOOT_REQUIRED         = 1 << 3,
    MP_STATUS_FLAG_THREAT_MANUAL_STEPS_REQUIRED   = 1 << 4,
    MP_STATUS_FLAG_DUE_AV_SIGNATURE               = 1 << 5,
    MP_STATUS_FLAG_DUE_AS_SIGNATURE               = 1 << 6,
    MP_STATUS_FLAG_DUE_QUICK_SCAN                 = 1 << 7,
    MP_STATUS_FLAG_DUE_FULL_SCAN                  = 1 << 8,
    MP_STATUS_FLAG_INPROGRESS_SYSTEM_SCAN         = 1 << 9,
    MP_STATUS_FLAG_INPROGRESS_ROUTINE_CLEANING    = 1 << 10,
    MP_STATUS_FLAG_DUE_SAMPLES                    = 1 << 11,
    MP_STATUS_FLAG_EVALUATION_MODE                = 1 << 12,
    MP_STATUS_FLAG_NONGENUINE                     = 1 << 13,
    MP_STATUS_FLAG_PRODUCT_EXPIRED                = 1 << 14,
    MP_STATUS_FLAG_THREAT_CALLISTO_REQUIRED       = 1 << 15,
    MP_STATUS_FLAG_SERVICE_ON_SYSTEM_SHUTDOWN     = 1 << 16,
    MP_STATUS_FLAG_SERVICE_CRITICAL_FAILURE       = 1 << 17,
    MP_STATUS_FLAG_SERVICE_NON_CRITICAL_FAILURE   = 1 << 18,
    MP_STATUS_FLAG_HEALTH_INITIALIZED             = 1 << 19,
    MP_STATUS_FLAG_DUE_PLATFORM_UPDATE            = 1 << 20,
    MP_STATUS_FLAG_INPROGRESS_PLATFORM_UPDATE     = 1 << 21,
    MP_STATUS_FLAG_PLATFORM_ABOUT_TO_BE_OUTDATED  = 1 << 22,
    MP_STATUS_FLAG_END_OF_LIFE                    = 1 << 23,
    MP_STATUS_FLAG_MAX                            = 1 << 23,
    MP_STATUS_FLAG_ALL                            = (1 << 24)-1
} MPSTATUS_FLAG, *PMPSTATUS_FLAG;

typedef enum tagMPTHREAT_DETECTION { 
    MP_THREAT_DETECTION_CONCRETE    = 0,
    MP_THREAT_DETECTION_HEURISTIC   = 1,
    MP_THREAT_DETECTION_GENERIC     = 2,
    MP_THREAT_DETECTION_SUSPICIOUS  = 4,
    MP_THREAT_DETECTION_FASTPATH    = 8
} MPTHREAT_DETECTION, *PMPTHREAT_DETECTION;

typedef enum tagMPEXECUTION_STATUS { 
    MP_EXECUTION_STATUS_UNKNOWN        = 0,
    MP_EXECUTION_STATUS_BLOCKED        = 1,
    MP_EXECUTION_STATUS_ALLOWED        = 2,
    MP_EXECUTION_STATUS_EXECUTING      = 3,
    MP_EXECUTION_STATUS_NOT_EXECUTING  = 4
} MPEXECUTION_STATUS, *PMPEXECUTION_STATUS;

typedef enum tagMP_FASTPATH_TYPE { 
    MP_FASTPATH_UNKNOWN   = 0,
    MP_FASTPATH_VDM       = 1,
    MP_FASTPATH_DISABLED  = 2
} MP_FASTPATH_TYPE, *PMP_FASTPATH_TYPE;

typedef enum tagMP_HASH_TYPE { 
    MP_HASH_TYPE_NONE    = 0,
    MP_HASH_TYPE_CRC32   = 2,
    MP_HASH_TYPE_MD5     = 4,
    MP_HASH_TYPE_SHA1    = 8,
    MP_HASH_TYPE_SHA256  = 16
} MP_HASH_TYPE, *PMP_HASH_TYPE;

typedef enum tagMPDETECTION_STATE { 
    MPDETECTION_STATE_UNKNOWN             = 0,
    MPDETECTION_STATE_ACTIVE              = 1,
    MPDETECTION_STATE_FINISHED            = 2,
    MPDETECTION_STATE_ADDITIONAL_ACTIONS  = 3,
    MPDETECTION_STATE_FAILED              = 4,
    MPDETECTION_STATE_CRITICALLY_FAILED   = 5,
    MPDETECTION_STATE_CLEARED             = 6
} MPDETECTION_STATE, *PMPDETECTION_STATE;

typedef enum tagMPSOURCE { 
    MPSOURCE_UNKNOWN             = 0,
    MPSOURCE_USER                = 1,
    MPSOURCE_SYSTEM              = 2,
    MPSOURCE_REALTIME            = 3,
    MPSOURCE_IOAV                = 4,
    MPSOURCE_NIS                 = 5,
    MPSOURCE_BHO                 = 6,
    MPSOURCE_IEPROTECT           = 6,
    MPSOURCE_ELAM                = 7,
    MPSOURCE_LOCAL_ATTESTATION   = 8,
    MPSOURCE_REMOTE_ATTESTATION  = 9,
    MPSOURCE_AMSI                = 10,
    MP_SOURCE_MAXVALUE           = 10
} MPSOURCE, *PMPSOURCE;

typedef enum tagMPDETECTION_ORIGIN { 
    MPDETECTION_ORIGIN_UNKNOWN        = 0,
    MPDETECTION_ORIGIN_LOCAL_MACHINE  = 1 << 0,
    MPDETECTION_ORIGIN_NETWORKSHARE   = 1 << 1,
    MPDETECTION_ORIGIN_INTERNET       = 1 << 2,
    MPDETECTION_ORIGIN_OUTBOUND       = 1 << 3,
    MPDETECTION_ORIGIN_INBOUND        = 1 << 4
} MPDETECTION_ORIGIN, *PMPDETECTION_ORIGIN;

typedef enum tagMPRESOLVED_REASON { 
    MPRESOLVED_REASON_UNKNOWN    = 0,
    MPRESOLVED_REASON_FULL_SCAN  = 1,
    MPRESOLVED_REASON_TIMED_OUT  = 2
} MPRESOLVED_REASON, *PMPRESOLVED_REASON;

typedef enum tagMPTHREAT_SOURCE {
    MPTHREAT_SOURCE_SCAN        = 0,
    MPTHREAT_SOURCE_ACTIVE      = 1,
    MPTHREAT_SOURCE_HISTORY     = 2,
    MPTHREAT_SOURCE_QUARANTINE  = 3,
    MPTHREAT_SOURCE_SIGNATURE   = 4,
    MPTHREAT_SOURCE_STATE       = 5,
    MPTHREAT_SOURCE_MAXVALUE    = 5
} MPTHREAT_SOURCE, *PMPTHREAT_SOURCE;

typedef enum tagMP_PERSISTENCE_LIMIT_TYPE { 
    MP_PERSISTENCE_UNKNOWN      = 0,
    MP_PERSISTENCE_NO_LIMIT     = 1,
    MP_PERSISTENCE_DURATION     = 2,
    MP_PERSISTENCE_VDM_VERSION  = 3,
    MP_PERSISTENCE_TIMESTAMP    = 4,
    MP_PERSISTENCE_FORCED       = 5
} MP_PERSISTENCE_LIMIT_TYPE, *PMP_PERSISTENCE_LIMIT_TYPE;

typedef enum tagMPSCAN_TYPE { 
    MPSCAN_TYPE_UNKNOWN   = 0,
    MPSCAN_TYPE_QUICK     = 1,
    MPSCAN_TYPE_FULL      = 2,
    MPSCAN_TYPE_RESOURCE  = 3,
    MPSCAN_TYPE_MAXVALUE  = 3
} MPSCAN_TYPE, *PMPSCAN_TYPE;

typedef enum tagMPNOTIFY { 
    MPNOTIFY_NONE,
    MPNOTIFY_CALL_START,
    MPNOTIFY_CALL_COMPLETE,
    MPNOTIFY_INTERNAL_FAILURE,
    MPNOTIFY_STATUS_SERVICE_START,
    MPNOTIFY_STATUS_SERVICE_RUNNING,
    MPNOTIFY_STATUS_SERVICE_STOP,
    MPNOTIFY_STATUS_COMPONENT,
    MPNOTIFY_STATUS_CHANGE,
    MPNOTIFY_STATUS_COMPONENT_CONFIGURATION,
    MPNOTIFY_STATUS_EXPIRATION_CHANGE,
    MPNOTIFY_STATUS_OFFLINE_SCAN_CHANGE,
    MPNOTIFY_SCAN_START,
    MPNOTIFY_SCAN_PAUSED,
    MPNOTIFY_SCAN_RESUMED,
    MPNOTIFY_SCAN_CANCEL,
    MPNOTIFY_SCAN_COMPLETE,
    MPNOTIFY_SCAN_PROGRESS,
    MPNOTIFY_SCAN_ERROR,
    MPNOTIFY_SCAN_INFECTED,
    MPNOTIFY_SCAN_MEMORYSTART,
    MPNOTIFY_SCAN_MEMORYCOMPLETE,
    MPNOTIFY_SCAN_SFC_BUILD_START,
    MPNOTIFY_SCAN_SFC_BUILD_COMPLETE,
    MPNOTIFY_SCAN_FASTPATH_START,
    MPNOTIFY_SCAN_FASTPATH_COMPLETE,
    MPNOTIFY_SCAN_FASTPATH_PROGRESS,
    MPNOTIFY_CLEAN_START,
    MPNOTIFY_CLEAN_COMPLETE,
    MPNOTIFY_CLEAN_RESTOREPOINT_START,
    MPNOTIFY_CLEAN_RESTOREPOINT_SUCCEEDED,
    MPNOTIFY_CLEAN_RESTOREPOINT_FAILED,
    MPNOTIFY_CLEAN_THREAT_START,
    MPNOTIFY_CLEAN_THREAT_SUCCEEDED,
    MPNOTIFY_CLEAN_THREAT_FAILED,
    MPNOTIFY_CLEAN_RESOURCE_SUCCEEDED,
    MPNOTIFY_CLEAN_RESOURCE_FAILED,
    MPNOTIFY_CLEAN_THREAT_COMPLETE,
    MPNOTIFY_PRECHECK_START,
    MPNOTIFY_PRECHECK_COMPLETE,
    MPNOTIFY_PRECHECK_RESOURCE_BLOCKED,
    MPNOTIFY_THREAT_DETECTED,
    MPNOTIFY_THREAT_MODIFIED,
    MPNOTIFY_THREAT_CLEAN_SUCCEEDED,
    MPNOTIFY_THREAT_CLEAN_FAILED,
    MPNOTIFY_THREAT_ABANDONED,
    MPNOTIFY_THREAT_CLEAN_EVENT_START,
    MPNOTIFY_THREAT_CLEAN_EVENT_COMPLETE,
    MPNOTIFY_SIGUPDATE_START,
    MPNOTIFY_SIGUPDATE_SEARCH_START,
    MPNOTIFY_SIGUPDATE_SEARCH_COMPLETE,
    MPNOTIFY_SIGUPDATE_SOFTWARE_UPDATE_AVAILABLE,
    MPNOTIFY_SIGUPDATE_DOWNLOAD_START,
    MPNOTIFY_SIGUPDATE_DOWNLOAD_PROGRESS,
    MPNOTIFY_SIGUPDATE_DOWNLOAD_COMPLETE,
    MPNOTIFY_SIGUPDATE_INSTALL_START,
    MPNOTIFY_SIGUPDATE_INSTALL_PROGRESS,
    MPNOTIFY_SIGUPDATE_INSTALL_COMPLETE,
    MPNOTIFY_SIGUPDATE_REBOOT_REQUIRED,
    MPNOTIFY_SIGUPDATE_REQUEST_PROCESSED,
    MPNOTIFY_SIGUPDATE_COMPLETE,
    MPNOTIFY_SAMPLE_START,
    MPNOTIFY_SAMPLE_COMPLETE,
    MPNOTIFY_SAMPLE_ITEM_START,
    MPNOTIFY_SAMPLE_ITEM_SUCCEEDED,
    MPNOTIFY_SAMPLE_ITEM_FAILED,
    MPNOTIFY_RESERVED_DATA,
    MPNOTIFY_FASTPATH_SIG_ADDED,
    MPNOTIFY_FASTPATH_SIG_REMOVED,
    MPNOTIFY_NIS_PRIVATE,
    MPNOTIFY_HEALTH_CHANGE,
    MPNOTIFY_HEALTH_RECOVERY,
    MPNOTIFY_HEALTH_START,
    MPNOTIFY_ENDOFLIFE_CHANGE,
    MPNOTIFY_MALWARETOAST_DATA
} MPNOTIFY, *PMPNOTIFY;

typedef enum tagMPCALLBACK_TYPE { 
    MPCALLBACK_UNKNOWN                     = 0,
    MPCALLBACK_STATUS                      = 1,
    MPCALLBACK_THREAT                      = 2,
    MPCALLBACK_SCAN                        = 3,
    MPCALLBACK_CLEAN                       = 4,
    MPCALLBACK_PRECHECK                    = 5,
    MPCALLBACK_SIGUPDATE                   = 6,
    MPCALLBACK_SAMPLE                      = 7,
    MPCALLBACK_RESERVED                    = 8,
    MPCALLBACK_CONFIGURATION_NOTIFICATION  = 9,
    MPCALLBACK_FASTPATH                    = 10,
    MPCALLBACK_PRODUCT_EXPIRATION          = 11,
    MPCALLBACK_NIS_PRIVATE                 = 12,
    MPCALLBACK_HEALTH                      = 13,
    MPCALLBACK_ENDOFLIFE                   = 14,
    MPCALLBACK_MALWARETOAST                = 15,
    MPCALLBACK_MAXVALUE                    = 15
} MPCALLBACK_TYPE, *PMPCALLBACK_TYPE;

typedef enum tagMPCOMPONENT_ID { 
    MPCOMPONENT_AS_SIGNATURE         = 0,
    MPCOMPONENT_AV_SIGNATURE         = 1,
    MPCOMPONENT_REALTIME_MONITOR     = 2,
    MPCOMPONENT_ONACCESS_PROTECTION  = 3,
    MPCOMPONENT_IOAV_PROTECTION      = 4,
    MPCOMPONENT_BEHAVIOR_MONITOR     = 5,
    MPCOMPONENT_AUTO_SCAN            = 6,
    MPCOMPONENT_AUTO_SIGUPDATE       = 7,
    MPCOMPONENT_IPC                  = 8,
    MPCOMPONENT_NIS                  = 9,
    MPCOMPONENT_ELAM                 = 10,
    MPCOMPONENT_MAXVALUE             = 10
} MPCOMPONENT_ID, *PMPCOMPONENT_ID;

typedef enum tagMP_SIGNATURE_TYPE { 
    MP_SIGNATURE_ANTIMALWARE     = 0,
    MP_SIGNATURE_ANTIVIRUS       = 1,
    MP_SIGNATURE_ANTISPYWARE     = 2,
    MP_SIGNATURE_NIS             = 3,
    MP_SIGNATURE_TYPES_MAXVALUE  = 3
} MP_SIGNATURE_TYPE, *PMP_SIGNATURE_TYPE;

typedef enum tagMP_REMOVAL_REASON { 
    MP_REMOVAL_UNKNOWN    = 0,
    MP_REMOVAL_MANUAL     = 1,
    MP_REMOVAL_AUTOMATIC  = 2
} MP_REMOVAL_REASON, *PMP_REMOVAL_REASON;

typedef enum tagMP_EXPIRE_REASON {
    MP_EXPIRED_UNKNOWN  = 0,
    MP_EXPIRED_EVAL     = 1,
    MP_EXPIRED_WAT      = 2
} MP_EXPIRE_REASON, *PMP_EXPIRE_REASON;

typedef enum tagMP_EXPIRE_STATE_REPORT {
    MP_EXPIRE_STATE_REPORT_UNKNOWN  = 0,
    MP_EXPIRE_STATE_REPORT_VALID    = 1,
    MP_EXPIRE_STATE_REPORT_WARNING  = 2,
    MP_EXPIRE_STATE_REPORT_EXPIRED  = 3
} MP_EXPIRE_STATE_REPORT, *PMP_EXPIRE_STATE_REPORT;

typedef enum tagMPCONTROL {
    MPCONTROL_ABORT   = 0,
    MPCONTROL_PAUSE   = 1,
    MPCONTROL_RESUME  = 2
} MPCONTROL, *PMCONTROL;



typedef struct tagMPCOMPONENT_VERSION {
    ULONGLONG      Version;
    ULARGE_INTEGER UpdateTime;
} MPCOMPONENT_VERSION, *PMPCOMPONENT_VERSION;

typedef struct tagMPVERSION_INFO {
    MPCOMPONENT_VERSION Product;
    MPCOMPONENT_VERSION Service;
    MPCOMPONENT_VERSION FileSystemFilter;
    MPCOMPONENT_VERSION Engine;
    MPCOMPONENT_VERSION ASSignature;
    MPCOMPONENT_VERSION AVSignature;
    MPCOMPONENT_VERSION NISEngine;
    MPCOMPONENT_VERSION NISSignature;
    MPCOMPONENT_VERSION Reserved[4];
} MPVERSION_INFO, *PMPVERSION_INFO;

typedef struct tagMPRESOURCE_INFO {
    MP_MIDL_STRING LPWSTR Scheme;
    MP_MIDL_STRING LPWSTR Path;
    MPRESOURCE_CLASS      Class;
} MPRESOURCE_INFO, *PMPRESOURCE_INFO;

typedef struct tagMPTHREAT_INFOEX_UNUSED {
    DWORD dwNone;
} MPTHREAT_INFOEX_UNUSED, *PMPTHREAT_INFOEX_UNUSED;

typedef struct tagMPTHREAT_INFOEX_BEHAVIOR {
    ULARGE_INTEGER         SignatureID;
    ULONGLONG              EngineVersion;
    ULONGLONG              ASDeltaSignatureVersion;
    ULONGLONG              AVDeltaSignatureVersion;
    MP_HASH_TYPE           HashType;
    DWORD                  FidelityValue;
    MP_MIDL_STRING  LPWSTR HashValue;
    MP_MIDL_STRING  LPWSTR TargetFileName;
    MP_MIDL_STRING  LPWSTR TargetFileHash;
} MPTHREAT_INFOEX_BEHAVIOR, *PMPTHREAT_INFOEX_BEHAVIOR;

typedef struct tagMPTHREAT_INFOEX_NIS {
    MP_MIDL_STRING LPWSTR SourceIP;
    MP_MIDL_STRING LPWSTR DestinationIP;
    DWORD                 dwSourceport;
    DWORD                 dwDestinationport;
    MP_MIDL_STRING LPWSTR Protocol;
    MP_MIDL_STRING LPWSTR Link;
} MPTHREAT_INFOEX_NIS, *PMPTHREAT_INFOEX_NIS;

typedef struct tagMPTHREAT_INFO {
    MPTHREAT_ID           ThreatID;
    GUID                  DetectionID;
    MP_MIDL_STRING        LPWSTR Name;
    MPTHREAT_TYPE         ThreatType;
    MPTHREAT_SEVERITY     ThreatCriticality;
    MPTHREAT_CATEGORY     ThreatCategory;
    DWORD                 ThreatShortDescriptionID;
    DWORD                 ThreatAdviseDescriptionID;
    MPTHREAT_STATUS       ThreatStatus;
    DWORD                 SuggestedActionCount;
    MPTHREAT_ACTION       SuggestedActionArray[ANYSIZE_ARRAY];
    DWORD                 ResourceCount;
    PMPRESOURCE_INFO      *ResourceList[ANYSIZE_ARRAY];
    ULARGE_INTEGER        ThreatStatusTime;
    HRESULT               ThreatStatusCode;
    MPTHREAT_DETECTION    ThreatDetection;
    GUID                  QuarantineGuid;
    MPEXECUTION_STATUS    ExecutionStatus;
    union {
        PMPTHREAT_INFOEX_UNUSED   pKnownBad;
        PMPTHREAT_INFOEX_BEHAVIOR pBehavior;
        PMPTHREAT_INFOEX_UNUSED   pUnknown;
        PMPTHREAT_INFOEX_UNUSED   pKnownGood;
        PMPTHREAT_INFOEX_NIS      pNis;
    } Data;
    MPDETECTION_STATE     State;
    MP_MIDL_STRING LPWSTR DetectionUser;
    MPSOURCE              DetectionSource;
    MP_MIDL_STRING LPWSTR ProcessName;
    MPDETECTION_ORIGIN    DetectionOrigin;
    DWORD                 reserved1;
    ULARGE_INTEGER        DetectionTime;
    MPEXECUTION_STATUS    PreExecutionStatus;
    ULARGE_INTEGER        RemediationTime;
    MPEXECUTION_STATUS    PostExecutionStatus;
    BOOL                  CriticalFailure;
    DWORD                 NonCriticalReason;
    MP_MIDL_STRING LPWSTR RemediationUser;
    DWORD                 RemediationResourceCount;
    PMPRESOURCE_INFO      RemediationResourceList[ANYSIZE_ARRAY];
    BOOL                  FailureResolved;
    MPRESOLVED_REASON     ResolvedReason;
    DWORD                 AdditionalActions;
    DWORD                 ResolvedActions;
    DWORD                 dwThreatStatusFlag;
} MPTHREAT_INFO, *PMPTHREAT_INFO;

typedef struct tagMPTHREAT_LOCALIZED_INFO {
    MPTHREAT_ID           ThreatID;
    MP_MIDL_STRING LPWSTR CategoryName;
    MP_MIDL_STRING LPWSTR CategoryDescription;
    MP_MIDL_STRING LPWSTR SeverityName;
    MP_MIDL_STRING LPWSTR SeverityDescription;
    MP_MIDL_STRING LPWSTR ShortDescription;
    MP_MIDL_STRING LPWSTR DefaultActionName;
    MP_MIDL_STRING LPWSTR Advice;
    MP_MIDL_STRING LPWSTR ThreatUrl;
} MPTHREAT_LOCALIZED_INFO, *PMPTHREAT_LOCALIZED_INFO;

typedef struct tagMPTHREAT_STATS {
    UINT ThreatCount;
    UINT SuspiciousThreatCount;
    UINT Reserved[4];
} MPTHREAT_STATS, *PMPTHREAT_STATS;

typedef struct tagMPTHREAT_DATA {
    MPTHREAT_ID     ThreatID;
    DWORD           dwSessionID;
    MPTHREAT_ACTION ThreatAction;
    DWORD           dwStatus;
} MPTHREAT_DATA, *PMPTHREAT_DATA;

typedef struct tagMPSCAN_RESOURCES {
    DWORD            dwResourceCount;
    PMPRESOURCE_INFO pResourceList;
} MPSCAN_RESOURCES, *PMPSCAN_RESOURCES;

typedef struct tagMPSTATUS_DATAEX_UNUSED {
    DWORD dwNone;
} MPSTATUS_DATAEX_UNUSED, *PMPSTATUS_DATAEX_UNUSED;

typedef struct tagMPSTATUS_DATA {
    MPCOMPONENT_ID ComponentID;
    BOOL           fEnable;
    union {
        PMPSTATUS_DATAEX_UNUSED p1;
        PMPSTATUS_DATAEX_UNUSED p2;
        PMPSTATUS_DATAEX_UNUSED p3;
        PMPSTATUS_DATAEX_UNUSED p4;
        PMPSTATUS_DATAEX_UNUSED p5;
        PMPSTATUS_DATAEX_UNUSED p6;
        PMPSTATUS_DATAEX_UNUSED p7;
        PMPSTATUS_DATAEX_UNUSED p8;
        PMPSTATUS_DATAEX_UNUSED p9;
        PMPSTATUS_DATAEX_UNUSED pa;
        PMPSTATUS_DATAEX_UNUSED pb;
    } ComponentStatus;
} MPSTATUS_DATA, *PMPSTATUS_DATA;

typedef struct tagMPRESOURCE_STATS {
    DWORD  PPMProgress;
    UINT64 ProcessCount;
    UINT64 FileCount;
    UINT64 FileBytesCount;
    UINT64 RegKeyCount;
    UINT64 Reserved[4];
} MPRESOURCE_STATS, *PMPRESOURCE_STATS;

typedef struct tagMPSCAN_DATA {
    MPSCAN_TYPE      ScanType;
    PMPRESOURCE_INFO ResourceInfo;
    MPRESOURCE_STATS ResourceStats;
    MPTHREAT_STATS   ThreatStats;
} MPSCAN_DATA, *PMPSCAN_DATA;

typedef struct tagMPCLEAN_DATA {
    MPTHREAT_ID      ThreatID;
    MPTHREAT_ACTION  ThreatAction;
    DWORD            dwStatus;
    PMPRESOURCE_INFO ResourceInfo;
} MPCLEAN_DATA, *PMPCLEAN_DATA;

typedef struct tagMPCLEAN_PRECHECK_DATA {
    PMPRESOURCE_INFO     BlockedResourceInfo;
    PMPRESOURCE_INFO     BlockingResourceInfo;
} MPCLEAN_PRECHECK_DATA, *PMPCLEAN_PRECHECK_DATA;

typedef struct tagMPSIGUPDATE_DATA {
    DWORD                 dwPercentComplete;
    DWORD                 dwTotalUpdates;
    DWORD                 dwCurrentUpdateIndex;
    ULONG                 eType;
    ULONG                 Stage;
    MP_MIDL_STRING LPWSTR Path;
} MPSIGUPDATE_DATA, *PMPSIGUPDATE_DATA;

typedef struct tagMPSAMPLE_DATA {
    DWORD dwSampleIndex;
} MPSAMPLE_DATA, *PMPSAMPLE_DATA;

typedef struct tagMPRESERVED_DATA {
    DWORD cbReservedData;
    BYTE  *pbReservedData;
} MPRESERVED_DATA, *PMPRESERVED_DATA;

typedef struct tagMPCONFIGURATION_DATA {
    MP_MIDL_STRING LPWSTR ConfigurationName;
    DWORD                 DataType;
    DWORD                 PreviousDataSize;
    BYTE                  *pPreviousData;
    DWORD                 CurrentDataSize;
    BYTE                  *pCurrentData;
} MPCONFIGURATION_DATA, *PMPCONFIGURATION_DATA;

typedef struct tagMPFASTPATH_DATA {
    MP_SIGNATURE_TYPE         SignatureType;
    MP_FASTPATH_TYPE          FastPathSignatureType;
    MP_MIDL_STRING LPWSTR     FastPathSignatureVersion;
    ULARGE_INTEGER            CompilationTimestamp;
    MP_PERSISTENCE_LIMIT_TYPE PersistenceType;
    MP_MIDL_STRING LPWSTR     PersistenceValue;
    MP_MIDL_STRING LPWSTR     PersistencePath;
    MP_REMOVAL_REASON         Reason;
} MPFASTPATH_DATA, *PMPFASTPATH_DATA;

typedef struct tagMPEXPIRATION_DATA {
    MP_EXPIRE_REASON       Reason;
    MP_EXPIRE_STATE_REPORT State;
} MPEXPIRATION_DATA, *PMPEXPIRATION_DATA;

typedef struct tagMPNIS_PRIVATE_DATA {
    DWORD dwNotificationType;
    DWORD cbDataSize;
    BYTE  *pbData;
} MPNIS_PRIVATE_DATA, *PMPNIS_PRIVATE_DATA;

typedef struct tagMPHEALTH_DATA {
    DWORD dwNotificationType;
    DWORD dwNotificationFlag;
} MPHEALTH_DATA, *PMPHEALTH_DATA;

typedef struct tagMPENDOFLIFE_DATA {
    FILETIME ftSignatureExpiry;
    FILETIME ftPlatformExpiry;
    BOOL     fAdminControlled;
    BOOL     fEndOfLifeImpendingOrPast;
} MPENDOFLIFE_DATA, *PMPENDOFLIFE_DATA;

typedef struct tagMPMALWARETOAST_DATA {
    DWORD                 dwThreatId;
    MP_MIDL_STRING LPWSTR pszThreatName;
} MPMALWARETOAST_DATA, *PMPMALWARETOAST_DATA;

typedef struct tagMPCALLBACK_DATA {
    MPNOTIFY        Notify;
    HRESULT         hResult;
    ULARGE_INTEGER  TimeStamp;
    MPCALLBACK_TYPE Type;
    union {
        PMPSTATUS_DATA         pStatusData;
        PMPSCAN_DATA           pScanData;
        PMPCLEAN_DATA          pCleanData;
        PMPCLEAN_PRECHECK_DATA pPrecheckData;
        PMPTHREAT_DATA         pThreatData;
        PMPSIGUPDATE_DATA      pSigUpdateData;
        PMPSAMPLE_DATA         pSampleData;
        PMPRESERVED_DATA       pReservedData;
        PMPCONFIGURATION_DATA  pConfigurationData;
        PMPFASTPATH_DATA       pFastPathData;
        PMPEXPIRATION_DATA     pExpirationData;
        PMPNIS_PRIVATE_DATA    pNISPrivateData;
        PMPHEALTH_DATA         pHealthData;
        PMPENDOFLIFE_DATA      pEndOfLifeData;
        PMPMALWARETOAST_DATA   pMalwareToastData;
    } Data;
} MPCALLBACK_DATA, *PMPCALLBACK_DATA;



HRESULT WINAPI WDStatus(
    _Out_ BOOL* pfEnabled);

HRESULT WINAPI WDEnable(
	_In_ BOOL fEnable);

HRESULT WINAPI MpManagerOpen(
    _In_  DWORD dwReserved,
    _Out_ PMPHANDLE phMpHandle);

HRESULT WINAPI MpHandleClose(
    _In_ MPHANDLE hMpHandle);

void WINAPI MpFreeMemory(
    _In_ PVOID pMemory);

HRESULT WINAPI MpManagerVersionQuery(
    _In_  MPHANDLE hMpHandle,
    _Out_ PMPVERSION_INFO pVersionInfo);

HRESULT WINAPI MpErrorMessageFormat(
    _In_  MPHANDLE hMpHandle,
    _In_  HRESULT  hrError,
    _Out_ LPWSTR   *pwszErrorDesc);

HRESULT WINAPI MpThreatEnumerate(
    _In_  MPHANDLE hThreatEnumHandle,
    _Out_ PMPTHREAT_INFO *ppThreatInfo);

HRESULT WINAPI MpThreatOpen(
    _In_  MPHANDLE        hScanHandle,
    _In_  MPTHREAT_SOURCE ThreatSource,
    _In_  MPTHREAT_TYPE   ThreatType,
    _Out_ PMPHANDLE       phThreatEnumHandle);

HRESULT WINAPI MpThreatQuery(
    _In_      MPHANDLE                 hMpHandle,
    _In_      MPTHREAT_ID              ThreatID,
    _Out_     PMPTHREAT_INFO           *ppThreatInfo,
    _Out_opt_ PMPTHREAT_LOCALIZED_INFO *ppThreatLocalizedInfo);

HRESULT WINAPI MpScanStart(
    _In_     MPHANDLE          hMpHandle,
    _In_     MPSCAN_TYPE       ScanType,
    _In_     DWORD             dwScanOptions,
    _In_opt_ PMPSCAN_RESOURCES pScanResources,
    _In_opt_ PMPCALLBACK_DATA  pCallbackInfo,
    _Out_    PMPHANDLE         phScanHandle);

HRESULT WINAPI MpScanControl(
    _In_ MPHANDLE  hScanHandle,
    _In_ MPCONTROL ScanControl);

HRESULT WINAPI MpManagerStatusQuery(
    _In_  MPHANDLE       hMpHandle,
    _Out_ PMPSTATUS_INFO pStatusInfo);

HRESULT WINAPI MpManagerStatusQueryEx(
    _In_  MPHANDLE       hMpHandle,
    _In_  DWORD          dwFlag,
    _Out_ PMPSTATUS_INFO pStatusInfo);

HRESULT WINAPI MpUpdateControl(
    _In_ MPHANDLE  hUpdateHandle,
    _In_ MPCONTROL UpdateControl);

HRESULT WINAPI MpUpdateStart(
    _In_     MPHANDLE         hMpHandle,
    _In_     DWORD            dwUpdateOptions,
    _In_opt_ PMPCALLBACK_INFO pCallbackInfo,
    _Out_    PMPHANDLE        phUpdateHandle);

#endif // !_MPCLIENT_
