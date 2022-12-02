#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#define Max_attack 4

class Battle
{
	public :

		Battle();
		void reload();
		int load();
		void draw(sf::RenderWindow& window);
		void MoveUp();
		void MoveDown();
		void pikachuAttack();
		void evoliAttack(int x);
		sf::Sprite GetSprite();
		int GetevoliLife();
		int GetpikachuLife();
		int AttackPressed() {
			return AttackSelected;
		}


	private :
		int pikachuLife = 120;
		int evoliLife = 120;
		int multiplier = 1;
		int AttackSelected;
		sf::Font font;
		sf::Text Attack[Max_attack];
		sf::Texture texture;
		sf::Sprite sprite;

};

