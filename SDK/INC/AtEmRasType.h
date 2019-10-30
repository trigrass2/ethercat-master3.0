/*-----------------------------------------------------------------------------
 * AtEmRasType.h            file
 * Copyright                acontis technologies GmbH, Weingarten, Germany
 * Response                 Willig, Andreas
 * Description              description of file
 * Date                     2007/5/4::13:58
 *---------------------------------------------------------------------------*/

#ifndef INC_ATEMRASTYPE
#define INC_ATEMRASTYPE 1

/*-INCLUDES------------------------------------------------------------------*/
#include <EcOs.h>

/*-COMPILER SETTINGS---------------------------------------------------------*/
#ifdef __cplusplus
extern "C"
{
#endif

/*-DEFINES-------------------------------------------------------------------*/
#undef INCLUDE_RAS_TRACESUPPORT

#if (defined EC_SOCKET_IP_SUPPORTED)
#define ATEMRAS_DEFAULT_PORT       ((EC_T_WORD)6000)
#elif (defined EC_SOCKET_MSGQUEUE_RTOSSHM_SUPPORTED)
#define ATEMRAS_DEFAULT_PORT       ((EC_T_WORD)2)
#elif (defined EC_SOCKET_SHM_SUPPORTED)
#define ATEMRAS_DEFAULT_PORT       ((EC_T_WORD)1)
#elif (defined EC_SOCKET_MSGQUEUE_WIN32_SUPPORTED)
#define ATEMRAS_DEFAULT_PORT       ((EC_T_WORD)0)
#elif (defined EC_SOCKET_RTOSLIB_SUPPORTED)
#define ATEMRAS_DEFAULT_PORT       ((EC_T_WORD)3)
#else
#error Unknown socket implementation
#endif /* EC_SOCKET_..._SUPPORTED */

/*-MACROS--------------------------------------------------------------------*/
#ifndef EC_TRACE_ADDMEM
    #define EC_TRACE_ADDMEM(Mask, szLoc, dwAddress, nSize)
    #define EC_TRACE_SUBMEM(Mask, szLoc, dwAddress, nSize)
#endif

/*-TYPEDEFS------------------------------------------------------------------*/
typedef union _EC_T_IPADDR ATEMRAS_T_IPADDR;

/*-COMPILER SETTINGS---------------------------------------------------------*/
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* INC_ATEMRASTYPE */ 

/*-END OF SOURCE FILE--------------------------------------------------------*/
