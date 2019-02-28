#include "assert_unit_tests.hpp"
#include <xtd/tunit>
#include <vector>

namespace unit_tests {
  class test_class_(test_assert_throws_any_failed) {
  public:
    void test_method_(test_case_failed) {
      std::vector v = {1, 2, 3, 4};
      xtd::tunit::assert::throws_any([&] {v.at(2);}, xtd::tunit::line_info {"test_assert_throws_any_failed.cpp", 10});
    }
  };
}

void test_(test_assert_throws_any_failed, test_output) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_throws_any_failed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  Start 1 test from test_assert_throws_any_failed\n"
                "    FAILED  test_case_failed\n"
                "\n"
                "Expected: <exception>\n"
                "But was:  <nothing>\n"
                "error: test_assert_throws_any_failed.cpp:10\n"
                "\n"
                "  End 1 test from test_assert_throws_any_failed\n"
                "\n"
                "  Summary :\n"
                "    FAILED  1 test, listed below:\n"
                "    FAILED  test_assert_throws_any_failed.test_case_failed\n"
                "\n"
                "    FAILED  1 test.\n"
                "End 1 test from 1 test case ran.\n"
                "\n", ss.str());
}

void test_(test_assert_throws_any_failed, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_throws_any_failed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  int result = xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_(1, result);
}