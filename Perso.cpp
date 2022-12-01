#include "Perso.h"

Perso::Perso(std::string nom_texture, int i, int j)
{
    this->x = i * SIZE_TILE;
    this->y = j * SIZE_TILE;
    this->last = 'd';
    if (!this->texture_perso.loadFromFile(nom_texture))
    {
        std::cout << "Erreur de chargement de la texture du personnage" << std::endl;
    }
    this->sprite_perso.setTexture(this->texture_perso);
    this->sprite_perso.setScale(sf::Vector2f(1.0f, 1.0f));
    this->sprite_perso.setPosition(x, y);
    this->sprite_perso.setTextureRect(sf::IntRect(30, 0, 30, 30));
    std::cout << this->walls[5];
}
Perso::~Perso()
{

}
void Perso::move()
{
    if (sf::Keyboard::isKeyPressed) //si n'importe quel touche est appuyé
    {
        std::cout << (this->x / 32) + (this->y / 32 * 60) << std::endl;
        if (this->x - SIZE_TILE > -SIZE_TILE && this->walls[(this->x / 32) + (this->y / 32 * 60) - 1] == 0)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {

                this->x -= SPEED;
                this->sprite_perso.setPosition(sf::Vector2f(x, y));
                this->last = this->animation('l');

            }
        }


        if (this->x + SIZE_TILE < WINDOW_SIZE_X && this->walls[(this->x / 32) + (this->y / 32 * 60) + 1] == 0)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                // la touche "flèche Droite" est enfoncée : on bouge le personnage a droite
                this->x += SPEED;
                this->sprite_perso.setPosition(sf::Vector2f(x, y));
                this->last = this->animation('r');
            }
        }








        if (this->y + SIZE_TILE < WINDOW_SIZE_Y && this->walls[(this->x / 32) + (this->y / 32 * 60) + 60] == 0)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                // la touche "flèche Bas" est enfoncée : on bouge le personnage en bas
                this->y += SPEED;
                this->sprite_perso.setPosition(sf::Vector2f(x, y));
                this->last = this->animation('d');
            }
        }
        if (this->y - SIZE_TILE > -SIZE_TILE && this->walls[(this->x / 32) + (this->y / 32 * 60) - 60] == 0)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                // la touche "flèche Haut" est enfoncée : on bouge le personnage en haut
                this->y -= SPEED;
                this->sprite_perso.setPosition(sf::Vector2f(x, y));
                this->last = this->animation('u');

            }
        }
    }
    else
    {
        //this->pause(this->last);
    }
    
}

char Perso::animation(char direction)
{
    switch (direction)
    {
    case 'r':   //droite
        this->sprite_perso.setTextureRect(sf::IntRect(0, 64, 30, 30));
        return 'r';
    case 'l':   //gauche
        this->sprite_perso.setTextureRect(sf::IntRect(0, 32, 30, 30));
        return 'l';
    case 'u'://En haut
        this->sprite_perso.setTextureRect(sf::IntRect(0, 96, 30, 30));
        return 'u';
    case 'd':   //En bas
        this->sprite_perso.setTextureRect(sf::IntRect(0, 0, 30, 30));
        return 'd';
    default:    //Regarde devant 
        this->sprite_perso.setTextureRect(sf::IntRect(30, 0, 30, 30));
        return 'd';
    }
}
char Perso::pause(char last_direction)
{
    switch (last_direction)
    {
    case 'r':   //regarde a droite
        this->sprite_perso.setTextureRect(sf::IntRect(30, 64, 30, 30));
        return 'r';
    case 'l':   //regarde a gauche
        this->sprite_perso.setTextureRect(sf::IntRect(30, 32, 30, 30));
        return 'l';
    case 'u':   //regarde en haut
        this->sprite_perso.setTextureRect(sf::IntRect(30, 96, 30, 30));
        return 'u';
    case 'd':   //regarde en bas
        this->sprite_perso.setTextureRect(sf::IntRect(30, 0, 30, 30));
        return 'd';
    default:    //Regarde en bas 
        this->sprite_perso.setTextureRect(sf::IntRect(30, 0, 30, 30));
        return 'd';
    }
}

sf::Sprite Perso::sprite()
{
    return this->sprite_perso;
}