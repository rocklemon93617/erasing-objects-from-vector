#include <iostream>
#include<SFML/Graphics.hpp>
#include<cmath>
#include<stdio.h> 
#include<vector>
#include"Player.h"
#include"Bullet.h"


using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Super gay ninja fighting zombies");
	window.setFramerateLimit(60);

	Vector2f mpos;
	Vector2f ppos;
	Vector2f bdir;
	Vector2f bdirnorm;

	Player player(window.getSize().x / 2, window.getSize().y / 2);

	vector<Bullet> bullets;

	while (window.isOpen())
	{
		Event event;
		Vector2f winsize{ window.getSize()};

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color::Black);

		mpos = Vector2f(Mouse::getPosition(window));
		ppos = player.getPosition();
		bdir = mpos - ppos;
		bdirnorm = bdir / sqrt(pow(bdir.x, 2.f) + pow(bdir.y, 2.f));
		cout << bdirnorm.x << " " << bdirnorm.y << endl;

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			Bullet b1 (ppos.x, ppos.y);
			b1.bvelocity = bdirnorm;
			b1.update();
			bullets.push_back(b1);
		}

		player.update(winsize);
		window.draw(player);
		for (size_t i = 0; i < bullets.size(); i++)
		{
			bullets[i].update();
			window.draw(bullets[i]);
			for (int j = 0; j < bullets.size(); j++)
			{
				if (bullets[j].right() > winsize.x || bullets[j].left() < 0 || bullets[j].down() > winsize.y || bullets[j].up() < 0)
				{
					bullets.erase(bullets.begin() + j);
					break;
				}
			}
		}

		window.display();
	}

	return 0;
}