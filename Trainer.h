#pragma once
#include <iostream>
#include <string>
#include "const.h"
#include <SFML/Graphics.hpp>


class Trainer
{
public:
	Trainer(std::string nom_texture, int x, int y);
	~Trainer();
	void deplacer(int x, int y);
	sf::Sprite sprite();

	int x;
	int y;

private:
	sf::Texture texture_trainer;
	sf::Sprite sprite_trainer;

};