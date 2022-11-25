#pragma once
#include <iostream>
#include <string>



class Decor
{
	public:
		Decor(std::string nom_texture,bool have_collision,int x, int y);
		~Decor();

		void new_emplacement(int x, int y);
		void change_collision(bool have_collision);
		sf::Sprite sprite();

	private:
		sf::Texture texture_decor;
		sf::Sprite sprite_decor;
		bool collision;
		int x;
		int y;

};