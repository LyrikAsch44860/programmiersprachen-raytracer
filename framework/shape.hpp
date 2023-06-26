#include "glm/vec3.hpp"
#include "iostream"
#include "color.hpp"
#ifndef SHAPE_HPP
#define SHAPE_HPP

class shape
{
public:
	shape();
	virtual ~shape();
	shape(Color color, std::string name);
	virtual float area() const = 0;
	virtual float volume() const = 0;
	virtual std::ostream& print(std::ostream& os) const;
	Color color() const;
	std::string name() const;
protected:
	Color color_;
	std::string name_;
};

std::ostream& operator<<(std::ostream& os, shape const& s);
#endif 
