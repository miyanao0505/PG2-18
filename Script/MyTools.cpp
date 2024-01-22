#include "MyTools.h"

// 長さ
float MyTools::Length(float x, float y)
{
	return sqrtf(x * x + y * y);
}

// 正規化
Vec2 MyTools::Normalization(float x, float y)
{
	float length = Length(x, y);
	if (length != 0) {
		x = x / length;
		y = y / length;
	}
	return Vector2{ x,y };
}

// 範囲
float MyTools::Clamp(float num, float min, float max)
{
	if (num < min)
	{
		return min;
	}
	if (num > max)
	{
		return max;
	}
	return num;
}

// 当たり判定
bool MyTools::Hit(Vec2 posA, Vec2 posB, float radiusA, float radiusB)
{
	float length = Length(posA.x - posB.x, posA.y - posB.y);

	if (length <= radiusA + radiusB)
	{
		return true;
	}
	return false;
}
