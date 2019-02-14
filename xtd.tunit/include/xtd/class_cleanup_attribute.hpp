/// @file
/// @brief Contains xtd::registered_method class.
#pragma once
#include "caller.hpp"
#include <xtd/delegates>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    struct class_cleanup_attribute final {
    public:
      template<typename TestClass>
      class_cleanup_attribute(const std::string& name, TestClass& test_class, void (*method)()) :  class_cleanup_attribute(name, test_class, method, xtd::tunit::caller()) {}
      
      template<typename TestClass>
      class_cleanup_attribute(const std::string& name, TestClass& test_class, void (*method)(), const xtd::tunit::caller& caller) {test_class.add_class_cleanup({name, method, caller});}
    };
  }
}