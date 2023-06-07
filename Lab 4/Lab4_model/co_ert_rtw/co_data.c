/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: co_data.c
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

#include "co.h"

/* Model block global parameters (default storage) */
real_T rtP_MAX_TORQUE = 80.0;          /* Variable: MAX_TORQUE
                                        * Referenced by: '<Root>/Model'
                                        */
real_T rtP_MAX_TORQUE_REVERSE = 40.0;  /* Variable: MAX_TORQUE_REVERSE
                                        * Referenced by: '<Root>/Model'
                                        */

/* Block parameters (default storage) */
P_co_T co_P = {
  /* Expression: -1
   * Referenced by: '<Root>/Analog Input'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input2'
   */
  -1.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Input'
   */
  0.1,

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Expression: 1/1023
   * Referenced by: '<Root>/Gain1'
   */
  0.00097751710654936461,

  /* Expression: 1/204.6
   * Referenced by: '<Root>/Gain4'
   */
  0.0048875855327468231,

  /* Expression: 1/3
   * Referenced by: '<Root>/Gain'
   */
  0.33333333333333331,

  /* Expression: 60
   * Referenced by: '<Root>/Constant'
   */
  60.0,

  /* Expression: 40
   * Referenced by: '<Root>/Constant1'
   */
  40.0,

  /* Expression: 2.125
   * Referenced by: '<Root>/Gain2'
   */
  2.125,

  /* Expression: 255
   * Referenced by: '<Root>/Saturation1'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant4'
   */
  10.0,

  /* Expression: 255
   * Referenced by: '<Root>/Saturation'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<Root>/Switch'
   */
  0,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<Root>/Gain3'
   */
  1711276032,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<Root>/Delay'
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
