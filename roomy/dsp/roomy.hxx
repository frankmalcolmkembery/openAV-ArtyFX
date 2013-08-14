
#ifndef OPENAV_ROOMY
#define OPENAV_ROOMY

#include "lv2/lv2plug.in/ns/lv2core/lv2.h"

#define ROOMY_URI    "http://www.openavproductions.com/artyfx#roomy"
#define ROOMY_UI_URI "http://www.openavproductions.com/artyfx#roomy/gui"

typedef enum
{
  ROOMY_INPUT_L = 0,
  ROOMY_INPUT_R,
  
  ROOMY_OUTPUT_L,
  ROOMY_OUTPUT_R,
  
  ROOMY_TIME,
  ROOMY_DAMPING,
  ROOMY_DRY_WET,
} PortIndex;

#endif // OPENAV_ROOMY
