#pragma once

class Myclass
{
public:
	bool IsPointInCircle(double R, double x, double y)
	{
		return ((x * x + y * y) < R * R);
	}
};