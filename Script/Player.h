#pragma once
#include "Vector2.h"
#include "Bullet.h"
#include "MyTools.h"

class Player
{
public:

	// 変数
	Vec2 _pos;
	Vec2 _velocity;
	float _radius;
	float _speed;

	static const int _bulletNum = 20;
	Bullet* _bulletObj[_bulletNum];
	const int _bulletTime = 10;
	int _bulletTimer;

	// 関数
	Player(Vec2 pos, float radius, float speed);
	~Player();
	void Initial(Vec2 pos, float radius, float speed);
	void Update(char* keys, char* preKeys);
	void Draw();

};

