#include <Arduboy2.h>

void title() {

    counter++;
    #ifdef SOUNDS
        if (soundCounter > 0) soundCounter--;
    #endif

    Sprites::drawOverwrite(0, 0, Images::Title, 0);

    if((counter >= 60) && (counter <= 71))
    {
        uint8_t eyeFrame = 0;

        if(counter >= 64)
            eyeFrame = 1;
        else if(counter >= 68)
            eyeFrame = 2;

        Sprites::drawOverwrite(81, 18, Images::Title_Eyes, eyeFrame);
    }

    if(counter == 120)
        counter = 0;

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
