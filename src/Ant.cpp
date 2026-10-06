#include "Ant.hpp"
#include "Grid.hpp"
#include "AntPng.hpp"
#include <stdexcept>
#include <algorithm>


Ant::Ant()
	:  m_antDirection(Direction::UP), m_antTexture(LoadTexture())
{
	m_antTexture.setSmooth(true);
	m_antSprite.emplace(m_antTexture);

	sf::Vector2u size = m_antTexture.getSize();
	m_antSprite->setOrigin({ size.x / 2.f, size.y / 2.f });
}

void Ant::TurnLeft()
{
	m_antSprite.value().rotate(sf::degrees(-90));
	switch (m_antDirection)
	{
		case Direction::UP:
			m_antDirection = Direction::LEFT;
			break;
		case Direction::DOWN: 
			m_antDirection = Direction::RIGHT;
			break;
		case Direction::LEFT:
			m_antDirection = Direction::DOWN;
			break;
		case Direction::RIGHT:
			m_antDirection = Direction::UP;
			break;
	}
}

void Ant::TurnRight()
{
	m_antSprite.value().rotate(sf::degrees(90));
	switch (m_antDirection)
	{
		case Direction::UP:
			m_antDirection = Direction::RIGHT;
			break;
		case Direction::DOWN: 
			m_antDirection = Direction::LEFT;
			break;
		case Direction::LEFT: 
			m_antDirection = Direction::UP;
			break;
		case Direction::RIGHT: 
			m_antDirection = Direction::DOWN;
			break;
	}
}

bool Ant::MoveForward(const Grid::LangtonGrid& grid)
{
	Cell next = m_antPosition;
	switch (m_antDirection)
	{
		case Direction::UP:    --next.Y; break;
		case Direction::DOWN:  ++next.Y; break;
		case Direction::LEFT:  --next.X; break;
		case Direction::RIGHT: ++next.X; break;
	}

	if (next.X < 0 || next.Y < 0 || next.X >= grid.gridSize || next.Y >= grid.gridSize)
		return false;

	m_antPosition = next;
	CalculatePosition(grid);
	return true;
}

void Ant::Reset(const Grid::LangtonGrid& grid)
{
	m_antDirection = Direction::UP;
	m_antSprite->setRotation(sf::degrees(0.f));
	m_antPosition = { grid.gridSize / 2, grid.gridSize / 2 };
	CalculatePosition(grid);
}

void Ant::CalculatePosition(const Grid::LangtonGrid& grid)
{
	Position c = grid.CellCenter(m_antPosition.X, m_antPosition.Y);
	m_antSprite->setPosition({ c.X, c.Y });
}

void Ant::SetSpriteScale(float size)
{
	sf::Vector2u texSize = m_antTexture.getSize();
	float scaleX = size / texSize.x;
	float scaleY = size / texSize.y;
	m_antSprite.value().setScale({ scaleX, scaleY });
}

 sf::Texture Ant::LoadTexture()
{
	 sf::Texture texture;
	 if (!texture.loadFromMemory(AntPng, AntPngSize))
	 {
         throw std::runtime_error("Embedded ant texture is corrupt");
	 }
	 return texture;
}


