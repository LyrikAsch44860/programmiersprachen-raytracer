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
private:
	glm::vec3 middle_;
	float radius_;
	std::string name_;
	Color color_;
};
#endif