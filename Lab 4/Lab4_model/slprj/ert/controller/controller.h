/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller.h
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 3.67
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jun  3 22:30:27 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_h_
#define RTW_HEADER_controller_h_
#ifndef controller_COMMON_INCLUDES_
#define controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* controller_COMMON_INCLUDES_ */

#include "controller_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Block signals for model 'controller' */
typedef struct {
  real_T TorqueRequest;                /* '<Root>/Driving Logic' */
} B_controller_c_T;

/* Block states (default storage) for model 'controller' */
typedef struct {
  uint8_T is_c3_controller;            /* '<Root>/Driving Logic' */
  uint8_T is_Break;                    /* '<Root>/Driving Logic' */
  uint8_T is_active_c3_controller;     /* '<Root>/Driving Logic' */
  uint8_T tp_Neutral;                  /* '<Root>/Driving Logic' */
} DW_controller_f_T;

/* Parameters (default storage) */
struct P_controller_T_ {
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant7_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant9_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant8_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Switch2_Threshold;            /* Expression: 4
                                        * Referenced by: '<Root>/Switch2'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<Root>/Switch'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  real32_T Switch5_Threshold;          /* Computed Parameter: Switch5_Threshold
                                        * Referenced by: '<Root>/Switch5'
                                        */
  boolean_T Constant4_Value;           /* Expression: true
                                        * Referenced by: '<Root>/Constant4'
                                        */
  boolean_T Constant3_Value;           /* Expression: false
                                        * Referenced by: '<Root>/Constant3'
                                        */
  boolean_T Constant5_Value;           /* Expression: false
                                        * Referenced by: '<Root>/Constant5'
                                        */
  boolean_T Constant6_Value;           /* Expression: true
                                        * Referenced by: '<Root>/Constant6'
                                        */
  boolean_T Constant10_Value;          /* Expression: false
                                        * Referenced by: '<Root>/Constant10'
                                        */
  boolean_T Constant11_Value;          /* Expression: true
                                        * Referenced by: '<Root>/Constant11'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_controller_T {
  const char_T **errorStatus;
};

typedef struct {
  B_controller_c_T rtb;
  DW_controller_f_T rtdw;
  RT_MODEL_controller_T rtm;
} MdlrefDW_controller_T;

/* Model block global parameters (default storage) */
extern real_T rtP_MAX_TORQUE;          /* Variable: MAX_TORQUE
                                        * Referenced by: '<Root>/Driving Logic'
                                        */
extern real_T rtP_MAX_TORQUE_REVERSE;  /* Variable: MAX_TORQUE_REVERSE
                                        * Referenced by: '<Root>/Driving Logic'
                                        */

/* Model reference registration function */
extern void controller_initialize(const char_T **rt_errorStatus,
  RT_MODEL_controller_T *const controller_M);
extern void controller(const boolean_T *rtu_BrakePedalPressed, const real32_T
  *rtu_ThrottlePedalPosition, const TransmissionState
  *rtu_AutomaticTrasmissionSelecto, const real32_T *rtu_VehicleSpeed_km_h,
  real32_T *rty_TorqueRequest_Nm, TransmissionState
  *rty_AutomaticTransmissionState, WarningState *rty_WarningState,
  B_controller_c_T *localB, DW_controller_f_T *localDW);

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
 * '<Root>' : 'controller'
 * '<S1>'   : 'controller/Driving Logic'
 */
#endif                                 /* RTW_HEADER_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
