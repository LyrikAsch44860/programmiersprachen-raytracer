#include "sphere.hpp"
#include "glm/vec3.hpp"
#include <numbers>
#include "cmath"

sphere::sphere(glm::vec3 middle, float radius, std::string name = "Kreis 1", Color color = {})
	: middle_{ middle }, radius_{ radius }, shape{ color, name } {};
float sphere::area() const
{
	return 4.0f * std::numbers::pi * radius_ * radius_;
}
float sphere::volume() const
{
	return (4.0f / 3.0f) * std::numbers::pi * radius_ * radius_ * radius_;
}
std::ostream& sphere::print(std::ostream& os) const
{
	shape::print(os);
	std::cout << "Mittelpunkt: x:" << middle_.x << ", y:" << middle_.y << ", z:" << middle_.z << ", Radius: " << radius_;
}