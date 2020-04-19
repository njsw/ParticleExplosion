#include "Particle.h"
#include <math.h>
#include <stdlib.h>


namespace graphics {

Particle::Particle() : x(0), y(0) {
	init();
}

Particle::~Particle() {
	//
}

void Particle::init() {
	x = 0;
	y = 0;
	direction_ = (2 * M_PI * rand()) / RAND_MAX;
	speed_ = (0.04 * rand()) / RAND_MAX;
	speed_ *= speed_;
}

void Particle::update(int interval) {
	direction_ += interval * 0.0003;

	double xSpeed = speed_ * cos(direction_);
	double ySpeed = speed_ * sin(direction_);

	x += xSpeed * interval;
	y += ySpeed * interval;

	if (x < -1 || x > 1 || y < -1 || y > 1) {
		init();
	}

	if (rand() < RAND_MAX / 100) {
		init();
	}
}

} /* namespace graphics */
