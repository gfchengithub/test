/* ###################################################################
**     Filename    : main.c
**     Processor   : S32K144
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "pin_mux.h"
#include "dmaController1.h"
#include "lpuart1.h"
#include "lpuart0.h"
#include "canCom1.h"
#include "adConv1.h"
#include "lpit1.h"
#include "trgmux1.h"
#include "pwrMan1.h"
#include "flexTimer1.h"
#include "flexTimer2.h"
#include "flash1.h"
#include "clockMan1.h"
#include "crc1.h"
#include "osif1.h"
#include "watchdog.h"
#include "canCom2.h"
#include "rtcTimer1.h"
#include "lpi2c1.h"
#include "adConv2.h"

#include "config.h"


dev1:
1 1213
2 4516

dev1-1
1 123dev1-1
2 456
3 789

void DefaultISR(void)
{
//	uint32_t nvic_reg;
//
//	nvic_reg = S32_NVIC->IABR[1];
}

void HardFault_Handler(void)
{
	for(;;);
}

void module_init(sys_run_source_t s_sys_source)
{
	    /*init*/
		 TargetInit(s_sys_source);

		 /* Initialize Power Manager */
		 POWER_SYS_Init(&powerConfigsArr, 7, &powerStaticCallbacksConfigsArr, 0);

		 ship_init();

}


int main(void)
 {
	int exit_code=0;

  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
#ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
#endif
  /*** End of Processor Expert internal initialization.                    ***/

    module_init(SYS_RESET_FLAG);
    Modem_SetRestarFlg(1);
    Judg_mcu_reset_source_status();

   while(1)
   	{
		Uart1_Process();
		Can0_Process();
		dealwith_time_proc();
		ship_proc();
   	}

  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the Freescale S32K series of microcontrollers.
**
** ###################################################################
*/
