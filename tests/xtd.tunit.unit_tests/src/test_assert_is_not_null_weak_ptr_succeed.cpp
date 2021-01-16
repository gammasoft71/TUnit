#include "assert_unit_tests.h"
#include <tunit/xtd.tunit>
#include <memory>

namespace unit_tests {
  class test_class_(test_assert_is_not_null_weak_ptr_succeed) {
  public:
    void test_method_(test_case_succeed) {
      std::shared_ptr<int> i = std::make_shared<int>(42);
      std::weak_ptr<int> p = i;
      xtd::tunit::assert::is_not_null(p);
    }
  };
}

void test_(test_assert_is_not_null_weak_ptr_succeed, test_output) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_not_null_weak_ptr_succeed.*");
  std::stringstream ss;
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  SUCCEED test_assert_is_not_null_weak_ptr_succeed.test_case_succeed\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_assert_is_not_null_weak_ptr_succeed, test_result) {
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_is_not_null_weak_ptr_succeed.*");
  std::stringstream ss;
  assert_value_(0, xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run());
}
