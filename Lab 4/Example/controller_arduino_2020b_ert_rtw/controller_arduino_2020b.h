/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_arduino_2020b.h
 *
 * Code generated for Simulink model 'controller_arduino_2020b'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jun  3 12:33:29 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_arduino_2020b_h_
#define RTW_HEADER_controller_arduino_2020b_h_
#ifndef controller_arduino_2020b_COMMON_INCLUDES_
#define controller_arduino_2020b_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#endif                           /* controller_arduino_2020b_COMMON_INCLUDES_ */

#include "controller_arduino_2020b_types.h"
#include "controller.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T Error;                       /* '<Root>/Model' */
  boolean_T LFP;                       /* '<Root>/Model' */
  boolean_T HFP;                       /* '<Root>/Model' */
} B_controller_arduino_2020b_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_g;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_e;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_block_T obj_b;/* '<Root>/Digital Output2' */
  codertarget_arduinobase_block_T obj_j;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Output' */
  boolean_T Delay_DSTATE;              /* '<Root>/Delay' */
  MdlrefDW_controller_T Model_InstanceData;/* '<Root>/Model' */
} DW_controller_arduino_2020b_T;

/* Parameters (default storage) */
struct P_controller_arduino_2020b_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T Gain_Gain;                    /* Expression: 5/(2^10-1)
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 200/5
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 5/(2^10-1)
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 4/5
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T MinimumFlow_Value;            /* Expression: -1
                                        * Referenced by: '<Root>/Minimum Flow'
                                        */
  boolean_T Delay_InitialCondition;/* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<Root>/Delay'
                                    */
};

/* Real-time Model Data Structure */
struct tag_RTM_controller_arduino_20_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_controller_arduino_2020b_T controller_arduino_2020b_P;

/* Block signals (default storage) */
extern B_controller_arduino_2020b_T controller_arduino_2020b_B;

/* Block states (default storage) */
extern DW_controller_arduino_2020b_T controller_arduino_2020b_DW;

/* External function called from main */
extern void controller_arduino_2020b_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void controller_arduino_2020b_initialize(void);
extern void controller_arduino_2020b_step0(void);
extern void controller_arduino_2020b_step1(void);
extern void controller_arduino_2020b_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controller_arduino_2_T *const controller_arduino_2020b_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
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
 * '<Root>' : 'controller_arduino_2020b'
 */
#endif                              /* RTW_HEADER_controller_arduino_2020b_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
