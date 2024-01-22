#pragma once
#include <Novice.h>
#include "Vector2.h"

class Bullet
{
public:

	// 変数
	Vec2 _pos;
	float _speed;
	float _radius;
	bool _isShot;

	// 関数
	Bullet(Vec2 pos, float radius, float speed);
	void Initial(Vec2 pos, float radius, float speed);
	void Update();
	void Draw();
};

