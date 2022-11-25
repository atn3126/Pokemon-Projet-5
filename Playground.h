#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Playground
{
private :

	sf::Texture texture;
	sf::Sprite sprite;

public :

	Playground();
	~Playground();
	int load();
	sf::Sprite GetSprite(int i, int j);

};

