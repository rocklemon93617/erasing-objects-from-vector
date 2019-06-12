#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include<stdio.h> 

using namespace std;
using namespace sf;

class Player : public Drawable
{
public:
	Player(float x, float y);
	Player() = delete;
	~Player() = default;

	float up();
	float down();
	float right();
	float left();

	Vector2f pvelocity{ 0.f, 0.f };

	void update(Vector2f winsize);

	CircleShape player;

	Vector2f getPosition();

private:
	void draw(RenderTarget& target, RenderStates state) const override;
	const float radius = 15.f;
	const float velocity = 10.f;
};

