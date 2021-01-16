/// @file
/// @brief Contains tunit::test_method_attribute class.
#pragma once
#include "test.h"
#include "test_state.h"

/// @brief The tunit namespace contains a unit test library.
namespace tunit {
  class test_method_attribute {
  public:
    template<typename TestClass>
    test_method_attribute(const std::string& name, TestClass& test_class, void (TestClass::*method)()) noexcept : test_method_attribute(name, test_class, method, tunit::test_state::considered, tunit::line_info()) {}
    
    template<typename TestClass>
    test_method_attribute(const std::string& name, TestClass& test_class, void (TestClass::*method)(), const tunit::line_info& line_info) noexcept : test_method_attribute(name, test_class, method, tunit::test_state::considered, line_info) {}
    
    template<typename TestClass>
    test_method_attribute(const std::string& name, TestClass& test_class, void (TestClass::*method)(), tunit::test_state test_state) noexcept : test_method_attribute(name, test_class, method, test_state, tunit::line_info()) {}
    
    template<typename TestClass>
    test_method_attribute(const std::string& name, TestClass& test_class, void (TestClass::*method)(), tunit::test_state test_state, const tunit::line_info& line_info) noexcept {test_class.add_test_method({name, std::bind(method, &test_class), test_state == tunit::test_state::ignored, line_info});}
  };
}

#define ignore_test_method_(method_name) \
  __##method_name##_unused() = delete; \
  class __##method_name##_attribute##_class : public tunit::test_method_attribute { \
  public:\
    template<typename test_class> __##method_name##_attribute##_class(test_class& test) : test_method_attribute(#method_name, test, &test_class::method_name, tunit::test_state::ignored, {__func__, __FILE__, __LINE__}) {} \
  } __##method_name##_attribute {*this}; \
  void method_name()

#define test_method_(method_name) \
  __##method_name##_unused() = delete; \
  class __##method_name##_attribute##_class : public tunit::test_method_attribute { \
  public:\
    template<typename test_class> __##method_name##_attribute##_class(test_class& test) : test_method_attribute(#method_name, test, &test_class::method_name, {__func__, __FILE__, __LINE__}) {} \
  } __##method_name##_attribute {*this}; \
  void method_name()
