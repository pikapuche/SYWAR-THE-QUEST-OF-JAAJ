#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>
#include "Class.cpp"
#include <thread>
#include <chrono>
#include <vector>
#include <string>

using namespace std;

int countMenu = 0;
int countFirstMenu = 0;
int gameCount = 0;
int stopMusic = 0;
bool infoBoxB = false;
bool menuExit = false;
int quiSoigner = 0;
int countPlay = 0;
int menuCOuntPlay = 0;
bool menuEnter = false;
int endCount = 0;
bool restartGame = false;


#pragma region Struct
struct CharacterStruct {
    bool isAttacking = false;
    bool SoundAttack = false;
    bool AttackMode = false;
    bool isHealing = false;
    bool SoundHeal = false;
    bool isHit = false;
    bool SoundHit = false;
    bool isDead = false;
    bool printBody = false;
    bool readyToPlay = false;
    int countAnimAtk = 0;
    int countAnimHeal = 0;
    int countAnimHit = 0;
    int countAnimDeath = 0;
    int DeathCount = 0;
}; CharacterStruct Char_S;

struct FireWormStruct {
    bool isAttacking = false;
    bool SoundAttack = false;
    bool isHit = false;
    bool SoundHit = false;
    bool isHealing = false;
    bool isDead = false;
    bool printBody = false;
    bool readyToPlay = false;
    bool readyToAttack = false;
    int countAnimHit = 0;
    int countAnimAtk = 0;
    int countAnimDeath = 0;
    int DeathCount = 0;
}; FireWormStruct Worm_S;

struct EvilWizardStruct {
    bool isAttacking = false;
    bool SoundAttack = false;
    bool isHealing = false;
    bool SoundHeal = false;
    bool isHit = false;
    bool SoundHit = false;
    bool isDead = false;
    bool printBody = false;
    bool readyToPlay = false;
    int countAnimAtk = 0;
    int countAnimHeal = 0;
    int countAnimHit = 0;
    int countAnimDeath = 0;
    int DeathCount = 0;
}; EvilWizardStruct Evil_S;

struct BossStruct {
    bool isAttacking = false;
    bool isAttacking2 = false;
    bool SoundAttack = false;
    bool SoundAttack2 = false;
    bool isHit = false;
    bool SoundHit = false;
    bool isHealing = false;
    bool isDead = false;
    bool printBody = false;
    bool readyToPlay = false;
    int countAnimAtk = 0;
    int countAnimAtk2 = 0;
    int countAnimHit = 0;
    int countAnimDeath = 0;
    int DeathCount = 0;
}; BossStruct Boss_S;

struct Settings {
    bool inSettings = false;
    bool inMenuMusic = false;
    float volumeMenuMusic = 25.f;

    bool inGameMusic = false;
    float volumeGameMusic = 25.f;

    bool inGameSound = false;
    float volumeGameSound = 25.f;

    bool loseMusic = false;
    bool winMusic = false;

    int settingsCountPlay = 0;

}; Settings Settings_S;

#pragma endregion Struct

