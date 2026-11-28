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
 * $Filename__:Platform_Types.h$
 *
 * $Author____:Nguyen Ba Vu Thach$
 *
 * $Function__:Based on AUTOSAR_SWS_PlatformTypes.pdf; AUTOSAR_CP_RS_BSWGeneral.pdf; AR26-11.$
 *
 *************************************************************************
 * $Domain____:NeoTech$
 * $User______:Nguyen Ba Vu Thach$
 * $Date______:23.11.2026$
 * $Class_____:CUCEL$
 * $Name______:Platform_Types$
 * $Variant___:1.0.0$
 * $Revision__:1$
 * $Type______:H$
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

/* TRACE[SWS_Platform_00002]: It is not allowed to add any project or supplier specific extension to this file.
   Any extension invalidates the AUTOSAR conformity.*/

/* TRACE[SWS_Std_00014]: protected against multiple inclusion. */
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */

/*
 **********************************************************************************************************************
 * Defines / Macros
 **********************************************************************************************************************
 */

/** @brief   TRACE[SWS_Platform_00044], TRACE[SWS_Platform_00045] & TRACE[SWS_Platform_00064]
 *  @details TRACE[SWS_Platform_00044]: For each platform the register width of the CPU
 *           used shall be indicated by defining CPU_TYPE.
 *  @details TRACE[SWS_Platform_00045]: According to the register width of the CPU used, CPU_TYPE shall
 *           be assigned to one of the symbols CPU_TYPE_8, CPU_TYPE_16, CPU_TYPE_32 or CPU_TYPE_64.
 */

#define CPU_TYPE_8 8U
#define CPU_TYPE_16 16U
#define CPU_TYPE_32 32U
#define CPU_TYPE_64 64U

#define CPU_TYPE CPU_TYPE_32

/** @brief   TRACE[Rule BSW_VersionInfo_002], TRACE[SRS_BSW_00374]
 *  @details Module vendor identifier.
 */
#define PLATFORM_VENDOR_ID 11u

/** @brief   TRACE[Rule BSW_VersionInfo_003], TRACE[SRS_BSW_00374]
 *  @details Module identifier.
 */
#define PLATFORM_MODULE_ID 0x00C7u

/** @brief   TRACE[Rule BSW_VersionInfo_004], TRACE[SRS_BSW_00374]
 *  @details Software version number and AUTOSAR specification version number.
 */
#define PLATFORM_SW_MAJOR_VERSION 0x05u
#define PLATFORM_SW_MINOR_VERSION 0x00u
#define PLATFORM_SW_PATCH_VERSION 0x00u
#define PLATFORM_AR_RELEASE_MAJOR_VERSION 0x04u
#define PLATFORM_AR_RELEASE_MINOR_VERSION 0x05u
#define PLATFORM_AR_RELEASE_REVISION_VERSION 0x00u

/** @brief   CPU byte and bit order constants.
 *  @details LSB_FIRST/HIGH_BYTE_FIRST indicate little-endian bit/byte ordering.
 */
#define MSB_FIRST 0
#define LSB_FIRST 1

#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST 1

/** @brief   TRACE[SWS_Platform_00038], TRACE[SWS_Platform_00043],
 *           TRACE[SWS_Platform_00048] & TRACE[SWS_Platform_00049]
 *  @details Defines CPU_BIT_ORDER for the target platform.
 */
#define CPU_BIT_ORDER LSB_FIRST

/** @brief   TRACE[SWS_Platform_00039], TRACE[SWS_Platform_00046],
 *           TRACE[SWS_Platform_00050] & TRACE[SWS_Platform_00051]
 *  @details Defines CPU_BYTE_ORDER for the target platform.
 */
#define CPU_BYTE_ORDER LOW_BYTE_FIRST

/** @brief   TRACE[SWS_Platform_00054], TRACE[SWS_Platform_00055]
 *           & TRACE[SWS_Platform_00056]
 *  @details TRUE and FALSE shall only be used in conjunction with the boolean type.
 *           In case of built-in compiler support, redefinitions shall be avoided
 *           using a conditional check.
 */
#ifndef TRUE
#define TRUE (1 != 0)
#endif

#ifndef FALSE
#define FALSE (0 != 0)
#endif

/*
 **********************************************************************************************************************
 * Types
 **********************************************************************************************************************
 */

/** @brief   Standard integer data types.
 */

/** @brief   TRACE[SWS_Platform_00016]
 *  @details This standard AUTOSAR type shall be 8-bit signed.
 *           Range: -128 .. +127 (0x80 .. 0x7F).
 */
typedef signed char sint8;

/** @brief   TRACE[SWS_Platform_00013]
 *  @details This standard AUTOSAR type shall be 8-bit unsigned.
 *           Range: 0 .. 255 (0x00 .. 0xFF).
 */
