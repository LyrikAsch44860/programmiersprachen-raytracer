#include "glm/vec3.hpp"
#include "color.hpp"

#ifndef HITPOINT_HPP
#define HITPOINT_HPP

struct Hit_point
{
	bool hit = false;
	float distance = 0.0f;
	std::string objekt_name = "";
	Color objekt_color = { 0.0f, 0.0f, 0.0f };
	glm::vec3 hit_point = { 0.0f, 0.0f, 0.0f };
	glm::vec3 hit_direction = { 0.0f, 0.0f, -1.0f };
};

#endif