int main()
{
    Wizard wizard;
    EvilWizard evilWizard;
    FireWorm fireWorm;
    Boss boss;

    // Creation de la fenetre
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SYWAR, THE QUEST OF JAAJ");
    window.setFramerateLimit(8);


#pragma region Gestion_images
    ////////// Background //////////

    // Charger une texture

    sf::Texture background_texture;
    if (!background_texture.loadFromFile("Extra\\decor.png")) {
        return -1; // Erreur si le fichier est introuvable
    }
    background_texture.setSmooth(true);
    // Associer la texture a un sprite

    sf::Sprite sprite_background;
    sprite_background.setTexture(background_texture);
    sprite_background.setTextureRect(sf::IntRect(0, 0, 1920, 1080));


    ////////////////////////////////



    ////////// Personnage //////////
    sf::Texture perso_texture;
    sf::Sprite perso_sprite;
    if (!perso_texture.loadFromFile("Extra\\TileSheets\\Wanderer Magican\\IdleV2.png")) {
        return -1;
    }
    perso_texture.setSmooth(true);

    perso_sprite.setTexture(perso_texture);
    perso_sprite.setPosition(225, 625);
    //
    sf::Texture perso_texture_Attack;
    sf::Sprite perso_sprite_Attack;
    if (!perso_texture_Attack.loadFromFile("Extra\\TileSheets\\Wanderer Magican\\Attack_1V2.png")) {
        return -1;
    }
    perso_texture_Attack.setSmooth(true);

    perso_sprite_Attack.setTexture(perso_texture_Attack);
    perso_sprite_Attack.setPosition(225, 625);
    //
    sf::Texture perso_texture_Heal;
    sf::Sprite perso_sprite_Heal;
    if (!perso_texture_Heal.loadFromFile("Extra\\TileSheets\\Wanderer Magican\\Attack_2V2.png")) {
        return -1;
    }
    perso_texture_Heal.setSmooth(true);

    perso_sprite_Heal.setTexture(perso_texture_Heal);
    perso_sprite_Heal.setPosition(225, 625);
    //
    sf::Texture perso_texture_Hit;
    sf::Sprite perso_sprite_Hit;
    if (!perso_texture_Hit.loadFromFile("Extra\\TileSheets\\Wanderer Magican\\HurtV2.png")) {
        return -1;
    }
    perso_texture_Hit.setSmooth(true);

    perso_sprite_Hit.setTexture(perso_texture_Hit);
    perso_sprite_Hit.setPosition(225, 625);
    //
    sf::Texture perso_texture_Death;
    sf::Sprite perso_sprite_Death;
    if (!perso_texture_Death.loadFromFile("Extra\\TileSheets\\Wanderer Magican\\DeadV2.png")) {
        return -1;
    }
    perso_texture_Death.setSmooth(true);

    perso_sprite_Death.setTexture(perso_texture_Death);
    perso_sprite_Death.setPosition(225, 625);
    ////////////////////////////////

    ////////// Ennemis //////////

    // Verre de terre de feu nul //
    sf::Texture fireWorm_texture;
    sf::Sprite fireWorm_sprite;
    if (!fireWorm_texture.loadFromFile("Extra\\TileSheets\\Fire Worm\\IdleV2.png")) {
        return -1;
    }
    fireWorm_texture.setSmooth(true);

    fireWorm_sprite.setTexture(fireWorm_texture);
    fireWorm_sprite.setPosition(925, 650);
    //
    sf::Texture fireWorm_texture_Attack;
    sf::Sprite fireWorm_sprite_Attack;
    if (!fireWorm_texture_Attack.loadFromFile("Extra\\TileSheets\\Fire Worm\\AttackV2.png")) {
        return -1;
    }
    fireWorm_texture_Attack.setSmooth(true);

    fireWorm_sprite_Attack.setTexture(fireWorm_texture_Attack);
    fireWorm_sprite_Attack.setPosition(925, 650);
    //
    sf::Texture fireWorm_texture_Hit;
    sf::Sprite fireWorm_sprite_Hit;
    if (!fireWorm_texture_Hit.loadFromFile("Extra\\TileSheets\\Fire Worm\\Get HitV2.png")) {
        return -1;
    }
    fireWorm_texture_Hit.setSmooth(true);

    fireWorm_sprite_Hit.setTexture(fireWorm_texture_Hit);
    fireWorm_sprite_Hit.setPosition(925, 650);
    //
    sf::Texture fireWorm_texture_Death;
    sf::Sprite fireWorm_sprite_Death;
    if (!fireWorm_texture_Death.loadFromFile("Extra\\TileSheets\\Fire Worm\\DeathV2.png")) {
        return -1;
    }
    fireWorm_texture_Death.setSmooth(true);

    fireWorm_sprite_Death.setTexture(fireWorm_texture_Death);
    fireWorm_sprite_Death.setPosition(925, 650);

    // Sorcier de feu m�chant //
    sf::Texture evilWizard_texture;
    sf::Sprite evilWizard_sprite;
    if (!evilWizard_texture.loadFromFile("Extra\\TileSheets\\Evil Wizard\\IdleV2.png")) {
        return -1;
    }
    evilWizard_texture.setSmooth(true);

    evilWizard_sprite.setTexture(evilWizard_texture);
    evilWizard_sprite.setPosition(1125, 444);
    //
    sf::Texture evilWizard_texture_Attack;
    sf::Sprite evilWizard_sprite_Attack;
    if (!evilWizard_texture_Attack.loadFromFile("Extra\\TileSheets\\Evil Wizard\\AttackV2.png")) {
        return -1;
    }
    evilWizard_texture_Attack.setSmooth(true);

    evilWizard_sprite_Attack.setTexture(evilWizard_texture_Attack);
    evilWizard_sprite_Attack.setPosition(1125, 444);
    //
    sf::Texture evilWizard_texture_Heal;
    sf::Sprite evilWizard_sprite_Heal;
    if (!evilWizard_texture_Heal.loadFromFile("Extra\\TileSheets\\Evil Wizard\\MoveV2.png")) {
        return -1;
    }
    evilWizard_texture_Heal.setSmooth(true);

    evilWizard_sprite_Heal.setTexture(evilWizard_texture_Heal);
    evilWizard_sprite_Heal.setPosition(1125, 444);
    //
    sf::Texture evilWizard_texture_Hit;
    sf::Sprite evilWizard_sprite_Hit;
    if (!evilWizard_texture_Hit.loadFromFile("Extra\\TileSheets\\Evil Wizard\\HitV2.png")) {
        return -1;
    }
    evilWizard_texture_Hit.setSmooth(true);

    evilWizard_sprite_Hit.setTexture(evilWizard_texture_Hit);
    evilWizard_sprite_Hit.setPosition(1125, 444);
    //
    sf::Texture evilWizard_texture_Death;
    sf::Sprite evilWizard_sprite_Death;
    if (!evilWizard_texture_Death.loadFromFile("Extra\\TileSheets\\Evil Wizard\\DeathV2.png")) {
        return -1;
    }
    evilWizard_texture_Death.setSmooth(true);

    evilWizard_sprite_Death.setTexture(evilWizard_texture_Death);
    evilWizard_sprite_Death.setPosition(1125, 444);

    // LE BOSS DE SES MORTS //
    sf::Texture boss_texture;
    sf::Sprite boss_sprite;
    if (!boss_texture.loadFromFile("Extra\\TileSheets\\EVil Wizard 2\\IdleV2.png")) {
        return -1;
    }
    boss_texture.setSmooth(true);

    boss_sprite.setTexture(boss_texture);
    boss_sprite.setPosition(1400, 333);
    //
    sf::Texture boss_texture_Attack;
    sf::Sprite boss_sprite_Attack;
    if (!boss_texture_Attack.loadFromFile("Extra\\TileSheets\\EVil Wizard 2\\Attack1V2.png")) {
        return -1;
    }
    boss_texture_Attack.setSmooth(true);

    boss_sprite_Attack.setTexture(boss_texture_Attack);
    boss_sprite_Attack.setPosition(1400, 333);
    //
    sf::Texture boss_texture_Attack2;
    sf::Sprite boss_sprite_Attack2;
    if (!boss_texture_Attack2.loadFromFile("Extra\\TileSheets\\EVil Wizard 2\\Attack2V2.png")) {
        return -1;
    }
    boss_texture_Attack2.setSmooth(true);

    boss_sprite_Attack2.setTexture(boss_texture_Attack2);
    boss_sprite_Attack2.setPosition(1400, 333);
    //
    sf::Texture boss_texture_Hit;
    sf::Sprite boss_sprite_Hit;
    if (!boss_texture_Hit.loadFromFile("Extra\\TileSheets\\EVil Wizard 2\\HitV2.png")) {
        return -1;
    }
    boss_texture_Hit.setSmooth(true);

    boss_sprite_Hit.setTexture(boss_texture_Hit);
    boss_sprite_Hit.setPosition(1400, 333);
    //
    sf::Texture boss_texture_Death;
    sf::Sprite boss_sprite_Death;
    if (!boss_texture_Death.loadFromFile("Extra\\TileSheets\\EVil Wizard 2\\DeathV2.png")) {
        return -1;
    }
    boss_texture_Death.setSmooth(true);

    boss_sprite_Death.setTexture(boss_texture_Death);
    boss_sprite_Death.setPosition(1400, 333);

    ////////////////////////////////

    ////////// Animation ///////////
    sf::Vector2i c_anim(1, 0);
    sf::Vector2i c_anim_Attack(1, 0);
    sf::Vector2i c_anim_Heal(1, 0);
    sf::Vector2i c_anim_Hit(1, 0);
    sf::Vector2i c_anim_Death(1, 0);

    sf::Vector2i f_anim(1, 0);
    sf::Vector2i f_anim_Attack(1, 0);
    sf::Vector2i f_anim_Hit(1, 0);
    sf::Vector2i f_anim_Death(1, 0);

    sf::Vector2i e_anim(1, 0);
    sf::Vector2i e_anim_Attack(1, 0);
    sf::Vector2i e_anim_Hit(1, 0);
    sf::Vector2i e_anim_Heal(1, 0);
    sf::Vector2i e_anim_Death(1, 0);

    sf::Vector2i b_anim(1, 0);
    sf::Vector2i b_anim_Attack(1, 0);
    sf::Vector2i b_anim_Attack2(1, 0);
    sf::Vector2i b_anim_Hit(1, 0);
    sf::Vector2i b_anim_Death(1, 0);
    ////////////////////////////////
#pragma endregion Gestion_images
#pragma region Gestion_son
    sf::Music menuMusic;
    if (!menuMusic.openFromFile("Extra\\Musiques\\MenuWAV.wav"))
        return -1;
    menuMusic.setLoop(true);
    if (gameCount == 0) menuMusic.play();
    menuMusic.setVolume(Settings_S.volumeMenuMusic);

    sf::Music endWinMusic;
    if (!endWinMusic.openFromFile("Extra\\Musiques\\FinalFantasyWinWAV.wav"))
        return -1;
    endWinMusic.setVolume(Settings_S.volumeMenuMusic);
    if (Settings_S.winMusic == true) endWinMusic.play();
    endWinMusic.setLoop(true);

    sf::Music endLoseMusic;
    if (!endLoseMusic.openFromFile("Extra\\Musiques\\endLoseMusicWAV.wav"))
        return -1;
    endLoseMusic.setVolume(Settings_S.volumeMenuMusic);
    if (Settings_S.loseMusic == true) endLoseMusic.play();
    endLoseMusic.setLoop(true);

    sf::Music fightMusic;
    if (!fightMusic.openFromFile("Extra\\Musiques\\V2 120bpm.wav"))
        return -1;
    fightMusic.setLoop(true);
    if(gameCount >= 1) fightMusic.play();
    fightMusic.setVolume(Settings_S.volumeGameMusic);


    sf::SoundBuffer wizardAttack;
    if (!wizardAttack.loadFromFile("Extra\\Musiques\\wizard attack V3.wav"))
        return -1;

    sf::Sound soundWizardAttack;
    soundWizardAttack.setBuffer(wizardAttack);
    soundWizardAttack.setVolume(Settings_S.volumeGameSound);

    sf::SoundBuffer Heal;
    if (!Heal.loadFromFile("Extra\\Musiques\\HealWAV.wav"))
        return -1;

    sf::Sound soundHeal;
    soundHeal.setBuffer(Heal);
    soundHeal.setVolume(Settings_S.volumeGameSound);


    sf::SoundBuffer fireWormAttack;
    if (!fireWormAttack.loadFromFile("Extra\\Musiques\\fireWormAttackWAV.wav"))
        return -1;

    sf::Sound soundFireWormAttack;
    soundFireWormAttack.setBuffer(fireWormAttack);
    soundFireWormAttack.setVolume(Settings_S.volumeGameSound);

    sf::SoundBuffer evilWizardAttack;
    if (!evilWizardAttack.loadFromFile("Extra\\Musiques\\fireWizardAttackLongWAV.wav"))
        return -1;

    sf::Sound soundEvilWizardAttack;
    soundEvilWizardAttack.setBuffer(evilWizardAttack);
    soundEvilWizardAttack.setVolume(Settings_S.volumeGameSound);
    soundEvilWizardAttack.setPlayingOffset(sf::seconds(14));

    sf::SoundBuffer bossAttack;
    if (!bossAttack.loadFromFile("Extra\\Musiques\\swooshEffectLourdWAV.wav"))
        return -1;

    sf::Sound soundBossAttack;
    soundBossAttack.setBuffer(bossAttack);
    soundBossAttack.setVolume(Settings_S.volumeGameSound);
    soundBossAttack.setPlayingOffset(sf::seconds(0.5));


#pragma endregion Gestion_son

#pragma region Menu principal

    sf::Texture background_texture_Menu;
    if (!background_texture_Menu.loadFromFile("Extra\\TileSheets\\Clouds 6\\1.png")) {
        return -1;
    }
    background_texture_Menu.setSmooth(true);

    sf::Sprite sprite_background_Menu;
    sprite_background_Menu.setTexture(background_texture_Menu);
    sprite_background_Menu.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    //
    sf::Texture background_texture_Menu2;
    if (!background_texture_Menu2.loadFromFile("Extra\\TileSheets\\Clouds 6\\2.png")) {
        return -1;
    }
    background_texture_Menu2.setSmooth(true);

    sf::Sprite sprite_background_Menu2;
    sprite_background_Menu2.setTexture(background_texture_Menu2);
    sprite_background_Menu2.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    //
    sf::Texture background_texture_Menu3;
    if (!background_texture_Menu3.loadFromFile("Extra\\TileSheets\\Clouds 6\\3.png")) {
        return -1;
    }
    background_texture_Menu3.setSmooth(true);

    sf::Sprite sprite_background_Menu3;
    sprite_background_Menu3.setTexture(background_texture_Menu3);
    sprite_background_Menu3.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    //
    sf::Texture background_texture_Menu4;
    if (!background_texture_Menu4.loadFromFile("Extra\\TileSheets\\Clouds 6\\4.png")) {
        return -1;
    }
    background_texture_Menu4.setSmooth(true);

    sf::Sprite sprite_background_Menu4;
    sprite_background_Menu4.setTexture(background_texture_Menu4);
    sprite_background_Menu4.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    //
    sf::Texture background_texture_Menu5;
    if (!background_texture_Menu5.loadFromFile("Extra\\TileSheets\\Clouds 6\\5.png")) {
        return -1;
    }
    background_texture_Menu5.setSmooth(true);

    sf::Sprite sprite_background_Menu5;
    sprite_background_Menu5.setTexture(background_texture_Menu5);
    sprite_background_Menu5.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    //
    sf::Texture background_texture_Menu6;
    if (!background_texture_Menu6.loadFromFile("Extra\\TileSheets\\Clouds 6\\6.png")) {
        return -1;
    }
    background_texture_Menu6.setSmooth(true);

    sf::Sprite sprite_background_Menu6;
    sprite_background_Menu6.setTexture(background_texture_Menu6);
    sprite_background_Menu6.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    //
    sf::Font fontMenu;
    if (!fontMenu.loadFromFile("Extra\\minecraft.ttf"))
    {
        return -1;
    }
    sf::Text title_Menu;
    title_Menu.setPosition(160, 110);
    title_Menu.setFont(fontMenu);
    title_Menu.setString("SYWAR, THE QUEST OF JAAJ");
    title_Menu.setCharacterSize(100);
    title_Menu.setFillColor(sf::Color::Cyan);
    title_Menu.setOutlineColor(sf::Color::Black);
    title_Menu.setOutlineThickness(9.f);
    title_Menu.setStyle(sf::Text::Bold);
    title_Menu.setStyle(sf::Text::Underlined);
    //
    sf::RectangleShape start_Menuu(sf::Vector2f(210.f, 80.f));
    start_Menuu.setPosition(550, 340);
    start_Menuu.setFillColor(sf::Color(255, 178, 101));
    sf::Text start_Menu;
    start_Menu.setPosition(570, 350);
    start_Menu.setFont(fontMenu);
    start_Menu.setString("START");
    start_Menu.setCharacterSize(50);
    start_Menu.setFillColor(sf::Color::White);
    start_Menu.setOutlineColor(sf::Color::Black);
    start_Menu.setOutlineThickness(8.f);
    start_Menu.setStyle(sf::Text::Bold);
    //
    sf::RectangleShape settings_Menuu(sf::Vector2f(300.f, 80.f));
    settings_Menuu.setPosition(500, 460);
    settings_Menuu.setFillColor(sf::Color(255, 178, 101));
    sf::Text settings_Menu;
    settings_Menu.setPosition(520, 470);
    settings_Menu.setFont(fontMenu);
    settings_Menu.setString("SETTINGS");
    settings_Menu.setCharacterSize(50);
    settings_Menu.setFillColor(sf::Color::White);
    settings_Menu.setOutlineColor(sf::Color::Black);
    settings_Menu.setOutlineThickness(8.f);
    settings_Menu.setStyle(sf::Text::Bold);
    //
    sf::RectangleShape quit_Menuu(sf::Vector2f(165.f, 80.f));
    quit_Menuu.setPosition(570, 580);
    quit_Menuu.setFillColor(sf::Color(255, 178, 101));
    sf::Text quit_Menu;
    quit_Menu.setPosition(590, 590);
    quit_Menu.setFont(fontMenu);
    quit_Menu.setString("QUIT");
    quit_Menu.setCharacterSize(50);
    quit_Menu.setFillColor(sf::Color::White);
    quit_Menu.setOutlineColor(sf::Color::Black);
    quit_Menu.setOutlineThickness(8.f);
    quit_Menu.setStyle(sf::Text::Bold);
#pragma endregion Menu principal

#pragma region Menu
    // Mini menu 
    sf::RectangleShape menuBackground(sf::Vector2f(420.0f, 226.f));
    menuBackground.setPosition(20, 20);
    menuBackground.setFillColor(sf::Color(255, 178, 101));

    sf::RectangleShape menuAtk(sf::Vector2f(420.f, 65.f));
    menuAtk.setPosition(20, 25);
    menuAtk.setFillColor(sf::Color(183, 127, 71));
    sf::Font font;
    if (!font.loadFromFile("Extra\\Minecraft.ttf"))
    {
        return -1;
    }
    sf::Text textAtk;
    textAtk.setPosition(130, 35);
    textAtk.setFont(font);
    textAtk.setString("ATTAQUER");
    textAtk.setCharacterSize(35);
    textAtk.setFillColor(sf::Color::White);
    textAtk.setOutlineColor(sf::Color::Black);
    textAtk.setOutlineThickness(5.f);
    textAtk.setStyle(sf::Text::Bold);

#pragma region sousMenuAtk
    // apres avoir choisi attaquer
    sf::RectangleShape menuWhoAtk(sf::Vector2f(420.f, 226.f));
    menuWhoAtk.setPosition(20, 20);
    menuWhoAtk.setFillColor(sf::Color(255, 178, 101));

    sf::RectangleShape menuWorm(sf::Vector2f(420.f, 65.f));
    menuWorm.setPosition(20, 25);
    menuWorm.setFillColor(sf::Color(183, 127, 71));
    sf::Text textMenuWorm;
    textMenuWorm.setPosition(120, 35);
    textMenuWorm.setFont(font);
    textMenuWorm.setString("FIRE WORM");
    textMenuWorm.setCharacterSize(35);
    textMenuWorm.setFillColor(sf::Color::White);
    textMenuWorm.setOutlineColor(sf::Color::Black);
    textMenuWorm.setOutlineThickness(5.f);
    textMenuWorm.setStyle(sf::Text::Bold);

    sf::RectangleShape menuEvilWizard(sf::Vector2f(420.f, 65.f));
    menuEvilWizard.setPosition(20, 100);
    menuEvilWizard.setFillColor(sf::Color(183, 127, 71));
    sf::Text textMenuEvilWizard;
    textMenuEvilWizard.setPosition(100, 110);
    textMenuEvilWizard.setFont(font);
    textMenuEvilWizard.setString("EVIL WIZARD");
    textMenuEvilWizard.setCharacterSize(35);
    textMenuEvilWizard.setFillColor(sf::Color::White);
    textMenuEvilWizard.setOutlineColor(sf::Color::Black);
    textMenuEvilWizard.setOutlineThickness(5.f);
    textMenuEvilWizard.setStyle(sf::Text::Bold);

    sf::RectangleShape menuBoss(sf::Vector2f(420.f, 65.f));
    menuBoss.setPosition(20, 175);
    menuBoss.setFillColor(sf::Color(183, 127, 71));
    sf::Text textMenuBoss;
    textMenuBoss.setPosition(180, 185);
    textMenuBoss.setFont(font);
    textMenuBoss.setString("???");
    textMenuBoss.setCharacterSize(35);
    textMenuBoss.setFillColor(sf::Color::White);
    textMenuBoss.setOutlineColor(sf::Color::Black);
    textMenuBoss.setOutlineThickness(5.f);
    textMenuBoss.setStyle(sf::Text::Bold);
#pragma endregion sousMenuAtk

    sf::RectangleShape menuHeal(sf::Vector2f(420.f, 65.f));
    menuHeal.setPosition(20, 100);
    menuHeal.setFillColor(sf::Color(183, 127, 71));
    sf::Text textHeal;
    textHeal.setPosition(180, 110);
    textHeal.setFont(font);
    textHeal.setString("SOIN");
    textHeal.setCharacterSize(35);
    textHeal.setFillColor(sf::Color::White);
    textHeal.setOutlineColor(sf::Color::Black);
    textHeal.setOutlineThickness(5.f);
    textHeal.setStyle(sf::Text::Bold);


    sf::RectangleShape menuSkip(sf::Vector2f(420.f, 65.f));
    menuSkip.setPosition(20, 175);
    menuSkip.setFillColor(sf::Color(183, 127, 71));
    sf::Text textSkip;
    textSkip.setPosition(70, 185);
    textSkip.setFont(font);
    textSkip.setString("PASSER LE TOUR");
    textSkip.setCharacterSize(35);
    textSkip.setFillColor(sf::Color::White);
    textSkip.setOutlineColor(sf::Color::Black);
    textSkip.setOutlineThickness(5.f);
    textSkip.setStyle(sf::Text::Bold);

#pragma region UI des ennemies 
    sf::Text UI_Character;
    UI_Character.setPosition(317, 690);
    UI_Character.setFont(font);
    UI_Character.setString("YOU");
    UI_Character.setCharacterSize(20);
    UI_Character.setFillColor(sf::Color::White);
    UI_Character.setOutlineColor(sf::Color::Black);
    UI_Character.setOutlineThickness(3.5f);
    UI_Character.setStyle(sf::Text::Bold);

    sf::Text UI_Character_PV;
    UI_Character_PV.setPosition(305, 720);
    UI_Character_PV.setFont(font);
    UI_Character_PV.setCharacterSize(20);
    UI_Character_PV.setFillColor(sf::Color::Green);
    UI_Character_PV.setOutlineColor(sf::Color::Black);
    UI_Character_PV.setOutlineThickness(3.5f);
    UI_Character_PV.setStyle(sf::Text::Bold);
    sf::Text UI_Character_PV2;
    UI_Character_PV2.setPosition(351, 720);
    UI_Character_PV2.setFont(font);
    UI_Character_PV2.setString(" PV");
    UI_Character_PV2.setCharacterSize(20);
    UI_Character_PV2.setFillColor(sf::Color::Green);
    UI_Character_PV2.setOutlineColor(sf::Color::Black);
    UI_Character_PV2.setOutlineThickness(3.5f);
    UI_Character_PV2.setStyle(sf::Text::Bold);

    sf::Text UI_Worm;
    UI_Worm.setPosition(940, 620);
    UI_Worm.setFont(font);
    UI_Worm.setString("FIRE WORM");
    UI_Worm.setCharacterSize(20);
    UI_Worm.setFillColor(sf::Color::White);
    UI_Worm.setOutlineColor(sf::Color::Black);
    UI_Worm.setOutlineThickness(3.5f);
    UI_Worm.setStyle(sf::Text::Bold);

    sf::Text UI_Worm_PV;
    UI_Worm_PV.setPosition(970, 650);
    UI_Worm_PV.setFont(font);
    UI_Worm_PV.setCharacterSize(20);
    UI_Worm_PV.setFillColor(sf::Color::Green);
    UI_Worm_PV.setOutlineColor(sf::Color::Black);
    UI_Worm_PV.setOutlineThickness(3.5f);
    UI_Worm_PV.setStyle(sf::Text::Bold);
    sf::Text UI_Worm_PV2;
    UI_Worm_PV2.setPosition(1005, 650);
    UI_Worm_PV2.setFont(font);
    UI_Worm_PV2.setString(" PV");
    UI_Worm_PV2.setCharacterSize(20);
    UI_Worm_PV2.setFillColor(sf::Color::Green);
    UI_Worm_PV2.setOutlineColor(sf::Color::Black);
    UI_Worm_PV2.setOutlineThickness(3.5f);
    UI_Worm_PV2.setStyle(sf::Text::Bold);

    sf::Text UI_Evil;
    UI_Evil.setPosition(1280, 520);
    UI_Evil.setFont(font);
    UI_Evil.setString("EVIL WIZARD");
    UI_Evil.setCharacterSize(20);
    UI_Evil.setFillColor(sf::Color::White);
    UI_Evil.setOutlineColor(sf::Color::Black);
    UI_Evil.setOutlineThickness(3.5f);
    UI_Evil.setStyle(sf::Text::Bold);

    sf::Text UI_Evil_PV;
    UI_Evil_PV.setPosition(1310, 550);
    UI_Evil_PV.setFont(font);;
    UI_Evil_PV.setCharacterSize(20);
    UI_Evil_PV.setFillColor(sf::Color::Green);
    UI_Evil_PV.setOutlineColor(sf::Color::Black);
    UI_Evil_PV.setOutlineThickness(3.5f);
    UI_Evil_PV.setStyle(sf::Text::Bold);
    sf::Text UI_Evil_PV2;
    UI_Evil_PV2.setPosition(1356, 550);
    UI_Evil_PV2.setFont(font);
    UI_Evil_PV2.setString(" PV");
    UI_Evil_PV2.setCharacterSize(20);
    UI_Evil_PV2.setFillColor(sf::Color::Green);
    UI_Evil_PV2.setOutlineColor(sf::Color::Black);
    UI_Evil_PV2.setOutlineThickness(3.5f);
    UI_Evil_PV2.setStyle(sf::Text::Bold);

    sf::Text UI_Boss;
    UI_Boss.setPosition(1780, 620);
    UI_Boss.setFont(font);
    UI_Boss.setString("???");
    UI_Boss.setCharacterSize(20);
    UI_Boss.setFillColor(sf::Color::White);
    UI_Boss.setOutlineColor(sf::Color::Black);
    UI_Boss.setOutlineThickness(3.5f);
    UI_Boss.setStyle(sf::Text::Bold);

    sf::Text UI_Boss_PV;
    UI_Boss_PV.setPosition(1750, 650);
    UI_Boss_PV.setFont(font);
    UI_Boss_PV.setCharacterSize(20);
    UI_Boss_PV.setFillColor(sf::Color::Green);
    UI_Boss_PV.setOutlineColor(sf::Color::Black);
    UI_Boss_PV.setOutlineThickness(3.5f);
    UI_Boss_PV.setStyle(sf::Text::Bold);
    sf::Text UI_Boss_PV2;
    UI_Boss_PV2.setPosition(1796, 650);
    UI_Boss_PV2.setFont(font);
    UI_Boss_PV2.setString(" PV");
    UI_Boss_PV2.setCharacterSize(20);
    UI_Boss_PV2.setFillColor(sf::Color::Green);
    UI_Boss_PV2.setOutlineColor(sf::Color::Black);
    UI_Boss_PV2.setOutlineThickness(3.5f);
    UI_Boss_PV2.setStyle(sf::Text::Bold);
#pragma endregion UI des ennemies
#pragma region autre menu
    sf::RectangleShape infoBox(sf::Vector2f(850.f, 180.f));
    infoBox.setPosition(1000, 35);
    infoBox.setFillColor(sf::Color::Black);
    infoBox.setOutlineColor(sf::Color::White);
    infoBox.setOutlineThickness(5.f);

    sf::Text textInfoBox;
    textInfoBox.setPosition(1120, 105);
    textInfoBox.setFont(font);
    textInfoBox.setString("Erreur");
    textInfoBox.setCharacterSize(25);
    textInfoBox.setFillColor(sf::Color::White);
    textInfoBox.setOutlineColor(sf::Color::Black);
    textInfoBox.setOutlineThickness(3.5f);
    textInfoBox.setStyle(sf::Text::Bold);



    sf::Text textWin;
    textWin.setPosition(660, 130);
    textWin.setFont(font);
    textWin.setString("WIN");
    textWin.setCharacterSize(300);
    textWin.setFillColor(sf::Color::Green);
    textWin.setOutlineColor(sf::Color::Black);
    textWin.setOutlineThickness(10.f);
    textWin.setStyle(sf::Text::Bold);

    sf::Text textDefeat;
    textDefeat.setPosition(330, 130);
    textDefeat.setFont(font);
    textDefeat.setString("DEFEAT");
    textDefeat.setCharacterSize(300);
    textDefeat.setFillColor(sf::Color::Red);
    textDefeat.setOutlineColor(sf::Color::Black);
    textDefeat.setOutlineThickness(10.f);
    textDefeat.setStyle(sf::Text::Bold);

    sf::RectangleShape quit_End(sf::Vector2f(165.f, 80.f));
    quit_End.setPosition(830, 690);
    quit_End.setFillColor(sf::Color(255, 178, 101));
    sf::Text quit_EndText;
    quit_EndText.setPosition(850, 700);
    quit_EndText.setFont(fontMenu);
    quit_EndText.setString("QUIT");
    quit_EndText.setCharacterSize(50);
    quit_EndText.setFillColor(sf::Color::White);
    quit_EndText.setOutlineColor(sf::Color::Black);
    quit_EndText.setOutlineThickness(8.f);
    quit_EndText.setStyle(sf::Text::Bold);

    sf::RectangleShape restart_End(sf::Vector2f(290.f, 80.f));
    restart_End.setPosition(770, 540);
    restart_End.setFillColor(sf::Color(255, 178, 101));
    sf::Text restart_EndText;
    restart_EndText.setPosition(790, 550);
    restart_EndText.setFont(fontMenu);
    restart_EndText.setString("RESTART");
    restart_EndText.setCharacterSize(50);
    restart_EndText.setFillColor(sf::Color::White);
    restart_EndText.setOutlineColor(sf::Color::Black);
    restart_EndText.setOutlineThickness(8.f);
    restart_EndText.setStyle(sf::Text::Bold);

    sf::RectangleShape settings_Window(sf::Vector2f(1400.f, 800.f));
    settings_Window.setPosition(200, 100);
    settings_Window.setFillColor(sf::Color::Black);

    sf::Text quit_settings_Window_Text;
    quit_settings_Window_Text.setPosition(1120, 240);
    quit_settings_Window_Text.setFont(fontMenu);
    quit_settings_Window_Text.setString("QUIT THE GAME");
    quit_settings_Window_Text.setCharacterSize(50);
    quit_settings_Window_Text.setFillColor(sf::Color::White);
    quit_settings_Window_Text.setOutlineColor(sf::Color::Black);
    quit_settings_Window_Text.setOutlineThickness(8.f);
    quit_settings_Window_Text.setStyle(sf::Text::Bold);

    sf::Text settings_music;
    settings_music.setPosition(250, 140);
    settings_music.setFont(fontMenu);
    settings_music.setString("SETTINGS ( ESCAPE FOR CLOSE )");
    settings_music.setCharacterSize(73);
    settings_music.setFillColor(sf::Color::White);
    settings_music.setOutlineColor(sf::Color::Magenta);
    settings_music.setOutlineThickness(1.f);
    settings_music.setStyle(sf::Text::Bold);

    sf::Text settings_menu_music;
    settings_menu_music.setPosition(250, 340);
    settings_menu_music.setFont(fontMenu);
    settings_menu_music.setString("MENU MUSIC : ");
    settings_menu_music.setCharacterSize(50);
    settings_menu_music.setFillColor(sf::Color::White);
    settings_menu_music.setOutlineColor(sf::Color::Black);
    settings_menu_music.setOutlineThickness(8.f);
    settings_menu_music.setStyle(sf::Text::Bold);
    sf::Text text_menu_music;
    text_menu_music.setPosition(720, 340);
    text_menu_music.setFont(fontMenu);
    text_menu_music.setCharacterSize(50);
    text_menu_music.setFillColor(sf::Color::White);
    text_menu_music.setOutlineColor(sf::Color::Black);
    text_menu_music.setOutlineThickness(8.f);
    text_menu_music.setStyle(sf::Text::Bold);

    sf::Text settings_game_music;
    settings_game_music.setPosition(250, 540);
    settings_game_music.setFont(fontMenu);
    settings_game_music.setString("GAME MUSIC : ");
    settings_game_music.setCharacterSize(50);
    settings_game_music.setFillColor(sf::Color::White);
    settings_game_music.setOutlineColor(sf::Color::Black);
    settings_game_music.setOutlineThickness(8.f);
    settings_game_music.setStyle(sf::Text::Bold);
    sf::Text text_game_music;
    text_game_music.setPosition(720, 540);
    text_game_music.setFont(fontMenu);
    text_game_music.setCharacterSize(50);
    text_game_music.setFillColor(sf::Color::White);
    text_game_music.setOutlineColor(sf::Color::Black);
    text_game_music.setOutlineThickness(8.f);
    text_game_music.setStyle(sf::Text::Bold);

    sf::Text settings_game_sound;
    settings_game_sound.setPosition(250, 740);
    settings_game_sound.setFont(fontMenu);
    settings_game_sound.setString("GAME SOUND EFFECT : ");
    settings_game_sound.setCharacterSize(50);
    settings_game_sound.setFillColor(sf::Color::White);
    settings_game_sound.setOutlineColor(sf::Color::Black);
    settings_game_sound.setOutlineThickness(8.f);
    settings_game_sound.setStyle(sf::Text::Bold);
    sf::Text text_game_sound;
    text_game_sound.setPosition(980, 740);
    text_game_sound.setFont(fontMenu);
    text_game_sound.setCharacterSize(50);
    text_game_sound.setFillColor(sf::Color::White);
    text_game_sound.setOutlineColor(sf::Color::Black);
    text_game_sound.setOutlineThickness(8.f);
    text_game_sound.setStyle(sf::Text::Bold);
#pragma endregion autre menu

#pragma endregion Menu
    f_anim_Death.x = 1440;
    f_anim_Hit.x = 540;
    f_anim_Attack.x = 2880;

    e_anim_Death.x = 2250;
    e_anim_Attack.x = 3600;
    e_anim_Hit.x = 1800;

    b_anim_Death.x = 5600;
    b_anim_Attack.x = 6400;
    b_anim_Attack2.x = 6400;
    b_anim_Hit.x = 2400;


    auto startTime = chrono::steady_clock::now();
    auto waitTime = chrono::seconds(1);

    auto startSetTime = chrono::steady_clock::now();
    auto waitSetTime = chrono::seconds(1);

    // Boucle principale
    while (window.isOpen()) {
        auto nowTime = chrono::steady_clock::now();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Fermer la fenetre
        }


        if (restartGame == true) {
            gameCount = 0;
            //Char
            Char_S.isAttacking = false;
            Char_S.SoundAttack = false;
            Char_S.AttackMode = false;
            Char_S.isHealing = false;
            Char_S.SoundHeal = false;
            Char_S.isHit = false;
            Char_S.SoundHit = false;
            Char_S.isDead = false;
            Char_S.printBody = false;
            Char_S.readyToPlay = false;
            Char_S.countAnimAtk = 0;
            Char_S.countAnimHeal = 0;
            Char_S.countAnimHit = 0;
            Char_S.countAnimDeath = 0;
            Char_S.DeathCount = 0;

            //fireWorm
            Worm_S.isAttacking = false;
            Worm_S.SoundAttack = false;
            Worm_S.isHit = false;
            Worm_S.SoundHit = false;
            Worm_S.isHealing = false;
            Worm_S.isDead = false;
            Worm_S.printBody = false;
            Worm_S.readyToPlay = false;
            Worm_S.readyToAttack = false;
            Worm_S.countAnimHit = 0;
            Worm_S.countAnimAtk = 0;
            Worm_S.countAnimDeath = 0;
            Worm_S.DeathCount = 0;

            //evilWizard
            Evil_S.isAttacking = false;
            Evil_S.SoundAttack = false;
            Evil_S.isHealing = false;
            Evil_S.SoundHeal = false;
            Evil_S.isHit = false;
            Evil_S.SoundHit = false;
            Evil_S.isDead = false;
            Evil_S.printBody = false;
            Evil_S.readyToPlay = false;
            Evil_S.countAnimAtk = 0;
            Evil_S.countAnimHeal = 0;
            Evil_S.countAnimHit = 0;
            Evil_S.countAnimDeath = 0;
            Evil_S.DeathCount = 0;

            //boss
            Boss_S.isAttacking = false;
            Boss_S.isAttacking2 = false;
            Boss_S.SoundAttack = false;
            Boss_S.SoundAttack2 = false;
            Boss_S.isHit = false;
            Boss_S.SoundHit = false;
            Boss_S.isHealing = false;
            Boss_S.isDead = false;
            Boss_S.printBody = false;
            Boss_S.readyToPlay = false;
            Boss_S.countAnimAtk = 0;
            Boss_S.countAnimAtk2 = 0;
            Boss_S.countAnimHit = 0;
            Boss_S.countAnimDeath = 0;
            Boss_S.DeathCount = 0;

            //settings
            Settings_S.inSettings = false;
            Settings_S.inMenuMusic = false;

            Settings_S.inGameMusic = false;

            Settings_S.inGameSound = false;

            Settings_S.loseMusic = false;
            Settings_S.winMusic = false;

            //autre
            countMenu = 0;
            countFirstMenu = 0;
            stopMusic = 0;
            infoBoxB = false;
            menuExit = false;
            quiSoigner = 0;
            countPlay = 0;
            endCount = 0;
            Settings_S.settingsCountPlay = 0;

            endWinMusic.stop();
            endLoseMusic.stop();
            if (gameCount == 0) menuMusic.play();

            wizard.HealthReset(500);
            fireWorm.HealthReset(75);
            evilWizard.HealthReset(150);
            boss.HealthReset(240);

            wizard.LifeReset();
            fireWorm.LifeReset();
            evilWizard.LifeReset();
            boss.LifeReset();

            restartGame = false;
        }

        if (gameCount == 1 && stopMusic == 0) {
            menuMusic.stop();
            fightMusic.play();
            stopMusic++;
        }
        if (Settings_S.winMusic == true && endCount == 1) endWinMusic.play();
            
        if (Settings_S.loseMusic == true && endCount == 1) endLoseMusic.play();


        if (gameCount >= 5 && restartGame == false) {
            gameCount = 1;
        }
        if (!infoBoxB) {
            infoBox.setFillColor(sf::Color::Transparent);
            infoBox.setOutlineColor(sf::Color::Transparent);
            textInfoBox.setString("");
        }
        if (infoBoxB) {
            infoBox.setFillColor(sf::Color::Black);
            infoBox.setOutlineColor(sf::Color::White);
            infoBox.setOutlineThickness(5.f);
        }

#pragma region animation
        //ici, on va rajouter 256px a notre image pour la faire changer et donc s'animer ;)
        // Character
        if (!Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && wizard.getAlive() == true) {
            Char_S.countAnimAtk = 0;
            Char_S.countAnimHeal = 0;
            Char_S.countAnimHit = 0;
            Char_S.countAnimDeath = 0;
            c_anim.x++;
            if (c_anim.x * 256 >= perso_texture.getSize().x) // boucle qui permet de revenir a la premiere slide de l'anim
                c_anim.x = 0;
            // ici, ce code permet de cr�er l'animation Idle du personnage
            perso_sprite.setTextureRect(sf::IntRect(c_anim.x * 256, 0, 256, 256));
        }
        //////////////////////////////////////////////////////////////////////////////////////
        // Worm
        if (!Worm_S.isHit && !Worm_S.isAttacking && !Worm_S.isHealing && fireWorm.getAlive() == true) {
            f_anim.x++;
            if (f_anim.x * 180 == fireWorm_texture.getSize().x) {
                f_anim.x = 0;
            }
            fireWorm_sprite.setTextureRect(sf::IntRect(f_anim.x * 180, 0, 180, 180));
            Worm_S.countAnimAtk = 0;
            Worm_S.countAnimHit = 0;
            Worm_S.countAnimDeath = 0;
        }

        //////////////////////////////////////////////////////////////////////////////////////
        // EvilWizard
        if (!Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && evilWizard.getAlive() == true) {
            e_anim.x++;
            if (e_anim.x * 450 == evilWizard_texture.getSize().x) {
                e_anim.x = 0;
            }
            evilWizard_sprite.setTextureRect(sf::IntRect(e_anim.x * 450, 0, 450, 450));
            Evil_S.countAnimAtk = 0;
            Evil_S.countAnimHeal = 0;
            Evil_S.countAnimHit = 0;
            Evil_S.countAnimDeath = 0;
        }


        //////////////////////////////////////////////////////////////////////////////////////
        // Boss
        if (!Boss_S.isAttacking && !Boss_S.isAttacking2 && !Boss_S.isHit && !Boss_S.isHealing && boss.getAlive() == true) {
            b_anim.x++;
            if (b_anim.x * 800 == boss_texture.getSize().x)
                b_anim.x = 0;

            boss_sprite.setTextureRect(sf::IntRect(b_anim.x * 800, 0, 800, 800));
            Boss_S.countAnimAtk = 0;
            Boss_S.countAnimAtk2 = 0;
            Boss_S.countAnimDeath = 0;
            Boss_S.countAnimHit = 0;
        }
#pragma endregion animation
#pragma region interMenu

        if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 110 && sf::Mouse::getPosition().y >= 45 && !Char_S.AttackMode) { // pointe sur attaque
            menuAtk.setOutlineColor(sf::Color::Cyan);
            menuAtk.setOutlineThickness(5.f);
        }
        else {
            menuAtk.setOutlineColor(sf::Color::Transparent); // disparait
            menuAtk.setOutlineThickness(0);
        }
        if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 185 && sf::Mouse::getPosition().y >= 120 && !Char_S.AttackMode) { // pointe sur soin
            menuHeal.setOutlineColor(sf::Color::Cyan);
            menuHeal.setOutlineThickness(5.f);
        }
        else {
            menuHeal.setOutlineColor(sf::Color::Transparent);
            menuHeal.setOutlineThickness(0);
        }
        if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 260 && sf::Mouse::getPosition().y >= 195 && !Char_S.AttackMode) { // pointe sur passe tour
            menuSkip.setOutlineColor(sf::Color::Cyan);
            menuSkip.setOutlineThickness(5.f);
        }
        else {
            menuSkip.setOutlineColor(sf::Color::Transparent);
            menuSkip.setOutlineThickness(0);
        }

        if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 110 && sf::Mouse::getPosition().y >= 45 && Char_S.AttackMode) { // fireworm
            menuWorm.setOutlineColor(sf::Color::Cyan);
            menuWorm.setOutlineThickness(5.f);
        }
        else {
            menuWorm.setOutlineColor(sf::Color::Transparent);
            menuWorm.setOutlineThickness(0);
        }
        if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 185 && sf::Mouse::getPosition().y >= 120 && Char_S.AttackMode) { // evilWizard
            menuEvilWizard.setOutlineColor(sf::Color::Cyan);
            menuEvilWizard.setOutlineThickness(5.f);
        }
        else {
            menuEvilWizard.setOutlineColor(sf::Color::Transparent);
            menuEvilWizard.setOutlineThickness(0);
        }
        if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 260 && sf::Mouse::getPosition().y >= 195 && Char_S.AttackMode) { // boss
            menuBoss.setOutlineColor(sf::Color::Cyan);
            menuBoss.setOutlineThickness(5.f);
        }
        else {
            menuBoss.setOutlineColor(sf::Color::Transparent);
            menuBoss.setOutlineThickness(0);
        }

