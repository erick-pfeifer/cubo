
#include "hello_world/hello_world.h"

#include "pw_digital_io/digital_io_mock.h"
#include "pw_unit_test/framework.h"

namespace hello_world {
namespace {

class HelloWorldTest : public ::testing::Test {
 protected:
  pw::digital_io::DigitalInOutMock<1> pin;
  HelloWorldThread hello_world_{pin};
};

TEST_F(HelloWorldTest, SaySomething) {
  constexpr std::string_view kTestedString = "1234";
  PW_TEST_ASSERT_OK_AND_ASSIGN(auto size_result,
                               hello_world_.SaySomething(kTestedString));
  EXPECT_EQ(size_result, kTestedString.size());
}

}  // namespace
}  // namespace hello_world