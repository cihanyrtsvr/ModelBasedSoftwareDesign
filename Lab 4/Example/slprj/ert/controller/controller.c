/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller.c
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

#include "controller.h"
#include "rtwtypes.h"
#include "controller_types.h"
#include "controller_private.h"
#include <math.h>
#include "rt_nonfinite.h"

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

P_controller_T controller_P = {
  /* Expression: 2
   * Referenced by: '<Root>/Constant1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant7'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant9'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant8'
   */
  2.0,

  /* Expression: 4
   * Referenced by: '<Root>/Switch2'
   */
  4.0,

  /* Expression: 1
   * Referenced by: '<Root>/Switch'
   */
  1.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  1073741824,

  /* Computed Parameter: Switch5_Threshold
   * Referenced by: '<Root>/Switch5'
   */
  1.0F,

  /* Expression: true
   * Referenced by: '<Root>/Constant4'
   */
  true,

  /* Expression: false
   * Referenced by: '<Root>/Constant3'
   */
  false,

  /* Expression: false
   * Referenced by: '<Root>/Constant5'
   */
  false,

  /* Expression: true
   * Referenced by: '<Root>/Constant6'
   */
  true,

  /* Expression: false
   * Referenced by: '<Root>/Constant10'
   */
  false,

  /* Expression: true
   * Referenced by: '<Root>/Constant11'
   */
  true
};

