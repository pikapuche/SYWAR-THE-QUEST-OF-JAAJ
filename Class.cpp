/*
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

class Entities {
protected :
	string e_name;
	int e_damage;
	int e_CoordX, e_CoordY;
	int e_health;
	bool e_isAlive = true;


public :
	Entities(bool A) : e_health(), e_damage(), e_CoordX(), e_CoordY(), e_isAlive(A) {}

	void printInfos() {
		cout << "Degats : " << e_damage << "Coordonnees : " << e_CoordX << ", " << e_CoordY << endl << endl;
	}

	virtual void attack(Entities& target) = 0;

	virtual int losePV(int damage) {
		e_health -= damage;
		if (e_health <= 0) {
			e_health = 0;
			e_isAlive = false;
		}
		return e_health;
	}
	virtual int getHealth() {
		return e_health;
	}
	virtual int getCoordX() {
		return e_CoordX;
	}
	virtual int getCoordY() {
		return e_CoordY;
	}
	virtual string getName() {
		return e_name;
	}
	virtual bool getAlive() {
		return e_isAlive;
	}
	virtual int heal() {
		e_health += 30;
		return e_health;
	}
	virtual int setHealth(int pv) {
		e_health = pv;
		return e_health;
	}
	virtual int HealthReset(int pv) {
		e_health = pv;
		return e_health;
	}
	virtual bool LifeReset() {
		e_isAlive = true;
		return e_isAlive;
	}
};

class Character : public Entities {
protected : 
	string c_name;
	int c_CoordX, c_CoordY;
	int c_health;
	bool c_isAlive = true;



public : 
	Character (string n, int CX, int CY, int h) : c_name(n), c_CoordX(CX), c_CoordY(CY), c_health(h), Entities(true) {}

	void attack(Entities& target) override {}

	int losePV(int damage) override {
		c_health -= damage;
		if (c_health <= 0) {
			c_health = 0;
			c_isAlive = false;
		}
		return c_health;
	}
	int getHealth() override {
		return c_health;
	}
	int getCoordX() override {
		return c_CoordX;
	}
	int getCoordY() override {
		return c_CoordY;
	}
	string getName() override {
		return c_name;
	}
	bool getAlive() override {
		return c_isAlive;
	}
	int heal() override {
		c_health += 35;
		return c_health;
	}
	int setHealth(int pv) override {
		c_health = pv;
		return c_health;
	}
	int HealthReset(int pv) override {
		c_health = pv;
		return c_health;
	}
	bool LifeReset() {
		c_isAlive = true;
		return c_isAlive;
	}
};

class Enemies : public Entities {
protected : 
	string E_name;
	int E_CoordX, E_CoordY;
	int E_health;
	bool E_isAlive = true;


public : 
	Enemies(string n, int CX, int CY, int h) : E_name(n), E_CoordX(CX), E_CoordY(CY), E_health(h), Entities(true) {}

	void attack(Entities& target) override {}

	int losePV(int damage) override {
		E_health -= damage;
		if (E_health <= 0) {
			E_health = 0;
			E_isAlive = false;
		}
		return E_health;
	}
	int getHealth() override {
		return E_health;
	}
	int getCoordX() override {
		return E_CoordX;
	}
	int getCoordY() override {
		return E_CoordY;
	}
	string getName() override {
		return E_name;
	}
	bool getAlive() override {
		return E_isAlive;
	}
	int heal() override {
		E_health += 30;
		return E_health;
	}
	int setHealth(int pv) override {
		E_health = pv;
		return E_health;
	}
	int HealthReset(int pv) override {
		E_health = pv;
		return E_health;
	}
	bool LifeReset() {
		E_isAlive = true;
		return E_isAlive;
	}
};

class Wizard : public Character {
public :
	Wizard() : Character("William l'intervenant", 225, 625, 500) {}
	void attack(Entities& target) override {
		int damage = 80;
		target.losePV(damage);
		cout << target.getHealth() << " PV" << endl << endl;
		cout << c_name << " lance une attaque sur " << target.getName() << " lui infligeant " << damage << " points de degats " << endl << endl;
	}
}; 

class FireWorm : public Enemies {
public:
	FireWorm() : Enemies("Fire Worm, THE ELDEN LORD", 925, 650, 75) {}
	void attack(Entities& target) override {
		int damage = 10;
		target.losePV(damage);
		cout << target.getHealth() << " PV" << endl << endl;
		cout << E_name << " lance une attaque sur " << target.getName() << " lui infligeant " << damage << " points de degats " << endl << endl;
	}

}; 

class EvilWizard : public Enemies {
public:
	EvilWizard() : Enemies("Omariu, THE LITTLE SHIT", 1125, 755, 150) {}
	void attack(Entities& target) override {
		int damage = 20;
		target.losePV(damage);
		cout << target.getHealth() << " PV" << endl << endl;
		cout << E_name << "lance une attaque sur " << target.getName() << " lui infligeant " << damage << " points de degats " << endl << endl;
	}
}; 

class Boss : public Enemies {
public:
	Boss() : Enemies("???", 1400, 625, 240) {}
	void attack(Entities& target) override {
		int damage = 35;
		target.losePV(damage);
		cout << target.getHealth() << " PV" << endl << endl;
		cout << E_name << "lance une attaque sur " << target.getName() << " lui infligeant " << damage << " points de degats " << endl << endl;
	}
};
*/