#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Bat
{
private:
	//m_ member
	Vector2f m_Position;
	// A RectangleShape object
	RectangleShape m_Shape;
	float m_Speed = 1000.0f;
	bool m_MovingRight = false;
	bool m_MovingLeft = false;

public:
	//Este constructor sirve para declarar la posicin inicial en X  y Y cuando comience el juego.
	Bat(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(Time dt);
};