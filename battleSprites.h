#pragma once

#include <iostream>
#include <string>
#include "const.h"
#include <SFML/Graphics.hpp>


class battleSprites
{
public:
	battleSprites(std::string nom_texture1, int x1, int y1, std::string nom_texture2, int x2, int y2);
	~battleSprites();
	sf::Sprite pikachu();
	sf::Sprite evoli();

	int x1;
	int y1;
	int x2;
	int y2;

private:
	sf::Texture texture_pikachu;
	sf::Sprite sprite_pikachu;
	sf::Texture texture_evoli;
	sf::Sprite sprite_evoli;

};