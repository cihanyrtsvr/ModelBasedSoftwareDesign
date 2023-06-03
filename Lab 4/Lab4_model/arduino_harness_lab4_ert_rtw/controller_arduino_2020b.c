/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_arduino_2020b.c
 *
 * Code generated for Simulink model 'controller_arduino_2020b'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jun  3 12:33:29 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller_arduino_2020b.h"
#include "controller_arduino_2020b_types.h"
#include "rtwtypes.h"
#include "controller.h"

/* Block signals (default storage) */
B_controller_arduino_2020b_T controller_arduino_2020b_B;

/* Block states (default storage) */
DW_controller_arduino_2020b_T controller_arduino_2020b_DW;

/* Real-time model */
static RT_MODEL_controller_arduino_2_T controller_arduino_2020b_M_;
RT_MODEL_controller_arduino_2_T *const controller_arduino_2020b_M =
  &controller_arduino_2020b_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void controller_arduino_2020b_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(controller_arduino_2020b_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (controller_arduino_2020b_M->Timing.TaskCounters.TID[1])++;
  if ((controller_arduino_2020b_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.5s, 0.0s] */
    controller_arduino_2020b_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void controller_arduino_2020b_step0(void) /* Sample time: [0.1s, 0.0s] */
{
  MW_AnalogIn_ResultDataType_Type datatype_id;
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_Gain1;
  uint16_T b_varargout_1;

  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<Root>/Analog Input' */
  if (controller_arduino_2020b_DW.obj_g.SampleTime !=
      controller_arduino_2020b_P.AnalogInput_SampleTime) {
    controller_arduino_2020b_DW.obj_g.SampleTime =
      controller_arduino_2020b_P.AnalogInput_SampleTime;
  }

  obj = &controller_arduino_2020b_DW.obj_g;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (controller_arduino_2020b_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, datatype_id);

  /* Gain: '<Root>/Gain1' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double'
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Analog Input'
   */
  rtb_Gain1 = controller_arduino_2020b_P.Gain_Gain * (real_T)b_varargout_1 *
    controller_arduino_2020b_P.Gain1_Gain;

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (controller_arduino_2020b_DW.obj.SampleTime !=
      controller_arduino_2020b_P.AnalogInput1_SampleTime) {
    controller_arduino_2020b_DW.obj.SampleTime =
      controller_arduino_2020b_P.AnalogInput1_SampleTime;
  }

  obj = &controller_arduino_2020b_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (controller_arduino_2020b_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, datatype_id);

  /* End of MATLABSystem: '<Root>/Analog Input1' */

  /* ModelReference: '<Root>/Model' */
  controller(&rtb_Gain1, &controller_arduino_2020b_B.Error,
             &controller_arduino_2020b_B.LFP, &controller_arduino_2020b_B.HFP,
             &(controller_arduino_2020b_DW.Model_InstanceData.rtdw));

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(11, controller_arduino_2020b_B.Error);

  /* MATLABSystem: '<Root>/Digital Output1' */
  writeDigitalPin(2, (uint8_T)controller_arduino_2020b_B.LFP);

  /* MATLABSystem: '<Root>/Digital Output2' */
  writeDigitalPin(7, (uint8_T)controller_arduino_2020b_B.HFP);
}

/* Model step function for TID1 */
void controller_arduino_2020b_step1(void) /* Sample time: [0.5s, 0.0s] */
{
  /* Logic: '<Root>/NOT' incorporates:
   *  Delay: '<Root>/Delay'
   */
  controller_arduino_2020b_DW.Delay_DSTATE =
    !controller_arduino_2020b_DW.Delay_DSTATE;

  /* MATLABSystem: '<Root>/Digital Output3' incorporates:
   *  Delay: '<Root>/Delay'
   */
  writeDigitalPin(13, (uint8_T)controller_arduino_2020b_DW.Delay_DSTATE);
}

/* Model initialize function */
void controller_arduino_2020b_initialize(void)
{
  /* Model Initialize function for ModelReference Block: '<Root>/Model' */
  controller_initialize(rtmGetErrorStatusPointer(controller_arduino_2020b_M),
                        &(controller_arduino_2020b_DW.Model_InstanceData.rtm));

  {
    codertarget_arduinobase_inter_T *obj;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    controller_arduino_2020b_DW.Delay_DSTATE =
      controller_arduino_2020b_P.Delay_InitialCondition;

    /* SystemInitialize for ModelReference: '<Root>/Model' */
    controller_Init(&(controller_arduino_2020b_DW.Model_InstanceData.rtdw));

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    controller_arduino_2020b_DW.obj_g.matlabCodegenIsDeleted = false;
    controller_arduino_2020b_DW.obj_g.SampleTime =
      controller_arduino_2020b_P.AnalogInput_SampleTime;
    obj = &controller_arduino_2020b_DW.obj_g;
    controller_arduino_2020b_DW.obj_g.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(14UL);
    controller_arduino_2020b_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    controller_arduino_2020b_DW.obj.matlabCodegenIsDeleted = false;
    controller_arduino_2020b_DW.obj.SampleTime =
      controller_arduino_2020b_P.AnalogInput1_SampleTime;
    obj = &controller_arduino_2020b_DW.obj;
    controller_arduino_2020b_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(15UL);
    controller_arduino_2020b_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    controller_arduino_2020b_DW.obj_h.matlabCodegenIsDeleted = false;
    controller_arduino_2020b_DW.obj_h.isInitialized = 1L;
    digitalIOSetup(11, 1);
    controller_arduino_2020b_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    controller_arduino_2020b_DW.obj_j.matlabCodegenIsDeleted = false;
    controller_arduino_2020b_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(2, 1);
    controller_arduino_2020b_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output2' */
    controller_arduino_2020b_DW.obj_b.matlabCodegenIsDeleted = false;
    controller_arduino_2020b_DW.obj_b.isInitialized = 1L;
    digitalIOSetup(7, 1);
    controller_arduino_2020b_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output3' */
    controller_arduino_2020b_DW.obj_e.matlabCodegenIsDeleted = false;
    controller_arduino_2020b_DW.obj_e.isInitialized = 1L;
    digitalIOSetup(13, 1);
    controller_arduino_2020b_DW.obj_e.isSetupComplete = true;
  }
}

/* Model terminate function */
void controller_arduino_2020b_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &controller_arduino_2020b_DW.obj_g;
  if (!controller_arduino_2020b_DW.obj_g.matlabCodegenIsDeleted) {
    controller_arduino_2020b_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((controller_arduino_2020b_DW.obj_g.isInitialized == 1L) &&
        controller_arduino_2020b_DW.obj_g.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (controller_arduino_2020b_DW.obj_g.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  obj = &controller_arduino_2020b_DW.obj;
  if (!controller_arduino_2020b_DW.obj.matlabCodegenIsDeleted) {
    controller_arduino_2020b_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_arduino_2020b_DW.obj.isInitialized == 1L) &&
        controller_arduino_2020b_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close
        (controller_arduino_2020b_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!controller_arduino_2020b_DW.obj_h.matlabCodegenIsDeleted) {
    controller_arduino_2020b_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!controller_arduino_2020b_DW.obj_j.matlabCodegenIsDeleted) {
    controller_arduino_2020b_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!controller_arduino_2020b_DW.obj_b.matlabCodegenIsDeleted) {
    controller_arduino_2020b_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!controller_arduino_2020b_DW.obj_e.matlabCodegenIsDeleted) {
    controller_arduino_2020b_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
