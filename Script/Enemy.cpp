#include "Enemy.h"

Enemy::Enemy(Vec2 pos, float radius, float speed)
{
	Initial(pos, radius, speed);
}

void Enemy::Initial(Vec2 pos, float radius, float speed)
{
	_pos = pos;
	_velocity = { speed, 0 };
	_radius = radius;
	_speed = speed;

	_isAlive = true;
}

void Enemy::Update()
{
	if (_isAlive)
	{
		if (_pos.x - _radius <= 0)
		{
			_velocity.x = _speed;
		}
		if (_pos.x + _radius >= 1280)
		{
			_velocity.x = -_speed;
		}
		if (_pos.y - _radius <= 0)
		{
			_velocity.y = _speed;
		}
		if (_pos.y + _radius >= 720)
		{
			_velocity.y = -_speed;
		}

		_velocity = MyTools::Normalization(_velocity.x, _velocity.y);

		_pos.x += _velocity.x * _speed;
		_pos.y += _velocity.y * _speed;

		_pos.x = MyTools::Clamp(_pos.x, _radius, 1280 - _radius);
		_pos.y = MyTools::Clamp(_pos.y, _radius, 720 - _radius);
	}
}

void Enemy::Draw()
{
	if (_isAlive)
	{
		Novice::DrawEllipse(int(_pos.x), int(_pos.y), int(_radius), int(_radius), 0.0f, 0xFF0000FF, kFillModeSolid);
	}
}
