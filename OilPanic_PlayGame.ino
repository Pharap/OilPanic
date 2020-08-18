#include <Arduboy2.h>



// ----------------------------------------------------------------------------
//  Initialise game ..
//
void playGame_Init() {

    lifeReset();

    arduboy.setFrameRate(50);
    
    gameState = GameState::PlayGame;
    frameRate = 50;
    score = 0;
    numberOfLives_Indoors = 3;
    numberOfLives_Outdoors = 3;

}


// ----------------------------------------------------------------------------
//  Reset life at start of game and after each death ..
//
void lifeReset() {

    counter = 10;
    outdoorsYOffset = 0;
    gameOverCounter = 0;

}


// ----------------------------------------------------------------------------
//  Update game and render ..
//
void playGame(void) {

    uint8_t justPressedButton = arduboy.justPressedButtons();


    if (gameOverCounter > 0) {
        gameOverCounter--;
    }


    // Update entity positions ..

    if (!gameOver && arduboy.isFrameCount(8)) {
        
        catcher.update();

    }

    if (arduboy.isFrameCount(2)) {

        if (updateThrowOil(throwOil)) {

            gameOver = true;
            gameOverCounter = 32;

        }

    }

    switch (gameScene) {

        case GameScene::Indoors:

            for (uint8_t x = 0; x < Constants::number_Of_Oils; x++) {

                Oil &oil = oils.getOil(x);

                switch (oil.getYPosition()) {

                    case YPosition::StartDrip_00 ... YPosition::Falling_13:

                        if (arduboy.isFrameCount(6)) {

                            if (oil.update()) {

                                numberOfLives_Indoors--;

                                if (numberOfLives_Indoors == 0) {

                                    gameOver = true;
                                    gameOverCounter = 32;

                                }

                            }

                        }
                        break;

                    case YPosition::Fire_00 ... YPosition::Fire_07:

                        if (arduboy.isFrameCount(2)) {

                            oil.update();

                        }
                        break;


                }

            }

            if (!gameOver) {

                if (arduboy.isFrameCount(96)) {

                    oils.launchOil(random(0,3));
                    
                }

                if (arduboy.isFrameCount(2)) {

                    player.update();

                }

                if (justPressedButton & LEFT_BUTTON)               { player.decXPosition(); }
                if (justPressedButton & RIGHT_BUTTON)              { player.incXPosition(); }

            }


            // Change scene?

            if (player.getXPosition() == XPosition::Position_Outside_LH || player.getXPosition() == XPosition::Position_Outside_RH) {

                gameScene = GameScene::Outdoors;
                throwOil = ThrowOil::None;

            }


            // Did we catch some oil ?

            switch (player.getXPosition()) {

                case XPosition::Position_5_Oil:
                case XPosition::Position_10_Oil:
                case XPosition::Position_15_Oil:
                    catchOil(player.getXPosition());
                    break;

                default: break;

            }


            break;

        case GameScene::Outdoors:

            if (!gameOver) {

                if (justPressedButton & LEFT_BUTTON) {

                    switch (player.getXPosition()) {
                        
                        case XPosition::Position_Outside_LH:

                            if (catcher.isCatching(Direction::Left)) {

                                score = score + player.getOilLevel();

                            }

                            if (throwOil == ThrowOil::None && player.getOilLevel() > 0) throwOil = ThrowOil::LH_Top;
                            player.setXPosition(XPosition::Position_Throwing_LH);
                            player.setOilLevel(0);
                            break;

                        case XPosition::Position_Throwing_RH:
                            player.setXPosition(XPosition::Position_Outside_RH);
                            break;

                        case XPosition::Position_Outside_RH:
                            gameScene = GameScene::Indoors; 
                            player.decXPosition();
                            break;

                        default: break;

                    }

                }

                if (justPressedButton & RIGHT_BUTTON) { 

                    switch (player.getXPosition()) {
                        
                        case XPosition::Position_Outside_RH:

                            if (catcher.isCatching(Direction::Right)) {

                                score = score + player.getOilLevel();

                            }

                            if (throwOil == ThrowOil::None && player.getOilLevel() > 0) throwOil = ThrowOil::RH_Top;
                            player.setOilLevel(0);
                            player.setXPosition(XPosition::Position_Throwing_RH);
                            break;

                        case XPosition::Position_Throwing_LH:
                            player.setXPosition(XPosition::Position_Outside_LH);
                            break;

                        case XPosition::Position_Outside_LH:
                            gameScene = GameScene::Indoors; 
                            player.incXPosition();
                            break;

                        default: break;

                    }

                }

            }

            break;

    }



    // --------------------------------------------------------------------------
    //  Render the screen ..

    switch (gameScene) {

        case GameScene::Indoors:

            Sprites::drawOverwrite(0, 0, Images::Indoors, 0);
            renderPlayer_Indoors();
            renderOil();
            renderCatcherMap();
            break;
            

        case GameScene::Outdoors:
    
            for (uint8_t x = 0; x < 13; x++) {

                Sprites::drawOverwrite(0, 0 - outdoorsYOffset + (x * 8), Images::Outdoors, x);

            }

            renderPlayer_Outdoors(outdoorsYOffset);
            renderThrowingOil(outdoorsYOffset);
            renderCatcher(outdoorsYOffset);
            renderBystanders(outdoorsYOffset);
            break;

    }

    renderScoreboard(gameScene);


    // Game over ?

    if (gameOver && gameOverCounter == 0) {

        Sprites::drawExternalMask(34, 24, Images::GameOver, Images::GameOver_Mask, 0, 0);

    }

}


