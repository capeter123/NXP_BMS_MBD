/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: rappid_main.c
 *
 * Code generated for Simulink model 'can_simple_block_bu1114'.
 *
 * Model version                  : 1.1239
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Jan 02 17:26:53 2018
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

/* Model's headers */
#include "can_simple_block_bu1114.h"
#include "target.h"
#include "sys_init.h"
#include "adc_init.h"
#include "adc_trigger_init.h"
#include<adc0_config.h>

extern const vuint32_t ISRVectorTable[];
void SYSTEM_INIT_TASK(void)
{
  /* Initialize model */
  can_simple_block_bu1114_initialize();
}

void SYSTEM_TASK(void)
{
  boolean_T eventFlags[2];             /* Model has 2 rates */

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.  The generated code includes function
   * writeCodeInfoFcn() which sets the rates
   * that need to run this time step.  The return values are 1 and 0
   * for true and false, respectively.
   */
  can_simple_block_bu1114_SetEventsForThisBaseStep(eventFlags);

  /* Set model inputs associated with base rate here */
  can_simple_block_bu1114_step(0);

  /* Get model outputs here */
  if (eventFlags[1]) {
    /* Set model inputs associated with subrates here */
    can_simple_block_bu1114_step(1);

    /* Get model outputs here */
  }
}

void pit_init_fnc(void)
{
  //PIT.PITMCR.R = 0x00000001;

  /* ----------------------------------------------------------- */

  /*               Configure Load Value Registers                */

  /* ----------------------------------------------------------- */

  //    PIT.CH[1].LDVAL.R  =  0x016E35FF;    /* The model's base sample time is 0.2 seconds. */

  /* ----------------------------------------------------------- */

  /*                     Enable Interrupts                       */

  /* ----------------------------------------------------------- */

  //    PIT.CH[1].TCTRL.R  = 0x00000003;
  PIT.PITMCR.B.MDIS = 1 ;

  /*Disable PIT for initialization         */

  /* ----------------------------------------------------------- */

  /*                     Configure Load Value Registers                */

  /* ----------------------------------------------------------- */
  PIT.CH[0].LDVAL.R = 0x016E35FF;      /* The model's base sample time is 0.2 seconds. */

  /* ----------------------------------------------------------- */

  /*                     Enable Interrupts                  */

  /* ----------------------------------------------------------- */
  PIT.CH[0].TCTRL.B.TIE = 0x1 ;

  /* ----------------------------------------------------------- */

  /*                   Start Timers                 */

  /* ----------------------------------------------------------- */
  PIT.CH[0].TCTRL.B.TEN = 0x1 ;

  /*Start Timer 0 is : Enabled    */
  PIT.PITMCR.B.MDIS = 0 ;

  /*PIT Module : Enabled        */
}

void PIT_Ch0_ISR(void)
{
  /* Attach SYSTEM_TASK to a timer or interrupt service routine with

   * period 0.2 seconds (the model's base sample time) here.  The

   * call syntax for SYSTEM_TASK is  SYSTEM_TASK();

   */
  PIT.CH[0].TFLG.B.TIF = 1 ;
  SYSTEM_TASK();
}

void main(void)
{
  /* Shut Down Software Watchdog Timer */

  /* remove the SWT Soft lock  */
  SWT.SR.R = 0x0000C520;
  SWT.SR.R = 0x0000D928;

  /* Disable SWT  */
  SWT.CR.B.WEN = 0x0;
  sys_init_fnc();                      /* Disable Watchdog */
  adc_init_fnc();                      /* Adc configuration */
  adc0_config();
  adc_normal_start_fnc();
  SYSTEM_INIT_TASK();                  /* Initialize the processor. */
  pit_init_fnc();                      /* Initialize PIT Timer Module */
  INTC.CPR.B.PRI = 0;                  /* Ensure INTC's current priority is 0 */
  intc_init_fnc();
  asm(" wrteei 1");                    /* Enable IRQ */
  INTC.CPR.R = 0x0B;                   /* Global Minimum Interrupt Priority */
  while (1) {
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
