#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "box.hpp"
#include "sphere.hpp"
#include "shape.hpp"
#include "glm/vec3.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "hitpoint.hpp"
#include "ray.hpp"


TEST_CASE("describe_sphere", "[sphere]")
{
	sphere a{ glm::vec3{0,0,0}, 3.0f, "sphere 1", {1,0,0} };
	sphere b{ glm::vec3{1,1,1}, 2.0f, "sphere 1", {1,0,0} };

	REQUIRE(a.area() == Approx(113.097f));
	REQUIRE(a.volume() == Approx(113.097f));
	REQUIRE(a.color().r == 1);
	REQUIRE(a.name() == "sphere 1");

	Ray ray{ {0,0,4}, {0,0,-1} };
	Ray ray1{ {1,5,1}, {0,-2,0} };
	Ray ray2{ {1,5,1}, {0,0,2} };
	Hit_point Hit = a.intersect(ray);
	Hit_point Hit1 = b.intersect(ray1);
	Hit_point Hit2 = b.intersect(ray2);

	REQUIRE(Hit.hit == true);
	REQUIRE(Hit.distance == Approx(1.0f));
	REQUIRE(Hit.hit_point == glm::vec3 {0,0,3});
	REQUIRE(Hit.hit_direction == glm::vec3 {0,0,-1});

	REQUIRE(Hit1.hit == true);
	REQUIRE(Hit1.distance == Approx(2.0f));
	REQUIRE(Hit1.hit_point == glm::vec3{ 1,3,1 });
	REQUIRE(Hit1.hit_direction == glm::vec3{ 0,-2,0 });

	REQUIRE(Hit2.hit == false);
}
TEST_CASE("describe_box", "[box]")
{
	box a{ glm::vec3{3,2,1}, glm::vec3{0,0,0}, "box 1", {0,1,0} };
	REQUIRE(a.area() == Approx(22.0f));
	REQUIRE(a.volume() == Approx(6.0f));
	REQUIRE(a.color().r == 0);
	REQUIRE(a.name() == "box 1");
}
TEST_CASE("intersect_ray_sphere", "[intersect]")
{
	// Ray
	glm::vec3 ray_origin{ 0.0f, 0.0f, 0.0f };
	// ray direction has to be normalized !
	// you can use :
	// v = glm :: normalize ( some_vector )
	glm::vec3 ray_direction{ 0.0f, 0.0f, 1.0f };
	// Sphere
	glm::vec3 sphere_center{ 0.0f ,0.0f, 5.0f };
	float sphere_radius{ 1.0f };
	float distance = 0.0f;
	auto result = glm::intersectRaySphere(
		ray_origin, ray_direction,
		sphere_center,
		sphere_radius * sphere_radius, // squared radius !!!
		distance);
	REQUIRE(distance == Approx(4.0f));
}
TEST_CASE("5.8", "5.8")
{
	Color red{ 255 , 0 , 0 };
	glm::vec3 position{ 0.0f, 0.0f, 0.0f };
	sphere* s1 = new sphere{ position , 1.2f, red , " sphere0 " };
	shape* s2 = new sphere{ position , 1.2f, red , " sphere1 " };
	s1 -> print(std::cout);
	s2 -> print(std::cout);
	delete s1;
	delete s2;

}
int main(int argc, char *argv[])
{
	sphere a{};
	box b{};
	std::cout << b;
	std::cout << a;
  return Catch::Session().run(argc, argv);
}
