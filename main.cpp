#include "Playground.h"
#include "Perso.h"
#include "const.h"
#include "Decor.h"
#include "Decor_Tile.h"
#include "Interaction.h"
#include "Game.h"
#include "Trainer.h"
#include "Menu.h"

#include <iostream>
#include <SFML/Graphics.hpp>


/*
texture.setRepeated(true);
sf::Sprite sprite;
sprite.setTexture(texture);
//sprite.setTextureRect(sf::IntRect(100, 100, 320, 320));       //affiche une certaine zone de la texture

sprite.setColor(sf::Color(255, 255, 255, 128));                 //couleur (actuellement transparence)
sprite.setScale(sf::Vector2f(0.5f, 0.5f));                      //taille de la texture
sprite.setPosition(sf::Vector2f(10.f, 50.f));                   //Position de la texture
sprite.setOrigin(sf::Vector2f(25.f, 25.f));                     //change le point d'origine de la texture
*/


int main()
{
    //RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Main Menu", Style::Default);
    MainMenu mainMenu;
    bool start = false;

    RectangleShape background;
    background.setSize(Vector2f(WINDOW_SIZE_X, WINDOW_SIZE_Y));
    Texture Maintexture;
    Maintexture.loadFromFile("texture/Background.Jfif");
    background.setTexture(&Maintexture);

    RectangleShape Titre;
    Titre.setSize(Vector2f(WINDOW_SIZE_X * 2 / 3, 200));
    Titre.setPosition(WINDOW_SIZE_X / 6, 50.f);
    Texture TextureTitre;
    TextureTitre.loadFromFile("texture/Titre.png");
    Titre.setTexture(&TextureTitre);


    while (window.isOpen())
    {
        window.clear();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::Up)
                {
                    mainMenu.MoveUp();
                    break;
                }

                if (event.key.code == Keyboard::Down)
                {
                    mainMenu.MoveDown();
                    break;
                }

                if (event.key.code == Keyboard::Return)
                {
                    
                    

                    int x = mainMenu.MainMenuPressed();
                    if (x == 0)
                    {
                        RenderWindow Play(VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Pokemon");
                        window.close();
                        while (Play.isOpen())
                        {
                            Playground pg;
                            Play.setFramerateLimit(60);


                            pg.load();

                            Perso poke("texture/trainer.png", 6, 16);
                            Trainer trainer("texture/trainer_adv.png", 5, 5);
                            Decor rock1("texture/pokemon_rock.png", false, 300, 300);
                            Decor_Tile herbe1('h', false, 20, 16);
                            Decor_Tile arbre1('a', false, 8, 4);





                            sf::Clock clock;
                            while (Play.isOpen())
                            {
                                sf::Event event;
                                while (Play.pollEvent(event))
                                {

                                    switch (event.type)
                                    {
                                    case sf::Event::Closed:
                                        Play.close();
                                        break;

                                    case sf::Event::KeyPressed:
                                        clock.restart();

                                        poke.move();

                                        break;

                                    default:
                                        poke.pause(poke.last);
                                        break;

                                    }
                                }
                                sf::Sprite perso_sprite = poke.sprite();
                                sf::Sprite trainer_sprite = trainer.sprite();
                                sf::Sprite rock1_sprite = rock1.sprite();
                                sf::Sprite herbe1_sprite = herbe1.sprite();
                                sf::Sprite arbre1_sprite = arbre1.sprite();

                                sf::FloatRect perso_box = perso_sprite.getGlobalBounds();
                                sf::FloatRect rock1_box = rock1_sprite.getGlobalBounds();


                                Play.clear();
                                                                        
                                Play.draw(pg.GetSprite());
                                if (Interaction(poke, trainer, 2))
                                {
                                    std::cout << "ui";
                                    Play.draw(arbre1_sprite);
                                }


                                Play.draw(herbe1_sprite);
                                Play.draw(trainer_sprite);
                                Play.draw(perso_sprite);
                                Play.draw(rock1_sprite);


                                Play.display();
                            }


                        }
                    }

                    if (x == 1)
                    {
                        RenderWindow Options(VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Options");
                        while (Options.isOpen())
                        {
                            Event aevent;
                            while (Options.pollEvent(aevent))
                            {
                                Event aevent;
                                while (Options.pollEvent(aevent)) {
                                    if (aevent.type == Event::Closed)
                                    {
                                        Options.close();
                                    }
                                    if (aevent.type == Event::KeyPressed)
                                    {
                                        if (aevent.key.code == Keyboard::Escape)
                                        {
                                            Options.close();
                                        }
                                    }
                                }
                                //Play.close();
                                Options.clear();
                                Options.display();
                            }
                        }

                    }
                    if (x == 2)
                    {
                        window.close();
                        break;
                    }

                }
            }
        }

        window.draw(background);
        window.draw(Titre);
        mainMenu.draw(window);
        window.display();
    }

    return 0;
}