#ifndef ANT_HPP
#define ANT_HPP

#include "Types.hpp"
#include <optional>
#include <SFML/Graphics/Sprite.hpp>
#include<SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace Grid {struct LangtonGrid;}

    class Ant
    {
    public:
        Ant();
        Cell GetPosition() const { return m_antPosition; }
        Direction GetDirection() const { return m_antDirection; }
        const sf::Sprite& GetSprite() const { return *m_antSprite; } 

        void TurnLeft();
        void TurnRight();
        bool MoveForward(const Grid::LangtonGrid& grid); //If move is outside grid then return flase 
        void Reset(const Grid::LangtonGrid& grid);        
        void SetSpriteScale(float size);
        sf::Sprite GetSprite() { return m_antSprite.value(); }
        void CalculatePosition(const Grid::LangtonGrid& grid);
    private:
        sf::Texture LoadTexture();
        Cell m_antPosition{ 0, 0 };
        Direction m_antDirection; //init = UP
        sf::Texture m_antTexture;
        std::optional<sf::Sprite> m_antSprite;
    };

#endif // !ANT_HPP
