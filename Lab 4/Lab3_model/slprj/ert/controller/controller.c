/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller.c
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 3.69
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed May 31 13:55:50 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller.h"
#include "rtwtypes.h"
#include "controller_types.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "multiword_types.h"
#include "controller_private.h"
#include "sLong2MultiWord.h"
#include "sMultiWordShl.h"
#include "sMultiWord2Double.h"

/* Named constants for Chart: '<Root>/Driving Logic' */
#define controll_IN_Acceleration_Region ((uint8_T)1U)
#define controll_IN_Reg_Breaking_Region ((uint8_T)3U)
#define controller_IN_Break            ((uint8_T)1U)
#define controller_IN_Breaking_end     ((uint8_T)2U)
#define controller_IN_Drive            ((uint8_T)2U)
#define controller_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define controller_IN_Neutral          ((uint8_T)3U)
#define controller_IN_Park             ((uint8_T)4U)
#define controller_IN_Reverse          ((uint8_T)5U)

/* Output and update for referenced model: 'controller' */
void controller(const boolean_T *rtu_BrakePedalPressed, const real32_T
                *rtu_ThrottlePedalPosition, const TransmissionState
                *rtu_AutomaticTrasmissionSelecto, const real32_T
                *rtu_VehicleSpeed_km_h, real32_T *rty_TorqueRequest_Nm,
                TransmissionState *rty_AutomaticTransmissionState, int32_T
                *rty_WarningState, B_controller_c_T *localB, DW_controller_f_T
                *localDW)
{
  int64m_T tmp;
  int64m_T tmp_0;
  real_T rtb_CastToDouble;
  int32_T rtb_Switch;
  int32_T rtb_Switch2;
  int32_T rtb_Transmission_State;

  /* DataTypeConversion: '<Root>/Cast To Double' */
  rtb_CastToDouble = *rtu_ThrottlePedalPosition;

  /* Chart: '<Root>/Driving Logic' */
  if (localDW->is_active_c3_controller == 0U) {
    localDW->is_active_c3_controller = 1U;
    localDW->is_c3_controller = controller_IN_Park;
    localB->TorqueRequest = 0.0;
    rtb_Transmission_State = 0;
  } else {
    switch (localDW->is_c3_controller) {
     case controller_IN_Break:
      rtb_Transmission_State = 4;
      if ((int32_T)*rtu_AutomaticTrasmissionSelecto != 4) {
        localDW->is_Break = controller_IN_NO_ACTIVE_CHILD;
        localDW->is_c3_controller = controller_IN_Drive;
        rtb_Transmission_State = 3;
      } else {
        switch (localDW->is_Break) {
         case controll_IN_Acceleration_Region:
          if (rtb_CastToDouble <= 0.33333333333333331) {
            localDW->is_Break = controll_IN_Reg_Breaking_Region;
          } else {
            localB->TorqueRequest = (rtb_CastToDouble - 0.33333333333333331) *
              120.0;
          }
          break;

         case controller_IN_Breaking_end:
          if (rtb_CastToDouble > 0.33333333333333331) {
            localDW->is_Break = controll_IN_Acceleration_Region;
          }
          break;

         default:
          /* case IN_Reg_Breaking_Region: */
          if (rtb_CastToDouble > 0.33333333333333331) {
            localDW->is_Break = controll_IN_Acceleration_Region;
          } else if (*rtu_VehicleSpeed_km_h <= 0.2) {
            localDW->is_Break = controller_IN_Breaking_end;
            localB->TorqueRequest = 0.0;
          } else {
            localB->TorqueRequest = (1.0 - rtb_CastToDouble * 3.0) * -80.0;
          }
          break;
        }
      }
      break;

     case controller_IN_Drive:
      {
        rtb_Transmission_State = 3;
        if ((int32_T)*rtu_AutomaticTrasmissionSelecto < 3) {
          localDW->is_c3_controller = controller_IN_Neutral;
          localDW->tp_Neutral = 1U;
          localB->TorqueRequest = 0.0;
          rtb_Transmission_State = 2;
        } else {
          boolean_T out;
          out = ((rtb_CastToDouble > 0.33333333333333331) && ((int32_T)
                  *rtu_AutomaticTrasmissionSelecto == 4));
          if (out) {
            localDW->is_c3_controller = controller_IN_Break;
            rtb_Transmission_State = 4;
            localDW->is_Break = controll_IN_Acceleration_Region;
          } else {
            localB->TorqueRequest = rtb_CastToDouble * 80.0;
          }
        }
      }
      break;

     case controller_IN_Neutral:
      {
        boolean_T out;
        rtb_Transmission_State = 2;
        out = ((*rtu_VehicleSpeed_km_h < 5.0F) && (*rtu_BrakePedalPressed) &&
               ((int32_T)*rtu_AutomaticTrasmissionSelecto == 1));
        if (out) {
          localDW->tp_Neutral = 0U;
          localDW->is_c3_controller = controller_IN_Reverse;
          rtb_Transmission_State = 1;
        } else {
          out = ((*rtu_VehicleSpeed_km_h > -5.0F) && (*rtu_BrakePedalPressed) &&
                 ((int32_T)*rtu_AutomaticTrasmissionSelecto > 2));
          if (out) {
            localDW->tp_Neutral = 0U;
            localDW->is_c3_controller = controller_IN_Drive;
            rtb_Transmission_State = 3;
          } else {
            out = ((fabsf(*rtu_VehicleSpeed_km_h) < 5.0F) &&
                   ((*rtu_BrakePedalPressed) && ((int32_T)
                     *rtu_AutomaticTrasmissionSelecto == 0)));
            if (out) {
              localDW->tp_Neutral = 0U;
              localDW->is_c3_controller = controller_IN_Park;
              localB->TorqueRequest = 0.0;
              rtb_Transmission_State = 0;
            }
          }
        }
      }
      break;

     case controller_IN_Park:
      {
        boolean_T out;
        rtb_Transmission_State = 0;
        out = ((*rtu_BrakePedalPressed) && ((int32_T)
                *rtu_AutomaticTrasmissionSelecto != 0));
        if (out) {
          localDW->is_c3_controller = controller_IN_Neutral;
          localDW->tp_Neutral = 1U;
          localB->TorqueRequest = 0.0;
          rtb_Transmission_State = 2;
        }
      }
      break;

     default:
      /* case IN_Reverse: */
      rtb_Transmission_State = 1;
      if ((int32_T)*rtu_AutomaticTrasmissionSelecto != 1) {
        localDW->is_c3_controller = controller_IN_Neutral;
        localDW->tp_Neutral = 1U;
        localB->TorqueRequest = 0.0;
        rtb_Transmission_State = 2;
      } else {
        localB->TorqueRequest = -rtb_CastToDouble * 40.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Driving Logic' */

  /* DataTypeConversion: '<Root>/Data Type Conversion4' */
  rtb_Switch2 = (int32_T)*rtu_AutomaticTrasmissionSelecto;

  /* Switch: '<Root>/Switch5' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant7'
   */
  if (*rtu_ThrottlePedalPosition > 1.0F) {
    rtb_Switch = 2;
  } else {
    rtb_Switch = 0;
  }

  /* End of Switch: '<Root>/Switch5' */

  /* Gain: '<Root>/Gain' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Logic: '<Root>/AND'
   *  Logic: '<Root>/OR'
   *  Rounding: '<Root>/Floor'
   *  Sum: '<Root>/Sum'
   *  Switch: '<Root>/Switch1'
   *  Switch: '<Root>/Switch3'
   *  Switch: '<Root>/Switch4'
   */
  sLong2MultiWord(((rtb_Transmission_State - 2 == 0) || (rtb_Transmission_State ==
    0)) && (floor(localB->TorqueRequest) != 0.0), &tmp_0.chunks[0U], 2);
  sMultiWordShl(&tmp_0.chunks[0U], 2, 30U, &tmp.chunks[0U], 2);

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  if (rtb_Switch2 > 4) {
    rtb_Switch2 = 2;
  } else {
    rtb_Switch2 = 0;
  }

  /* MinMax: '<Root>/Max' incorporates:
   *  Switch: '<Root>/Switch2'
   */
  rtb_CastToDouble = fmax(fmax(sMultiWord2Double(&tmp.chunks[0U], 2, 0) *
    1.862645149230957E-9, rtb_Switch2), rtb_Switch);

  /* Switch: '<Root>/Switch' */
  if (rtb_CastToDouble > 1.0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion3' */
    *rty_AutomaticTransmissionState = Neutral;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion3' */
    *rty_AutomaticTransmissionState = (TransmissionState)rtb_Transmission_State;
  }

  /* End of Switch: '<Root>/Switch' */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  rtb_CastToDouble = floor(rtb_CastToDouble);
  if (rtIsInf(rtb_CastToDouble)) {
    *rty_WarningState = 0;
  } else {
    *rty_WarningState = (int32_T)(uint32_T)fmod(rtb_CastToDouble, 4.294967296E+9);
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion2' */

  /* DataTypeConversion: '<Root>/Cast To Single' */
  *rty_TorqueRequest_Nm = (real32_T)localB->TorqueRequest;
}

/* Model initialize function */
void controller_initialize(const char_T **rt_errorStatus, RT_MODEL_controller_T *
  const controller_M)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(controller_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
