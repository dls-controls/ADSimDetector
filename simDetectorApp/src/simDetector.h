#include <epicsEvent.h>
#include "ADDriver.h"
#include "simDetectorParamSet.h"

#define DRIVER_VERSION      2
#define DRIVER_REVISION     9
#define DRIVER_MODIFICATION 0

/** Our param indexes are member variables via inheritance of our paramSet */
#define FIRST_SIM_DETECTOR_PARAM FIRST_SIM_DETECTOR_PARAM_INDEX

/** Simulation detector driver; demonstrates most of the features that areaDetector drivers can support. */
class epicsShareClass simDetector : public simDetectorParamSet, public ADDriver {
public:
    simDetector(const char *portName, int maxSizeX, int maxSizeY, NDDataType_t dataType,
                int maxBuffers, size_t maxMemory,
                int priority, int stackSize);

    /* These are the methods that we override from ADDriver */
    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);
    virtual asynStatus writeFloat64(asynUser *pasynUser, epicsFloat64 value);
    virtual void setShutter(int open);
    virtual void report(FILE *fp, int details);
    void simTask(); /**< Should be private, but gets called from C, so must be public */


private:
    /* These are the methods that are new to this class */
    template <typename epicsType> int computeArray(int sizeX, int sizeY);
    template <typename epicsType> int computeLinearRampArray(int sizeX, int sizeY);
    template <typename epicsType> int computePeaksArray(int sizeX, int sizeY);
    template <typename epicsType> int computeSineArray(int sizeX, int sizeY);
    int computeImage();

    /* Our data */
    epicsEventId startEventId_;
    epicsEventId stopEventId_;
    NDArray *pRaw_;
    NDArray *pBackground_;
    bool useBackground_;
    NDArray *pRamp_;
    NDArray *pPeak_;
    NDArrayInfo arrayInfo_;
    double *xSine1_;
    double *xSine2_;
    double *ySine1_;
    double *ySine2_;
    double xSineCounter_;
    double ySineCounter_;
};

typedef enum {
    SimModeLinearRamp,
    SimModePeaks,
    SimModeSine,
    SimModeOffsetNoise
} SimModes_t;

typedef enum {
    SimSineOperationAdd,
    SimSineOperationMultiply
} SimSineOperation_t;
