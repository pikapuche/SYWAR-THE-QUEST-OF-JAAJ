#pragma once
#include "allincludive.hpp"

class Entity {
protected :

	RectangleShape shape;
	Texture texture;
	Vector2f position;

public : 

	Entity();
	~Entity();

	enum State { IDLE, ATTACK, HEAL, TAKE_DMG };
	State state;

	virtual void animationManager(float deltaTime) = 0; // gère les animations du personnage avec un switch et un enum

	virtual void draw(RenderWindow& window) = 0;
};