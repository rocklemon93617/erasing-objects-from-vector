#include "Bullet.h"
#include <iostream>
#include<SFML/Graphics.hpp>
#include<stdio.h> 

using namespace std;
using namespace sf;



Bullet::Bullet(float x, float y)
{
	bullet.setFillColor(Color::White);
	bullet.setOrigin(radius, radius);
	bullet.setPosition(x, y);
	bullet.setRadius(radius);
}



void Bullet::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(bullet, state);
}

void Bullet::update()
{
	bullet.move(bvelocity * velocity);
}

float Bullet::up()
{
	return bullet.getPosition().y - radius;
}

float Bullet::down()
{
	return bullet.getPosition().y + radius;
}

float Bullet::left()
{
	return bullet.getPosition().x - radius;
}

float Bullet::right()
{
	return bullet.getPosition().x + radius;
}