#pragma endregion interMenu
#pragma region interFirstMenu

        if (sf::Mouse::getPosition().x <= 760 && sf::Mouse::getPosition().x >= 550 && sf::Mouse::getPosition().y <= 450 && sf::Mouse::getPosition().y >= 360) {
            start_Menuu.setOutlineColor(sf::Color::Cyan);
            start_Menuu.setOutlineThickness(5.f);
            quit_Menuu.setOutlineColor(sf::Color::Transparent);
            quit_Menuu.setOutlineThickness(0);
            settings_Menuu.setOutlineColor(sf::Color::Transparent);
            settings_Menuu.setOutlineThickness(0);
        }
        else {
            start_Menuu.setOutlineColor(sf::Color::Transparent);
            start_Menuu.setOutlineThickness(0);

        }
        if (sf::Mouse::getPosition().x <= 800 && sf::Mouse::getPosition().x >= 500 && sf::Mouse::getPosition().y <= 570 && sf::Mouse::getPosition().y >= 480) {
            settings_Menuu.setOutlineColor(sf::Color::Cyan);
            settings_Menuu.setOutlineThickness(5.f);
            start_Menuu.setOutlineColor(sf::Color::Transparent);
            start_Menuu.setOutlineThickness(0);
            quit_Menuu.setOutlineColor(sf::Color::Transparent);
            quit_Menuu.setOutlineThickness(0);
        }
        else {
            settings_Menuu.setOutlineColor(sf::Color::Transparent);
            settings_Menuu.setOutlineThickness(0);


        }
        if (sf::Mouse::getPosition().x <= 735 && sf::Mouse::getPosition().x >= 570 && sf::Mouse::getPosition().y <= 690 && sf::Mouse::getPosition().y >= 600) {
            quit_Menuu.setOutlineColor(sf::Color::Cyan);
            quit_Menuu.setOutlineThickness(5.f);
            start_Menuu.setOutlineColor(sf::Color::Transparent);
            start_Menuu.setOutlineThickness(0);
            settings_Menuu.setOutlineColor(sf::Color::Transparent);
            settings_Menuu.setOutlineThickness(0);
        }
        else {
            quit_Menuu.setOutlineColor(sf::Color::Transparent);
            quit_Menuu.setOutlineThickness(0);

        }
        if (sf::Mouse::getPosition().x <= 600 && sf::Mouse::getPosition().x >= 250 && sf::Mouse::getPosition().y <= 430 && sf::Mouse::getPosition().y >= 380 && Settings_S.inSettings == true) {
            settings_menu_music.setFillColor(sf::Color::Cyan);
        }
        else {
            settings_menu_music.setFillColor(sf::Color::White);
        }
        if (sf::Mouse::getPosition().x <= 600 && sf::Mouse::getPosition().x >= 250 && sf::Mouse::getPosition().y <= 630 && sf::Mouse::getPosition().y >= 580 && Settings_S.inSettings == true) {
            settings_game_music.setFillColor(sf::Color::Cyan);
        }
        else {
            settings_game_music.setFillColor(sf::Color::White);
        }
        if (sf::Mouse::getPosition().x <= 870 && sf::Mouse::getPosition().x >= 250 && sf::Mouse::getPosition().y <= 830 && sf::Mouse::getPosition().y >= 780 && Settings_S.inSettings == true) {
            settings_game_sound.setFillColor(sf::Color::Cyan);
        }
        else {
            settings_game_sound.setFillColor(sf::Color::White);
        }
        if (sf::Mouse::getPosition().x <= 1545 && sf::Mouse::getPosition().x >= 1120 && sf::Mouse::getPosition().y <= 325 && sf::Mouse::getPosition().y >= 280 && Settings_S.inSettings == true) {
            quit_settings_Window_Text.setFillColor(sf::Color::Red);
        }
        else {
            quit_settings_Window_Text.setFillColor(sf::Color::White);
        }

