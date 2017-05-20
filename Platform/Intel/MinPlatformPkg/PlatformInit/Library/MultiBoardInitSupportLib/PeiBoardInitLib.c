/** @file

Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials are licensed and made available under
the terms and conditions of the BSD License that accompanies this distribution.
The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <Library/BoardInitLib.h>
#include <Library/MultiBoardInitSupportLib.h>
#include <Library/PcdLib.h>
#include <Library/DebugLib.h>
#include <Library/PeiServicesLib.h>

EFI_STATUS
EFIAPI
BoardDetect (
  VOID
  )
{
  BOARD_DETECT_FUNC          *BoardDetectFunc;
  UINTN                      Index;
  EFI_STATUS                 Status;

  for (Index = 0; ; Index++) {
    Status = PeiServicesLocatePpi(
               &gBoardDetectGuid,
               Index,
               NULL,
               (VOID **)&BoardDetectFunc
               );
    if (EFI_ERROR(Status)) {
      break;
    }
    if (BoardDetectFunc->BoardDetect != NULL) {
      BoardDetectFunc->BoardDetect ();
    }
  }
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
BoardDebugInit (
  VOID
  )
{
  BOARD_PRE_MEM_INIT_FUNC    *BoardPreMemInit;
  EFI_STATUS                 Status;

  Status = PeiServicesLocatePpi(
             &gBoardPreMemInitGuid,
             0,
             NULL,
             (VOID **)&BoardPreMemInit
             );
  if (!EFI_ERROR(Status)) {
    if (BoardPreMemInit->BoardDebugInit != NULL) {
      return BoardPreMemInit->BoardDebugInit ();
    }
  }
  return EFI_SUCCESS;
}

EFI_BOOT_MODE
EFIAPI
BoardBootModeDetect (
  VOID
  )
{
  BOARD_PRE_MEM_INIT_FUNC    *BoardPreMemInit;
  EFI_STATUS                 Status;

  Status = PeiServicesLocatePpi(
             &gBoardPreMemInitGuid,
             0,
             NULL,
             (VOID **)&BoardPreMemInit
             );
  if (!EFI_ERROR(Status)) {
    if (BoardPreMemInit->BoardBootModeDetect != NULL) {
      return BoardPreMemInit->BoardBootModeDetect ();
    }
  }
  return BOOT_WITH_FULL_CONFIGURATION;
}

EFI_STATUS
EFIAPI
BoardInitBeforeMemoryInit (
  VOID
  )
{
  BOARD_PRE_MEM_INIT_FUNC    *BoardPreMemInit;
  EFI_STATUS                 Status;

  Status = PeiServicesLocatePpi(
             &gBoardPreMemInitGuid,
             0,
             NULL,
             (VOID **)&BoardPreMemInit
             );
  if (!EFI_ERROR(Status)) {
    if (BoardPreMemInit->BoardInitBeforeMemoryInit != NULL) {
      return BoardPreMemInit->BoardInitBeforeMemoryInit ();
    }
  }
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
BoardInitAfterMemoryInit (
  VOID
  )
{
  BOARD_PRE_MEM_INIT_FUNC    *BoardPreMemInit;
  EFI_STATUS                 Status;

  Status = PeiServicesLocatePpi(
             &gBoardPreMemInitGuid,
             0,
             NULL,
             (VOID **)&BoardPreMemInit
             );
  if (!EFI_ERROR(Status)) {
    if (BoardPreMemInit->BoardInitAfterMemoryInit != NULL) {
      return BoardPreMemInit->BoardInitAfterMemoryInit ();
    }
  }
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
BoardInitBeforeTempRamExit (
  VOID
  )
{
  BOARD_PRE_MEM_INIT_FUNC    *BoardPreMemInit;
  EFI_STATUS                 Status;

  Status = PeiServicesLocatePpi(
             &gBoardPreMemInitGuid,
             0,
             NULL,
             (VOID **)&BoardPreMemInit
             );
  if (!EFI_ERROR(Status)) {
    if (BoardPreMemInit->BoardInitBeforeTempRamExit != NULL) {
      return BoardPreMemInit->BoardInitBeforeTempRamExit ();
    }
  }
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
BoardInitAfterTempRamExit (
  VOID
  )
{
  BOARD_PRE_MEM_INIT_FUNC    *BoardPreMemInit;
  EFI_STATUS                 Status;

  Status = PeiServicesLocatePpi(
             &gBoardPreMemInitGuid,
             0,
             NULL,
             (VOID **)&BoardPreMemInit
             );
  if (!EFI_ERROR(Status)) {
    if (BoardPreMemInit->BoardInitAfterTempRamExit != NULL) {
      return BoardPreMemInit->BoardInitAfterTempRamExit ();
    }
  }
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
BoardInitBeforeSiliconInit (
  VOID
  )
{
  BOARD_POST_MEM_INIT_FUNC   *BoardPostMemInit;
  EFI_STATUS                 Status;

  Status = PeiServicesLocatePpi(
             &gBoardPostMemInitGuid,
             0,
             NULL,
             (VOID **)&BoardPostMemInit
             );
  if (!EFI_ERROR(Status)) {
    if (BoardPostMemInit->BoardInitBeforeSiliconInit != NULL) {
      return BoardPostMemInit->BoardInitBeforeSiliconInit ();
    }
  }
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
BoardInitAfterSiliconInit (
  VOID
  )
{
  BOARD_POST_MEM_INIT_FUNC   *BoardPostMemInit;
  EFI_STATUS                 Status;

  Status = PeiServicesLocatePpi(
             &gBoardPostMemInitGuid,
             0,
             NULL,
             (VOID **)&BoardPostMemInit
             );
  if (!EFI_ERROR(Status)) {
    if (BoardPostMemInit->BoardInitAfterSiliconInit != NULL) {
      return BoardPostMemInit->BoardInitAfterSiliconInit ();
    }
  }
  return EFI_SUCCESS;
}
