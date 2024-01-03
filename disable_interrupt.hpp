#ifndef DISABLE_INTERRUPT_HPP
#define DISABLE_INTERRUPT_HPP
/*********************************************************************
*
*   HEADER:
*       header file for disable_interrupt
*
*   DESCRIPTION:
*       C++ RAII implementation for disabling interrupts
*
*   Copyright 2023 Nate Lenze
*
****************a*****************************************************/
/*--------------------------------------------------------------------
                              INCLUDES
--------------------------------------------------------------------*/
#include <cstdint>

/*--------------------------------------------------------------------
                          GLOBAL NAMESPACES
--------------------------------------------------------------------*/
namespace utl {
/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            TYPES/ENUMS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               CLASSES
--------------------------------------------------------------------*/
class disable_interrupts 
    {
    public:
        disable_interrupts();
        ~disable_interrupts();
    private:
        uint32_t p_int_status;
    };

} /* namespace utl */
#endif