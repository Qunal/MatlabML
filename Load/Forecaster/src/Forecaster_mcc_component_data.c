//
// MATLAB Compiler: 4.13 (R2010a)
// Date: Mon Aug 09 11:38:08 2010
// Arguments: "-B" "macro_default" "-W" "excel:Forecaster,Class1,1.0" "-T"
// "link:lib" "-b" "-d" "C:\Seminars\Load Forecasting\Load\Forecaster\src" "-N"
// "-p" "nnet" "-p" "stats" "-w" "enable:specified_file_mismatch" "-w"
// "enable:repeated_file" "-w" "enable:switch_ignored" "-w"
// "enable:missing_lib_sentinel" "-w" "enable:demo_license" "-v"
// "class{Class1:C:\Seminars\Load Forecasting\Load\loadForecast.m}" "-a"
// "C:\Seminars\Load Forecasting\Load\Models" 
//

#include "mclmcrrt.h"

#ifdef __cplusplus
extern "C" {
#endif
extern const unsigned char __MCC_Forecaster_session_key[] = {
    'A', 'E', '6', '3', '9', '6', 'E', '9', 'C', 'C', '6', 'D', '1', '9', '5',
    '0', '7', 'C', '9', '8', '9', 'C', '7', '8', '7', 'B', '8', 'F', 'C', 'D',
    '4', 'B', '9', 'D', 'F', '7', 'F', 'C', 'A', 'A', '1', '8', '0', 'C', '3',
    '0', 'B', '4', 'D', '6', '6', '0', '2', '6', 'A', '3', 'A', '8', 'C', 'A',
    'F', '2', '6', '5', '1', '6', 'A', 'E', 'B', '0', 'E', '7', 'E', 'C', '4',
    'C', 'F', '9', 'E', '0', '0', '3', '7', '9', '3', 'E', 'C', 'A', 'C', 'C',
    'C', '6', 'C', '6', '9', 'A', '1', 'B', 'E', '2', 'D', '8', '0', 'F', '1',
    '7', '9', '3', '6', '7', 'A', '6', '6', '3', '0', 'A', '2', 'A', 'C', '4',
    '7', '2', '5', '9', '6', '7', '9', '0', '8', '3', 'D', 'C', '8', 'A', '1',
    '5', '6', '2', '0', '3', 'E', '8', '1', 'C', '5', '5', '2', '0', '6', 'D',
    '1', '2', '4', '1', '3', '8', 'A', '9', '8', '2', '1', '7', '4', 'A', '4',
    'E', '0', '1', '6', '0', '4', 'E', 'B', '7', 'B', '1', '1', '4', 'A', '6',
    'E', '8', 'B', 'F', 'B', 'F', '9', 'A', 'C', 'B', '6', 'D', 'B', 'E', '9',
    '7', '3', 'D', 'B', 'B', 'C', 'C', 'E', 'E', '5', 'C', 'B', '6', '0', '4',
    'B', '2', '4', '2', 'E', '0', '8', 'F', '7', '9', '6', 'D', '8', '1', 'D',
    'E', '9', 'D', '0', '9', 'B', '8', '1', 'B', '3', '7', '6', '9', 'D', 'B',
    '6', '3', 'D', '4', 'E', '0', '7', '6', '5', 'E', 'D', 'E', 'B', '3', 'C',
    '7', '\0'};

extern const unsigned char __MCC_Forecaster_public_key[] = {
    '3', '0', '8', '1', '9', 'D', '3', '0', '0', 'D', '0', '6', '0', '9', '2',
    'A', '8', '6', '4', '8', '8', '6', 'F', '7', '0', 'D', '0', '1', '0', '1',
    '0', '1', '0', '5', '0', '0', '0', '3', '8', '1', '8', 'B', '0', '0', '3',
    '0', '8', '1', '8', '7', '0', '2', '8', '1', '8', '1', '0', '0', 'C', '4',
    '9', 'C', 'A', 'C', '3', '4', 'E', 'D', '1', '3', 'A', '5', '2', '0', '6',
    '5', '8', 'F', '6', 'F', '8', 'E', '0', '1', '3', '8', 'C', '4', '3', '1',
    '5', 'B', '4', '3', '1', '5', '2', '7', '7', 'E', 'D', '3', 'F', '7', 'D',
    'A', 'E', '5', '3', '0', '9', '9', 'D', 'B', '0', '8', 'E', 'E', '5', '8',
    '9', 'F', '8', '0', '4', 'D', '4', 'B', '9', '8', '1', '3', '2', '6', 'A',
    '5', '2', 'C', 'C', 'E', '4', '3', '8', '2', 'E', '9', 'F', '2', 'B', '4',
    'D', '0', '8', '5', 'E', 'B', '9', '5', '0', 'C', '7', 'A', 'B', '1', '2',
    'E', 'D', 'E', '2', 'D', '4', '1', '2', '9', '7', '8', '2', '0', 'E', '6',
    '3', '7', '7', 'A', '5', 'F', 'E', 'B', '5', '6', '8', '9', 'D', '4', 'E',
    '6', '0', '3', '2', 'F', '6', '0', 'C', '4', '3', '0', '7', '4', 'A', '0',
    '4', 'C', '2', '6', 'A', 'B', '7', '2', 'F', '5', '4', 'B', '5', '1', 'B',
    'B', '4', '6', '0', '5', '7', '8', '7', '8', '5', 'B', '1', '9', '9', '0',
    '1', '4', '3', '1', '4', 'A', '6', '5', 'F', '0', '9', '0', 'B', '6', '1',
    'F', 'C', '2', '0', '1', '6', '9', '4', '5', '3', 'B', '5', '8', 'F', 'C',
    '8', 'B', 'A', '4', '3', 'E', '6', '7', '7', '6', 'E', 'B', '7', 'E', 'C',
    'D', '3', '1', '7', '8', 'B', '5', '6', 'A', 'B', '0', 'F', 'A', '0', '6',
    'D', 'D', '6', '4', '9', '6', '7', 'C', 'B', '1', '4', '9', 'E', '5', '0',
    '2', '0', '1', '1', '1', '\0'};

static const char * MCC_Forecaster_matlabpath_data[] = 
  { "Forecaster/", "$TOOLBOXDEPLOYDIR/", "Models/",
    "$TOOLBOXMATLABDIR/general/", "$TOOLBOXMATLABDIR/ops/",
    "$TOOLBOXMATLABDIR/lang/", "$TOOLBOXMATLABDIR/elmat/",
    "$TOOLBOXMATLABDIR/randfun/", "$TOOLBOXMATLABDIR/elfun/",
    "$TOOLBOXMATLABDIR/specfun/", "$TOOLBOXMATLABDIR/matfun/",
    "$TOOLBOXMATLABDIR/datafun/", "$TOOLBOXMATLABDIR/polyfun/",
    "$TOOLBOXMATLABDIR/funfun/", "$TOOLBOXMATLABDIR/sparfun/",
    "$TOOLBOXMATLABDIR/scribe/", "$TOOLBOXMATLABDIR/graph2d/",
    "$TOOLBOXMATLABDIR/graph3d/", "$TOOLBOXMATLABDIR/specgraph/",
    "$TOOLBOXMATLABDIR/graphics/", "$TOOLBOXMATLABDIR/uitools/",
    "$TOOLBOXMATLABDIR/strfun/", "$TOOLBOXMATLABDIR/imagesci/",
    "$TOOLBOXMATLABDIR/iofun/", "$TOOLBOXMATLABDIR/audiovideo/",
    "$TOOLBOXMATLABDIR/timefun/", "$TOOLBOXMATLABDIR/datatypes/",
    "$TOOLBOXMATLABDIR/verctrl/", "$TOOLBOXMATLABDIR/codetools/",
    "$TOOLBOXMATLABDIR/helptools/", "$TOOLBOXMATLABDIR/winfun/",
    "$TOOLBOXMATLABDIR/winfun/net/", "$TOOLBOXMATLABDIR/demos/",
    "$TOOLBOXMATLABDIR/timeseries/", "$TOOLBOXMATLABDIR/hds/",
    "$TOOLBOXMATLABDIR/guide/", "$TOOLBOXMATLABDIR/plottools/",
    "toolbox/local/", "$TOOLBOXMATLABDIR/datamanager/", "toolbox/compiler/",
    "toolbox/nnet/nnet/", "toolbox/nnet/nnet/nndistance/",
    "toolbox/nnet/nnet/nnformat/", "toolbox/nnet/nnet/nnnetinput/",
    "toolbox/nnet/nnet/nnprocess/", "toolbox/nnet/nnet/nntopology/",
    "toolbox/nnet/nnet/nntransfer/", "toolbox/nnet/nnet/nnweight/",
    "toolbox/nnet/nnutils/", "toolbox/shared/statslib/", "toolbox/stats/" };

static const char * MCC_Forecaster_classpath_data[] = 
  { "" };

static const char * MCC_Forecaster_libpath_data[] = 
  { "" };

static const char * MCC_Forecaster_app_opts_data[] = 
  { "" };

static const char * MCC_Forecaster_run_opts_data[] = 
  { "" };

static const char * MCC_Forecaster_warning_state_data[] = 
  { "off:MATLAB:dispatcher:nameConflict" };


mclComponentData __MCC_Forecaster_component_data = { 

  /* Public key data */
  __MCC_Forecaster_public_key,

  /* Component name */
  "Forecaster",

  /* Component Root */
  "",

  /* Application key data */
  __MCC_Forecaster_session_key,

  /* Component's MATLAB Path */
  MCC_Forecaster_matlabpath_data,

  /* Number of directories in the MATLAB Path */
  51,

  /* Component's Java class path */
  MCC_Forecaster_classpath_data,
  /* Number of directories in the Java class path */
  0,

  /* Component's load library path (for extra shared libraries) */
  MCC_Forecaster_libpath_data,
  /* Number of directories in the load library path */
  0,

  /* MCR instance-specific runtime options */
  MCC_Forecaster_app_opts_data,
  /* Number of MCR instance-specific runtime options */
  0,

  /* MCR global runtime options */
  MCC_Forecaster_run_opts_data,
  /* Number of MCR global runtime options */
  0,
  
  /* Component preferences directory */
  "Forecaster_F7B41948E86597261EC33BF0C730F691",

  /* MCR warning status data */
  MCC_Forecaster_warning_state_data,
  /* Number of MCR warning status modifiers */
  1,

  /* Path to component - evaluated at runtime */
  NULL

};

#ifdef __cplusplus
}
#endif


