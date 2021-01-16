/// @file
/// @brief Contains xtd::tunit::class_event_args class.
#pragma once
#include "test_class.h"
#include "tunit_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Provides data for the xtd::tunit::class_test events.
    class class_event_args : public xtd::tunit::tunit_event_args {
    public:
      /// @brief Create a new instance of class class_event_args.
      /// @param test_class Current class_test.
      class_event_args(const xtd::tunit::test_class& test_class, const xtd::tunit::unit_test& unit_test) : xtd::tunit::tunit_event_args(unit_test), tc_(test_class) {}

      /// @brief Gets current class test.
      /// @return Current class test.
      const xtd::tunit::test_class& test_class() const noexcept {return this->tc_;}

    private:
      const xtd::tunit::test_class& tc_;
    };
  }
}
