/*<NeoTechHead>
 *************************************************************************
 *                              NeoTech
 *************************************************************************
 *
 * /   / /////  ///  ///// /////  ///  /   /
 * //  / /     /   /   /   /     /   / /   /
 * / / / ///   /   /   /   ///   /     /////
 * /  // /     /   /   /   /     /   / /   /
 * /   / /////  ///    /   /////  ///  /   /
 *
 *************************************************************************
 * Administrative Information
 *************************************************************************
 *
 * $Filename__:Std_Types.h$
 *
 * $Author____:Nguyen Ba Vu Thach$
 *
 * $Function__:Brief description of this module.$
 *
 *************************************************************************
 * $Domain____:NeoTech$
 * $User______: Nguyen Ba Vu Thach$
 * $Date______: 23.11.2026$
 * $Class_____:CUCEL$
 * $Name______: Std_Types$
 * $Variant___:1.0.0$
 * $Revision__:1$
 * $Type______: H$
 * $State_____:PROTOTYPE$
 *
 *************************************************************************
 * List Of Changes
 *
 * $History
 *
 * 1.0.0; 1     23.11.2026 Nguyen Ba Vu Thach
 *   Initial version.
 *
 * $
 *
 *************************************************************************
</NeoTechHead>*/

/* TRACE[SWS_Std_00004]: It is not allowed to add any project or supplier specific extension to this file.
   Any extension invalidates the AUTOSAR conformity.*/

/* TRACE[SWS_Std_00014]: protected against multiple inclusion. */
#ifndef STD_TYPES_H
#define STD_TYPES_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */

/** @brief   TRACE[SWS_Std_00016]
 *  @details Include file structure for standard types.
 */
#include "Platform_Types.h"

/*
 **********************************************************************************************************************
 * Defines / Macros
 **********************************************************************************************************************
 */

/** @brief   TRACE[SWS_Std_00006]
 *  @details Because E_OK is already defined within OSEK, the symbol E_OK has to be
 *           defined in the following way (approved within implementation):
 */
#ifndef STATUSTYPEDEFINED
    #define STATUSTYPEDEFINED
    #define E_OK 0x00u     /* No error occurs            */
    typedef unsigned char StatusType; /* OSEK compliance */
#endif

#define E_NOT_OK   0x01u   /* An error occurs            */

/** @brief   TRACE[SWS_Std_00007]
 *  @details The symbols STD_HIGH and STD_LOW shall be defined as follows:
 */
#define STD_HIGH 0x01u   /* Physical state 5V or 3.3V */
#define STD_LOW  0x00u   /* Physical state 0V */

/** @brief   TRACE[SWS_Std_00013]
 *  @details The symbols STD_ACTIVE and STD_IDLE shall be defined as follows:
 */
#define STD_ACTIVE 0x01u    /* Logical state active */ 
#define STD_IDLE   0x00u   /* Logical state idle */


/** @brief   TRACE[SWS_Std_00010]
 *  @details The symbols STD_ON and STD_OFF shall be defined as follows:
 */
#define STD_ON  0x01u   /* On state */
#define STD_OFF 0x00u   /* Off state */

/** @brief   TRACE[SWS_Std_00031]
 *  @details Definition of NULL pointer
 */
#ifndef NULL_PTR
  #ifdef SIL_BUILD_ENABLED
    #define NULL_PTR        ((void*)0)
  #else
    #ifdef __cplusplus
      #define NULL_PTR        (0)
    #else
      #define NULL_PTR        ((void*)0)
    #endif
  #endif
#endif

/*
 **********************************************************************************************************************
 * Types
 **********************************************************************************************************************
 */

 /** @brief   TRACE[SWS_Std_00005]
 *  @details This type can be used as standard API return type which is shared between the RTE 
 *           and the BSW modules.  It shall be defined as follows:
 */
typedef uint8 Std_ReturnType;

/** @brief   TRACE[SWS_Std_00015]
 *  @details This type shall be used to request the version of a BSW module using the 
 *           <Module name>_GetVersionInfo() function. 
 *           The type shall be defined as follows:
 */
typedef struct
{
    uint16  vendorID;
    uint16  moduleID;
    uint8  sw_major_version;
    uint8  sw_minor_version;
    uint8  sw_patch_version;
} Std_VersionInfoType;

/** @brief   TRACE[SWS_Std_00022]
 *  @details The values are specified for each transformer class in ASWS_TransformerGeneral.
 */
typedef uint8 Std_TransformerErrorCode;

/** @brief   TRACE[SWS_Std_00024]
 *  @details The Std_TransformerClass represents the transformer class in which the error occurred.
 */
typedef enum
{
    STD_TRANSFORMER_UNSPECIFIED = 0x00, /* Transformer of a unspecified transformer class.*/
    STD_TRANSFORMER_SERIALIZER  = 0x01, /* Transformer of a serializer class.*/
    STD_TRANSFORMER_SAFETY      = 0x02, /* Transformer of a safety class.*/
    STD_TRANSFORMER_SECURITY    = 0x03, /* Transformer of a security class.*/
    STD_TRANSFORMER_CUSTOM      = 0xFF  /* Transformer of a custom class not standardized by AUTOSAR.*/
} Std_TransformerClass;


/** @brief   TRACE[SWS_Std_00021]
 *  @details Std_TransformerError represents a transformer error in the context of a certain transformer chain.
 *           The structure contains the error code and the transformer class to which the error belongs.
 */
typedef struct
{
    Std_TransformerErrorCode errorCode;
    Std_TransformerClass transformerClass;
} Std_TransformerError;

/** @brief   TRACE[SWS_Std_91001]
 *  @details This type is used to encode the different type of messages. Currently this encoding is limited to the distinction between requests and responses in C/S communication.
 */
typedef enum
{
    STD_MESSAGETYPE_REQUEST  =  0x00, /* Message type for a request message.  */
    STD_MESSAGETYPE_RESPONSE =  0x01  /* Message type for a response message. */
} Std_MessageTypeType;

/** @brief   TRACE[SWS_Std_91002]
 *  @details This type is used to encode different types of results for response messages. Currently this encoding is limited to the distinction between OK and ERROR responses.
 */
typedef enum
{
    STD_MESSAGERESULT_OK    =  0x00, /* Message result for an OK response.   */
    STD_MESSAGERESULT_ERROR =  0x01  /* Message result for an ERROR response */
} Std_MessageResultType;

/**
 * @brief TRACE[SWS_Std_91003]
 * @details Type for the function pointer to extract the relevant protocol header fields of the message and 
 *          the type of the message result for a transformer.
 */
typedef Std_ReturnType (*Std_ExtractProtocolHeaderFieldsType) ( 
    const uint8* buffer, 
    uint32 bufferLength, 
    Std_MessageTypeType* messageType, 
    Std_MessageResultType* messageResult
);

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */



/*
 **********************************************************************************************************************
 * Function prototypes
 **********************************************************************************************************************
 */



#endif /* STD_TYPES_H */
