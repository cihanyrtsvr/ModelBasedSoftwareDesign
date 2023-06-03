/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sMultiWordCmp.c
 *
 * Code generated for Simulink model 'arduino_harness_lab4'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jun  3 21:40:05 2023
 */

#include "sMultiWordCmp.h"
#include "rtwtypes.h"

int16_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  uint32_T su1;
  int16_T y;
  su1 = u1[n - 1] & 2147483648UL;
  if ((u2[n - 1] & 2147483648UL) != su1) {
    y = su1 != 0UL ? -1 : 1;
  } else {
    int16_T i;
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      uint32_T u2i;
      i--;
      su1 = u1[i];
      u2i = u2[i];
      if (su1 != u2i) {
        y = su1 > u2i ? 1 : -1;
      }
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
