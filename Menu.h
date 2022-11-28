#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Menu
{
	public:
		Menu();
		~Menu();
		int loadMenu();
		sf::Sprite GetSprite();
		bool start();
	private:
		sf::Texture texture;
		sf::Sprite sprite;

};