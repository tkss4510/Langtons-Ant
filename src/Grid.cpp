#include "Grid.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <algorithm>

/* Notes:
	line count = gridSize + 1
	gridSpace = (gridSize + 1) * gridLineSize + gridSize * cellSize
	layout: l + C + l + C + ... + C + l
*/

void Grid::UpdateLayout(LangtonGrid& g, const sf::RenderWindow& window)
{
	sf::Vector2u win = window.getSize();

	g.gridSpace    = std::min(win.x, win.y) * 0.9f;
	g.gridPos      = { (win.x - g.gridSpace) / 2.f, (win.y - g.gridSpace) / 2.f };
	g.gridLineSize = g.gridSpace * 0.005f;
	g.cellSize     = (g.gridSpace - (g.gridSize + 1) * g.gridLineSize) / g.gridSize;
}

void Grid::DrawGrid(const LangtonGrid& g, sf::RenderWindow& window)
{
	sf::RectangleShape line;
	line.setFillColor(sf::Color::Black);

	for (int i = 0; i <= g.gridSize; i++)
	{
		float pos = i * g.Pitch();

		line.setSize({ g.gridLineSize, g.gridSpace });
		line.setPosition({ g.gridPos.X + pos, g.gridPos.Y });
		window.draw(line);

		line.setSize({ g.gridSpace, g.gridLineSize });
		line.setPosition({ g.gridPos.X, g.gridPos.Y + pos });
		window.draw(line);
	}

	sf::RectangleShape square({ g.cellSize, g.cellSize });
	square.setFillColor(sf::Color::Black);
	for (int y = 0; y < g.gridSize; ++y)
	{
		for (int x = 0; x < g.gridSize; ++x)
		{
			if (!g.IsBlack(x, y)) continue;
			Position o = g.CellOrigin(x, y);
			square.setPosition({ o.X, o.Y });
			window.draw(square);
		}
	}
}

Grid::LangtonGrid::LangtonGrid()
{
	Resize(100);
	gridSpace = 300;
	gridLineSize = 1;
	cellSize = 0;
	gridPos = { 0.f, 0.f };
}
