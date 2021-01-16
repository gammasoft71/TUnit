/// @file
/// @brief Contains tunit::class_initialize_attribute class.
#pragma once
#include "test.h"

/// @brief The tunit namespace contains a unit test library.
namespace tunit {
  /// @brief This attribute is use to add initialize class method to class test attribute.
  class class_initialize_attribute {
  public:
    /// @brief Creates new instance of classinitialize_attribute attribute.
    /// @param name Name of attribute
    /// @param test_class tunit::class_test containing initialize method.
    /// @param method Initialize class method.
    template<typename TestClass>
    class_initialize_attribute(const std::string& name, TestClass& test_class, void (*method)()) noexcept :  class_initialize_attribute(name, test_class, method, tunit::line_info()) {}
    
    /// @brief Creates new instance of classinitialize_attribute attribute.
    /// @param name Name of attribute
    /// @param test_class tunit::class_test containing initialize method.
    /// @param method Initialize class method.
    /// @param line_info Contains information about current file and current line.
    template<typename TestClass>
    class_initialize_attribute(const std::string& name, TestClass& test_class, void (*method)(), const tunit::line_info& caller) noexcept {test_class.add_class_initialize({name, method, caller});}
  };
}

/// @brief add initialize class method to class test.
/// @param method_name cleanup class method to add.
/// @ingroup tunit
#define class_initialize_(method_name) \
  __##method_name##_static() {} \
  class __class_initialize_attribute : public tunit::class_initialize_attribute { \
  public:\
    template<typename test_class> __class_initialize_attribute(test_class& test) : class_initialize_attribute(#method_name, test, &method_name, {__func__, __FILE__, __LINE__}) {__##method_name##_static();} \
  } __class_initialize_attribute {*this}; \
  static void method_name()

