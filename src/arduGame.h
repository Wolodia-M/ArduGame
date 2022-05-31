// Maybe this file is main
// Detect architecture
#if defined(ESP32)
#else
#error "Board unsapported"  //compile only if board chip is ESP32
#endif
// Libs
#include <TFT_eSPI.h> //tft lib
#include <btnapi.h>   //lib for buttons
#include "FS.h"
#include "SD.h"
// Parts
#include "embeded_libs/Tone.h" //tone implementation
// Defines
#define PYEZO 12 // pin for pyezospeaker
// DEBUG / NODEBUG
#define DEBUG
// MUS_POINTER_DEBUG, MUS_DEBUG, BUTTONS_DEBUG
#define BUTTONS_DEBUG
// Typeedefs
typedef struct{
    int progID;
    String progName;
} prog_init_t;
// Buttons
 btnapi start_b(13);
 btnapi select_b(15);
// Objects
TFT_eSPI tft = TFT_eSPI();              // display
toneAPI tn((uint8_t)PYEZO, (uint8_t)0); // pyezospeaker
#include "embeded_libs/soundAPI.h"  //api for sounds
soundAPI sapi;
// files
#include "embeded_libs/music/music.h"
#include "GUI.h"
#include "grafick.h"
// OS
#include "os/os.h"
ARDUGAMEOS OS;
// Apps
#include "apps/dummy.h"