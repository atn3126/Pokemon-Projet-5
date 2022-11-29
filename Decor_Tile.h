#pragma once
#include <iostream>
#include <string>
class Decor_Tile
{
public:
	Decor_Tile(char nom_texture, bool have_collision, int x, int y);
	~Decor_Tile();

	void new_emplacement(int x, int y);
	void change_collision(bool have_collision);
	void change_texture(char new_sprite);
	sf::Sprite sprite();

private:
	sf::Texture texture_decor;
	sf::Sprite sprite_decor;
	bool collision;
	int x;
	int y;

};