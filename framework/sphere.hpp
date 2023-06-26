#include "shape.hpp"
#include "glm/vec3.hpp"
#include "ray.hpp"
#include "hitpoint.hpp"
#ifndef SPHERE_HPP
#define SPHERE_HPP

class sphere : public shape
{
public:
	sphere(glm::vec3 middle, float radius, std::string name, Color color);
	sphere(glm::vec3 middle, float radius, Color color, std::string name);
	sphere();
	~sphere();
	float area() const override;
	float volume() const override;
	Hit_point intersect(Ray r);
	std::ostream& print(std::ostream& os) const override;
private:
	glm::vec3 middle_;
	float radius_;
};
#endif