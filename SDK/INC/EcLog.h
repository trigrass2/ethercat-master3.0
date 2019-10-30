/*-----------------------------------------------------------------------------
* EcLog.h
* Copyright                acontis technologies GmbH, Weingarten, Germany
* Response                 Holger Oelhaf
* Description              Logging interface
*---------------------------------------------------------------------------*/

#ifndef INC_ECLOG
#define INC_ECLOG

#if (!defined EC_PACKED)
#error EcOs.h / LinkOsLayer.h include missing!
#endif

#define EC_LOG_LEVEL_SILENT       0
#define EC_LOG_LEVEL_CRITICAL     1
#define EC_LOG_LEVEL_ERROR        2
#define EC_LOG_LEVEL_WARNING      3
#define EC_LOG_LEVEL_INFO         4
#define EC_LOG_LEVEL_VERBOSE      5
#define EC_LOG_LEVEL_VERBOSE_ACYC EC_LOG_LEVEL_VERBOSE
#define EC_LOG_LEVEL_VERBOSE_CYC  6
#define EC_LOG_LEVEL_UNDEFINED    ((EC_T_DWORD)-1)

#include EC_PACKED_INCLUDESTART(8)
typedef struct _EC_T_LOG_PARMS
{
    EC_T_DWORD                  dwLogLevel;           /*< [in] log level. See EC_LOG_LEVEL_... */
    EC_PF_LOGMSGHK              pfLogMsg;             /*< [in] optional call back function to log msg from the EC-Master. set to EC_NULL if not used.  */
    struct _EC_T_LOG_CONTEXT*   pLogContext;          /*< [in] log context */
} EC_PACKED(8) EC_T_LOG_PARMS;
#include EC_PACKED_INCLUDESTOP

/* default definition for pEcLogParms */
#if (defined G_pEcLogParms)
#ifndef pEcLogParms
#define pEcLogParms (G_pEcLogParms)
#endif
#ifndef G_pEcLogContext
#define G_pEcLogContext (G_pEcLogParms->pLogContext)
#endif
#endif /* G_pEcLogParms */

/* default definitions for dwLogLevel, pfLogMsg, pLogContext */
#if (defined pEcLogParms)
#ifndef dwEcLogLevel
#define dwEcLogLevel    (pEcLogParms->dwLogLevel)
#endif
#ifndef pLogMsgCallback
#define pLogMsgCallback (pEcLogParms->pfLogMsg)
#endif
#ifndef pEcLogContext
#define pEcLogContext   (pEcLogParms->pLogContext)
#endif
#endif /* pEcLogParms */

#ifndef EcLogMsg
#if (defined INCLUDE_LOG_MESSAGES)
#define EcLogMsg(dwLogSeverity, pLogMsgCallbackParms) ((dwLogSeverity <= dwEcLogLevel)?(pLogMsgCallback pLogMsgCallbackParms):0)
#else
#define EcLogMsg(dwLogSeverity, pLogMsgCallbackParms)
#endif
#endif

/* global GetLogParms() for static functions (context not available) */
#if (!defined GetLogParms) && (defined G_pEcLogParms)
static EC_INLINESTART struct _EC_T_LOG_PARMS* GetLogParms()
{
    return G_pEcLogParms;
} EC_INLINESTOP
#endif /* global GetLogParms() */

#endif
