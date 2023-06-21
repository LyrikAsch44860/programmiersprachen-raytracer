#include "shape.hpp"
#include "glm/vec3.hpp"
#ifndef SPHERE_HPP
#define SPHERE_HPP

class sphere : public shape
{
public:
	sphere(glm::vec3 middle, float radius, std::string name, Color color);
	float area() const override;
	float volume() const override;
	std::ostream& print(std::ostream& os) const override;
private:
	glm::vec3 middle_;
	float radius_;
};
#endif