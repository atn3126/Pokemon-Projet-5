#include "Interaction.h"


bool Interaction(Perso poke, Trainer trainer, int tile)
{
    sf::Texture texture;
    sf::Sprite sprite;
    if (!texture.loadFromFile("texture/main_interagir.png"))
    {
        std::cout << "Erreur de chargement de la texture de la main" << std::endl;
    }
    sprite.setPosition(WINDOW_SIZE_X / 2 - (SIZE_TILE * 4), WINDOW_SIZE_Y - (SIZE_TILE * 9));
    sprite.setScale(1.0f, 1.0f);
    sprite.setTexture(texture);

    if (poke.x > trainer.x - tile * SIZE_TILE && poke.x < trainer.x + tile * SIZE_TILE && poke.y > trainer.y - tile * SIZE_TILE&& poke.y < trainer.y + tile * SIZE_TILE)
    {
        
        window.draw(sprite);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
             return 1;
        }

    }
    return 0;
}
