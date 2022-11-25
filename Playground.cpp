#include "Playground.h"
#include "macro.h"

Playground::Playground()
{
   
}

Playground::~Playground()
{
}

int Playground::load()
{
    
    if (!this->texture.loadFromFile("tile.png"))
    {
        std::cout << "erreur d'image" << std::endl;
        return EXIT_FAILURE;
    }
}


sf::Sprite Playground::GetSprite(int i, int j)
{
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(0.4f, 0.4f);
    this->sprite.setPosition(i * SIZE_TILE, j * SIZE_TILE);
    return this->sprite;
}
