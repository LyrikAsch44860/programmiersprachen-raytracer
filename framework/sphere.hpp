#include "shape.hpp"
#include "glm/vec3.hpp"
#ifndef BOX_HPP
#define BOX_HPP

class sphere : public shape
{
public:
	sphere(glm::vec3 middle, float radius)
		: middle_{ middle }, radius_{ radius } {};

private:
	glm::vec3 middle_;
	float radius_;
};

#endif