typedef unsigned char uint8;

/** @brief   TRACE[SWS_Platform_00017]
 *  @details This standard AUTOSAR type shall be 16-bit signed.
 *           Range: -32768 .. +32767 (0x8000 .. 0x7FFF).
 */
typedef signed short sint16;

/** @brief   TRACE[SWS_Platform_00014]
 *  @details This standard AUTOSAR type shall be 16-bit unsigned.
 *           Range: 0 .. 65535 (0x0000 .. 0xFFFF).
 */
typedef unsigned short uint16;

/** @brief   TRACE[SWS_Platform_00018]
 *  @details This standard AUTOSAR type shall be 32-bit signed.
 *           Range: -2147483648 .. +2147483647
 *           (0x80000000 .. 0x7FFFFFFF).
 */
typedef signed long sint32;

/** @brief   TRACE[SWS_Platform_00067]
 *  @details This standard AUTOSAR type shall be 64-bit signed.
 *           Range: -9223372036854775808 .. +9223372036854775807
 *           (0x8000000000000000 .. 0x7FFFFFFFFFFFFFFF).
 */
typedef signed long long sint64;

/** @brief   TRACE[SWS_Platform_00015]
 *  @details This standard AUTOSAR type shall be 32-bit unsigned.
 *           Range: 0 .. 4294967295 (0x00000000 .. 0xFFFFFFFF).
 */
typedef unsigned long uint32;

/** @brief   TRACE[SWS_Platform_00066]
 *  @details This standard AUTOSAR type shall be 64-bit unsigned.
 *           Range: 0 .. 18446744073709551615
 *           (0x0000000000000000 .. 0xFFFFFFFFFFFFFFFF).
 */
typedef unsigned long long uint64;

/** @brief   Standard float data types.
 */

/** @brief   TRACE[SWS_Platform_00041]
 *  @details This standard AUTOSAR type shall follow the 32-bit binary interchange
 *           format according to IEEE 754-2008, as specified in chapter 3.6,
 *           table 3.5, column "binary32".
 */
typedef float float32;

/** @brief   TRACE[SWS_Platform_00042]
 *  @details This standard AUTOSAR type shall follow the 64-bit binary interchange
 *           format according to IEEE 754-2008, as specified in chapter 3.6,
 *           table 3.5, column "binary64".
 */
typedef double float64;

/** @brief   Boolean data type.
 *  @details TRACE[SWS_Platform_00026]: This standard AUTOSAR type shall only be
 *           used together with the definitions TRUE and FALSE.
 *           MR12 DIR 1.1 VIOLATION: _Bool is mapped to the AUTOSAR boolean type
 *           to prevent direct use of _Bool.
 */

typedef _Bool boolean;


/** @brief   Optimized integer data types.
 */

/** @brief   TRACE[SWS_Platform_00023]
 *  @details This optimized AUTOSAR type shall be at least 8-bit signed.
 *           At least -128 .. +127 (0x80 .. 0x7F).
 */
typedef signed long sint8_least;

/** @brief   TRACE[SWS_Platform_00020]
 *  @details This optimized AUTOSAR type shall be at least 8-bit unsigned.
 *           At least 0 .. 255.
 */
typedef unsigned long uint8_least;

/** @brief   TRACE[SWS_Platform_00024]
 *  @details This optimized AUTOSAR type shall be at least 16-bit signed.
 *           At least -32768 .. +32767 (0x8000 .. 0x7FFF).
 */
typedef signed long sint16_least;

/** @brief   TRACE[SWS_Platform_00021]
 *  @details This optimized AUTOSAR type shall be at least 16-bit unsigned.
 *           At least 0 .. 65535 (0x0000 .. 0xFFFF).
 */
typedef unsigned long uint16_least;

/** @brief   TRACE[SWS_Platform_00025]
 *  @details This optimized AUTOSAR type shall be at least 32-bit signed.
 *           At least -2147483648 .. +2147483647
 *           (0x80000000 .. 0x7FFFFFFF).
 */
typedef signed long sint32_least;

/** @brief   TRACE[SWS_Platform_00022]
 *  @details This optimized AUTOSAR type shall be at least 32-bit unsigned.
 *           At least 0 .. 4294967295 (0x00000000 .. 0xFFFFFFFF).
 */
typedef unsigned long uint32_least;

/** @brief   TRACE[SWS_Platform_91001]
 *  @details This standard AUTOSAR type shall be a void pointer.
 *           It shall be used for buffers that contain data returned to the caller.
 */
typedef void *VoidPtr;

/** @brief   TRACE[SWS_Platform_91002]
 *  @details This standard AUTOSAR type shall be a void pointer to const.
 *           It shall be used for buffers that are passed to the callee.
 */
typedef const void *ConstVoidPtr;

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

#endif /* PLATFORM_TYPES_H */
