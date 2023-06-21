#include "box.hpp"
#include "glm/vec3.hpp"
#include <numbers>

box::box(glm::vec3 max, glm::vec3 min, std::string name = "Quader 1", Color color ={})
	: max_{ max }, min_{ min }, shape{color, name} {};

float box::area() const
{
	return 2 * (abs(max_.x - min_.x) * abs(max_.y - min_.y) + abs(max_.x - min_.x) * abs(max_.z - min_.z) + abs(max_.y - min_.y) * abs(max_.z - min_.z));
}
float box::volume() const
{
	return abs(max_.x - min_.x) * abs(max_.y - min_.y) * abs(max_.z - min_.z);
}
std::ostream& box::print(std::ostream& os) const
{
	shape::print(os);
	std::cout << "Minimum: x:" << min_.x << ", y:" << min_.y << ", z:" << min_.z << ", Maximum: x:" << max_.x << ", y:" << max_.y << ", z:" << max_.z;
}