#pragma endregion interFirstMenu

#pragma region Gestion Entree
        if (gameCount == 0) {
            if (sf::Mouse::getPosition().x <= 760 && sf::Mouse::getPosition().x >= 550 && sf::Mouse::getPosition().y <= 450 && sf::Mouse::getPosition().y >= 360 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Settings_S.inSettings == false)
            {
                gameCount++;
            }
            else if (sf::Mouse::getPosition().x <= 800 && sf::Mouse::getPosition().x >= 500 && sf::Mouse::getPosition().y <= 570 && sf::Mouse::getPosition().y >= 480 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Settings_S.inSettings = true;
            }
            else if (sf::Mouse::getPosition().x <= 735 && sf::Mouse::getPosition().x >= 570 && sf::Mouse::getPosition().y <= 690 && sf::Mouse::getPosition().y >= 600 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Settings_S.inSettings == false)
            {
                window.close();
            }
        }
        if (gameCount == 1 && !Boss_S.isAttacking && !Boss_S.isAttacking2 && !Boss_S.isHit) {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && Settings_S.inSettings == false) Settings_S.inSettings = true;
            // Choix attaque
            if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 110 && sf::Mouse::getPosition().y >= 45 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !Char_S.AttackMode)
            {
                Char_S.AttackMode = true;
                Char_S.isAttacking = false;
                Char_S.isHealing = false;
                Char_S.isHit = false;
            }
            // menu d'atk
            else if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 110 && sf::Mouse::getPosition().y >= 45 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Char_S.AttackMode && fireWorm.getAlive() == true && gameCount == 1)
            {
                c_anim_Attack.x = 0;
                Char_S.AttackMode = false;
                Char_S.isAttacking = true;
                Worm_S.isHit = true;
                Char_S.isHealing = false;
                wizard.attack(fireWorm);
                //Cr�ation du rectangle de ce qui se passe
                infoBoxB = true;
                textInfoBox.setString("Vous infligez une attaque au fireWorm !");
                gameCount++;
                countPlay = 0;
                startTime = nowTime;
            }
            else if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 110 && sf::Mouse::getPosition().y >= 45 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Char_S.AttackMode && fireWorm.getAlive() == false) {
                infoBoxB = true;
                textInfoBox.setString("FireWorm est mort !");
            }
            else if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 185 && sf::Mouse::getPosition().y >= 120 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Char_S.AttackMode && evilWizard.getAlive() == true && gameCount == 1)
            {
                Char_S.isHealing = false;
                Char_S.AttackMode = false;
                Char_S.isAttacking = true;
                Evil_S.isHit = true;
                wizard.attack(evilWizard);
                infoBoxB = true;
                textInfoBox.setString("Vous infligez une attaque au Evil Wizard !");
                gameCount++;
                countPlay = 0;
                startTime = nowTime;
            }
            else if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 185 && sf::Mouse::getPosition().y >= 120 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Char_S.AttackMode && evilWizard.getAlive() == false) {
                Char_S.isHealing = false;
                infoBoxB = true;
                textInfoBox.setString("EvilWizard est mort !");
            }
            else if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 260 && sf::Mouse::getPosition().y >= 195 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Char_S.AttackMode && boss.getAlive() == true && gameCount == 1)
            {
                Char_S.AttackMode = false;
                Char_S.isAttacking = true;
                Boss_S.isHit = true;
                wizard.attack(boss);
                infoBoxB = true;
                textInfoBox.setString("Vous infligez une attaque au ??? !");
                gameCount++;
                countPlay = 0;
                startTime = nowTime;
            }
            else if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 260 && sf::Mouse::getPosition().y >= 195 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Char_S.AttackMode && boss.getAlive() == false) {
                infoBoxB = true;
                textInfoBox.setString("??? est mort !");
            }
            // Choix Soin
            else if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 185 && sf::Mouse::getPosition().y >= 120 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && wizard.getHealth() < 500 && gameCount == 1)
            {
                c_anim_Heal.x = 0;
                c_anim.x = 0;
                Char_S.isHealing = true;
                wizard.heal();
                infoBoxB = true;
                textInfoBox.setString("Vous vous soignez de 35 PV");
                gameCount++;
                countPlay = 0;
                startTime = nowTime;
            }
            else if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 185 && sf::Mouse::getPosition().y >= 120 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && wizard.getHealth() >= 500)
            {
                infoBoxB = true;
                textInfoBox.setString("T'es full Vie mec");
                wizard.setHealth(500);
            }
            // Choix passe ton tour
            else if (sf::Mouse::getPosition().x <= 440 && sf::Mouse::getPosition().x >= 20 && sf::Mouse::getPosition().y <= 260 && sf::Mouse::getPosition().y >= 195 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && gameCount == 1)
            {
                infoBoxB = true;
                textInfoBox.setString("Vous passez un tour");
                gameCount++;
                countPlay = 0;
                startTime = nowTime;
            }
        }
