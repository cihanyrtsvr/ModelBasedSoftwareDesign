/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sMultiWordGt.c
 *
 * Code generated for Simulink model 'arduino_harness_lab4'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jun  3 21:40:05 2023
 */

#include "sMultiWordGt.h"
#include "sMultiWordCmp.h"
#include "rtwtypes.h"

boolean_T sMultiWordGt(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  return sMultiWordCmp(u1, u2, n) > 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
