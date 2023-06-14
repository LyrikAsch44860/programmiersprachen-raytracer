#include "shape.hpp"
#include "glm/vec3.hpp"
#ifndef BOX_HPP
#define BOX_HPP

class box : public shape
{
public:
	box(glm::vec3 max, glm::vec3 min);
	float area() const override;
private:
	glm::vec3 max_;
	glm::vec3 min_;
};

#endif