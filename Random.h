#pragma once

#include <stdlib.h>
#include <DirectXMath.h>

class Random
{
public:
	static float Randf0to1();
	static float RandfRad();
	static int	RandInteger(int min, int max);
	static float RandFloat(float min, float max);
	static bool Probably(float probability);
	static bool HalfProbably();
};

