#include <iostream>
#include<SFML/Graphics.hpp>
#include<stdio.h> 


using namespace std;
using namespace sf;


class Bullet : public Drawable
{
public:
	Bullet(float x, float y);
	Bullet() = delete;
	~Bullet() = default;


	float up();
	float down();
	float right();
	float left();

	Vector2f bvelocity{ 0.f, 0.f };

	void update();

	CircleShape bullet;

private:
	void draw(RenderTarget& target, RenderStates state) const override;
	const float radius = 1.f;
	const float velocity = 20.f;
};

