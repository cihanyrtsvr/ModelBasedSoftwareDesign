/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sLong2MultiWord.c
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 3.65
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jun  3 21:34:24 2023
 */

#include "sLong2MultiWord.h"
#include "rtwtypes.h"

void sLong2MultiWord(int32_T u, uint32_T y[], int16_T n)
{
  uint32_T yi;
  int16_T i;
  y[0] = (uint32_T)u;
  yi = u < 0L ? MAX_uint32_T : 0UL;
  for (i = 1; i < n; i++) {
    y[i] = yi;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
