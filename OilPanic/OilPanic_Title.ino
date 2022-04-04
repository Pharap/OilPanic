#include <Arduboy2.h>

void title() {

    counter++;
    #ifdef SOUNDS
        if (soundCounter > 0) soundCounter--;
    #endif

    Sprites::drawOverwrite(0, 0, Images::Title, 0);

    uint8_t eyeFrame = 0;

    switch (counter) {

        case 60 ... 63:
            eyeFrame = 0;
            break;

        case 64 ... 67:
            eyeFrame = 1;
            break;

        case 68 ... 71:
            eyeFrame = 2;
            break;


        case 120:
            counter = 0;
            break;
    }

    if((counter >= 60) && (counter <= 71))
        Sprites::drawOverwrite(81, 18, Images::Title_Eyes, eyeFrame);

    if (arduboy.justPressed(A_BUTTON)) { 

        gameState = GameState::Instructions_Init;

    }

    if (arduboy.justPressed(B_BUTTON)) { 

        score = 0;
        gameState = GameState::HighScore_Init;

    }

    #ifdef SOUNDS

        if (arduboy.justPressed(UP_BUTTON) || arduboy.justPressed(DOWN_BUTTON)) {
            soundsOnOff = EEPROM_Utils::toggleSoundSettings(arduboy);
            soundCounter = 32;
        }

        if (soundCounter > 0) {
            Sprites::drawOverwrite(116, 54, Images::Sound, !soundsOnOff);
        }

    #endif

}
