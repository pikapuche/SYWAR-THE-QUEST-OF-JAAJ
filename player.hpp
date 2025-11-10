#pragma once
#include "entity.hpp"

class Player : public Entity {
protected:

	const int CHARACTER_ASSET_SIZE = 128; // taille du character

	RectangleShape lifeBar; // barre d'endurance du jetpack
	RectangleShape lifeBarRect; // outline de la barre d'endurance du jetpack maximale

#pragma region Animations

	Clock clockIdle; // Clock qui permet de modifier la vitesse d'anim
	Clock clockAttack; // Clock qui permet de modifier la vitesse d'anim
	Clock clockHeal; // Clock qui permet de modifier la vitesse d'anim
	Clock clockTakeDmg; // Clock qui permet de modifier la vitesse d'anim

	Texture textureAttack; // Texture de l'attack
	Texture textureHeal; // Texture du heal
	Texture textureTakeDmg; // Texture de l'attack

	// Vector d'animation qui compte les frames
	Vector2i animIdle;
	Vector2i animAttack;
	Vector2i animHeal;
	Vector2i animTakeDmg;

#pragma endregion Animations

	SoundBuffer bufferIdle; 
	SoundBuffer bufferAttack; 
	SoundBuffer bufferHeal; 

	Sound sound;

public:

	Player();
	~Player();

	void playerControl(float deltaTime); // controle les mouvements du player

	//void soundManager();

	void update(float deltaTime); // update les fonctions du player avec le deltaTime

	void draw(RenderWindow& window) override; // draw le player
};