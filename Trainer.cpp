#include "Trainer.h"


Trainer::Trainer(std::string nom_texture, int i, int j)
{
    this->x = i * SIZE_TILE;
    this->y = j * SIZE_TILE;

    if (!this->texture_trainer.loadFromFile(nom_texture))
    {
        std::cout << "Erreur de chargement de la texture de l'entraineur" << std::endl;
    }

    this->sprite_trainer.setTexture(this->texture_trainer);
    this->sprite_trainer.setScale( 0.85f, 0.80f);
    this->deplacer(this->x, this->y);
}
Trainer::~Trainer()
{

}
void Trainer::deplacer(int i, int j)
{
    this->sprite_trainer.setPosition(i, j);

}
sf::Sprite Trainer::sprite()
{
    return this->sprite_trainer;
}
