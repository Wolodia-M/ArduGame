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
/*   SD, unused now
    #define SD_MISO 27
    #define SD_MOSI 26
    #define SD_SCK 25
    #define SD_CS 33
*/
#define PYEZO 13 // pin for pyezospeaker
#define DEBUG
uint8_t arr[] = {1, 5, 6, 100, 200, 20};
// Objects
TFT_eSPI tft = TFT_eSPI();              // display
toneAPI tn((uint8_t)PYEZO, (uint8_t)0); // pyezospeaker
#include "embeded_libs/soundAPI.h"  //api for sounds
soundAPI sapi;
// Buttons
// btnapi up(13);
// btnapi down(12);
//змінні

// files
#include "GUI.h"
#include "grafick.h"
