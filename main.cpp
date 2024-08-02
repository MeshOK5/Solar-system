#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <string>
#include "Planets.h"

using namespace std;
using namespace sf;

int main()
{
    srand(time(NULL));

    int scrX = GetSystemMetrics(SM_CXSCREEN);
    int scrY = GetSystemMetrics(SM_CYSCREEN);

    bool pressed = false;
    bool TS = false;

    bool NoGui_state = false;

    RenderWindow window(VideoMode(scrX, scrY), "Solar system", Style::Fullscreen);
    window.setVerticalSyncEnabled(true);

    CircleShape sun(100.f), merk(3), vener(6), earth(10), moon(4), mars(6), jupiter(30), saturn(25), uran(20), neptune(22);

    Vector2f centerPos = Vector2f(window.getSize().x / 2, window.getSize().y / 2);
    float x = centerPos.x - sun.getGlobalBounds().width / 2;
    float y = centerPos.y - sun.getGlobalBounds().height / 2;

    Image icon;
    icon.loadFromFile("Sources/logo.png");
    window.setIcon(32, 32, icon.getPixelsPtr());

    sun.setPosition(x, y);           
    sun.setOrigin(100,100);
    Texture texsun;
    texsun.loadFromFile("Sources/sun.png");
    sun.setTexture(&texsun);

    VertexArray stars(Points, 70);
    for (int i = 0; i < 69; i++) 
    {
        stars[i].color = Color::White;
        stars[i].position = Vector2f(rand() % scrX, rand() % scrY);
    }

    merk.setFillColor(Color(208, 159, 46));

    vener.setFillColor(Color(208, 159, 46));
    vener.setOrigin(3, 3);

    Texture texearth;
    texearth.loadFromFile("Sources/earth.png");
    earth.setTexture(&texearth);
    earth.setOrigin(5, 5);

    moon.setFillColor(Color(51, 51, 48));
    moon.setOrigin(2, 2);

    mars.setFillColor(Color(223, 54, 16));
    mars.setOrigin(2, 2);

    Texture texjupiter;
    texjupiter.loadFromFile("Sources/jupiter.png");
    jupiter.setTexture(&texjupiter);
    jupiter.setOrigin(5, 5);

    Texture texsaturn;
    texsaturn.loadFromFile("Sources/saturn.png");
    saturn.setTexture(&texsaturn);
    saturn.setOrigin(7, 7);

    uran.setFillColor(Color(63, 168, 217));
    uran.setOrigin(2, 2);

    neptune.setFillColor(Color(55, 86, 189));
    neptune.setOrigin(5, 5);

    Font font;
    font.loadFromFile("Sources/font.ttf");

    Text text_logo;
    text_logo.setFont(font);
    text_logo.setCharacterSize(70);
    text_logo.setStyle(Text::Bold);
    text_logo.setFillColor(Color::White);
    text_logo.setString("Solar\nsMESH");
    text_logo.setPosition(50, 50);

    RectangleShape reset(Vector2f(200, 40));
    reset.setFillColor(Color::Black);
    reset.setOutlineColor(Color::White);
    reset.setOutlineThickness(15);
    reset.setPosition(40, 245);

    Text reset_text;
    reset_text.setFont(font);
    reset_text.setCharacterSize(20);
    reset_text.setStyle(Text::Bold);
    reset_text.setFillColor(Color::White);
    reset_text.setString("Reset");
    reset_text.setPosition(50, 255);

    double acceleration = 0;

    Text acceleration_text;
    acceleration_text.setFont(font);
    acceleration_text.setCharacterSize(35);
    acceleration_text.setStyle(Text::Bold);
    acceleration_text.setFillColor(Color::White);
    acceleration_text.setString("Acceleration:(0-6 key)");
    acceleration_text.setPosition(scrX - 700, 50);

    RectangleShape acceleration_button(Vector2f(100, 100));
    acceleration_button.setFillColor(Color::Black);
    acceleration_button.setOutlineColor(Color::White);
    acceleration_button.setOutlineThickness(25);
    acceleration_button.setPosition(scrX - 550, 150);

    Text acceleration_but_text;
    acceleration_but_text.setFont(font);
    acceleration_but_text.setCharacterSize(40);
    acceleration_but_text.setStyle(Text::Bold);
    acceleration_but_text.setFillColor(Color::White);
    acceleration_but_text.setString("0");
    acceleration_but_text.setPosition(scrX - 543, 170);

    RectangleShape timeStop(Vector2f(100, 100));
    timeStop.setFillColor(Color::Black);
    timeStop.setOutlineColor(Color::White);
    timeStop.setOutlineThickness(25);
    timeStop.setPosition(scrX - 550, 350);

    Text timeStop_text;
    timeStop_text.setFont(font);
    timeStop_text.setCharacterSize(40);
    timeStop_text.setStyle(Text::Bold);
    timeStop_text.setFillColor(Color::White);
    timeStop_text.setString("T.S");
    timeStop_text.setPosition(scrX - 550, 370);

    RectangleShape NoGui(Vector2f(200, 40));
    NoGui.setFillColor(Color::Black);
    NoGui.setOutlineColor(Color::White);
    NoGui.setOutlineThickness(15);
    NoGui.setPosition(scrX - 400, scrY - 190);

    Text NoGui_text;
    NoGui_text.setFont(font);
    NoGui_text.setCharacterSize(20);
    NoGui_text.setStyle(Text::Bold);
    NoGui_text.setFillColor(Color::Green);
    NoGui_text.setString("Gui on");
    NoGui_text.setPosition(scrX - 395, scrY - 180);

    Planets merkxy(x, y, 150, -1),venerxy(x, y, 200, -1), earthxy(x, y, 250, -1), marsxy(x, y, 300, -1), jupiterxy(x, y, 400, -1), saturnxy(x, y, 480, -1), uranxy(x, y, 550, -1), neptunexy(x, y, 640, -1);
    Planets moonxy(30, -1);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || event.key.code == Keyboard::Escape)window.close();

            if(event.type == Event::KeyPressed)
            {
                if(pressed == true)
                {
                    switch (event.key.code)
                    {
                    case Keyboard::Num6:
                        acceleration = 6;
                        break;
                    case Keyboard::Num5:
                        acceleration = 5;
                        break;
                    case Keyboard::Num4:
                        acceleration = 4;
                        break;
                    case Keyboard::Num3:
                        acceleration = 3;
                        break;
                    case Keyboard::Num2:
                        acceleration = 2;
                        break;
                    case Keyboard::Num1:
                        acceleration = 1;
                        break;
                    case Keyboard::Num0:
                        acceleration = 0;
                        break;
                    default:
                        break;
                    }
                    acceleration_but_text.setString(to_string(int(acceleration)));
                    pressed = false;
                }
            }
        }

        HWND hWnd = GetConsoleWindow();
        ShowWindow(hWnd, SW_HIDE);

        Vector2i mouse_pos = Mouse::getPosition(window);
        
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            if(timeStop.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
            {
                TS ^= 1;
                sleep(seconds(0.2));
            }

            if(acceleration_button.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
            {
                acceleration_but_text.setString(" ");
                pressed = true;
            }

            if(reset.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
            {
                merkxy.angle = 0;
                venerxy.angle = 0;
                earthxy.angle = 0;
                moonxy.angle = 0;
                marsxy.angle = 0;
                jupiterxy.angle = 0;
                saturnxy.angle = 0;
                uranxy.angle = 0;
                neptunexy.angle = 0;
                sun.setRotation(-1 + acceleration / 10);

                merkxy.isPressed = 0;
                venerxy.isPressed = 0;
                earthxy.isPressed = 0;
                moonxy.isPressed = 0;
                marsxy.isPressed = 0;
                jupiterxy.isPressed = 0;
                saturnxy.isPressed = 0;
                uranxy.isPressed = 0;
                neptunexy.isPressed = 0;
            }

            if(NoGui.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
            {
                NoGui_state ^= 1;
                switch (NoGui_state)
                {
                case 1:
                    NoGui_text.setFillColor(Color::Red);
                    NoGui_text.setString("Gui off");
                    break;
                case 0:
                    NoGui_text.setFillColor(Color::Green);
                    NoGui_text.setString("Gui on");
                    break;
                
                default:
                    break;
                }
                sleep(seconds(0.2));
            }

            if(merk.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))merkxy.isPressed = true;
            if(vener.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))venerxy.isPressed = true;
            if(earth.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))earthxy.isPressed = true;
            if(moon.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))moonxy.isPressed = true;
            if(mars.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))marsxy.isPressed = true;
            if(jupiter.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))jupiterxy.isPressed = true;
            if(saturn.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))saturnxy.isPressed = true;
            if(uran.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))uranxy.isPressed = true;
            if(neptune.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))neptunexy.isPressed = true;
        }

        if(!TS)
        {
            sun.rotate(-1 - acceleration / 10);

            merkxy.move(1 + acceleration / 10);
            merk.setPosition(merkxy.getx(), merkxy.gety());

            venerxy.move(0.5 + acceleration / 10);
            vener.setPosition(venerxy.getx(), venerxy.gety());

            earthxy.move(0.8 + acceleration / 10);
            earth.setPosition(earthxy.getx(), earthxy.gety());
        
            moonxy.setposition(earth.getPosition().x, earth.getPosition().y);
            moonxy.move(3 + acceleration / 10);
            moon.setPosition(moonxy.getx(), moonxy.gety());

            marsxy.move(1.5 + acceleration / 10);
            mars.setPosition(marsxy.getx(), marsxy.gety());

            jupiterxy.move(0.4 + acceleration / 10);
            jupiter.setPosition(jupiterxy.getx(), jupiterxy.gety());

            saturnxy.move(0.25 + acceleration / 10);
            saturn.setPosition(saturnxy.getx(), saturnxy.gety());

            uranxy.move(0.20 + acceleration / 10);
            uran.setPosition(uranxy.getx(), uranxy.gety());

            neptunexy.move(0.16 + acceleration / 10);
            neptune.setPosition(neptunexy.getx(), neptunexy.gety());
        }

        window.clear();

        window.draw(stars);

        window.draw(sun);

        if(!merkxy.isPressed)window.draw(merk);
        if(!venerxy.isPressed)window.draw(vener);
        if(!earthxy.isPressed)window.draw(earth);
        if(!moonxy.isPressed)window.draw(moon);
        if(!marsxy.isPressed)window.draw(mars);
        if(!jupiterxy.isPressed)window.draw(jupiter);
        if(!saturnxy.isPressed)window.draw(saturn);
        if(!uranxy.isPressed)window.draw(uran);
        if(!neptunexy.isPressed)window.draw(neptune);

        if(!NoGui_state)
        {
            window.draw(text_logo);

            window.draw(acceleration_text);
            window.draw(acceleration_button);
            window.draw(acceleration_but_text);

            window.draw(reset);
            window.draw(reset_text);

            window.draw(timeStop);
            window.draw(timeStop_text);
        }

        window.draw(NoGui);
        window.draw(NoGui_text);

        window.display();
    }
    
    return 0;
}