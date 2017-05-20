/** @file
  This file contains a structure definition for the ACPI 2.0 Multiple APIC
  Description Table (MADT).  Any changes to the MADT table require updating the
  respective structure count in Madt.h and then adding the structure to the
  MADT defined in this file.

Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials are licensed and made available under
the terms and conditions of the BSD License that accompanies this distribution.
The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

//
// Statements that include other files
//

#include "Madt.h"

//
// Multiple APIC Description Table
//

EFI_ACPI_2_0_MULTIPLE_APIC_DESCRIPTION_TABLE Madt = {
  {
    {
      EFI_ACPI_2_0_MULTIPLE_SAPIC_DESCRIPTION_TABLE_SIGNATURE,
      sizeof (EFI_ACPI_2_0_MULTIPLE_APIC_DESCRIPTION_TABLE),
      EFI_ACPI_5_1_MULTIPLE_APIC_DESCRIPTION_TABLE_REVISION,

      //
      // Checksum will be updated at runtime
      //
      0x00,

      //
      // It is expected that these values will be programmed at runtime
      //
      { ' ', ' ', ' ', ' ', ' ', ' ' },

      0,
      EFI_ACPI_OEM_MADT_REVISION,
      0,
      0
    },

    //
    // MADT specific fields
    //
    FixedPcdGet64 (PcdApicLocalAddress),
    EFI_ACPI_2_0_MULTIPLE_APIC_FLAGS
  },
  
  //
  // Sample Processor Local APIC Structure
  //
  //EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                          // Type
  //sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),       // Length
  //0x00                                                        // Processor ID
  //0x00                                                        // Local APIC ID
  //0x00000000,                                                 // Flags - Disabled (until initialized by platform driver)
  {
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x01,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x02,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x03,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x04,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x05,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x06,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x07,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x08,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x09,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x0A,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x0B,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x0C,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x0D,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x0E,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x0F,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    },
    {
      EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC,                        // Type
      sizeof (EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE),     // Length
      0x10,                                                     // Processor ID
      0xFF,                                                     // Local APIC ID
      0x00000000                                                // Flags - Disabled (until initialized by platform driver)
    }
  },

  //
  // Sample IO APIC Structure
  //
  //EFI_ACPI_2_0_IO_APIC,                                      // Type
  //sizeof (EFI_ACPI_2_0_IO_APIC_STRUCTURE),                   // Length
  //0x00,                                                      // IO APIC ID
  //EFI_ACPI_RESERVED_BYTE,                                    // Reserved
  //0x00000000,                                                // IO APIC Address (physical)
  //0x00000000,                                                // Global System Interrupt Base
  {
    {
      //
      // I/O SAPIC (ICH)
      // 
      EFI_ACPI_2_0_IO_APIC,                                    // Type
      sizeof (EFI_ACPI_2_0_IO_APIC_STRUCTURE),                 // Length
      FixedPcdGet8 (PcdApicIoIdPch),                           // IO APIC ID
      EFI_ACPI_RESERVED_BYTE,                                  // Reserved
      FixedPcdGet64 (PcdApicIoAddress),                        // IO APIC Address (physical)
      0x18 * 0                                                 // Global System Interrupt Base
    }
  },
  //
  // Sample Interrupt Source Override Structure
  //
  //EFI_ACPI_2_0_INTERRUPT_SOURCE_OVERRIDE,                    // Type
  //sizeof (EFI_ACPI_2_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE), // Length
  //0x00,                                                      // Bus
  //0x00,                                                      // Source
  //0x00000000,                                                // Global System Interrupt
  //0x0000,                                                    // Flags
  {
    {
      //
      // IRQ0=>IRQ2 Interrupt Source Override Structure
      //
      EFI_ACPI_2_0_INTERRUPT_SOURCE_OVERRIDE,                   // Type
      sizeof (EFI_ACPI_2_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE),// Length
      0x00,                                                     // Bus - ISA
      0x00,                                                     // Source - IRQ0
      0x00000002,                                               // Global System Interrupt - IRQ2
      0x0000                                                    // Flags - Conforms to specifications of the bus
    },
    {
      //
      // ISO (SCI Active High) Interrupt Source Override Structure
      //
      EFI_ACPI_2_0_INTERRUPT_SOURCE_OVERRIDE,                   // Type
      sizeof (EFI_ACPI_2_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE),// Length
      0x00,                                                     // Bus - ISA
      0x09,                                                     // Source - IRQ9
      0x00000009,                                               // Global System Interrupt - IRQ9
      0x000D                                                    // Flags - Level-tiggered, Active High
    }
  },
  //
  // Sample Non-Maskable Interrupt Source Structure
  //
  //EFI_ACPI_2_0_NON_MASKABLE_INTERRUPT_SOURCE,                     // Type
  //sizeof (EFI_ACPI_2_0_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE),  // Length
  //0x0000,                                                         // Flags
  //0x00000000,                                                     // Global System Interrupt

  //
  // Sample Local APIC NMI Structure
  //
  //EFI_ACPI_2_0_LOCAL_APIC_NMI,                                // Type
  //sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),             // Length
  //0x00,                                                       // ACPI Processor ID
  //0x0000,                                                     // Flags
  //0x00,                                                       // Local APIC LINT#

  {
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x01,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x02,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x03,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x04,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x05,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x06,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x07,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x08,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x09,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x0A,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x0B,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x0C,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x0D,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x0E,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x0F,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    },
    {
      EFI_ACPI_2_0_LOCAL_APIC_NMI,                              // Type
      sizeof (EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE),           // Length
      0x10,                                                     // ACPI Processor ID
      0x0005,                                                   // Flags - Edge-tiggered, Active High
      0x01                                                      // Local APIC LINT#
    }
  }

  //
  // Sample Local APIC Address Override Structure
  //
  //EFI_ACPI_2_0_LOCAL_APIC_ADDRESS_OVERRIDE,                     // Type
  //sizeof (EFI_ACPI_2_0_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE),  // Length
  //EFI_ACPI_RESERVED_WORD,                                       // Reserved
  //0x0000000000000000,                                           // Local APIC Address

  //
  // Sample Platform Interrupt Sources Structure
  //
  //EFI_ACPI_2_0_PLATFORM_INTERRUPT_SOURCES,                      // Type
  //sizeof (EFI_ACPI_2_0_PLATFORM_INTERRUPT_SOURCES_STRUCTURE),   // Length
  //0x0000,                                                       // Flags
  //0x00,                                                         // Interrupt Type
  //0x00,                                                         // Processor ID
  //0x00,                                                         // Processor EID
  //0x00,                                                         // IO SAPIC Vector
  //0x00000000,                                                   // Global System Interrupt
  //EFI_ACPI_RESERVED_DWORD,                                      // Reserved

};
