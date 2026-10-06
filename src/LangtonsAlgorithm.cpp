#include "LangtonsAlgorithm.hpp"
#include "Ant.hpp"

bool LangtonAlgorithms::StandartAlg(Ant& ant, Grid::LangtonGrid& grid)
{
	Cell pos = ant.GetPosition();

	if (grid.IsBlack(pos.X, pos.Y))
		ant.TurnLeft();
	else
		ant.TurnRight();

	grid.Flip(pos.X, pos.Y);
	return ant.MoveForward(grid);
}
