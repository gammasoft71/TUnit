| [Home](home.md) | [Downloads](downloads.md) | [Examples](examples.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/tunit) | [Project](https://sourceforge.net/projects/tunitpro/) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/tunit) |

# Example

The classic first application 'Hello World'.

tunit_hello_world.cpp:

```c++
#include <tunit/tunit>
#include <string>

using namespace std;
using namespace tunit;

namespace unit_tests {
  class test_class_(hello_world_test) {
  public:
    void test_method_(create_string_from_literal) {
      string s = "Hello, World!";
      assert::are_equal("Hello, World!", s);
    }
    
    void test_method_(create_string_from_chars) {
      string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      assert::are_equal("Hello, World!", s);
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(tunit_hello_world)
find_package(tunit REQUIRED)
add_executable(${PROJECT_NAME} tunit_hello_world.cpp)
target_link_libraries(${PROJECT_NAME} tunit)
```

Output:

```
tart 2 tests from 1 test case
Run tests:
  SUCCEED hello_world_test.create_string_from_literal (0 ms total)
  SUCCEED hello_world_test.create_string_from_chars (0 ms total)

Test results:
  SUCCEED 2 tests.
End 2 tests from 1 test case ran. (0 ms total)
```

[Click here to see more examples](../examples)

______________________________________________________________________________________________

© 2021 Gammasoft.
