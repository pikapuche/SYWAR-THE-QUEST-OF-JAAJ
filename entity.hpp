#pragma once
#include "datas.hpp"

class Entity {
protected :

	string name;
	RectangleShape shape;
	Texture texture;
	Vector2f position;
	bool isAlive = true;
	int damage;
	int life;

public : 

	Entity(string n, Vector2f pos, int dmg, int l);
	~Entity();

	enum class State { IDLE, ATTACK, HEAL, TAKE_DMG };
	State state;

	void animationManager(float deltaTime, Vector2i vector, Texture texture, float timeAnim); // gère les animations du personnage avec un switch et un enum

	void attack(Entity& entity);

	void updateLife();

	virtual void draw(RenderWindow& window) = 0;
};