#pragma endregion Gestion Entree
#pragma region Gestion IA
        if (boss.getHealth() > 240) {
            boss_sprite.setColor(sf::Color::Cyan);
            boss_sprite_Attack.setColor(sf::Color::Cyan);
            boss_sprite_Attack2.setColor(sf::Color::Cyan);
        }
        else {
            boss_sprite.setColor(sf::Color::White);
            boss_sprite_Attack.setColor(sf::Color::White);
            boss_sprite_Attack2.setColor(sf::Color::White);
        }
        // FireWorm
        if (gameCount == 2 && fireWorm.getAlive() == false) {
            Worm_S.isAttacking = false;
            Worm_S.isHit = false;
            gameCount++;
            Worm_S.readyToPlay = false;
        }
        else if (gameCount == 2 && fireWorm.getAlive() == true) {
            if (nowTime >= startTime + waitTime) {
                countPlay++;
                startTime = nowTime;
            }
            if (countPlay == 2 && gameCount == 2) {
                Worm_S.readyToPlay = true;
                countPlay = 0;
            }
        }
        else if (gameCount == 2 && fireWorm.getAlive() == false && Worm_S.readyToPlay == true) {
            Worm_S.isAttacking = false;
            Worm_S.isHit = false;
            gameCount++;
            Worm_S.readyToPlay = false;
            countPlay = 0;
        }
        if (gameCount == 2 && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && !Worm_S.isHit && fireWorm.getAlive() == true && Worm_S.readyToPlay == true) {
            Worm_S.isHit = false;
            Worm_S.isAttacking = true;
            infoBoxB = true;
            textInfoBox.setString("FireWorm vous inflige 10 points de degats !");
            gameCount++;
            Worm_S.readyToPlay = false;
            countPlay = 0;
        }

        // EvilWizard
        if (gameCount == 3 && evilWizard.getAlive() == false) {
            Evil_S.isAttacking = false;
            Evil_S.isHit = false;
            gameCount++;
            Evil_S.readyToPlay = false;
        }
        else if (gameCount == 3 && evilWizard.getAlive() == true) {
            if (nowTime >= startTime + waitTime) {
                countPlay++;
                startTime = nowTime;
            }
            if (countPlay == 2 && gameCount == 3) {
                Evil_S.readyToPlay = true;
                countPlay = 0;
            }
        }
        else if (gameCount == 3 && evilWizard.getAlive() == false && Evil_S.readyToPlay == true) {
            Evil_S.isAttacking = false;
            Evil_S.isHealing = false;
            Evil_S.isHit = false;
            gameCount++;
            Evil_S.readyToPlay = false;
        }
        if (gameCount == 3 && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && !Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && evilWizard.getAlive() == true && Evil_S.readyToPlay == true) {
            int action = rand() % 3;
            switch (action) {
            case 0:
                Evil_S.isHit = false;
                Evil_S.isAttacking = true;
                evilWizard.attack(wizard);
                Char_S.isHit = true;
                infoBoxB = true;
                textInfoBox.setString("Evil Wizard vous inflige 20 points de degats !");
                gameCount++;
                Evil_S.readyToPlay = false;
                break;

            case 1:
                quiSoigner = 0;
                quiSoigner = rand() % 3;
                if (quiSoigner == 0 && fireWorm.getAlive() == true && fireWorm.getHealth() < 75) {
                    Evil_S.isHealing = true;
                    fireWorm.heal();
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard soigne le FireWorm de 30 PV !");
                    cout << evilWizard.getName() << " soigne" << endl << endl;
                    gameCount++;
                    Evil_S.readyToPlay = false;
                }
                else if (quiSoigner == 1 && evilWizard.getAlive() == true && evilWizard.getHealth() < 150) {
                    Evil_S.isHealing = true;
                    evilWizard.heal();
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard se soigne de 30 PV !");
                    cout << evilWizard.getName() << " soigne" << endl << endl;
                    gameCount++;
                    Evil_S.readyToPlay = false;
                }
                else if (quiSoigner == 2 && boss.getAlive() == true && boss.getHealth() < 300) {
                    Evil_S.isHealing = true;
                    boss.heal();
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard soigne ??? de 30 PV !");
                    cout << evilWizard.getName() << " soigne" << endl << endl;
                    gameCount++;
                    Evil_S.readyToPlay = false;
                }
                else {
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard a rate son incantation !");
                    cout << evilWizard.getName() << " fait caca" << endl << endl;
                    gameCount++;
                    Evil_S.readyToPlay = false;
                }
                break;

            case 2:
                quiSoigner = 0;
                quiSoigner = rand() % 3;
                quiSoigner += 3;
                if (quiSoigner == 3 && fireWorm.getAlive() == true && fireWorm.getHealth() < 75) {
                    Evil_S.isHealing = true;
                    fireWorm.heal();
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard soigne le FireWorm de 30 PV !");
                    cout << evilWizard.getName() << " soigne" << endl << endl;
                    gameCount++;
                    Evil_S.readyToPlay = false;
                }
                else if (quiSoigner == 4 && evilWizard.getAlive() == true && evilWizard.getHealth() < 150) {
                    Evil_S.isHealing = true;
                    evilWizard.heal();
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard se soigne de 30 PV !");
                    cout << evilWizard.getName() << " soigne" << endl << endl;
                    gameCount++;
                    Evil_S.readyToPlay = false;
                }
                else if (quiSoigner == 5 && boss.getAlive() == true && boss.getHealth() < 300) {
                    Evil_S.isHealing = true;
                    boss.heal();
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard soigne ??? de 30 PV !");
                    cout << evilWizard.getName() << " soigne" << endl << endl;
                    gameCount++;
                    Evil_S.readyToPlay = false;
                }
                else {
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard a rate son incantation !");
                    cout << evilWizard.getName() << " fait caca" << endl << endl;
                    gameCount++;
                    Evil_S.readyToPlay = false;
                }
                break;

            default:
                break;
            }
            countPlay = 0;
        }

        // Boss
        if (gameCount == 4 && boss.getAlive() == false) {
            Boss_S.isAttacking = false;
            Boss_S.isHit = false;
            gameCount++;
            Boss_S.readyToPlay = false;
            countPlay = 0;
        }
        else if (gameCount == 4 && boss.getAlive() == true) {
            if (nowTime >= startTime + waitTime) {
                countPlay++;
                startTime = nowTime;
            }
            if (countPlay == 2 && gameCount == 4) {
                Boss_S.readyToPlay = true;
                countPlay = 0;
            }
        }
        else if (gameCount == 4 && boss.getAlive() == false && Boss_S.readyToPlay == true) {
            Boss_S.isAttacking = false;
            Boss_S.isAttacking2 = false;
            Boss_S.isHit = false;
            gameCount++;
            Boss_S.readyToPlay = false;
            countPlay = 0;
        }
        if (gameCount == 4 && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && !Boss_S.isHit && !Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && boss.getAlive() == true && Boss_S.readyToPlay == true) {
            int actionBoss = rand() % 6;
            switch (actionBoss) {
            case 0:
                Boss_S.isHit = false;
                Boss_S.isAttacking = true;
                infoBoxB = true;
                textInfoBox.setString("??? vous inflige 35 points de degats !");
                Boss_S.readyToPlay = false;
                countPlay = 0;
                break;

            case 1:
                cout << boss.getName() << " regarde les mouches voler" << endl << endl;
                gameCount++;
                Boss_S.readyToPlay = false;
                countPlay = 0;
                break;

            case 2:
                Boss_S.isHit = false;
                Boss_S.isAttacking = false;
                Boss_S.isAttacking2 = true;
                infoBoxB = true;
                textInfoBox.setString("??? vous inflige 35 points de degats !");
                Boss_S.readyToPlay = false;
                countPlay = 0;
                break;

            case 3:
                Boss_S.isHit = false;
                Boss_S.isAttacking = true;
                infoBoxB = true;
                textInfoBox.setString("??? vous inflige 35 points de degats !");
                Boss_S.readyToPlay = false;
                countPlay = 0;
                break;

            case 4:
                Boss_S.isHit = false;
                Boss_S.isAttacking = false;
                Boss_S.isAttacking2 = true;
                infoBoxB = true;
                textInfoBox.setString("??? vous inflige 35 points de degats !");
                Boss_S.readyToPlay = false;
                countPlay = 0;
                break;

            case 5:
                cout << boss.getName() << " regarde les mouches voler" << endl << endl;
                gameCount++;
                Boss_S.readyToPlay = false;
                countPlay = 0;
                break;

            default:
                break;
            }
        }
