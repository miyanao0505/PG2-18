#include "Player.h"

// 
Player::Player(Vec2 pos, float radius, float speed)
{
	Initial(pos, radius, speed);
}

// 
Player::~Player()
{
	for (int i = 0; i < _bulletNum; i++)
	{
		delete _bulletObj[i];
	}
}

//
void Player::Initial(Vec2 pos, float radius, float speed)
{
	_pos = pos;
	_velocity = { 0, 0 };
	_radius = radius;
	_speed = speed;

	for (int i = 0; i < _bulletNum; i++)
	{
		_bulletObj[i] = new Bullet(Vec2{ 0, 0 }, 8, 8);
	}
	_bulletTimer = 0;
}

// 動作処理
void Player::Update(char* keys)
{
	_velocity = { 0, 0 };

	// キー入力処理
	if (keys[DIK_W] || keys[DIK_UP])
	{
		_velocity.y -= _speed;
	}
	if (keys[DIK_S] || keys[DIK_DOWN])
	{
		_velocity.y += _speed;
	}
	if (keys[DIK_A] || keys[DIK_LEFT])
	{
		_velocity.x -= _speed;
	}
	if (keys[DIK_D] || keys[DIK_RIGHT])
	{
		_velocity.x += _speed;
	}

	// 速度正規化
	_velocity = MyTools::Normalization(_velocity.x, _velocity.y);

	// 座標移動
	_pos.x += _velocity.x * _speed;
	_pos.y += _velocity.y * _speed;

	// 画面内に収める
	_pos.x = MyTools::Clamp(_pos.x, _radius, 1280 - _radius);
	_pos.y = MyTools::Clamp(_pos.y, _radius, 720 - _radius);

	// キー入力処理
	if (keys[DIK_SPACE] && _bulletTimer <= 0)
	{
		for (int i = 0; i < _bulletNum; i++)
		{
			if (!_bulletObj[i]->_isShot)
			{
				_bulletObj[i]->_pos = _pos;
				_bulletObj[i]->_isShot = true;

				_bulletTimer = _bulletTime;

				break;
			}
		}
	}

	// 弾のリロードタイム
	if (_bulletTimer > 0)
	{
		_bulletTimer--;
	}

	// 弾の移動処理
	for (int i = 0; i < _bulletNum; i++)
	{
		_bulletObj[i]->Update();
	}

}

// 描画処理
void Player::Draw()
{
	// 弾の描画
	for (int i = 0; i < _bulletNum; i++)
	{
		_bulletObj[i]->Draw();
	}
	
	// プレイヤーの描画
	Novice::DrawEllipse(int(_pos.x), int(_pos.y), int(_radius), int(_radius), 0.0f, 0x00FF00FF, kFillModeSolid);
}