void catchOil(XPosition xPosition) {

    for (uint8_t x = 0; x < Constants::number_Of_Oils; x++) {

        Oil &oil = oils.getOil(x); 

        if (oil.getYPosition() != YPosition::None && oil.getXPosition() == xPosition) {

            switch (oil.getYPosition()) {

                case YPosition::Falling_08 ... YPosition::Falling_11:
                    if (player.incOilLevel()) {
                        oil.setYPosition(YPosition::None);
                    }
                    break;

                default: break;
                
            }
 
        }       

    }

}



bool updateThrowOil(ThrowOil &throwOil) {

    switch (throwOil) {

        case ThrowOil::LH_Top:
            throwOil++;
            break;

        case ThrowOil::LH_Middle:
            if (catcher.isCatching(Direction::Left)) {
                throwOil = ThrowOil::LH_Bottom;
            }
            else {
                throwOil = ThrowOil::LH_Miss_Down_Start;
            }
            break;
            
        case ThrowOil::LH_Bottom:
            throwOil = ThrowOil::None;
            break;

        case ThrowOil::LH_Miss_Down_Start ... ThrowOil::LH_Miss_Down_End:
            
            throwOil++;
            outdoorsYOffset = outdoorsYOffset + 4;
            
            if (throwOil == ThrowOil::LH_Miss_Bottom_Start) {
            
                numberOfLives_Outdoors--;

                if (numberOfLives_Outdoors == 0) {

                    return true;
                    
                }

            }
            break;

        case ThrowOil::LH_Miss_Bottom_Start ... ThrowOil::LH_Miss_Bottom_End:
            throwOil++;
            break;

        case ThrowOil::LH_Miss_Up_Start ... ThrowOil::LH_Miss_Up_NearlyEnd:
            if (!gameOver) {
                throwOil++;
                outdoorsYOffset = outdoorsYOffset - 4;
            }
            break;

        case ThrowOil::RH_Top:
            throwOil++;
            break;

        case ThrowOil::RH_Middle:
            if (catcher.isCatching(Direction::Right)) {
                throwOil = ThrowOil::RH_Bottom;
            }
            else {
                throwOil = ThrowOil::RH_Miss_Down_Start;
            }
            break;
            
        case ThrowOil::RH_Bottom:
            throwOil = ThrowOil::None;
            break;

        case ThrowOil::RH_Miss_Down_Start ... ThrowOil::RH_Miss_Down_End:

            throwOil++;
            outdoorsYOffset = outdoorsYOffset + 4;

            if (throwOil == ThrowOil::RH_Miss_Bottom_Start) {
                            
                numberOfLives_Outdoors--;

                if (numberOfLives_Outdoors == 0) {

                    return true;
                    
                }

            }

            break;

        case ThrowOil::RH_Miss_Bottom_Start ... ThrowOil::RH_Miss_Bottom_End:
            throwOil++;
            break;

        case ThrowOil::RH_Miss_Up_Start ... ThrowOil::RH_Miss_Up_NearlyEnd:
            if (!gameOver) {
                throwOil++;
                outdoorsYOffset = outdoorsYOffset - 4;
            }
            break;

    }

    return false;

}