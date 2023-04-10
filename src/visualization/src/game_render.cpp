#include <SDL2/SDL.h>
#include "rclcpp/rclcpp.hpp"
#include "visualization/Pong_field.hpp"
#include "visualization/SDL2_UI.hpp"


class GameRender : public rclcpp::Node
{
public:
  GameRender()
  : Node("GameRender")
  {
        Pong_field field;
    
    int frameCounter = 0;
    bool quit = false;

    while (!quit) {
        frameCounter++;
        //if (frameCounter>=1000){
        //    frameCounter = 0;
        //}

        // Update the positions of the objects
        field.setYBatLeft(frameCounter);
        field.setYBatRight(100-frameCounter);
        field.setXYBall(frameCounter,frameCounter/2);

        // Update the text
        if (frameCounter%100==0) {
            // No need to set the values each time you call DrawField
            if (frameCounter==800) {
                // Any text
                //field.setFieldText(std::string("Game Over"));     //Game over screen after 800 frames
            } else if (frameCounter==900)
            {
                // Show no text
                //field.setFieldText(std::string(""));              //Flicker at 900 frames (100 frames after Game over screen)
            } else {
                // Show score
                //field.setFieldText(std::to_string(frameCounter/100)+ std::string(" - 0"));  //Counter for score
                field.setFieldText(std::string("0 - 0"));
            }
        }

        // Show it on the screen
        field.DrawField();

        // We regularly need to let SDL process windows events such as mouse presses and keyboard presses
        // (even if they are not used; there are also windows events 'under water' that *are* used).
        // The function .processEvents() that does that also tells us if the user has pressed the quit button.
        bool wantsToQuit;
        wantsToQuit = field.sdl2_ui.processEvents();
        if (wantsToQuit)
        {
            quit = true;
        }
    }

  }
};