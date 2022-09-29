#include "bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
    // Create a video mode object
    VideoMode vm(1920, 1080);
    // Create and open a window for the game
    RenderWindow window(vm, "Pong", Style::Fullscreen);
    int lives2 = 3;
    int lives = 3;

    // Create a bat at the bottom center of the screen
    Bat bat(20, 1080 / 2);
    Bat batj2(1900, 1802 / 2);
    // Create a ball
    Ball ball(1920 / 2, 5);

    // Create a Text object called HUD
    Text hud;
    // A cool retro-style font
    Font font;
    font.loadFromFile("fonts/JMH Typewriter-Black.ttf");
    // Set the font to our retro-style
    hud.setFont(font);
    // Make it nice and big
    hud.setCharacterSize(75);
    // Choose a color
    hud.setFillColor(Color::White);
    hud.setPosition(20, 20);

    Text comedordeserpientes;
    comedordeserpientes.setFont(font);
    comedordeserpientes.setCharacterSize(75);
    comedordeserpientes.setPosition(1920 / 4, 1080 / 2);
    std::stringstream y;
    y << "PRESS R TO START";
    comedordeserpientes.setString(y.str());


    // Here is our clock for timing everything
    bool sectoragropecuario=true;
    bool oshieteo = true;
    
    Clock clock;

    while (window.isOpen())
    {
        /*
        Handle the player input
        ****************************
        ****************************
        ****************************
        */
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                // Quit the game when the window is closed
                window.close();
        }
        

        // Handle the player quitting
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
       
   
         // Handle the pressing and releasing of the arrow keys
        if (Keyboard::isKeyPressed(Keyboard::R)) {
            sectoragropecuario = !sectoragropecuario;
            comedordeserpientes.setString(y.str());

        }

            if (Keyboard::isKeyPressed(Keyboard::W))
            {
                bat.moveLeft();
            }
            else
            {
                bat.stopLeft();
            }

            if (Keyboard::isKeyPressed(Keyboard::S))
            {
                bat.moveRight();
            }
            else
            {
                bat.stopRight();
            }
            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                batj2.moveLeft();
            }
            else
            {
                batj2.stopLeft();
            }

            if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                batj2.moveRight();
            }
            else
            {
                batj2.stopRight();
            }
            /*
            Update the bat, the ball and the HUD
            *****************************
            *****************************
            *****************************
            */
            
            if (!sectoragropecuario) {
                // Update the delta time
                Time dt = clock.restart();

                bat.update(dt);
                batj2.update(dt);
                ball.update(dt);

                // Update the HUD text
                std::stringstream ss;
                ss << "        vidasj1:" << lives2 << "        vidasj2:" << lives;
                hud.setString(ss.str());

                // Handle ball hitting the bottom
                if (ball.getPosition().left > window.getSize().x)
                {
                    // reverse the ball direction
                    ball.reboundBottom();
                    // Remove a life
                    lives--;
                    // Check for zero lives
                    if (lives < 1) {
                        // reset the score

                        // reset the lives
                        lives = 3;
                        lives2 = 3;
                        sectoragropecuario = !sectoragropecuario;
                        
                        std::stringstream x;
                        x << "player 1 win";
                        comedordeserpientes.setString(x.str());
                        
                    }
                    
                   

                }

                if (ball.getPosition().left < 0)
                {
                    // reverse the ball direction
                    ball.reboundBottom();
                    // Remove a life
                    lives2--;
                    // Check for zero lives
                    if (lives2 < 1) {
                        // reset the score

                        // reset the lives
                        lives = 3;
                        lives2 = 3;
                        sectoragropecuario = !sectoragropecuario;
                        std::stringstream z;
         z << "PLAYER 1 WIN";
                        comedordeserpientes.setString(z.str());

                        
                        
                       
                    }

                }

                // Handle ball hitting top
                if (ball.getPosition().top < 0 || ball.getPosition().top + ball.getPosition().height>1080)
                {
                    ball.reboundBatOrTop();
                    // Add a point to the players score
                    ;
                }


                // Handle ball hitting sides


                // Has the ball hit the bat?
                if (ball.getPosition().intersects(bat.getPosition()) || ball.getPosition().intersects(batj2.getPosition()))
                {
                    // Hit detected so reverse the ball and score a point
                    ball.reboundSides();
                }
            }
        
        /*
        Draw the bat, the ball and the HUD
        *****************************
        *****************************
        *****************************
        */
        window.clear();
        if (sectoragropecuario) {
            window.draw(comedordeserpientes);
        }
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.draw(batj2.getShape());

        window.display();
    }
    return 0;
}