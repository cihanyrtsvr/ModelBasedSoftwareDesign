/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_types.h
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 3.71
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed May 31 14:31:36 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_types_h_
#define RTW_HEADER_controller_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_TransmissionState_
#define DEFINED_TYPEDEF_FOR_TransmissionState_

typedef enum {
  Park = 0,                            /* Default value */
  Reverse,
  Neutral,
  Drive,
  Brake,
  Error
} TransmissionState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_WarningState_
#define DEFINED_TYPEDEF_FOR_WarningState_

typedef enum {
  Ok = 0,                              /* Default value */
  Warning,
  ErrorSig
} WarningState;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_controller_T RT_MODEL_controller_T;

#endif                                 /* RTW_HEADER_controller_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
