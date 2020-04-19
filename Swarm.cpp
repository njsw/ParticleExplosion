/*
 * Swarm.cpp
 *
 *  Created on: Apr 4, 2020
 *      Author: nlowing
 */

#include "Swarm.h"

namespace graphics {

Swarm::Swarm() : lastTime_(0) {
	particles_ = new Particle[NUM_PARTICLES];
}

Swarm::~Swarm() {
	delete [] particles_;
}

const Particle* const Swarm::getParticles() {
	return particles_;
}

void Swarm::update(int elapsed) {
	int interval = elapsed - lastTime_;

	for (int i = 0; i < Swarm::NUM_PARTICLES; i++) {
		particles_[i].update(interval);
	}

	lastTime_ = elapsed;
}

} /* namespace graphics */
