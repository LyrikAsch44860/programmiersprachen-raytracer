#include "box.hpp"
#include "glm/vec3.hpp"
#include <numbers>

box::box(glm::vec3 max, glm::vec3 min)
	: max_{ max }, min_{ min } {};

float box::area() const
{

}