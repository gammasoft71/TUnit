#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      int i = 24;
      assert::are_not_equal(23, i);
    }

    void test_method_(test_case_failed) {
      int i = 24;
      assert::are_not_equal(24, i);
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case_succeed (0 ms total)
//   FAILED  test.test_case_failed (0 ms total)
//     Expected: not 24
//     But was:  24
//     Stack Trace: in |---OMMITED---|/xtd/xtd.tunit/examples/assert_are_not_equal/src/assert_are_not_equal.cpp:13
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
