#ifndef TYPES_HPP
#define TYPES_HPP

enum class Direction
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};

struct Position
{
	float X, Y;

	bool operator==(const Position& other) const
	{
		return X == other.X && Y == other.Y;
	}

	bool operator!=(const Position& other) const
	{
		return !(*this == other);
	}
};

struct Cell
{
	int X, Y;
};

#endif // !TYPES_HPP

