/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: co.h
 *
 * Code generated for Simulink model 'co'.
 *
 * Model version                  : 5.9
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Jun  7 12:40:47 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_co_h_
#define RTW_HEADER_co_h_
#ifndef co_COMMON_INCLUDES_
#define co_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* co_COMMON_INCLUDES_ */

#include "co_types.h"
#include "controller.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
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

/* Block signals (default storage) */
typedef struct {
  MW_AnalogIn_ResultDataType_Type datatype_id;
  real_T u0;
  real32_T DataTypeConversion3;        /* '<Root>/Data Type Conversion3' */
} B_co_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input2' */
  codertarget_arduinobase_inter_T obj_h;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_o;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_e;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_l_T obj_n;/* '<Root>/Digital Output4' */
  codertarget_arduinobase_blo_l_T obj_ef;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_int_l_T obj_g;/* '<Root>/PWM1' */
  codertarget_arduinobase_int_l_T obj_e0;/* '<Root>/PWM' */
  boolean_T Delay_DSTATE;              /* '<Root>/Delay' */
  MdlrefDW_controller_T Model_InstanceData;/* '<Root>/Model' */
} DW_co_T;

/* Parameters (default storage) */
struct P_co_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T AnalogInput2_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input2'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/1023
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/204.6
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/3
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 60
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 40
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2.125
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 255
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Constant4_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  int32_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<Root>/Switch'
                                        */
  int32_T Gain3_Gain;                  /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<Root>/Gain3'
                                        */
  boolean_T Delay_InitialCondition;/* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<Root>/Delay'
                                    */
};

/* Real-time Model Data Structure */
struct tag_RTM_co_T {
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
extern P_co_T co_P;

/* Block signals (default storage) */
extern B_co_T co_B;

/* Block states (default storage) */
extern DW_co_T co_DW;

/* Model block global parameters (default storage) */
extern real_T rtP_MAX_TORQUE;          /* Variable: MAX_TORQUE
                                        * Referenced by: '<Root>/Model'
                                        */
extern real_T rtP_MAX_TORQUE_REVERSE;  /* Variable: MAX_TORQUE_REVERSE
                                        * Referenced by: '<Root>/Model'
                                        */

/* Model entry point functions */
extern void co_initialize(void);
extern void co_step(void);
extern void co_terminate(void);

/* Real-time Model object */
extern RT_MODEL_co_T *const co_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'co'
 */
#endif                                 /* RTW_HEADER_co_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
