/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: co.c
 *
 * Code generated for Simulink model 'co'.
 *
 * Model version                  : 5.11
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jun 10 09:43:38 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "co.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rt_roundd_snf.h"
#include "rtwtypes.h"
#include "co_types.h"
#include "co_private.h"
#include "controller.h"

/* Block signals (default storage) */
B_co_T co_B;

/* Block states (default storage) */
DW_co_T co_DW;

/* Real-time model */
static RT_MODEL_co_T co_M_;
RT_MODEL_co_T *const co_M = &co_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (co_M->Timing.TaskCounters.TID[1])++;
  if ((co_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.5s, 0.0s] */
    co_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void co_step(void)
{
  /* local block i/o variables */
  real32_T rtb_Model_o1;
  WarningState rtb_Model_o3;
  TransmissionState rtb_AutomaticTransmissionState;
  codertarget_arduinobase_int_l_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real32_T rtb_CastToSingle;
  uint16_T b_varargout_1;
  uint8_T tmp;
  boolean_T b_value;
  TransmissionState rtb_DataTypeConversion1;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (co_DW.obj_e.SampleTime != co_P.DigitalInput_SampleTime) {
    co_DW.obj_e.SampleTime = co_P.DigitalInput_SampleTime;
  }

  b_value = readDigitalPin(8);

  /* MATLABSystem: '<Root>/Analog Input' */
  if (co_DW.obj_o.SampleTime != co_P.AnalogInput_SampleTime) {
    co_DW.obj_o.SampleTime = co_P.AnalogInput_SampleTime;
  }

  obj = &co_DW.obj_o;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
  co_B.datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult(co_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &b_varargout_1, co_B.datatype_id);

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double'
   *  Gain: '<Root>/Gain1'
   *  MATLABSystem: '<Root>/Analog Input'
   */
  co_B.DataTypeConversion3 = (real32_T)(co_P.Gain1_Gain * (real_T)b_varargout_1);

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (co_DW.obj_h.SampleTime != co_P.AnalogInput1_SampleTime) {
    co_DW.obj_h.SampleTime = co_P.AnalogInput1_SampleTime;
  }

  obj = &co_DW.obj_h;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(17UL);
  co_B.datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult(co_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &b_varargout_1, co_B.datatype_id);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double1'
   *  Gain: '<Root>/Gain4'
   *  MATLABSystem: '<Root>/Analog Input1'
   *  Rounding: '<Root>/Floor'
   */
  co_B.u0 = floor(co_P.Gain4_Gain * (real_T)b_varargout_1);
  if (rtIsNaN(co_B.u0) || rtIsInf(co_B.u0)) {
    co_B.u0 = 0.0;
  } else {
    co_B.u0 = fmod(co_B.u0, 4.294967296E+9);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  rtb_DataTypeConversion1 = (TransmissionState)(co_B.u0 < 0.0 ? -(int32_T)
    (uint32_T)-co_B.u0 : (int32_T)(uint32_T)co_B.u0);

  /* MATLABSystem: '<Root>/Analog Input2' */
  if (co_DW.obj.SampleTime != co_P.AnalogInput2_SampleTime) {
    co_DW.obj.SampleTime = co_P.AnalogInput2_SampleTime;
  }

  obj = &co_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16UL);
  co_B.datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult(co_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &b_varargout_1, co_B.datatype_id);

  /* DataTypeConversion: '<Root>/Cast To Single' incorporates:
   *  Constant: '<Root>/Constant'
   *  DataTypeConversion: '<Root>/Cast To Double2'
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Analog Input2'
   *  Sum: '<Root>/Add'
   */
  rtb_CastToSingle = (real32_T)(co_P.Gain_Gain * (real_T)b_varargout_1 -
    co_P.Constant_Value);

  /* ModelReference: '<Root>/Model' incorporates:
   *  MATLABSystem: '<Root>/Digital Input'
   */
  controller(&b_value, &co_B.DataTypeConversion3, &rtb_DataTypeConversion1,
             &rtb_CastToSingle, &rtb_Model_o1, &rtb_AutomaticTransmissionState,
             &rtb_Model_o3, &(co_DW.Model_InstanceData.rtb),
             &(co_DW.Model_InstanceData.rtdw));

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   */
  if ((int32_T)rtb_Model_o3 > co_P.Switch_Threshold) {
    co_B.u0 = co_P.Constant2_Value;
  } else {
    co_B.u0 = co_P.Constant3_Value;
  }

  /* MATLABSystem: '<Root>/Digital Output4' incorporates:
   *  Switch: '<Root>/Switch'
   */
  co_B.u0 = rt_roundd_snf(co_B.u0);
  if (co_B.u0 < 256.0) {
    if (co_B.u0 >= 0.0) {
      tmp = (uint8_T)co_B.u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(6, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output4' */

  /* MATLABSystem: '<Root>/PWM' */
  obj_0 = &co_DW.obj_e0;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);

  /* Gain: '<Root>/Gain2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sum: '<Root>/Add1'
   */
  co_B.u0 = (rtb_Model_o1 + co_P.Constant1_Value) * co_P.Gain2_Gain;

  /* Saturate: '<Root>/Saturation1' */
  if (co_B.u0 > co_P.Saturation1_UpperSat) {
    co_B.u0 = co_P.Saturation1_UpperSat;
  } else if (co_B.u0 < co_P.Saturation1_LowerSat) {
    co_B.u0 = co_P.Saturation1_LowerSat;
  }

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  Saturate: '<Root>/Saturation1'
   */
  MW_PWM_SetDutyCycle(co_DW.obj_e0.PWMDriverObj.MW_PWM_HANDLE, fmax(fmin(co_B.u0,
    255.0), 0.0));

  /* MATLABSystem: '<Root>/PWM1' */
  obj_0 = &co_DW.obj_g;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

  /* Sum: '<Root>/Add2' incorporates:
   *  Constant: '<Root>/Constant4'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  Gain: '<Root>/Gain3'
   */
  co_B.u0 = (real_T)(co_P.Gain3_Gain * (int64_T)rtb_AutomaticTransmissionState) *
    2.9802322387695312E-8 + co_P.Constant4_Value;

  /* Saturate: '<Root>/Saturation' */
  if (co_B.u0 > co_P.Saturation_UpperSat) {
    co_B.u0 = co_P.Saturation_UpperSat;
  } else if (co_B.u0 < co_P.Saturation_LowerSat) {
    co_B.u0 = co_P.Saturation_LowerSat;
  }

  /* MATLABSystem: '<Root>/PWM1' incorporates:
   *  Saturate: '<Root>/Saturation'
   */
  MW_PWM_SetDutyCycle(co_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, fmax(fmin(co_B.u0,
    255.0), 0.0));
  if (co_M->Timing.TaskCounters.TID[1] == 0) {
    /* Logic: '<Root>/NOT' incorporates:
     *  Delay: '<Root>/Delay'
     */
    co_DW.Delay_DSTATE = !co_DW.Delay_DSTATE;

    /* MATLABSystem: '<Root>/Digital Output3' incorporates:
     *  Delay: '<Root>/Delay'
     */
    writeDigitalPin(13, (uint8_T)co_DW.Delay_DSTATE);
  }

  rate_scheduler();
}

/* Model initialize function */
void co_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Model Initialize function for ModelReference Block: '<Root>/Model' */
  controller_initialize(rtmGetErrorStatusPointer(co_M),
                        &(co_DW.Model_InstanceData.rtm));

  {
    codertarget_arduinobase_int_l_T *obj_0;
    codertarget_arduinobase_inter_T *obj;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    co_DW.Delay_DSTATE = co_P.Delay_InitialCondition;

    /* Start for MATLABSystem: '<Root>/Digital Input' */
    co_DW.obj_e.matlabCodegenIsDeleted = false;
    co_DW.obj_e.SampleTime = co_P.DigitalInput_SampleTime;
    co_DW.obj_e.isInitialized = 1L;
    digitalIOSetup(8, 0);
    co_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    co_DW.obj_o.matlabCodegenIsDeleted = false;
    co_DW.obj_o.SampleTime = co_P.AnalogInput_SampleTime;
    obj = &co_DW.obj_o;
    co_DW.obj_o.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(18UL);
    co_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    co_DW.obj_h.matlabCodegenIsDeleted = false;
    co_DW.obj_h.SampleTime = co_P.AnalogInput1_SampleTime;
    obj = &co_DW.obj_h;
    co_DW.obj_h.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17UL);
    co_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input2' */
    co_DW.obj.matlabCodegenIsDeleted = false;
    co_DW.obj.SampleTime = co_P.AnalogInput2_SampleTime;
    obj = &co_DW.obj;
    co_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16UL);
    co_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output4' */
    co_DW.obj_n.matlabCodegenIsDeleted = false;
    co_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(6, 1);
    co_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    co_DW.obj_e0.matlabCodegenIsDeleted = false;
    obj_0 = &co_DW.obj_e0;
    co_DW.obj_e0.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(3UL, 0.0, 0.0);
    co_DW.obj_e0.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM1' */
    co_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_0 = &co_DW.obj_g;
    co_DW.obj_g.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
    co_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output3' */
    co_DW.obj_ef.matlabCodegenIsDeleted = false;
    co_DW.obj_ef.isInitialized = 1L;
    digitalIOSetup(13, 1);
    co_DW.obj_ef.isSetupComplete = true;
  }
}

