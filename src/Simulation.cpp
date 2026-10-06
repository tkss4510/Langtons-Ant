#include "Simulation.hpp"
#include "LangtonsAlgorithm.hpp"
#include <algorithm>

namespace
{
	constexpr float kMaxCatchUp = 0.25f;  // drop time beyond this after a stall
}

Simulation::Simulation()
{
	m_ant.Reset(m_grid);
}

void Simulation::Update(float dt)
{
	if (m_finished) return;

	m_accumulator = std::min(m_accumulator + dt, kMaxCatchUp);
	while (!m_finished && m_accumulator >= m_stepInterval)
	{
		Step();
		m_accumulator -= m_stepInterval;
	}
}

void Simulation::Step()
{
	if (m_finished) return;

	if (!LangtonAlgorithms::StandartAlg(m_ant, m_grid))
		m_finished = true;
}

void Simulation::Reset()
{
	m_grid.Resize(m_grid.gridSize);   // clears every cell
	m_ant.Reset(m_grid);
	m_accumulator = 0.f;
	m_finished = false;
}

void Simulation::ApplyLayout(const sf::RenderWindow& window)
{
	Grid::UpdateLayout(m_grid, window);
	m_ant.SetSpriteScale(m_grid.cellSize);
	m_ant.CalculatePosition(m_grid);
}
