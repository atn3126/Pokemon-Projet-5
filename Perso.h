#pragma once
#include <iostream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "const.h"

class Perso
{
	public:
		Perso(std::string nom_texture, int x, int y);
		~Perso();

		void move();
		char animation(char direction);
		char pause(char last_direction);
		char last;
		int x;
		int y;
		
		sf::Sprite sprite();

	private:
		sf::Texture texture_perso;
		sf::Sprite sprite_perso;


};