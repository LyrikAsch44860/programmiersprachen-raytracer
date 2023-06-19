#include "glm/vec3.hpp"
#include "iostream"
#include "color.hpp"
#ifndef SHAPE_HPP
#define SHAPE_HPP

class shape
{
public:
	virtual float area() const = 0;
	virtual float volume() const = 0;
protected:
	Color color_;
	std::string name_;
};
#endif 
