#include "Entity.hpp"

Entity::Entity(string n, Vector2f pos, int dmg, int l) : name(n), position(pos), damage(dmg), life(l) {}

Entity::~Entity() {}

void Entity::animationManager(float deltaTime, Vector2i vector, Texture texture, float timeAnim)
{
    switch (state) {
    case State::IDLE:
    {
        /*
        soundManager(Shared::bufferRun);
        shape.setTexture(&Shared::playerTexture);
        animRun.y = 0; // reset le cycle d'anim sur y car on a pas d'anim sur l'axe y
        animJump.x = 0;

        if (clockRun.getElapsedTime().asMilliseconds() > 55) { // horloge qui permet de modifier la vitesse d'anim
            animRun.x++; // on met +1 a notre anim donc change de "case"
            clockRun.restart(); // on restart la clock pour continuer
        }
        if (animRun.x > 5) // si on atteint la "fin de l'image" (la fin des "cases")
            animRun.x = 0; // on reset l'image et on recommence
        shape.setTextureRect(sf::IntRect({ animRun.x * CHARACTER_ASSET_SIZE, animRun.y * CHARACTER_ASSET_SIZE }, { CHARACTER_ASSET_SIZE, CHARACTER_ASSET_SIZE })); // on set le rect pour prendre que le 120x80
        break;
        */
    }
    }
}

void Entity::attack(Entity& entity)
{
    entity.life -= damage;

    if (entity.life <= 0) {
        entity.life = 0;
    }
}

void Entity::updateLife()
{
    if (life <= 0) {
        life = 0;
        isAlive = false;
    }
}
