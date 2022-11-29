#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Decor_Tile.h"

Decor_Tile::Decor_Tile(char nom_texture, bool have_collision, int x, int y)
{
    this->collision = have_collision;

    if (!this->texture_decor.loadFromFile("texture/poke_tile.png"))
    {
        std::cout << "Erreur de chargement de la texture du decor" << std::endl;
    }

    this->sprite_decor.setTexture(this->texture_decor);
    this->sprite_decor.setScale(2.0f, 2.0f);


    switch (nom_texture)
    {
    case 'a':
        this->sprite_decor.setTextureRect(sf::IntRect(63, 2, 33, 47));
        break;
    case 'h':
        this->sprite_decor.setTextureRect(sf::IntRect(15, 0, 17, 15));
        break;
    default:
        break;
    }
    sprite_decor.setPosition(sf::Vector2f(x * 30, y * 30));
}
Decor_Tile::~Decor_Tile()
{

}
void Decor_Tile::new_emplacement(int x, int y)
{
    sprite_decor.setPosition(sf::Vector2f(x * 30, y * 30));
}
void Decor_Tile::change_collision(bool have_collision)
{

}
void Decor_Tile::change_texture(char new_sprite)
{

}
sf::Sprite Decor_Tile::sprite()
{
    return this->sprite_decor;
}