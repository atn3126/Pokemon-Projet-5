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
    
    if (!this->texture.loadFromFile("texture/map.png"))
    {
        std::cout << "erreur d'image" << std::endl;
        return EXIT_FAILURE;
    }
}


sf::Sprite Playground::GetSprite()
{
    this->sprite.setTexture(this->texture);
    return this->sprite;
}