#pragma endregion Gestion IA
#pragma region atelier dessin

        // Effacer la fen�tre
        window.clear();

        if (gameCount == 0) {
            window.draw(sprite_background_Menu);
            window.draw(sprite_background_Menu2);
            window.draw(sprite_background_Menu3);
            window.draw(sprite_background_Menu4);
            window.draw(sprite_background_Menu5);
            window.draw(sprite_background_Menu6);

            window.draw(title_Menu);
            window.draw(start_Menuu);
            window.draw(start_Menu);
            window.draw(settings_Menuu);
            window.draw(settings_Menu);
            window.draw(quit_Menuu);
            window.draw(quit_Menu);
            if (Settings_S.inSettings == true) {
                window.draw(settings_Window);
                window.draw(settings_music);
                window.draw(settings_menu_music);
                window.draw(settings_game_music);
                window.draw(settings_game_sound);

                string Volume_MenuMusic(to_string(Settings_S.volumeMenuMusic));
                text_menu_music.setString(Volume_MenuMusic);
                window.draw(text_menu_music);

                string Volume_fightMusic(to_string(Settings_S.volumeGameMusic));
                text_game_music.setString(Volume_fightMusic);
                window.draw(text_game_music);

                string Volume_gameSound(to_string(Settings_S.volumeGameSound));
                text_game_sound.setString(Volume_gameSound);
                window.draw(text_game_sound);

                if (sf::Mouse::getPosition().x <= 600 && sf::Mouse::getPosition().x >= 250 && sf::Mouse::getPosition().y <= 430 && sf::Mouse::getPosition().y >= 380 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Settings_S.inSettings == true) {
                    Settings_S.inMenuMusic = true;
                    Settings_S.inGameMusic = false;
                    Settings_S.inGameSound = false;
                }
                else if (sf::Mouse::getPosition().x <= 600 && sf::Mouse::getPosition().x >= 250 && sf::Mouse::getPosition().y <= 630 && sf::Mouse::getPosition().y >= 580 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Settings_S.inSettings == true) {
                    Settings_S.inGameMusic = true;
                    Settings_S.inMenuMusic = false;
                    Settings_S.inGameSound = false;
                }
                else if (sf::Mouse::getPosition().x <= 870 && sf::Mouse::getPosition().x >= 250 && sf::Mouse::getPosition().y <= 830 && sf::Mouse::getPosition().y >= 780 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Settings_S.inSettings == true) {
                    Settings_S.inGameSound = true;
                    Settings_S.inMenuMusic = false;
                    Settings_S.inGameMusic = false;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Settings_S.inMenuMusic == true) {
                    Settings_S.volumeMenuMusic -= 5.f;
                    if (Settings_S.volumeMenuMusic <= 0.f) Settings_S.volumeMenuMusic = 0.f;
                    cout << "-5 pour menu musique";
                    menuMusic.setVolume(Settings_S.volumeMenuMusic);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && Settings_S.inMenuMusic == true) {
                    Settings_S.volumeMenuMusic += 5.f;
                    if (Settings_S.volumeMenuMusic >= 100.f) Settings_S.volumeMenuMusic = 100.f;
                    cout << "+5 pour menu musique";
                    menuMusic.setVolume(Settings_S.volumeMenuMusic);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Settings_S.inGameMusic == true) {
                    Settings_S.volumeGameMusic -= 5.f;
                    if (Settings_S.volumeGameMusic <= 0.f) Settings_S.volumeGameMusic = 0.f;
                    cout << "-5 pour game musique";
                    fightMusic.setVolume(Settings_S.volumeGameMusic);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && Settings_S.inGameMusic == true) {
                    Settings_S.volumeGameMusic += 5.f;
                    if (Settings_S.volumeGameMusic >= 100.f) Settings_S.volumeGameMusic = 100.f;
                    cout << "+5 pour game musique";
                    fightMusic.setVolume(Settings_S.volumeGameMusic);

                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Settings_S.inGameSound == true) {
                    Settings_S.volumeGameSound -= 5.f;
                    if (Settings_S.volumeGameSound <= 0.f) Settings_S.volumeGameSound = 0.f;
                    cout << "-5 pour game sound";
                    soundWizardAttack.setVolume(Settings_S.volumeGameSound);
                    soundFireWormAttack.setVolume(Settings_S.volumeGameSound);
                    soundHeal.setVolume(Settings_S.volumeGameSound);

                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && Settings_S.inGameSound == true) {
                    Settings_S.volumeGameSound += 5.f;
                    if (Settings_S.volumeGameMusic >= 100.f) Settings_S.volumeGameMusic = 100.f;
                    cout << "+5 pour game sound";
                    soundWizardAttack.setVolume(Settings_S.volumeGameSound);
                    soundFireWormAttack.setVolume(Settings_S.volumeGameSound);
                    soundHeal.setVolume(Settings_S.volumeGameSound);
                    soundEvilWizardAttack.setVolume(Settings_S.volumeGameSound);
                    soundBossAttack.setVolume(Settings_S.volumeGameSound);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    Settings_S.inSettings = false;
                }
            }
        }
        if (gameCount >= 1) {

            // Dessiner la forme
            window.draw(sprite_background);

#pragma region animation qui marche 

            if (!Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && wizard.getAlive() == true) {
                window.draw(perso_sprite);
            }///////////////////////////////////

            else if (Char_S.isAttacking && wizard.getAlive() == true && !Boss_S.isAttacking && !Boss_S.isAttacking2) {
                c_anim_Attack.x++;
                if (c_anim_Attack.x * 256 >= perso_texture_Attack.getSize().x)
                    c_anim_Attack.x = 0;
                perso_sprite_Attack.setTextureRect(sf::IntRect(c_anim_Attack.x * 256, 0, 256, 256));
                Char_S.countAnimAtk++;
                if (Char_S.countAnimAtk == 2) {
                    soundWizardAttack.play();
                }
                if (Char_S.countAnimAtk == 7) {
                    Char_S.isAttacking = false;
                }
                // faut vraiment mettre un timeur pour permettre de faire les tours moins rapidement;
                window.draw(perso_sprite_Attack);
            }///////////////////////////////////
            else if (Char_S.isHealing && wizard.getAlive() == true && !Char_S.isAttacking) {
                c_anim_Heal.x++;
                if (c_anim_Heal.x * 256 >= perso_texture_Heal.getSize().x)
                    c_anim_Heal.x = 0;
                perso_sprite_Heal.setTextureRect(sf::IntRect(c_anim_Heal.x * 256, 0, 256, 256));
                perso_sprite_Heal.setColor(sf::Color(0, 255, 0));
                Char_S.countAnimHeal++;
                if (Char_S.countAnimHeal == 7) {
                    soundFireWormAttack.stop();
                    soundWizardAttack.stop();
                    soundHeal.play();
                }
                if (Char_S.countAnimHeal == 10) {
                    Char_S.isHealing = false;
                }
                window.draw(perso_sprite_Heal);
            }///////////////////////////////////
            else if (Char_S.isHit && !Char_S.isAttacking && !Char_S.isHealing && wizard.getAlive() == true) {
                c_anim_Hit.x++;
                if (c_anim_Hit.x * 256 >= perso_texture_Hit.getSize().x)
                    c_anim_Hit.x = 0;
                perso_sprite_Hit.setTextureRect(sf::IntRect(c_anim_Hit.x * 256, 0, 256, 256));
                perso_sprite_Hit.setColor(sf::Color(255, 0, 0));
                Char_S.countAnimHit++;
                if (Char_S.countAnimHit == 4) {
                    Char_S.isHit = false;
                }
                window.draw(perso_sprite_Hit);
            }///////////////////////////////////
            else if (Char_S.DeathCount == 0) {
                if (wizard.getAlive() == false) {
                    c_anim_Death.x++;
                    if (c_anim_Death.x * 256 >= perso_texture_Death.getSize().x)
                        c_anim_Death.x = perso_texture_Death.getSize().x;
                    perso_sprite_Death.setTextureRect(sf::IntRect(c_anim_Death.x * 256, 0, 256, 256));
                    Char_S.countAnimDeath++;
                    if (Char_S.countAnimDeath == 4) {
                        Char_S.isDead = false;
                        Char_S.DeathCount++;
                        //Char_S.printBody = true;
                    }
                    window.draw(perso_sprite_Death);
                }
            }///////////////////////////////////

            ////////// Worm ///////////

            if (!Worm_S.isHit && !Worm_S.isAttacking && !Worm_S.isHealing && fireWorm.getAlive() == true) {
                window.draw(fireWorm_sprite);
            }///////////////////////////////////

            else if (!Worm_S.isHit && !Worm_S.isAttacking && Worm_S.isHealing && fireWorm.getAlive() == true) {
                fireWorm_sprite.setColor(sf::Color(0, 255, 0));
            }///////////////////////////////////


            else if (Worm_S.isAttacking && !Char_S.isAttacking && !Char_S.isHealing && !Worm_S.isHit && fireWorm.getAlive() == true) {
                f_anim_Attack.x -= 180;
                if (f_anim_Attack.x == 0) f_anim_Attack.x = 2880;
                fireWorm_sprite_Attack.setTextureRect(sf::IntRect(f_anim_Attack.x - 180, 0, 180, 180));
                Worm_S.countAnimAtk++;
                if (Worm_S.countAnimAtk == 8) {
                    soundWizardAttack.stop();
                    soundFireWormAttack.play();
                }
                if (Worm_S.countAnimAtk == 10) {
                    fireWorm.attack(wizard);
                    Char_S.isHit = true;
                }
                if (Worm_S.countAnimAtk == 16) {
                    Worm_S.isAttacking = false;
                }
                window.draw(fireWorm_sprite_Attack);
            }///////////////////////////////////

            else if (Worm_S.isHit && !Char_S.isHealing && fireWorm.getAlive() == true) {

                f_anim_Hit.x -= 180;
                if (f_anim_Hit.x == 0) f_anim_Hit.x = 540;
                fireWorm_sprite_Hit.setTextureRect(sf::IntRect(f_anim_Hit.x - 180, 0, 180, 180));
                fireWorm_sprite_Hit.setColor(sf::Color(255, 0, 0));
                Worm_S.countAnimHit++;
                if (Worm_S.countAnimHit == 4) {
                    Worm_S.isHit = false;
                }
                window.draw(fireWorm_sprite_Hit);
            }///////////////////////////////////
            else if (Worm_S.DeathCount == 0) {
                if (fireWorm.getAlive() == false) {
                    f_anim_Death.x -= 180;
                    fireWorm_sprite_Death.setTextureRect(sf::IntRect(f_anim_Death.x - 180, 0, 180, 180));
                    Worm_S.countAnimDeath++;
                    if (Worm_S.countAnimDeath == 8) {
                        Worm_S.isDead = false;
                        Worm_S.DeathCount++;
                        Worm_S.printBody = true;
                    }
                    window.draw(fireWorm_sprite_Death);
                }
            }
            if (Worm_S.printBody == true) {
                f_anim_Death.x = 0;
                fireWorm_sprite_Death.setTextureRect(sf::IntRect(f_anim_Death.x * 180, 0, 180, 180));
                window.draw(fireWorm_sprite_Death);
            }


        ////////// Evil Wizard ///////////

            if (!Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && evilWizard.getAlive() == true) {
                window.draw(evilWizard_sprite);
            }
            else if (Evil_S.isAttacking && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isAttacking && !Char_S.isHealing && evilWizard.getAlive() == true) { //&& wormisHit/atk etc pour vraiment mettre de l'ordre dans la boucle
                e_anim_Attack.x -= 450;
                if (e_anim_Attack.x == 0) e_anim_Attack.x = 3600;
                evilWizard_sprite_Attack.setTextureRect(sf::IntRect(e_anim_Attack.x - 450, 0, 450, 450));
                Evil_S.countAnimAtk++;
                if (Evil_S.countAnimAtk == 1) {
                    soundEvilWizardAttack.setPlayingOffset(sf::seconds(14));
                    soundEvilWizardAttack.play();
                }
                if (Evil_S.countAnimAtk == 9) {
                    Evil_S.isAttacking = false;
                }
                window.draw(evilWizard_sprite_Attack);
            }
            else if (Evil_S.isHealing && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && evilWizard.getAlive() == true) {
                e_anim_Heal.x++;
                if (e_anim_Heal.x * 450 >= evilWizard_texture_Heal.getSize().x)
                    e_anim_Heal.x = 0;
                evilWizard_sprite_Heal.setTextureRect(sf::IntRect(e_anim_Heal.x * 450, 0, 450, 450));
                evilWizard_sprite_Heal.setColor(sf::Color(0, 255, 0));
                Evil_S.countAnimHeal++;
                if (Evil_S.countAnimHeal == 2) {
                    soundWizardAttack.stop();
                    soundFireWormAttack.stop();
                    soundHeal.play();
                }
                if (Evil_S.countAnimHeal == 9) {
                    Evil_S.isHealing = false;
                }
                window.draw(evilWizard_sprite_Heal);
            }
            else if (Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && evilWizard.getAlive() == true) {
                e_anim_Hit.x -= 450;
                if (e_anim_Hit.x == 0) e_anim_Hit.x = 1800;
                evilWizard_sprite_Hit.setTextureRect(sf::IntRect(e_anim_Hit.x - 450, 0, 450, 450));
                evilWizard_sprite_Hit.setColor(sf::Color(255, 0, 0));
                Evil_S.countAnimHit++;
                if (Evil_S.countAnimHit == 4) {
                    Evil_S.isHit = false;
                }
                window.draw(evilWizard_sprite_Hit);
            }
            else if (Evil_S.DeathCount == 0) {
                if (evilWizard.getAlive() == false) {
                    e_anim_Death.x -= 450;
                    evilWizard_sprite_Death.setTextureRect(sf::IntRect(e_anim_Death.x - 450, 0, 450, 450));
                    Evil_S.countAnimDeath++;
                    if (Evil_S.countAnimDeath == 5) {
                        Evil_S.isDead = false;
                        Evil_S.DeathCount++;
                        Evil_S.printBody = true;
                    }
                    window.draw(evilWizard_sprite_Death);
                }
            }
            if (Evil_S.printBody == true) {
                e_anim_Death.x = 0;
                evilWizard_sprite_Death.setTextureRect(sf::IntRect(e_anim_Death.x * 450, 0, 450, 450));
                window.draw(evilWizard_sprite_Death);
            }

            ////////// Boss ///////////

            if (!Boss_S.isAttacking && !Boss_S.isHit && !Boss_S.isAttacking2 && !Boss_S.isHealing && boss.getAlive() == true) {
                window.draw(boss_sprite);
            }
            else if (!Boss_S.isHit && !Boss_S.isAttacking && Boss_S.isHealing && boss.getAlive() == true) {
                boss_sprite.setColor(sf::Color(0, 255, 0));
            }///////////////////////////////////
            else if (Boss_S.isAttacking && !Boss_S.isAttacking2 && !Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isAttacking && !Char_S.isHealing && !Worm_S.isDead && !Evil_S.isDead && boss.getAlive() == true) {
                b_anim_Attack.x -= 800;
                if (b_anim_Attack.x == 0) b_anim_Attack.x = 6400;
                boss_sprite_Attack.setTextureRect(sf::IntRect(b_anim_Attack.x - 800, 0, 800, 800));
                Boss_S.countAnimAtk++;
                if (Boss_S.countAnimAtk == 1) {
                    soundBossAttack.setPlayingOffset(sf::seconds(0.5));
                    soundBossAttack.play();
                }
                if (Boss_S.countAnimAtk == 5) {
                    boss.attack(wizard);
                    Char_S.isHit = true;
                }
                if (Boss_S.countAnimAtk == 8) {
                    Boss_S.isAttacking = false;
                    gameCount++;
                }
                window.draw(boss_sprite_Attack);
            }
            else if (Boss_S.isHit && !Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && boss.getAlive() == true) {
                b_anim_Hit.x -= 800;
                if (b_anim_Hit.x == 0) b_anim_Hit.x = 2400;
                boss_sprite_Hit.setTextureRect(sf::IntRect(b_anim_Hit.x - 800, 0, 800, 800));
                boss_sprite_Hit.setColor(sf::Color(255, 0, 0));
                Boss_S.countAnimHit++;
                if (Boss_S.countAnimHit == 3) {
                    Boss_S.isHit = false;
                }
                window.draw(boss_sprite_Hit);
            }
            else if (Boss_S.isAttacking2 && !Boss_S.isAttacking && !Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isAttacking && !Char_S.isHealing && !Worm_S.isDead && !Evil_S.isDead && boss.getAlive() == true) {
                b_anim_Attack2.x -= 800;
                if (b_anim_Attack2.x == 0) b_anim_Attack2.x = 6400;
                boss_sprite_Attack2.setTextureRect(sf::IntRect(b_anim_Attack2.x - 800, 0, 800, 800));
                Boss_S.countAnimAtk2++;
                if (Boss_S.countAnimAtk2 == 1) {
                   soundBossAttack.setPlayingOffset(sf::seconds(0.5));
                    soundBossAttack.play();
                }
                if (Boss_S.countAnimAtk2 == 5) {
                    boss.attack(wizard);
                    Char_S.isHit = true;
                }
                if (Boss_S.countAnimAtk2 == 8) {
                    Boss_S.isAttacking2 = false;
                    gameCount++;
                }
                window.draw(boss_sprite_Attack2);
            }
            else if (Boss_S.DeathCount == 0) {
                if (boss.getAlive() == false) {
                    b_anim_Death.x -= 800;
                    boss_sprite_Death.setTextureRect(sf::IntRect(b_anim_Death.x - 800, 0, 800, 800));
                    Boss_S.countAnimDeath++;
                    if (Boss_S.countAnimDeath == 6) {
                        Boss_S.isDead = false;
                        Boss_S.DeathCount++;
                        Boss_S.printBody = true;
                        gameCount++;
                    }
                    window.draw(boss_sprite_Death);
                }
            }
            if (Boss_S.printBody == true) {
                b_anim_Death.x = 0;
                boss_sprite_Death.setTextureRect(sf::IntRect(b_anim_Death.x * 800, 0, 800, 800));
                window.draw(boss_sprite_Death);
            }
#pragma endregion animation qui marche

            if ((fireWorm.getAlive() == true || evilWizard.getAlive() == true || boss.getAlive() == true) && wizard.getAlive() == true) {
                if (gameCount == 1 && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && wizard.getAlive() == true) {
                    window.draw(menuBackground);
                    window.draw(menuAtk);
                    window.draw(textAtk);
                    window.draw(menuHeal);
                    window.draw(textHeal);
                    window.draw(menuSkip);
                    window.draw(textSkip);
                }
                if (Char_S.AttackMode && gameCount == 1 && wizard.getAlive() == true) {
                    window.draw(menuWhoAtk);
                    window.draw(menuWorm);
                    window.draw(textMenuWorm);
                    window.draw(menuEvilWizard);
                    window.draw(textMenuEvilWizard);
                    window.draw(menuBoss);
                    window.draw(textMenuBoss);
                }

                window.draw(infoBox);
                window.draw(textInfoBox);
            }

            if (wizard.getAlive() == true) {
                window.draw(UI_Character);
                window.draw(UI_Character_PV);
                window.draw(UI_Character_PV2);
                string Vie_Char(to_string(wizard.getHealth()));
                UI_Character_PV.setString(Vie_Char);
            }
            if (fireWorm.getAlive() == true) {
                window.draw(UI_Worm);
                window.draw(UI_Worm_PV);
                window.draw(UI_Worm_PV2);
                string Vie_Worm(to_string(fireWorm.getHealth()));
                UI_Worm_PV.setString(Vie_Worm);
            }
            if (evilWizard.getAlive() == true) {
                window.draw(UI_Evil);
                window.draw(UI_Evil_PV);
                window.draw(UI_Evil_PV2);
                string Vie_Evil(to_string(evilWizard.getHealth()));
                UI_Evil_PV.setString(Vie_Evil);
            }
            if (boss.getAlive() == true) {
                window.draw(UI_Boss);
                window.draw(UI_Boss_PV);
                window.draw(UI_Boss_PV2);
                string Vie_Boss(to_string(boss.getHealth()));
                UI_Boss_PV.setString(Vie_Boss);
            }
        }

        if (Settings_S.inSettings == true && gameCount == 1) {
            auto nowSetTime = chrono::steady_clock::now();
            window.draw(settings_Window);
            window.draw(settings_music);
            window.draw(settings_menu_music);
            window.draw(settings_game_music);
            window.draw(settings_game_sound);
            window.draw(quit_settings_Window_Text);

            string Volume_MenuMusic(to_string(Settings_S.volumeMenuMusic));
            text_menu_music.setString(Volume_MenuMusic);
            window.draw(text_menu_music);

            string Volume_fightMusic(to_string(Settings_S.volumeGameMusic));
            text_game_music.setString(Volume_fightMusic);
            window.draw(text_game_music);

            string Volume_gameSound(to_string(Settings_S.volumeGameSound));
            text_game_sound.setString(Volume_gameSound);
            window.draw(text_game_sound);

            if (sf::Mouse::getPosition().x <= 600 && sf::Mouse::getPosition().x >= 250 && sf::Mouse::getPosition().y <= 430 && sf::Mouse::getPosition().y >= 380 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Settings_S.inSettings == true) {
                Settings_S.inMenuMusic = true;
                Settings_S.inGameMusic = false;
                Settings_S.inGameSound = false;
            }
            else if (sf::Mouse::getPosition().x <= 600 && sf::Mouse::getPosition().x >= 250 && sf::Mouse::getPosition().y <= 630 && sf::Mouse::getPosition().y >= 580 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Settings_S.inSettings == true) {
                Settings_S.inGameMusic = true;
                Settings_S.inMenuMusic = false;
                Settings_S.inGameSound = false;
            }
            else if (sf::Mouse::getPosition().x <= 870 && sf::Mouse::getPosition().x >= 250 && sf::Mouse::getPosition().y <= 830 && sf::Mouse::getPosition().y >= 780 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Settings_S.inSettings == true) {
                Settings_S.inGameSound = true;
                Settings_S.inMenuMusic = false;
                Settings_S.inGameMusic = false;
            }
            else if (sf::Mouse::getPosition().x <= 1545 && sf::Mouse::getPosition().x >= 1120 && sf::Mouse::getPosition().y <= 325 && sf::Mouse::getPosition().y >= 280 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Settings_S.inSettings == true) {
                Settings_S.inGameSound = false;
                Settings_S.inMenuMusic = false;
                Settings_S.inGameMusic = false;
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Settings_S.inMenuMusic == true) {
                Settings_S.volumeMenuMusic -= 10.f;
                if (Settings_S.volumeMenuMusic <= 0.f) Settings_S.volumeMenuMusic = 0.f;
                cout << "-10 pour menu musique";
                menuMusic.setVolume(Settings_S.volumeMenuMusic);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && Settings_S.inMenuMusic == true) {
                Settings_S.volumeMenuMusic += 10.f;
                if (Settings_S.volumeMenuMusic >= 100.f) Settings_S.volumeMenuMusic = 100.f;
                cout << "+10 pour menu musique";
                menuMusic.setVolume(Settings_S.volumeMenuMusic);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Settings_S.inGameMusic == true) {
                Settings_S.volumeGameMusic -= 10.f;
                if (Settings_S.volumeGameMusic <= 0.f) Settings_S.volumeGameMusic = 0.f;
                cout << "-10 pour game musique";
                fightMusic.setVolume(Settings_S.volumeGameMusic);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && Settings_S.inGameMusic == true) {
                Settings_S.volumeGameMusic += 10.f;
                if (Settings_S.volumeGameMusic >= 100.f) Settings_S.volumeGameMusic = 100.f;
                cout << "+10 pour game musique";
                fightMusic.setVolume(Settings_S.volumeGameMusic);

            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Settings_S.inGameSound == true) {
                Settings_S.volumeGameSound -= 10.f;
                if (Settings_S.volumeGameSound <= 0.f) Settings_S.volumeGameSound = 0.f;
                cout << "-10 pour game sound";
                soundWizardAttack.setVolume(Settings_S.volumeGameSound);
                soundFireWormAttack.setVolume(Settings_S.volumeGameSound);
                soundHeal.setVolume(Settings_S.volumeGameSound);

            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && Settings_S.inGameSound == true) {
                Settings_S.volumeGameSound += 10.f;
                if (Settings_S.volumeGameMusic >= 100.f) Settings_S.volumeGameMusic = 100.f;
                cout << "+10 pour game sound";
                soundWizardAttack.setVolume(Settings_S.volumeGameSound);
                soundFireWormAttack.setVolume(Settings_S.volumeGameSound);
                soundHeal.setVolume(Settings_S.volumeGameSound);
                soundEvilWizardAttack.setVolume(Settings_S.volumeGameSound);
                soundBossAttack.setVolume(Settings_S.volumeGameSound);
            }
            if (nowSetTime >= startSetTime + waitSetTime) {
                Settings_S.settingsCountPlay++;
                startSetTime = nowSetTime;
            }
            if (Settings_S.settingsCountPlay >= 2) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    Settings_S.inSettings = false;
                    Settings_S.settingsCountPlay = 0;
                }
            }
        }

