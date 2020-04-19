#ifndef PARTICLE_H_
#define PARTICLE_H_


namespace graphics {

struct Particle {
public:
	double x;
	double y;

public:
	Particle();
	virtual ~Particle();
	void update(int interval);

private:
	double speed_;
	double direction_;

private:
	void init();
};

} /* namespace graphics */

#endif /* PARTICLE_H_ */
