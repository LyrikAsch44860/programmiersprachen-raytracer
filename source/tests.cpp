#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "box.hpp"
#include "sphere.hpp"
#include "shape.hpp"
#include "glm/vec3.hpp"


TEST_CASE("describe_sphere", "[sphere]")
{
	sphere a{ glm::vec3{}, 3.0f };
	REQUIRE(a.area() == Approx(113.097f));
	REQUIRE(a.volume() == Approx(113.097f));
}
TEST_CASE("describe_box", "[box]")
{
	box a{ glm::vec3{3,2,1}, glm::vec3{0,0,0} };
	REQUIRE(a.area() == Approx(22.0f));
	REQUIRE(a.volume() == Approx(6.0f));
}


int main(int argc, char *argv[])
{

  return Catch::Session().run(argc, argv);
}
