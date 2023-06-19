#include "box.hpp"
#include "glm/vec3.hpp"
#include <numbers>

box::box(glm::vec3 max, glm::vec3 min, std::string name = "Quader 1", Color color ={})
	: max_{ max }, min_{ min }, name_{ name }, color_{color} {};

float box::area() const
{
	return 2 * (abs(max_.x - min_.x) * abs(max_.y - min_.y) + abs(max_.x - min_.x) * abs(max_.z - min_.z) + abs(max_.y - min_.y) * abs(max_.z - min_.z));
}
float box::volume() const
{
	return abs(max_.x - min_.x) * abs(max_.y - min_.y) * abs(max_.z - min_.z);
}