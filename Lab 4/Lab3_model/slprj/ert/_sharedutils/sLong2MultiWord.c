/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sLong2MultiWord.c
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 3.69
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed May 31 13:54:00 2023
 */

#include "sLong2MultiWord.h"
#include "rtwtypes.h"

void sLong2MultiWord(int32_T u, uint32_T y[], int32_T n)
{
  int32_T i;
  uint32_T yi;
  y[0] = (uint32_T)u;
  yi = u < 0 ? MAX_uint32_T : 0U;
  for (i = 1; i < n; i++) {
    y[i] = yi;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
