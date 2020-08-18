#include "src/utils/Arduboy2Ext.h"
#include <ArduboyTones.h>
#include "src/images/Images.h"
#include "src/utils/Consts.h"
#include "src/utils/EEPROM_Utils.h"
#include "src/entities/Entities.h"
#include "src/sounds/Sounds.h"

Arduboy2Ext arduboy;

#ifdef SOUNDS
    ArduboyTones sound(arduboy.audio.enabled);
#endif

Player player;
Catcher catcher;
Oils oils;

GameState gameState = GameState::Splash_Init;
GameMode gameMode = GameMode::Easy;
GameScene gameScene = GameScene::Indoors;

int16_t counter = 10;
uint8_t frameRate = 50;
uint16_t score = 0;
uint8_t numberOfLives_Indoors = 3;
uint8_t numberOfLives_Outdoors = 3;
uint8_t outdoorsYOffset = 0;
uint8_t gameOverCounter = 0;

bool gameOver = false;
ThrowOil throwOil = ThrowOil::None;


#ifdef SOUNDS
    uint8_t soundCounter = 0;
    bool sounds = arduboy.audio.enabled();
#endif

void setup(void) {

	arduboy.boot();
	arduboy.flashlight();
	arduboy.systemButtons();

    #ifdef SOUNDS    
	    arduboy.audio.begin();
    #endif

	arduboy.initRandomSeed();
	arduboy.setFrameRate(40);
    arduboy.setRGBled(0, 0, 0);

    EEPROM_Utils::initEEPROM();
	
}

void loop(void) {

	if (!arduboy.nextFrame()) return;

	arduboy.pollButtons();

    switch (gameState) {

        case GameState::Splash_Init:

            splashScreen_Init();
            gameState = GameState::Splash;
            [[fallthrough]]

        case GameState::Splash:

            splashScreen();
            arduboy.display();
            break;

        case GameState::Title_Init:

            gameState = GameState::Title;

            #ifdef SOUNDS
                soundCounter = 0;
//                sound.tones(Sounds::Title);
            #endif
            [[fallthrough]]

        case GameState::Title:

            title();
            arduboy.displayClearToWhite();
            break;

        case GameState::PlayGame_Init:

            playGame_Init();
            [[fallthrough]]

        case GameState::PlayGame:

            playGame();

            if (frameRate != 40 + (score / 8)) {
                frameRate = 40 + (score / 8);
                arduboy.setFrameRate(frameRate);
            }
            arduboy.displayClearToWhite();
            break;

    }


}

