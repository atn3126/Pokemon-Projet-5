#include "Playground.h"
#include "const.h"

Playground::Playground()
{
   
}

Playground::~Playground()
{
}

int Playground::load()
{
    
    if (!this->texture.loadFromFile("texture/poke_tile.png"))
    {
        std::cout << "erreur d'image" << std::endl;
        return EXIT_FAILURE;
    }
}


sf::Sprite Playground::GetSprite(int i, int j)
{
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 15, 15));
    this->sprite.setScale(2.0f, 2.0f);
    this->sprite.setPosition(i * SIZE_TILE, j * SIZE_TILE);
    return this->sprite;
}
