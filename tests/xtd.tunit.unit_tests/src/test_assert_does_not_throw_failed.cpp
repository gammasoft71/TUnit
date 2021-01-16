#include "assert_unit_tests.h"
#include <tunit/tunit>
#include <vector>

namespace unit_tests {
  class test_class_(test_assert_does_not_throw_failed) {
  public:
    void test_method_(test_case_failed) {
      std::vector v = {1, 2, 3, 4};
      xtd::tunit::assert::does_not_throw([&] {v.at(5);});
    }
  };
}

void test_(test_assert_does_not_throw_failed, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_does_not_throw_failed.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  FAILED  test_assert_does_not_throw_failed.test_case_failed\n"
                "    Expected: No Exception to be thrown\n"
                "    But was:  <std::out_of_range>\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_assert_does_not_throw_failed, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_does_not_throw_failed.*");
  std::stringstream ss;
  assert_value_(1, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
