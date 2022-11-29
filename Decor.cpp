#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Decor.h"

Decor::Decor(std::string nom_texture, bool have_collision, int x, int y)
{
    this->collision = have_collision;
    if (!this->texture_decor.loadFromFile(nom_texture))
    {
        std::cout << "Erreur de chargement de la texture du decor" << std::endl;
    }
    this->sprite_decor.setTexture(this->texture_decor);
    this->sprite_decor.setScale(0.20f,0.20f);

    sprite_decor.setPosition(sf::Vector2f(x, y));
}
Decor::~Decor()
{

}
void Decor::new_emplacement(int x, int y)
{

}
void Decor::change_collision(bool have_collision)
{

}
void Decor::change_texture(char new_sprite)
{
    switch (new_sprite)
    {
        case 'h':
            this->sprite_decor.setTextureRect(sf::IntRect(0, 15, 15, 15));

        case 'a':
            this->sprite_decor.setTextureRect(sf::IntRect(0, 45, 30, 45));

    default:
        break;
    }
    
}

sf::Sprite Decor::sprite()
{
    return this->sprite_decor;
}