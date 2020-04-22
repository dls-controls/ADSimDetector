#ifndef SimDetectorParamSet_H
#define SimDetectorParamSet_H

#include "ADDriverParamSet.h"

#define SimGainXString                "SIM_GAIN_X"
#define SimGainYString                "SIM_GAIN_Y"
#define SimGainRedString              "SIM_GAIN_RED"
#define SimGainGreenString            "SIM_GAIN_GREEN"
#define SimGainBlueString             "SIM_GAIN_BLUE"
#define SimOffsetString               "SIM_OFFSET"
#define SimNoiseString                "SIM_NOISE"
#define SimResetImageString           "RESET_IMAGE"
#define SimModeString                 "SIM_MODE"
#define SimPeakStartXString           "SIM_PEAK_START_X"
#define SimPeakStartYString           "SIM_PEAK_START_Y"
#define SimPeakWidthXString           "SIM_PEAK_WIDTH_X"
#define SimPeakWidthYString           "SIM_PEAK_WIDTH_Y"
#define SimPeakNumXString             "SIM_PEAK_NUM_X"
#define SimPeakNumYString             "SIM_PEAK_NUM_Y"
#define SimPeakStepXString            "SIM_PEAK_STEP_X"
#define SimPeakStepYString            "SIM_PEAK_STEP_Y"
#define SimPeakHeightVariationString  "SIM_PEAK_HEIGHT_VARIATION"
#define SimXSineOperationString       "SIM_XSINE_OPERATION"
#define SimXSine1AmplitudeString      "SIM_XSINE1_AMPLITUDE"
#define SimXSine1FrequencyString      "SIM_XSINE1_FREQUENCY"
#define SimXSine1PhaseString          "SIM_XSINE1_PHASE"
#define SimXSine2AmplitudeString      "SIM_XSINE2_AMPLITUDE"
#define SimXSine2FrequencyString      "SIM_XSINE2_FREQUENCY"
#define SimXSine2PhaseString          "SIM_XSINE2_PHASE"
#define SimYSineOperationString       "SIM_YSINE_OPERATION"
#define SimYSine1AmplitudeString      "SIM_YSINE1_AMPLITUDE"
#define SimYSine1FrequencyString      "SIM_YSINE1_FREQUENCY"
#define SimYSine1PhaseString          "SIM_YSINE1_PHASE"
#define SimYSine2AmplitudeString      "SIM_YSINE2_AMPLITUDE"
#define SimYSine2FrequencyString      "SIM_YSINE2_FREQUENCY"
#define SimYSine2PhaseString          "SIM_YSINE2_PHASE"

/** Simulation detector param set */
class simDetectorParamSet : public virtual ADDriverParamSet {
public:
    simDetectorParamSet() {
        this->add(SimGainXString, asynParamFloat64, &SimGainX);
        this->add(SimGainYString, asynParamFloat64, &SimGainY);
        this->add(SimGainRedString, asynParamFloat64, &SimGainRed);
        this->add(SimGainGreenString, asynParamFloat64, &SimGainGreen);
        this->add(SimGainBlueString, asynParamFloat64, &SimGainBlue);
        this->add(SimOffsetString, asynParamFloat64, &SimOffset);
        this->add(SimNoiseString, asynParamFloat64, &SimNoise);
        this->add(SimResetImageString, asynParamInt32, &SimResetImage);
        this->add(SimModeString, asynParamInt32, &SimMode);
        this->add(SimPeakStartXString, asynParamInt32, &SimPeakStartX);
        this->add(SimPeakStartYString, asynParamInt32, &SimPeakStartY);
        this->add(SimPeakWidthXString, asynParamInt32, &SimPeakWidthX);
        this->add(SimPeakWidthYString, asynParamInt32, &SimPeakWidthY);
        this->add(SimPeakNumXString, asynParamInt32, &SimPeakNumX);
        this->add(SimPeakNumYString, asynParamInt32, &SimPeakNumY);
        this->add(SimPeakStepXString, asynParamInt32, &SimPeakStepX);
        this->add(SimPeakStepYString, asynParamInt32, &SimPeakStepY);
        this->add(SimPeakHeightVariationString, asynParamFloat64, &SimPeakHeightVariation);
        this->add(SimXSineOperationString, asynParamInt32, &SimXSineOperation);
        this->add(SimYSineOperationString, asynParamInt32, &SimYSineOperation);
        this->add(SimXSine1AmplitudeString, asynParamFloat64, &SimXSine1Amplitude);
        this->add(SimXSine1FrequencyString, asynParamFloat64, &SimXSine1Frequency);
        this->add(SimXSine1PhaseString, asynParamFloat64, &SimXSine1Phase);
        this->add(SimXSine2AmplitudeString, asynParamFloat64, &SimXSine2Amplitude);
        this->add(SimXSine2FrequencyString, asynParamFloat64, &SimXSine2Frequency);
        this->add(SimXSine2PhaseString, asynParamFloat64, &SimXSine2Phase);
        this->add(SimYSine1AmplitudeString, asynParamFloat64, &SimYSine1Amplitude);
        this->add(SimYSine1FrequencyString, asynParamFloat64, &SimYSine1Frequency);
        this->add(SimYSine1PhaseString, asynParamFloat64, &SimYSine1Phase);
        this->add(SimYSine2AmplitudeString, asynParamFloat64, &SimYSine2Amplitude);
        this->add(SimYSine2FrequencyString, asynParamFloat64, &SimYSine2Frequency);
        this->add(SimYSine2PhaseString, asynParamFloat64, &SimYSine2Phase);
    }

    int SimGainX;
    #define FIRST_SIM_DETECTOR_PARAM_INDEX SimGainX
    int SimGainY;
    int SimGainRed;
    int SimGainGreen;
    int SimGainBlue;
    int SimNoise;
    int SimResetImage;
    int SimMode;
    int SimPeakStartX;
    int SimPeakStartY;
    int SimPeakWidthX;
    int SimPeakWidthY;
    int SimPeakNumX;
    int SimPeakNumY;
    int SimPeakStepX;
    int SimPeakStepY;
    int SimPeakHeightVariation;
    int SimOffset;
    int SimXSineOperation;
    int SimXSine1Amplitude;
    int SimXSine1Frequency;
    int SimXSine1Phase;
    int SimXSine2Amplitude;
    int SimXSine2Frequency;
    int SimXSine2Phase;
    int SimYSineOperation;
    int SimYSine1Amplitude;
    int SimYSine1Frequency;
    int SimYSine1Phase;
    int SimYSine2Amplitude;
    int SimYSine2Frequency;
    int SimYSine2Phase;
};

#endif  // SimDetectorParamSet_H
