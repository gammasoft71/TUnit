/// @file
/// @brief Contains__tunit_join__items functions.
#pragma once
#include "default_insert_basic_ostream_operator.h"
#include <sstream>
#include <string>

/// @cond
template<typename TCollection>
std::string __tunit_join__items(const TCollection& collection) {
  std::stringstream ss;
  ss << "< ";
  bool first = true;
  for (const auto& item : collection) {
    if (!first) ss << ", ";
    ss << __tunit_to_string(item);
    first = false;
  }
  ss << " >";
  return ss.str();
}

template<>
inline std::string __tunit_join__items<std::string>(const std::string& collection) {
  std::stringstream ss;
  ss << "< ";
  bool first = true;
  for (const char& item : collection) {
    if (!first) ss << ", ";
    ss << '\'' << item << '\'';
    first = false;
  }
  ss << " >";
  return ss.str();
}
/// @endcond
