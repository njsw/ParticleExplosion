#ifndef SWARM_H_
#define SWARM_H_


#include "Particle.h"


namespace graphics {

class Swarm {
public:
	const static int NUM_PARTICLES = 5000;

public:
	Swarm();
	virtual ~Swarm();
	const Particle* const getParticles();
	void update(int elapsed);

private:
	Particle* particles_;
	int lastTime_;
};

} /* namespace graphics */

#endif /* SWARM_H_ */
