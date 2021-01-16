/// @file
/// @brief Contains tunit::ignore_error exception.
#pragma once
#include <stdexcept>
#include <string>

/// @brief The tunit namespace contains a unit test library.
namespace tunit {
  /// @brief Exception thow when ignore.
  class ignore_error : public std::exception {
  public:
    /// @brief Create a new instance of ignore_error class.
    /// @param message Message string associate to the error.
    explicit ignore_error(const std::string& message) : message_(message) {}

    /// @brief Create a new instance of ignore_error class.
    /// @param message Message string associate to the error.
    explicit ignore_error(const char* message) : message_(message) {}

    /// @cond
    ignore_error(const ignore_error&) = default;
    ignore_error& operator=(const ignore_error&) = default;
    /// @endcond

    /// @brief Returns a string that represents the current ignore_error.
    /// @return string A string that represents the current ignore_error.
    const char* what() const noexcept {return this->message_.c_str();}
    
  private:
    std::string message_;
  };
}
