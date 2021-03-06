#include "../../include/tunit/test_class.h"
#include "../../include/tunit/unit_test.h"

using namespace tunit;

void test_class::run(const unit_test& unit_test) {
  if (tunit::settings::default_settings().shuffle_test()) {
    std::random_device rd;
    std::mt19937 g = tunit::settings::default_settings().random_seed() == 0 ? std::mt19937(rd()) : std::mt19937(tunit::settings::default_settings().random_seed());
    std::shuffle(tests_.begin(), tests_.end(), g);
  }
  
  unit_test.event_listener_->on_class_initialize_start(tunit::class_event_args(*this, unit_test));
  if (this->class_initialize().method() != nullptr)
    this->class_initialize().method()();
  unit_test.event_listener_->on_class_initialize_end(tunit::class_event_args(*this, unit_test));
  
  unit_test.event_listener_->on_class_start(tunit::class_event_args(*this, unit_test));
  
  this->start_time_point = std::chrono::high_resolution_clock::now();
  for (auto& test_method : this->tests_)
    test_method.run(unit_test, *this);
  this->end_time_point = std::chrono::high_resolution_clock::now();
  unit_test.event_listener_->on_class_end(tunit::class_event_args(*this, unit_test));
  
  unit_test.event_listener_->on_class_cleanup_start(tunit::class_event_args(*this, unit_test));
  if (this->class_cleanup().method() != nullptr)
    this->class_cleanup().method()();
  unit_test.event_listener_->on_class_cleanup_end(tunit::class_event_args(*this, unit_test));
}
