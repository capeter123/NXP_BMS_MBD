/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: can_simple_block_bu11142.h
 *
 * Code generated for Simulink model 'can_simple_block_bu11142'.
 *
 * Model version                  : 1.1343
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Jan 02 16:38:38 2018
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_can_simple_block_bu11142_h_
#define RTW_HEADER_can_simple_block_bu11142_h_
#include <math.h>
#ifndef can_simple_block_bu11142_COMMON_INCLUDES_
# define can_simple_block_bu11142_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* can_simple_block_bu11142_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define can_simple_block_bu11142_M     (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (auto storage) for system '<S2>/Subsystem' */
typedef struct {
  real_T count;                        /* '<S23>/Chart1' */
  uint8_T VTDataCAN_8b[8];             /* '<S23>/RawData to StoreData' */
  uint8_T is_active_c19_can_simple_block_;/* '<S23>/Chart1' */
  uint8_T is_c19_can_simple_block_bu11142;/* '<S23>/Chart1' */
} rtDW_Subsystem;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  rtDW_Subsystem Subsystem_i5;         /* '<S2>/Subsystem' */
  real_T count;                        /* '<S2>/Data collection chart' */
  real_T count_a;                      /* '<S2>/Chart' */
  real_T count_m;                      /* '<S2>/Chart1' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator7' */
  int32_T PackI;                       /* '<S2>/Data Store Memory2' */
  uint32_T SFunctionBuilder1_o1;       /* '<S7>/S-Function Builder1' */
  uint32_T SFunctionBuilder1_o2;       /* '<S7>/S-Function Builder1' */
  uint32_T SFunctionBuilder1_o3;       /* '<S7>/S-Function Builder1' */
  uint32_T SFunctionBuilder1_o4;       /* '<S7>/S-Function Builder1' */
  int16_T CellGP_1_78[78];             /* '<S2>/Data Store Memory1' */
  int16_T CellSOP_1_104[104];          /* '<S2>/Data Store Memory4' */
  uint16_T CellV_1_104[104];           /* '<S2>/Data Store Memory' */
  uint16_T CellSOC_1_104[104];         /* '<S2>/Data Store Memory3' */
  uint16_T DataTypeConversion;         /* '<Root>/Data Type Conversion' */
  uint16_T CANReceiveDataTrigger1_o5;  /* '<Root>/CAN Receive Data Trigger1' */
  uint16_T count_k;                    /* '<S7>/Chart' */
  uint8_T CANReceiveDataTrigger1_o4[8];/* '<Root>/CAN Receive Data Trigger1' */
  uint8_T SFunctionBuilder_o1[56];     /* '<S2>/S-Function Builder' */
  uint8_T SFunctionBuilder_o2[14];     /* '<S2>/S-Function Builder' */
  uint8_T CMD32[4];                    /* '<S2>/Data collection chart' */
  uint8_T In3[8];                      /* '<S5>/In3' */
  uint8_T CANReceiveDataTrigger1_o2;   /* '<Root>/CAN Receive Data Trigger1' */
  uint8_T CANReceiveDataTrigger1_o3;   /* '<Root>/CAN Receive Data Trigger1' */
  uint8_T is_active_c15_can_simple_block_;/* '<S2>/Data collection chart' */
  uint8_T is_c15_can_simple_block_bu11142;/* '<S2>/Data collection chart' */
  uint8_T is_active_c22_can_simple_block_;/* '<S2>/Chart3' */
  uint8_T is_c22_can_simple_block_bu11142;/* '<S2>/Chart3' */
  uint8_T is_active_c17_can_simple_block_;/* '<S2>/Chart1' */
  uint8_T is_c17_can_simple_block_bu11142;/* '<S2>/Chart1' */
  uint8_T is_active_c7_can_simple_block_b;/* '<S2>/Chart' */
  uint8_T is_c7_can_simple_block_bu11142;/* '<S2>/Chart' */
  uint8_T is_active_c1_can_simple_block_b;/* '<S7>/Chart' */
  uint8_T is_c1_can_simple_block_bu11142;/* '<S7>/Chart' */
  boolean_T A;                         /* '<S2>/Chart' */
  boolean_T A_m;                       /* '<S7>/Chart' */
} D_Work;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T var1;                         /* '<Root>/In1' */
} ExternalInputs;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  uint8_T Out1[8];                     /* '<Root>/Out1' */
  uint8_T Out2;                        /* '<Root>/Out2' */
  uint8_T Out3;                        /* '<Root>/Out3' */
  uint16_T Out4;                       /* '<Root>/Out4' */
  uint8_T Out5;                        /* '<Root>/Out5' */
  uint16_T Out7;                       /* '<Root>/Out7' */
} ExternalOutputs;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (auto storage) */
extern D_Work rtDWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs rtY;

