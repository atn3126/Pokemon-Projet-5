#include "Battle.h"

Battle::Battle()
{
}

void Battle::reload()
{
	pikachuLife = 120;
	evoliLife = 120;
	multiplier = 1;
}

int Battle::load()
{
	if (!font.loadFromFile("font/PKMN RBYGSC.ttf")) {
		std::cout << "error";
	}

    if (!this->texture.loadFromFile("texture/battle.png"))
    {
        std::cout << "erreur d'image" << std::endl;
        return EXIT_FAILURE;
    }

	Attack[0].setFont(font);
	Attack[0].setFillColor(sf::Color::Black);
	Attack[0].setString("Attack 1");
	Attack[0].setCharacterSize(30);
	Attack[0].setPosition(740, 660);

	Attack[1].setFont(font);
	Attack[1].setFillColor(sf::Color::Black);
	Attack[1].setString("Attack 2");
	Attack[1].setCharacterSize(30);
	Attack[1].setPosition(740, 740);

	Attack[2].setFont(font);
	Attack[2].setFillColor(sf::Color::Black);
	Attack[2].setString("Attack 3");
	Attack[2].setCharacterSize(30);
	Attack[2].setPosition(740, 820);

	Attack[3].setFont(font);
	Attack[3].setFillColor(sf::Color::Black);
	Attack[3].setString("Buff");
	Attack[3].setCharacterSize(30);
	Attack[3].setPosition(740, 900);

	AttackSelected = 0;
}

void Battle::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Max_attack; ++i) {
		window.draw(Attack[i]);
	}

}

void Battle::MoveUp()
{
	if (AttackSelected - 1 >= -1) {
		Attack[AttackSelected].setFillColor(sf::Color::Black);

		AttackSelected--;
		if (AttackSelected == -1) {
			AttackSelected = 3;
		}
		Attack[AttackSelected].setFillColor(sf::Color::Red);
	}
}

void Battle::MoveDown()
{
	if (AttackSelected + 1 >= 0) {
		Attack[AttackSelected].setFillColor(sf::Color::Black);

		AttackSelected++;
		if (AttackSelected == 4) {
			AttackSelected = 0;
		}
		Attack[AttackSelected].setFillColor(sf::Color::Red);
	}
}

void Battle::pikachuAttack() 
{
	evoliLife -= rand() % 5 + 10;
	std::cout << "Evoli PV : " << evoliLife << std::endl;
}

void Battle::evoliAttack(int x)
{
	if (x == 0) {
		pikachuLife -= (rand() % 5 + 10) * multiplier;
	}
	if (x == 1) {
		pikachuLife -= (rand() % 15 + 5) * multiplier;
	}
	if (x == 2) {
		pikachuLife -= (rand() % 25) * multiplier;
	}
	if (x == 3) {
		if (multiplier < 4) {
			multiplier += 1;
		}		
	}
	std::cout << "Pikachu PV : " << pikachuLife << std::endl;
}

sf::Sprite Battle::GetSprite()
{
    this->sprite.setTexture(this->texture);
    return this->sprite;
}

int Battle::GetevoliLife()
{
	return evoliLife;
}

int Battle::GetpikachuLife()
{
	return pikachuLife;
}