/* Model terminate function */
void co_terminate(void)
{
  codertarget_arduinobase_int_l_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!co_DW.obj_e.matlabCodegenIsDeleted) {
    co_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &co_DW.obj_o;
  if (!co_DW.obj_o.matlabCodegenIsDeleted) {
    co_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((co_DW.obj_o.isInitialized == 1L) && co_DW.obj_o.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(18UL);
      MW_AnalogIn_Close(co_DW.obj_o.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  obj = &co_DW.obj_h;
  if (!co_DW.obj_h.matlabCodegenIsDeleted) {
    co_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((co_DW.obj_h.isInitialized == 1L) && co_DW.obj_h.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(17UL);
      MW_AnalogIn_Close(co_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  obj = &co_DW.obj;
  if (!co_DW.obj.matlabCodegenIsDeleted) {
    co_DW.obj.matlabCodegenIsDeleted = true;
    if ((co_DW.obj.isInitialized == 1L) && co_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(16UL);
      MW_AnalogIn_Close(co_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output4' */
  if (!co_DW.obj_n.matlabCodegenIsDeleted) {
    co_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output4' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj_0 = &co_DW.obj_e0;
  if (!co_DW.obj_e0.matlabCodegenIsDeleted) {
    co_DW.obj_e0.matlabCodegenIsDeleted = true;
    if ((co_DW.obj_e0.isInitialized == 1L) && co_DW.obj_e0.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);
      MW_PWM_SetDutyCycle(co_DW.obj_e0.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);
      MW_PWM_Close(co_DW.obj_e0.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  obj_0 = &co_DW.obj_g;
  if (!co_DW.obj_g.matlabCodegenIsDeleted) {
    co_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((co_DW.obj_g.isInitialized == 1L) && co_DW.obj_g.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(co_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(co_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!co_DW.obj_ef.matlabCodegenIsDeleted) {
    co_DW.obj_ef.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
