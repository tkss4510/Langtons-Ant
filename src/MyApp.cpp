#include "MyApp.hpp"
#include "Ant.hpp"
#include "Grid.hpp"
#include <SFML/Graphics.hpp>
#include  "LangtonsAlgorithm.hpp"
#include <memory>


void MyApp::Initialize()
{
	window = sf::RenderWindow(sf::VideoMode({ 800, 600 }), "Langton's Ant");
	window.setFramerateLimit(60);

	sim = std::make_unique<Simulation>();
	sim->ApplyLayout(window);

	isRunning = true;
}

void MyApp::Run()
{
	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();

		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
				isRunning = false;
			}
			else if (const auto* resized = event->getIf<sf::Event::Resized>())
			{
				handleResized(resized->size.x, resized->size.y);
			}
		}

		sim->Update(dt);

		window.clear(sf::Color(255, 255, 255));
		Grid::DrawGrid(sim->GetGrid(), window);
		window.draw(sim->GetAnt().GetSprite());
		window.display();
	}
}

void MyApp::handleResized(unsigned int newWidth, unsigned int newHeight)
{
	window.setView(sf::View(sf::Vector2f(newWidth / 2.0f, newHeight / 2.0f), sf::Vector2f(newWidth, newHeight)));
	sim->ApplyLayout(window);
}
