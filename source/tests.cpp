#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "box.hpp"
#include "sphere.hpp"
#include "shape.hpp"
#include "glm/vec3.hpp"


TEST_CASE("describe_sphere", "[sphere]")
{
	sphere a{ glm::vec3{}, 3.0f, "sphere 1", {1,0,0} };
	REQUIRE(a.area() == Approx(113.097f));
	REQUIRE(a.volume() == Approx(113.097f));
	REQUIRE(a.color().r == 1);
	REQUIRE(a.name() == "sphere 1");

}
TEST_CASE("describe_box", "[box]")
{
	box a{ glm::vec3{3,2,1}, glm::vec3{0,0,0}, "box 1", {0,1,0} };
	REQUIRE(a.area() == Approx(22.0f));
	REQUIRE(a.volume() == Approx(6.0f));
	REQUIRE(a.color().r == 0);
	REQUIRE(a.name() == "box 1");
}


int main(int argc, char *argv[])
{

  return Catch::Session().run(argc, argv);
}
