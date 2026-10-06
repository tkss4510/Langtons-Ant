#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Ant.hpp"
#include "Grid.hpp"

class Simulation
{
public:
	Simulation();

	void Update(float dt);                       // advance by dt seconds 
	void Step();                                 // one algorithm step
	void Reset();                                // clear grid, ant back to middle
	void ApplyLayout(const sf::RenderWindow& window);

	void SetStepInterval(float seconds) { m_stepInterval = seconds; }
	bool IsFinished() const { return m_finished; }

	const Grid::LangtonGrid& GetGrid() const { return m_grid; }
	const Ant& GetAnt() const { return m_ant; }

private:
	Grid::LangtonGrid m_grid;
	Ant m_ant;
	float m_stepInterval = 0.001f;   // simulated seconds per step
	float m_accumulator = 0.f;
	bool m_finished = false;
};
 
#endif // !SIMULATION_HPP
