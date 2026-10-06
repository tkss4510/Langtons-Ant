#ifndef GRID_HPP
#define GRID_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include <cstdint>
#include <cstddef>
#include "Types.hpp"

namespace Grid
{
	struct LangtonGrid
	{
		int gridSize;          // N*N grid
		float gridSpace;       // side of the whole square (px)
		float gridLineSize;    // line thickness (px)
		float cellSize;        // inner cell side (px)
		Position gridPos;      // top-left corner (px)
        std::vector<uint8_t> cells;  // gridSize * gridSize, row-major, 0 = white, 1 = black
		LangtonGrid();

		// Distance from one cell's origin to the next (cell + one line)
		float Pitch() const { return cellSize + gridLineSize; }

		// x, y are 0-based cell indices
		Position CellOrigin(int x, int y) const
		{
			return { gridPos.X + gridLineSize + x * Pitch(),
			         gridPos.Y + gridLineSize + y * Pitch() };
		}

		Position CellCenter(int x, int y) const
		{
			Position o = CellOrigin(x, y);
			return { o.X + cellSize / 2.f, o.Y + cellSize / 2.f };
		}
        void Resize(int size)
        {
            gridSize = size;
            cells.assign(static_cast<size_t>(size) * size, 0);
        }
        bool IsBlack(int x, int y) const { return cells[static_cast<size_t>(y) * gridSize + x] != 0; }
        void Flip(int x, int y)          { cells[static_cast<size_t>(y) * gridSize + x] ^= 1; }
	};

	void UpdateLayout(LangtonGrid& grid, const sf::RenderWindow& window);
	void DrawGrid(const LangtonGrid& grid, sf::RenderWindow& window);
}

#endif // !GRID_HPP