#pragma region WinCondition
        if (fireWorm.getAlive() == false && evilWizard.getAlive() == false && boss.getAlive() == false && gameCount >= 1) {
            window.draw(textWin);
            window.draw(quit_End);
            window.draw(quit_EndText);
            window.draw(restart_End);
            window.draw(restart_EndText);
            fightMusic.stop();
            Settings_S.winMusic = true;
            if (Settings_S.winMusic == true) {
                endCount++;
                if (nowTime >= startTime + waitTime) {
                    countPlay++;
                    startTime = nowTime;
                }
                if (countPlay == 4) {
                    endWinMusic.setPlayingOffset(sf::seconds(4.39));
                    countPlay = 0;
                }
            }
            if (sf::Mouse::getPosition().x <= 1015 && sf::Mouse::getPosition().x >= 830 && sf::Mouse::getPosition().y <= 800 && sf::Mouse::getPosition().y >= 710) {
                quit_End.setOutlineColor(sf::Color::Cyan);
                quit_End.setOutlineThickness(5.f);
            }
            else {
                quit_End.setOutlineColor(sf::Color::Transparent);
                quit_End.setOutlineThickness(0.f);
            }
            if (sf::Mouse::getPosition().x <= 1015 && sf::Mouse::getPosition().x >= 830 && sf::Mouse::getPosition().y <= 800 && sf::Mouse::getPosition().y >= 710 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                window.close();
            }

            if (sf::Mouse::getPosition().x <= 1070 && sf::Mouse::getPosition().x >= 770 && sf::Mouse::getPosition().y <= 650 && sf::Mouse::getPosition().y >= 560) {
                restart_End.setOutlineColor(sf::Color::Cyan);
                restart_End.setOutlineThickness(5.f);
            }
            else {
                restart_End.setOutlineColor(sf::Color::Transparent);
                restart_End.setOutlineThickness(0.f);
            }
            if (sf::Mouse::getPosition().x <= 1070 && sf::Mouse::getPosition().x >= 770 && sf::Mouse::getPosition().y <= 650 && sf::Mouse::getPosition().y >= 560 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                cout << "restart";
                restartGame = true;
            }
        }
        else if (wizard.getAlive() == false && gameCount >= 1) {
            window.draw(textDefeat);
            window.draw(quit_End);
            window.draw(quit_EndText);
            window.draw(restart_End);
            window.draw(restart_EndText);
            fightMusic.stop();
            Settings_S.loseMusic = true;
            if (Settings_S.loseMusic == true) {
                endCount++;
            }
            if (sf::Mouse::getPosition().x <= 1015 && sf::Mouse::getPosition().x >= 830 && sf::Mouse::getPosition().y <= 800 && sf::Mouse::getPosition().y >= 710) {
                quit_End.setOutlineColor(sf::Color::Cyan);
                quit_End.setOutlineThickness(5.f);
            }
            else {
                quit_End.setOutlineColor(sf::Color::Transparent);
                quit_End.setOutlineThickness(0.f);
            }
            if (sf::Mouse::getPosition().x <= 1015 && sf::Mouse::getPosition().x >= 830 && sf::Mouse::getPosition().y <= 800 && sf::Mouse::getPosition().y >= 710 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                window.close();
            }

            if (sf::Mouse::getPosition().x <= 1070 && sf::Mouse::getPosition().x >= 770 && sf::Mouse::getPosition().y <= 650 && sf::Mouse::getPosition().y >= 560) {
                restart_End.setOutlineColor(sf::Color::Cyan);
                restart_End.setOutlineThickness(5.f);
            }
            else {
                restart_End.setOutlineColor(sf::Color::Transparent);
                restart_End.setOutlineThickness(0.f);
            }
            if (sf::Mouse::getPosition().x <= 1070 && sf::Mouse::getPosition().x >= 770 && sf::Mouse::getPosition().y <= 650 && sf::Mouse::getPosition().y >= 560 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                cout << "restart";
                restartGame = true;
            }
        }
#pragma endregion WinCondition
        // Afficher le contenu
        window.display();
#pragma endregion atelier dessin
    }
    return 0;
}