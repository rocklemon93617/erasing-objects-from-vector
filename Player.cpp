#include "Player.h"
#include <iostream>
#include<SFML/Graphics.hpp>
#include<stdio.h> 

using namespace std;
using namespace sf;



Player::Player(float x, float y)
{
	player.setFillColor(Color::White);
	player.setOrigin(radius, radius);
	player.setPosition(x, y);
	player.setRadius(radius);
}

void Player::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(player, state);
}

void Player::update(Vector2f winsize)
{
	if (Keyboard::isKeyPressed(Keyboard::A) && left() > 0.f)
	{
		pvelocity.x = -velocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && right() < winsize.x)
	{
		pvelocity.x = velocity;
	}
	else
	{
		pvelocity.x = 0.f;
	}

	if (Keyboard::isKeyPressed(Keyboard::W) && up() > 0.f)
	{
		pvelocity.y = -velocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) && down() < winsize.y)
	{
		pvelocity.y = velocity;
	}
	else
	{
		pvelocity.y = 0.f;
	}

	player.move(pvelocity);
}

float Player::up()
{
	return player.getPosition().y - radius;
}

float Player::down()
{
	return player.getPosition().y + radius;
}

float Player::left()
{
	return player.getPosition().x - radius;
}

float Player::right()
{
	return player.getPosition().x + radius;
}

Vector2f Player::getPosition()
{
	return player.getPosition();
}