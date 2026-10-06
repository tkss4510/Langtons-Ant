#ifndef MYAPP_HPP
#define MYAPP_HPP

#include "Simulation.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class MyApp
{
public:
	MyApp() = default;
	~MyApp() = default;
	void Initialize();
	void Run();
private:
	sf::RenderWindow window;
	void handleResized(unsigned int newWidth, unsigned int newHeight);
	bool isRunning;
	std::unique_ptr<Simulation> sim;
	sf::Clock clock;
};

#endif // !MYAPP_HPP
