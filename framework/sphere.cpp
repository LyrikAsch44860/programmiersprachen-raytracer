#include "sphere.hpp"
#include "glm/vec3.hpp"
#include "glm/glm.hpp"
#include "glm/gtx/intersect.hpp"
#include <numbers>
#include "limits"
#include "cmath"

sphere::sphere(glm::vec3 middle, float radius, std::string name = "Kreis 1", Color color = {})
	: middle_{ middle }, radius_{ radius }, shape{ color, name } {std::cout << "sphere constructor\n";};
sphere::sphere(glm::vec3 middle, float radius, Color color = {}, std::string name = "Kreis 1")
	: middle_{ middle }, radius_{ radius }, shape{ color, name } {std::cout << "sphere constructor\n";};
sphere::sphere()
	: middle_{}, radius_{1.0f}, shape{} {std::cout << "sphere std constructor\n";};
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
	std::cout << "Mittelpunkt: x:" << middle_.x << ", y:" << middle_.y << ", z:" << middle_.z << ", Radius: " << radius_ <<" ";
	return shape::print(os);
}
Hit_point sphere::intersect(Ray r)
{
	float distance = 0.0f;
	bool hit = glm::intersectRaySphere(r.origin, glm::normalize(r.direction), middle_,radius_*radius_,distance);
	return { hit, distance, name_, color_, r.origin + distance * glm::normalize(r.direction), r.direction };
}
sphere::~sphere()
{
	std::cout << "sphere destructor\n";
}