/* External function called from main */
extern void can_simple_block_bu11142_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void can_simple_block_bu11142_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void can_simple_block_bu11142_initialize(void);
extern void can_simple_block_bu11142_step(int_T tid);
extern void can_simple_block_bu11142_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion4' : Unused code path elimination
 * Block '<S2>/Gain' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'can_simple_block_bu11142'
 * '<S1>'   : 'can_simple_block_bu11142/Chart'
 * '<S2>'   : 'can_simple_block_bu11142/Function-Call Subsystem'
 * '<S3>'   : 'can_simple_block_bu11142/MATLAB Function'
 * '<S4>'   : 'can_simple_block_bu11142/MATLAB Function2'
 * '<S5>'   : 'can_simple_block_bu11142/Subsystem'
 * '<S6>'   : 'can_simple_block_bu11142/Subsystem1'
 * '<S7>'   : 'can_simple_block_bu11142/Subsystem2'
 * '<S8>'   : 'can_simple_block_bu11142/Subsystem3'
 * '<S9>'   : 'can_simple_block_bu11142/Subsystem4'
 * '<S10>'  : 'can_simple_block_bu11142/Function-Call Subsystem/Chart'
 * '<S11>'  : 'can_simple_block_bu11142/Function-Call Subsystem/Chart1'
 * '<S12>'  : 'can_simple_block_bu11142/Function-Call Subsystem/Chart2'
 * '<S13>'  : 'can_simple_block_bu11142/Function-Call Subsystem/Chart3'
 * '<S14>'  : 'can_simple_block_bu11142/Function-Call Subsystem/Chart4'
 * '<S15>'  : 'can_simple_block_bu11142/Function-Call Subsystem/DMA_Init'
 * '<S16>'  : 'can_simple_block_bu11142/Function-Call Subsystem/Data collection chart'
 * '<S17>'  : 'can_simple_block_bu11142/Function-Call Subsystem/MATLAB Function1'
 * '<S18>'  : 'can_simple_block_bu11142/Function-Call Subsystem/MATLAB Function2'
 * '<S19>'  : 'can_simple_block_bu11142/Function-Call Subsystem/PEC generation'
 * '<S20>'  : 'can_simple_block_bu11142/Function-Call Subsystem/RawData to StoreData'
 * '<S21>'  : 'can_simple_block_bu11142/Function-Call Subsystem/SOCKF_Init1'
 * '<S22>'  : 'can_simple_block_bu11142/Function-Call Subsystem/SOCKF_Run'
 * '<S23>'  : 'can_simple_block_bu11142/Function-Call Subsystem/Subsystem'
 * '<S24>'  : 'can_simple_block_bu11142/Function-Call Subsystem/Subsystem1'
 * '<S25>'  : 'can_simple_block_bu11142/Function-Call Subsystem/SOCKF_Run/Chart1'
 * '<S26>'  : 'can_simple_block_bu11142/Function-Call Subsystem/SOCKF_Run/RawData to StoreData'
 * '<S27>'  : 'can_simple_block_bu11142/Function-Call Subsystem/SOCKF_Run/RawData to StoreData1'
 * '<S28>'  : 'can_simple_block_bu11142/Function-Call Subsystem/Subsystem/Chart1'
 * '<S29>'  : 'can_simple_block_bu11142/Function-Call Subsystem/Subsystem/RawData to StoreData'
 * '<S30>'  : 'can_simple_block_bu11142/Function-Call Subsystem/Subsystem1/Chart1'
 * '<S31>'  : 'can_simple_block_bu11142/Function-Call Subsystem/Subsystem1/RawData to StoreData'
 * '<S32>'  : 'can_simple_block_bu11142/Subsystem1/Chart'
 * '<S33>'  : 'can_simple_block_bu11142/Subsystem1/SPI_SEND_SYSTEM'
 * '<S34>'  : 'can_simple_block_bu11142/Subsystem1/SPI_SEND_SYSTEM/PEC generation'
 * '<S35>'  : 'can_simple_block_bu11142/Subsystem1/SPI_SEND_SYSTEM/SPI_SEND_STATE_FLOW'
 * '<S36>'  : 'can_simple_block_bu11142/Subsystem2/Chart'
 * '<S37>'  : 'can_simple_block_bu11142/Subsystem3/Chart'
 * '<S38>'  : 'can_simple_block_bu11142/Subsystem4/Chart'
 */
#endif                                 /* RTW_HEADER_can_simple_block_bu11142_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
