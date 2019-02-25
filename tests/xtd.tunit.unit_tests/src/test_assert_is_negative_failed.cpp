#include "assert_unit_tests.hpp"
#include <xtd/tunit>

namespace unit_tests {
  class test_class_(test_assert_is_negative_failed) {
  public:
    void test_method_(test_case_failed) {
      int i = 1;
      xtd::tunit::assert::is_negative(i, xtd::tunit::line_info {"test_assert_is_negative_failed.cpp", 9});
    }
  };
}

void test_(test_assert_is_negative_failed, test_output) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_negative_failed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  xtd::tunit::ostream_unit_test(ss, argv, argc).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  Start 1 test from test_assert_is_negative_failed\n"
                "    FAILED test_case_failed\n"
                "\n"
                "Expected: negative\n"
                "But was:  1\n"
                "error: test_assert_is_negative_failed.cpp:9\n"
                "\n"
                "  End 1 test from test_assert_is_negative_failed\n"
                "\n"
                "  Summary :\n"
                "    PASSED 0 test.\n"
                "*** FAILED 1 test, listed below:\n"
                "*** FAILED test_assert_is_negative_failed.test_case_failed\n"
                "\n"
                "    FAILED 1 test.\n"
                "End 1 test from 1 test case ran.\n"
                "\n", ss.str());
}

void test_(test_assert_is_negative_failed, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_negative_failed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  int result = xtd::tunit::ostream_unit_test(ss).run();
  assert_value_(1, result);
}