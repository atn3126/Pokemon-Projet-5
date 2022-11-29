#include "Playground.h"
#include "Perso.h"
#include "const.h"
#include "Decor.h"
#include "Decor_Tile.h"
#include "Interaction.h"
#include "Game.h"
#include "Trainer.h"

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
    Playground pg;
    window.setFramerateLimit(60);


    pg.load();

    Perso poke("texture/trainer.png", 2 , 2);
    Trainer trainer("texture/trainer_adv.png", 5 , 5);
    Decor rock1("texture/pokemon_rock.png", false, 300, 300);
    Decor_Tile herbe1('h', false, 20, 16);
    Decor_Tile arbre1('a', false, 8, 4);


    sf::Texture texture;
    sf::Sprite sprite_main;
    if (!texture.loadFromFile("texture/main_interaction.png"))
    {
        std::cout << "Erreur de chargement de la texture de la main" << std::endl;
    }
    sprite_main.setTexture(texture);








    sf::Clock clock;    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
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

        
        window.clear();
        for (int i = 0; i < WINDOW_SIZE_Y / SIZE_TILE; i++) {
            for (int j = 0; j < WINDOW_SIZE_X / SIZE_TILE; j++) {
                window.draw(pg.GetSprite(i, j));
            }
        }
        if (Interaction(poke, trainer, 2))
        {
            std::cout << "ui";
            window.draw(arbre1_sprite);
        }

        
        window.draw(herbe1_sprite);
        window.draw(trainer_sprite);
        window.draw(perso_sprite);
        window.draw(rock1_sprite);
        
        
        window.display();
    }

    return 0;
}