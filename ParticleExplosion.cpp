#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <SDL.h>
#include "Screen.h"
#include "Swarm.h"
using namespace graphics;


int main() {
	srand(time(NULL));

	Screen screen;

	if (screen.init() == false) {
		std::cout << "Error initializing SDL." << std::endl;
	}

	Swarm swarm;

	while (true) {
		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

		const Particle* const particles = swarm.getParticles();

		for (int i = 0; i < Swarm::NUM_PARTICLES; i++) {
			Particle particle = particles[i];

			int x = (particle.x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();
		screen.update();

		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();

	return 0;
}
