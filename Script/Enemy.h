#pragma once
#include "Vector2.h"
#include "MyTools.h"
#include "Novice.h"

class Enemy
{
public:

	// メンバ変数
	Vec2 _pos;
	Vec2 _velocity;
	float _radius;
	float _speed;

	static bool _isAlive;

	// メンバ関数
	Enemy(Vec2 pos, float radius, float speed);
	void Initial(Vec2 pos, float radius, float speed);
	void Update();
	void Draw();

};