/* Output and update for referenced model: 'controller' */
void controller(const boolean_T *rtu_BrakePedalPressed, const real32_T
                *rtu_ThrottlePedalPosition, const TransmissionState
                *rtu_AutomaticTrasmissionSelecto, const real32_T
                *rtu_VehicleSpeed_km_h, real32_T *rty_TorqueRequest_Nm,
                TransmissionState *rty_AutomaticTransmissionState, WarningState *
                rty_WarningState, B_controller_c_T *localB, DW_controller_f_T
                *localDW)
{
  real_T rtb_CastToDouble;
  real_T rtb_Switch5;
  int16_T rtb_Switch2;
  int16_T rtb_Transmission_State;
  boolean_T out;
  boolean_T tmp;
  boolean_T tmp_0;

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
      if ((int16_T)*rtu_AutomaticTrasmissionSelecto != 4) {
        localDW->is_Break = controller_IN_NO_ACTIVE_CHILD;
        localDW->is_c3_controller = controller_IN_Drive;
        rtb_Transmission_State = 3;
      } else {
        switch (localDW->is_Break) {
         case controll_IN_Acceleration_Region:
          if (rtb_CastToDouble <= 0.33333333333333331) {
            localDW->is_Break = controll_IN_Reg_Breaking_Region;
          } else {
            localB->TorqueRequest = rtP_MAX_TORQUE * 3.0 / 2.0 *
              (rtb_CastToDouble - 0.33333333333333331);
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
            localB->TorqueRequest = (1.0 - rtb_CastToDouble * 3.0) *
              -rtP_MAX_TORQUE;
          }
          break;
        }
      }
      break;

     case controller_IN_Drive:
      rtb_Transmission_State = 3;
      if ((int16_T)*rtu_AutomaticTrasmissionSelecto < 3) {
        localDW->is_c3_controller = controller_IN_Neutral;
        localDW->tp_Neutral = 1U;
        localB->TorqueRequest = 0.0;
        rtb_Transmission_State = 2;
      } else {
        out = ((rtb_CastToDouble > 0.33333333333333331) && ((int16_T)
                *rtu_AutomaticTrasmissionSelecto == 4));
        if (out) {
          localDW->is_c3_controller = controller_IN_Break;
          rtb_Transmission_State = 4;
          localDW->is_Break = controll_IN_Acceleration_Region;
        } else {
          localB->TorqueRequest = rtb_CastToDouble * rtP_MAX_TORQUE;
        }
      }
      break;

     case controller_IN_Neutral:
      rtb_Transmission_State = 2;
      out = ((*rtu_VehicleSpeed_km_h < 5.0F) && (*rtu_BrakePedalPressed) &&
             ((int16_T)*rtu_AutomaticTrasmissionSelecto == 1));
      if (out) {
        localDW->tp_Neutral = 0U;
        localDW->is_c3_controller = controller_IN_Reverse;
        rtb_Transmission_State = 1;
      } else {
        out = ((*rtu_VehicleSpeed_km_h > -5.0F) && (*rtu_BrakePedalPressed) &&
               ((int16_T)*rtu_AutomaticTrasmissionSelecto > 2));
        if (out) {
          localDW->tp_Neutral = 0U;
          localDW->is_c3_controller = controller_IN_Drive;
          rtb_Transmission_State = 3;
        } else {
          out = ((fabsf(*rtu_VehicleSpeed_km_h) < 5.0F) &&
                 ((*rtu_BrakePedalPressed) && ((int16_T)
                   *rtu_AutomaticTrasmissionSelecto == 0)));
          if (out) {
            localDW->tp_Neutral = 0U;
            localDW->is_c3_controller = controller_IN_Park;
            localB->TorqueRequest = 0.0;
            rtb_Transmission_State = 0;
          }
        }
      }
      break;

     case controller_IN_Park:
      rtb_Transmission_State = 0;
      out = ((*rtu_BrakePedalPressed) && ((int16_T)
              *rtu_AutomaticTrasmissionSelecto != 0));
      if (out) {
        localDW->is_c3_controller = controller_IN_Neutral;
        localDW->tp_Neutral = 1U;
        localB->TorqueRequest = 0.0;
        rtb_Transmission_State = 2;
      }
      break;

     default:
      /* case IN_Reverse: */
      rtb_Transmission_State = 1;
      if ((int16_T)*rtu_AutomaticTrasmissionSelecto != 1) {
        localDW->is_c3_controller = controller_IN_Neutral;
        localDW->tp_Neutral = 1U;
        localB->TorqueRequest = 0.0;
        rtb_Transmission_State = 2;
      } else {
        localB->TorqueRequest = -rtb_CastToDouble * rtP_MAX_TORQUE_REVERSE;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Driving Logic' */

  /* DataTypeConversion: '<Root>/Data Type Conversion4' */
  rtb_Switch2 = (int16_T)*rtu_AutomaticTrasmissionSelecto;

  /* Switch: '<Root>/Switch5' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant7'
   */
  if (*rtu_ThrottlePedalPosition > controller_P.Switch5_Threshold) {
    rtb_Switch5 = controller_P.Constant7_Value;
  } else {
    rtb_Switch5 = controller_P.Constant2_Value;
  }

  /* End of Switch: '<Root>/Switch5' */

  /* Switch: '<Root>/Switch4' incorporates:
   *  Constant: '<Root>/Constant10'
   *  Constant: '<Root>/Constant11'
   *  Constant: '<Root>/Constant8'
   *  Sum: '<Root>/Sum'
   */
  if ((real_T)rtb_Transmission_State - controller_P.Constant8_Value != 0.0) {
    out = controller_P.Constant10_Value;
  } else {
    out = controller_P.Constant11_Value;
  }

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   */
  if (rtb_Transmission_State != 0) {
    tmp = controller_P.Constant5_Value;
  } else {
    tmp = controller_P.Constant6_Value;
  }

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Rounding: '<Root>/Floor'
   */
  if (floor(localB->TorqueRequest) != 0.0) {
    tmp_0 = controller_P.Constant4_Value;
  } else {
    tmp_0 = controller_P.Constant3_Value;
  }

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  if (rtb_Switch2 > controller_P.Switch2_Threshold) {
    rtb_CastToDouble = controller_P.Constant1_Value;
  } else {
    rtb_CastToDouble = controller_P.Constant_Value;
  }

  /* MinMax: '<Root>/Max' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  Gain: '<Root>/Gain'
   *  Logic: '<Root>/AND'
   *  Logic: '<Root>/OR'
   *  Switch: '<Root>/Switch1'
   *  Switch: '<Root>/Switch2'
   *  Switch: '<Root>/Switch3'
   *  Switch: '<Root>/Switch4'
   */
  rtb_Switch5 = fmax(fmax((real_T)((out || tmp) && tmp_0) * (real_T)
    controller_P.Gain_Gain * 1.862645149230957E-9, rtb_CastToDouble),
                     rtb_Switch5);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  rtb_CastToDouble = floor(rtb_Switch5);
  if (rtIsInf(rtb_CastToDouble)) {
    rtb_CastToDouble = 0.0;
  } else {
    rtb_CastToDouble = fmod(rtb_CastToDouble, 4.294967296E+9);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  *rty_WarningState = (WarningState)(rtb_CastToDouble < 0.0 ? -(int32_T)
    (uint32_T)-rtb_CastToDouble : (int32_T)(uint32_T)rtb_CastToDouble);

  /* Switch: '<Root>/Switch' */
  if (rtb_Switch5 > controller_P.Switch_Threshold) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
     *  Constant: '<Root>/Constant9'
     */
    rtb_CastToDouble = floor(controller_P.Constant9_Value);
    if (rtIsNaN(rtb_CastToDouble) || rtIsInf(rtb_CastToDouble)) {
      rtb_CastToDouble = 0.0;
    } else {
      rtb_CastToDouble = fmod(rtb_CastToDouble, 4.294967296E+9);
    }

    /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     */
    *rty_AutomaticTransmissionState = (TransmissionState)(rtb_CastToDouble < 0.0
      ? -(int32_T)(uint32_T)-rtb_CastToDouble : (int32_T)(uint32_T)
      rtb_CastToDouble);
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     */
    *rty_AutomaticTransmissionState = (TransmissionState)rtb_Transmission_State;
  }

  /* End of Switch: '<Root>/Switch' */

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
