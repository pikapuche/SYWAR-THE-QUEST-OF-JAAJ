#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace std;
using namespace sf;

class Shared {
public : 

	// background
	static Texture backgroundGameTexture;
	static Texture backgroundMenuTexture;

	// player
	static Texture playerIdleTexture, playerAttackTexture1, playerAttackTexture2, playerDeathTexture, playerHitTexture, playerHealTexture;
	// enemies
	static Texture wormIdleTexture, wormAttackTexture, wormHitTexture, wormDeathTexture;
	static Texture evilIdleTexture, evilAttackTexture, evilHealTexture, evilHitTexture, evilDeathTexture;
	static Texture bossIdleTexture, bossAttackTexture1, bossAttackTexture2, bossHitTexture, bossDeathTexture;
	// other

	//font
};