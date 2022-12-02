#include "battleSprites.h"

battleSprites::battleSprites(std::string nom_texture1, int i1, int j1, std::string nom_texture2, int i2, int j2)
{
    this->x1 = i1 * SIZE_TILE;
    this->y1 = j1 * SIZE_TILE;

    this->x2 = i2 * SIZE_TILE;
    this->y2 = j2 * SIZE_TILE;

    if (!this->texture_pikachu.loadFromFile(nom_texture1))
    {
        std::cout << "Erreur de chargement de la texture de pikachu" << std::endl;
    }

    if (!this->texture_evoli.loadFromFile(nom_texture2))
    {
        std::cout << "Erreur de chargement de la texture d'e l'entraineur d'evoli" << std::endl;
    }

    this->sprite_pikachu.setTexture(this->texture_pikachu);
    this->sprite_pikachu.setScale(0.75f, 0.70f);
    this->sprite_pikachu.setPosition(x1, y1);

    this->sprite_evoli.setTexture(this->texture_evoli);
    this->sprite_evoli.setScale(0.85f, 0.80f);
    this->sprite_evoli.setPosition(x2, y2);
}
battleSprites::~battleSprites()
{

}

sf::Sprite battleSprites::pikachu()
{
    return this->sprite_pikachu;
}

sf::Sprite battleSprites::evoli()
{
    return this->sprite_evoli;
}
