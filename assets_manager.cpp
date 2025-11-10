#include "assets_manager.hpp"

AssetManager::AssetManager()
{
	loadAssetsFromFiles();
}

void AssetManager::loadAssetsFromFiles()
{
	//////////////// BACKGROUND ////////////////
	if (!Shared::backgroundGameTexture.loadFromFile(""))
		cerr << "load backgroundGameTexture file impossible \n";
	if (!Shared::backgroundMenuTexture.loadFromFile(""))
		cerr << "load backgroundMenuTexture file impossible \n";

	//////////////// PLAYER ////////////////

	if (!Shared::playerIdleTexture.loadFromFile(""))
		cerr << "load playerIdleTexture file impossible \n";
	if (!Shared::playerAttackTexture1.loadFromFile(""))
		cerr << "load playerAttackTexture1 file impossible \n";
	if (!Shared::playerAttackTexture2.loadFromFile(""))
		cerr << "load playerAttackTexture2 file impossible \n";
	if (!Shared::playerDeathTexture.loadFromFile(""))
		cerr << "load playerDeathTexture file impossible \n";
	if (!Shared::playerHitTexture.loadFromFile(""))
		cerr << "load playerHitTexture file impossible \n";
	if (!Shared::playerHealTexture.loadFromFile(""))
		cerr << "load playerHealTexture file impossible \n";

	//////////////// ENEMIES ////////////////

	if (!Shared::wormIdleTexture.loadFromFile(""))
		cerr << "load wormIdleTexture file impossible \n";
	if (!Shared::wormAttackTexture.loadFromFile(""))
		cerr << "load wormAttackTexture file impossible \n";
	if (!Shared::wormHitTexture.loadFromFile(""))
		cerr << "load wormHitTexture file impossible \n";
	if (!Shared::wormDeathTexture.loadFromFile(""))
		cerr << "load wormDeathTexture file impossible \n";

	if (!Shared::evilIdleTexture.loadFromFile(""))
		cerr << "load evilIdleTexture file impossible \n";
	if (!Shared::evilAttackTexture.loadFromFile(""))
		cerr << "load evilAttackTexture file impossible \n";
	if (!Shared::evilHitTexture.loadFromFile(""))
		cerr << "load evilHitTexture file impossible \n";
	if (!Shared::evilHealTexture.loadFromFile(""))
		cerr << "load evilHealTexture file impossible \n";
	if (!Shared::evilDeathTexture.loadFromFile(""))
		cerr << "load evilDeathTexture file impossible \n";

	if (!Shared::bossIdleTexture.loadFromFile(""))
		cerr << "load bossIdleTexture file impossible \n";
	if (!Shared::bossAttackTexture1.loadFromFile(""))
		cerr << "load bossAttackTexture1 file impossible \n";
	if (!Shared::bossAttackTexture2.loadFromFile(""))
		cerr << "load bossAttackTexture2 file impossible \n";
	if (!Shared::bossHitTexture.loadFromFile(""))
		cerr << "load bossHitTexture file impossible \n";
	if (!Shared::bossDeathTexture.loadFromFile(""))
		cerr << "load bossDeathTexture file impossible \n";

	//////////////// OTHER ////////////////
}