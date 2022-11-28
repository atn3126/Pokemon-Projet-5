#include "Menu.h"


Menu::Menu()
{
   
}

Menu::~Menu()
{
}

int Menu::loadMenu()
{
    if (!this->texture.loadFromFile("MainMenu.png"))
    {
        std::cout << "erreur d'image" << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

sf::Sprite Menu::GetSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.setScale();
    return this->sprite;
}

bool Menu::start()
{
    return false;
}
