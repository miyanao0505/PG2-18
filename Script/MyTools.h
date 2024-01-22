#pragma once
#include <math.h>
#include "Vector2.h"

class MyTools
{
public:

	// 長さ
	static float Length(float x, float y);

	// 正規化
	static Vec2 Normalization(float x, float y);

	// 範囲
	static float Clamp(float num, float min, float max);

	// 当たり判定
	static bool Hit(Vec2 posA, Vec2 posB, float radiusA, float radiusB);

};

