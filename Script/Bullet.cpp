#include "Bullet.h"

// 
Bullet::Bullet(Vec2 pos, float radius, float speed)
{
	Initial(pos, radius, speed);
}

//
void Bullet::Initial(Vec2 pos, float radius, float speed)
{
	_pos = pos;
	_speed = speed;
	_radius = radius;
	_isShot = false;
}

// 動作処理
void Bullet::Update()
{
	if (_isShot)
	{
		if (_pos.y - _radius < 0)
		{
			_isShot = false;
		}
		_pos.y -= _speed;
	}
}

// 描画処理
void Bullet::Draw()
{
	if (_isShot)
	{
		Novice::DrawEllipse(int(_pos.x), int(_pos.y), int(_radius), int(_radius), 0.0f, 0xFFFFFFFF, kFillModeSolid);
	}
}
