/** @file

Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials are licensed and made available under
the terms and conditions of the BSD License that accompanies this distribution.
The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <Uefi.h>
#include <PiDxe.h>
#include <Library/TestPointCheckLib.h>
#include <Library/TestPointLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/HstiLib.h>
#include <IndustryStandard/Hsti.h>

/**
  Dump HSTI info

  @param[in] HstiData     - Pointer to HSTI data
**/
VOID
DumpHsti (
  IN VOID                     *HstiData
  )
{
  ADAPTER_INFO_PLATFORM_SECURITY *Hsti;
  UINT8                          *SecurityFeatures;
  CHAR16                         *ErrorString;
  UINTN                          Index;
  CHAR16                         ErrorChar;

  Hsti = HstiData;
  DEBUG ((DEBUG_INFO, "HSTI\n"));
  DEBUG ((DEBUG_INFO, "  Version                     - 0x%08x\n", Hsti->Version));
  DEBUG ((DEBUG_INFO, "  Role                        - 0x%08x\n", Hsti->Role));
  DEBUG ((DEBUG_INFO, "  ImplementationID            - %S\n", Hsti->ImplementationID));
  DEBUG ((DEBUG_INFO, "  SecurityFeaturesSize        - 0x%08x\n", Hsti->SecurityFeaturesSize));

  SecurityFeatures = (UINT8 *) (Hsti + 1);
  DEBUG ((DEBUG_INFO, "  SecurityFeaturesRequired    - "));
  for (Index = 0; Index < Hsti->SecurityFeaturesSize; Index++) {
    DEBUG ((DEBUG_INFO, "%02x ", SecurityFeatures[Index]));
  }
  DEBUG ((DEBUG_INFO, "\n"));

  SecurityFeatures = (UINT8 *) (SecurityFeatures + Hsti->SecurityFeaturesSize);
  DEBUG ((DEBUG_INFO, "  SecurityFeaturesImplemented - "));
  for (Index = 0; Index < Hsti->SecurityFeaturesSize; Index++) {
    DEBUG ((DEBUG_INFO, "%02x ", SecurityFeatures[Index]));
  }
  DEBUG ((DEBUG_INFO, "\n"));

  SecurityFeatures = (UINT8 *) (SecurityFeatures + Hsti->SecurityFeaturesSize);
  DEBUG ((DEBUG_INFO, "  SecurityFeaturesVerified    - "));
  for (Index = 0; Index < Hsti->SecurityFeaturesSize; Index++) {
    DEBUG ((DEBUG_INFO, "%02x ", SecurityFeatures[Index]));
  }
  DEBUG ((DEBUG_INFO, "\n"));

  ErrorString = (CHAR16 *) (SecurityFeatures + Hsti->SecurityFeaturesSize);
  DEBUG ((DEBUG_INFO, "  ErrorString                 - \""));
  CopyMem (&ErrorChar, ErrorString, sizeof (ErrorChar));
  for (; ErrorChar != 0;) {
    DEBUG ((DEBUG_INFO, "%c", ErrorChar));
    ErrorString++;
    CopyMem (&ErrorChar, ErrorString, sizeof (ErrorChar));
  }
  DEBUG ((DEBUG_INFO, "\"\n"));
}

UINT32                  mRole[] = {
  PLATFORM_SECURITY_ROLE_PLATFORM_REFERENCE,
  PLATFORM_SECURITY_ROLE_PLATFORM_IBV,
  PLATFORM_SECURITY_ROLE_IMPLEMENTOR_OEM,
  PLATFORM_SECURITY_ROLE_IMPLEMENTOR_ODM,
};

EFI_STATUS
TestPointDumpHsti (
  VOID
  )
{
  VOID        *Hsti;
  UINTN       HstiSize;
  EFI_STATUS  Status;
  UINTN       Index;
  BOOLEAN     Result;
  
  Result = TRUE;
  DEBUG ((DEBUG_INFO, "==== TestPointDumpHsti - Enter\n"));
  for (Index = 0; Index < sizeof(mRole)/sizeof(mRole[0]); Index++) {
    Status = HstiLibGetTable (mRole[Index], NULL, &Hsti, &HstiSize);
    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "HSTI (Role - 0x%08x) not found!\n", mRole[Index]));
      if (mRole[Index] <= PLATFORM_SECURITY_ROLE_PLATFORM_IBV) {
        Result = FALSE;
      }
      continue;
    }
    DumpHsti (Hsti);
    FreePool (Hsti);
  }
  DEBUG ((DEBUG_INFO, "==== TestPointDumpHsti - Exit\n"));

  if (!Result) {
    TestPointLibAppendErrorString (
      PLATFORM_TEST_POINT_ROLE_PLATFORM_IBV,
      NULL,
      TEST_POINT_BYTE2_READY_TO_BOOT_ERROR_CODE_8 TEST_POINT_READY_TO_BOOT TEST_POINT_BYTE2_READY_TO_BOOT_ERROR_STRING_8
      );
    return EFI_NOT_FOUND;
  }
  return EFI_SUCCESS;
}
