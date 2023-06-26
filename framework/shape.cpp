#include "shape.hpp"

shape::shape()
	: color_{ 0,0,0 }, name_{ "shape" } {std::cout << "shape std constructor\n";};
shape::shape(Color color, std::string name)
	: color_{ color }, name_{ name } {std::cout << "shape constructor\n";};
Color shape::color() const
{
	return color_;
}
std::string shape::name() const
{
	return name_;
}
std::ostream& shape::print(std::ostream& os) const
{
	return os << "Name: " << name_ << ", Farbe: " << color_;
}
std::ostream& operator<<(std::ostream& os, shape const& s)
{
	return s.print(os);
}
shape::~shape()
{
	std::cout << "shape destructor\n";
}