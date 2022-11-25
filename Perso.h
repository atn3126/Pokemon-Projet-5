#pragma once
#include <iostream>
#include <string>

#include "const.h"

class Perso
{
	public:
		Perso(std::string nom_texture);
		~Perso();

		void move();
		char animation(char direction);
		char pause(char last_direction);
		char last;

		sf::Sprite sprite();

	private:
		sf::Texture texture_perso;
		sf::Sprite sprite_perso;
		int x;
		int y;
		

};