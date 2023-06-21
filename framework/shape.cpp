#include "shape.hpp"

shape::shape()
	: color_{ 0,0,0 }, name_{ "shape" } {};
shape::shape(Color color, std::string name)
	: color_{ color }, name_{ name } {};
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
	return os << "name: " << name_ << ", color: " << color_;
}
std::ostream& operator<<(std::ostream& os, shape const& s)
{
	return s.print(os);
}