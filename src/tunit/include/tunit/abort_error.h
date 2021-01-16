/// @file
/// @brief Contains tunit::abort_error exception.
#pragma once
#include <stdexcept>
#include <string>

/// @brief The tunit namespace contains a unit test library.
namespace tunit {
  /// @brief Exception thow when abort.
  class abort_error : public std::exception {
  public:
    /// @brief Create a new instance of abort_error class.
    /// @param message Message string associate to the error.
    explicit abort_error(const std::string& message) : message_(message) {}
    
    /// @brief Create a new instance of abort_error class.
    /// @param message Message string associate to the error.
    explicit abort_error(const char* message) : message_(message) {}
    
    /// @cond
    abort_error(const abort_error&) = default;
    abort_error& operator=(const abort_error&) = default;
    /// @endcond
    
    /// @brief Returns a string that represents the current abort_error.
    /// @return string A string that represents the current abort_error.
    const char* what() const noexcept {return this->message_.c_str();}
    
  private:
    std::string message_;
  };
}
