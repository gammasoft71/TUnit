/// @file
/// @brief Contains tunit::collection_assert class.
#pragma once
#include "assert.h"

/// @brief The tunit namespace contains a unit test library.
namespace tunit {
  /// @brief The collection_assert class contains a collection of static methods that implement the most collection assertions used in tUnit.
  /// @par Examples
  /// This example show how to used some methods :
  /// @include assert.cpp
  class collection_assert final : private base_assert {
  public:
    /// @cond
    collection_assert() = delete;
    /// @endcond

    /// @brief Asserts that all collection items are of the type supplied or a derived type.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
    /// tunit::collection_assert::all_items_are_instances_of<std::ios_base*>(a); // test ok.
    /// tunit::collection_assert::all_items_are_instances_of<std::basic_ostream<char>*>(a); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TCollection>
    static void all_items_are_instances_of(const TCollection& collection) {all_items_are_instances_of<TExpected>(collection, "", line_info());}
    
    /// @brief Asserts that all collection items are of the type supplied or a derived type.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
    /// tunit::collection_assert::all_items_are_instances_of<std::ios_base*>(a, "User message..."); // test ok.
    /// tunit::collection_assert::all_items_are_instances_of<std::basic_ostream<char>*>(a, "User message..."); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TCollection>
    static void all_items_are_instances_of(const TCollection& collection, const std::string& message) {all_items_are_instances_of<TExpected>(collection, message, line_info());}
    
    /// @brief Asserts that all collection items are of the type supplied or a derived type.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
    /// tunit::collection_assert::all_items_are_instances_of<std::ios_base*>(a, line_info_); // test ok.
    /// tunit::collection_assert::all_items_are_instances_of<std::basic_ostream<char>*>(a, line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TCollection>
    static void all_items_are_instances_of(const TCollection& collection, const tunit::line_info& line_info) {all_items_are_instances_of<TExpected>(collection, "", line_info);}
    
    /// @brief Asserts that all collection items are of the type supplied or a derived type.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
    /// tunit::collection_assert::all_items_are_instances_of<std::ios_base*>(a, "User message...", line_info_); // test ok.
    /// tunit::collection_assert::all_items_are_instances_of<std::basic_ostream<char>*>(a, "User message...", line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TCollection>
    static void all_items_are_instances_of(const TCollection& collection, const std::string& message, const tunit::line_info& line_info) {
      for (auto item : collection)
        if (dynamic_cast<TExpected>(item) == nullptr) {
          base_assert::fail("all items instance of <" + __tunit_demangle(typeid(TExpected).name()) + ">", base_assert::join_items(collection), message, line_info);
          return;
        }
      assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TExpected, typename TItem>
    static void all_items_are_instances_of(const std::initializer_list<TItem>& collection) {all_items_are_instances_of<TExpected>(collection, "", line_info());}
    template<typename TExpected, typename TItem>
    static void all_items_are_instances_of(const std::initializer_list<TItem>& collection, const std::string& message) {all_items_are_instances_of<TExpected>(collection, message, line_info());}
    template<typename TExpected, typename TItem>
    static void all_items_are_instances_of(const std::initializer_list<TItem>& collection, const tunit::line_info& line_info) {all_items_are_instances_of<TExpected>(collection, "", line_info);}
    template<typename TExpected, typename TItem>
    static void all_items_are_instances_of(const std::initializer_list<TItem>& collection, const std::string& message, const tunit::line_info& line_info) {
      for (auto item : collection)
        if (dynamic_cast<TExpected>(item) == nullptr) {
          base_assert::fail("all items instance of <" + __tunit_demangle(typeid(TExpected).name()) + ">", base_assert::join_items(collection), message, line_info);
          return;
        }
      assert::succeed(message, line_info);
    }
    /// @endcond

    /// @brief Asserts that all collection items are not null.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// int i1 = 0, i2 = 3;
    /// std::vector<int*> a1 = {&i1, &i2};
    /// tunit::collection_assert::all_items_are_not_null(a1); // test ok.
    /// std::vector<int*> a2 = {&i1, &i2, nullptr};
    /// tunit::collection_assert::all_items_are_not_null(a2); // test throws an assertion_error exception.
    /// @endcode
    template<typename TCollection>
    static void all_items_are_not_null(const TCollection& collection) {all_items_are_not_null(collection, "", line_info());}
    
    /// @brief Asserts that all collection items are not null.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// int i1 = 0, i2 = 3;
    /// std::vector<int*> a1 = {&i1, &i2};
    /// tunit::collection_assert::all_items_are_not_null(a1, "User message..."); // test ok.
    /// std::vector<int*> a2 = {&i1, &i2, nullptr};
    /// tunit::collection_assert::all_items_are_not_null(a2, "User message..."); // test throws an assertion_error exception.
    /// @endcode
    template<typename TCollection>
    static void all_items_are_not_null(const TCollection& collection, const std::string& message) {all_items_are_not_null(collection, message, line_info());}
    
    /// @brief Asserts that all collection items are not null.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// int i1 = 0, i2 = 3;
    /// std::vector<int*> a1 = {&i1, &i2};
    /// tunit::collection_assert::all_items_are_not_null(a1, line_info_); // test ok.
    /// std::vector<int*> a2 = {&i1, &i2, nullptr};
    /// tunit::collection_assert::all_items_are_not_null(a2, line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TCollection>
    static void all_items_are_not_null(const TCollection& collection, const tunit::line_info& line_info) {all_items_are_instances_of(collection, "", line_info);}
    
    /// @brief Asserts that all collection items are not null.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// int i1 = 0, i2 = 3;
    /// std::vector<int*> a1 = {&i1, &i2};
    /// tunit::collection_assert::all_items_are_not_null(a1, "User message...", line_info_); // test ok.
    /// std::vector<int*> a2 = {&i1, &i2, nullptr};
    /// tunit::collection_assert::all_items_are_not_null(a2, "User message...", line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TCollection>
    static void all_items_are_not_null(const TCollection& collection, const std::string& message, const tunit::line_info& line_info) {
      for (auto item : collection)
        if (item == nullptr) {
          base_assert::fail("all items are not null", base_assert::join_items(collection), message, line_info);
          return;
        }
      assert::succeed(message, line_info);
    }

    /// @cond
    template<typename TItem>
    static void all_items_are_not_null(const std::initializer_list<TItem>& collection) {all_items_are_not_null(collection, "", line_info());}
    template<typename TItem>
    static void all_items_are_not_null(const std::initializer_list<TItem>& collection, const std::string& message) {all_items_are_not_null(collection, message, line_info());}
    template<typename TItem>
    static void all_items_are_not_null(const std::initializer_list<TItem>& collection, const tunit::line_info& line_info) {all_items_are_instances_of(collection, "", line_info);}
    template<typename TItem>
    static void all_items_are_not_null(const std::initializer_list<TItem>& collection, const std::string& message, const tunit::line_info& line_info) {
      for (auto item : collection)
        if (item == nullptr) {
          base_assert::fail("all items are not null", base_assert::join_items(collection), message, line_info);
          return;
        }
      assert::succeed(message, line_info);
    }
    /// @endcond

    /// @brief Asserts that all collection items are unique.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a1 = {1, 2, 3, 4};
    /// tunit::collection_assert::all_items_are_unique(a1); // test ok.
    /// std::vector<int> a2 = {1, 2, 3, 4, 1};
    /// tunit::collection_assert::all_items_are_unique(a2); // test throws an assertion_error exception.
    /// @endcode
    template<typename TCollection>
    static void all_items_are_unique(const TCollection& collection) {all_items_are_unique(collection, "", line_info());}
    
    /// @brief Asserts that all collection items are unique.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a1 = {1, 2, 3, 4};
    /// tunit::collection_assert::all_items_are_unique(a1, "User message..."); // test ok.
    /// std::vector<int> a2 = {1, 2, 3, 4, 1};
    /// tunit::collection_assert::all_items_are_unique(a2, "User message..."); // test throws an assertion_error exception.
    /// @endcode
    template<typename TCollection>
    static void all_items_are_unique(const TCollection& collection, const std::string& message) {all_items_are_unique(collection, message, line_info());}
    
    /// @brief Asserts that all collection items are unique.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a1 = {1, 2, 3, 4};
    /// tunit::collection_assert::all_iall_items_are_uniquetems_are_not_null(a1, line_info_); // test ok.
    /// std::vector<int> a2 = {1, 2, 3, 4, 1};
    /// tunit::collection_assert::all_items_are_unique(a2, line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TCollection>
    static void all_items_are_unique(const TCollection& collection, const tunit::line_info& line_info) {all_items_are_unique(collection, "", line_info);}
    
    /// @brief Asserts that all collection items are unique.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a1 = {1, 2, 3, 4};
    /// tunit::collection_assert::all_items_are_unique(a1, "User message...", line_info_); // test ok.
    /// std::vector<int> a2 = {1, 2, 3, 4, 1};
    /// tunit::collection_assert::all_items_are_unique(a2, "User message...", line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TCollection>
    static void all_items_are_unique(const TCollection& collection, const std::string& message, const tunit::line_info& line_info) {
      auto value = *collection.cbegin();
      std::map<decltype(value), int> counts;
      for (auto item : collection) {
        auto result = counts.insert(std::pair<decltype(item), int>(item, 1));
        if (result.second == false)
          base_assert::fail("all items are unqiue", base_assert::join_items(collection), message, line_info);
      }
      assert::succeed(message, line_info);
    }

    /// @cond
    template<typename TItem>
    static void all_items_are_unique(const std::initializer_list<TItem>& collection) {all_items_are_unique(collection, "", line_info());}
    template<typename TItem>
    static void all_items_are_unique(const std::initializer_list<TItem>& collection, const tunit::line_info& line_info) {all_items_are_unique(collection, "", line_info);}
    template<typename TItem>
    static void all_items_are_unique(const std::initializer_list<TItem>& collection, const std::string& message) {all_items_are_unique(collection, message, line_info());}
    template<typename TItem>
    static void all_items_are_unique(const std::initializer_list<TItem>& collection, const std::string& message, const tunit::line_info& line_info) {
      std::map<TItem, int> counts;
      for (auto item : collection) {
        auto result = counts.insert(std::pair<TItem, int>(item, 1));
        if (result.second == false)
          base_assert::fail("all items are unqiue", base_assert::join_items(collection), message, line_info);
      }
      assert::succeed(message, line_info);
    }
    /// @endcond

    /// @brief Asserts that all collection items are equal.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_equal({1, 2, 3, 4}, a); // test ok.
    /// tunit::collection_assert::are_equal({4, 3, 2, 1}, a); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_equal(const TExpected& expected, const TAcutal& actual) {are_equal(expected, actual, "", line_info());}
    
    /// @brief Asserts that all collection items are equal.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_equal({1, 2, 3, 4}, a, "User message..."); // test ok.
    /// tunit::collection_assert::are_equal({4, 3, 2, 1}, a, "User message..."); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_equal(const TExpected& expected, const TAcutal& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
    
    /// @brief Asserts that all collection items are equal.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_equal({1, 2, 3, 4}, a, line_info_); // test ok.
    /// tunit::collection_assert::are_equal({4, 3, 2, 1}, a, line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_equal(const TExpected& expected, const TAcutal& actual, const tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
    
    /// @brief Asserts that all collection items are equal.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_equal({1, 2, 3, 4}, a, "User message...", line_info_); // test ok.
    /// tunit::collection_assert::are_equal({4, 3, 2, 1}, a, "User message...", line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_equal(const TExpected& expected, const TAcutal& actual, const std::string& message, const tunit::line_info& line_info) {
      if (std::equal(expected.begin(), expected.end(), actual.begin(), actual.end()) == false)
        base_assert::fail(base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TItem>
    static void are_equal(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual) {are_equal(expected, actual, "", line_info());}
    template<typename TItem>
    static void are_equal(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual, const tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
    template<typename TItem>
    static void are_equal(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
    template<typename TItem>
    static void are_equal(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual, const std::string& message, const tunit::line_info& line_info) {
      if (std::equal(expected.begin(), expected.end(), actual.begin(), actual.end()) == false)
        base_assert::fail(base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TCollection, typename TItem>
    static void are_equal(const TCollection& expected, const std::initializer_list<TItem>& actual) {are_equal(expected, actual, "", line_info());}
    template<typename TCollection, typename TItem>
    static void are_equal(const TCollection& expected, const std::initializer_list<TItem>& actual, const tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
    template<typename TCollection, typename TItem>
    static void are_equal(const TCollection& expected, const std::initializer_list<TItem>& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
    template<typename TCollection, typename TItem>
    static void are_equal(const TCollection& expected, const std::initializer_list<TItem>& actual, const std::string& message, const tunit::line_info& line_info) {
      if (std::equal(expected.begin(), expected.end(), actual.begin(), actual.end()) == false)
        base_assert::fail(base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TItem, typename TCollection>
    static void are_equal(const std::initializer_list<TItem>& expected, const TCollection& actual) {are_equal(expected, actual, "", line_info());}
    template<typename TItem, typename TCollection>
    static void are_equal(const std::initializer_list<TItem>& expected, const TCollection& actual, const tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
    template<typename TItem, typename TCollection>
    static void are_equal(const std::initializer_list<TItem>& expected, const TCollection& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
    template<typename TItem, typename TCollection>
    static void are_equal(const std::initializer_list<TItem>& expected, const TCollection& actual, const std::string& message, const tunit::line_info& line_info) {
      if (std::equal(expected.begin(), expected.end(), actual.begin(), actual.end()) == false)
        base_assert::fail(base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    /// @endcond

    /// @brief Asserts that all collection items are equivalent.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_equivalent({4, 3, 2, 1}, a); // test ok.
    /// tunit::collection_assert::are_equivalent({1, 2, 3, 5}, a); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_equivalent(const TExpected& expected, const TAcutal& actual) {are_equivalent(expected, actual, "", line_info());}
    
    /// @brief Asserts that all collection items are equivalent.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_equivalent({4, 3, 2, 1}, a, "User message..."); // test ok.
    /// tunit::collection_assert::are_equivalent({1, 2, 3, 5}, a, "User message..."); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_equivalent(const TExpected& expected, const TAcutal& actual, const std::string& message) {are_equivalent(expected, actual, message, line_info());}
    
    /// @brief Asserts that all collection items are equivalent.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_equivalent({4, 3, 2, 1}, a, line_info_); // test ok.
    /// tunit::collection_assert::are_equivalent({1, 2, 3, 5}, a, line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_equivalent(const TExpected& expected, const TAcutal& actual, const tunit::line_info& line_info) {are_equivalent(expected, actual, "", line_info);}
    
    /// @brief Asserts that all collection items are equivalent.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_equivalent({4, 3, 2, 1}, a, "User message...", line_info_); // test ok.
    /// tunit::collection_assert::are_equivalent({1, 2, 3, 5}, a, "User message...", line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_equivalent(const TExpected& expected, const TAcutal& actual, const std::string& message, const tunit::line_info& line_info) {
      TExpected expect_sorted = expected;
      std::sort(expect_sorted.begin(), expect_sorted.end());
      TExpected actual_sorted = actual;
      std::sort(actual_sorted.begin(), actual_sorted.end());
      if (std::equal(expect_sorted.begin(), expect_sorted.end(), actual_sorted.begin(), actual_sorted.end()) == false)
        base_assert::fail("equivalent " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TExpected, typename TActual>
    static void are_equivalent(const std::initializer_list<TExpected>& expected, const std::initializer_list<TActual>& actual) {are_equivalent(expected, actual, "", line_info());}
    template<typename TExpected, typename TActual>
    static void are_equivalent(const std::initializer_list<TExpected>& expected, const std::initializer_list<TActual>& actual, const tunit::line_info& line_info) {are_equivalent(expected, actual, "", line_info);}
    template<typename TExpected, typename TActual>
    static void are_equivalent(const std::initializer_list<TExpected>& expected, const std::initializer_list<TActual>& actual, const std::string& message) {are_equal(are_equivalent, actual, message, line_info());}
    template<typename TExpected, typename TActual>
    static void are_equivalent(const std::initializer_list<TExpected>& expected, const std::initializer_list<TActual>& actual, const std::string& message, const tunit::line_info& line_info) {
      std::vector<TExpected> expect_sorted = expected;
      std::sort(expect_sorted.begin(), expect_sorted.end());
      std::vector<TActual> actual_sorted = actual;
      std::sort(actual_sorted.begin(), actual_sorted.end());
      if (std::equal(expect_sorted.begin(), expect_sorted.end(), actual_sorted.begin(), actual_sorted.end()) == false)
        base_assert::fail("equivalent " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TCollection, typename TItem>
    static void are_equivalent(const TCollection& expected, const std::initializer_list<TItem>& actual) {are_equivalent(expected, actual, "", line_info());}
    template<typename TCollection, typename TItem>
    static void are_equivalent(const TCollection& expected, const std::initializer_list<TItem>& actual, const tunit::line_info& line_info) {are_equivalent(expected, actual, "", line_info);}
    template<typename TCollection, typename TItem>
    static void are_equivalent(const TCollection& expected, const std::initializer_list<TItem>& actual, const std::string& message) {are_equivalent(expected, actual, message, line_info());}
    template<typename TCollection, typename TItem>
    static void are_equivalent(const TCollection& expected, const std::initializer_list<TItem>& actual, const std::string& message, const tunit::line_info& line_info) {
      TCollection expect_sorted = expected;
      std::sort(expect_sorted.begin(), expect_sorted.end());
      std::vector<TItem> actual_sorted = actual;
      std::sort(actual_sorted.begin(), actual_sorted.end());
      if (std::equal(expect_sorted.begin(), expect_sorted.end(), actual_sorted.begin(), actual_sorted.end()) == false)
        base_assert::fail("equivalent " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TItem, typename TCollection>
    static void are_equivalent(const std::initializer_list<TItem>& expected, const TCollection& actual) {are_equivalent(expected, actual, "", line_info());}
    template<typename TItem, typename TCollection>
    static void are_equivalent(const std::initializer_list<TItem>& expected, const TCollection& actual, const tunit::line_info& line_info) {are_equivalent(expected, actual, "", line_info);}
    template<typename TItem, typename TCollection>
    static void are_equivalent(const std::initializer_list<TItem>& expected, const TCollection& actual, const std::string& message) {are_equivalent(expected, actual, message, line_info());}
    template<typename TItem, typename TCollection>
    static void are_equivalent(const std::initializer_list<TItem>& expected, const TCollection& actual, const std::string& message, const tunit::line_info& line_info) {
      std::vector<TItem> expect_sorted = expected;
      std::sort(expect_sorted.begin(), expect_sorted.end());
      TCollection actual_sorted = actual;
      std::sort(actual_sorted.begin(), actual_sorted.end());
      if (std::equal(expect_sorted.begin(), expect_sorted.end(), actual_sorted.begin(), actual_sorted.end()) == false)
        base_assert::fail("equivalent " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    /// @endcond

    /// @brief Asserts that all collection items are not equal.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_not_equal({4, 3, 2, 1}, a); // test ok.
    /// tunit::collection_assert::are_not_equal({1, 2, 3, 4}, a); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_not_equal(const TExpected& expected, const TAcutal& actual) {are_not_equal(expected, actual, "", line_info());}
    
    /// @brief Asserts that all collection items are not equal.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_not_equal({4, 3, 2, 1}, a, "User message..."); // test ok.
    /// tunit::collection_assert::are_not_equal({1, 2, 3, 4}, a, "User message..."); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_not_equal(const TExpected& expected, const TAcutal& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
    
    /// @brief Asserts that all collection items are not equal.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_not_equal({4, 3, 2, 1}, a, line_info_); // test ok.
    /// tunit::collection_assert::are_not_equal({1, 2, 3, 4}, a, line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_not_equal(const TExpected& expected, const TAcutal& actual, const tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
    
    /// @brief Asserts that all collection items arenot  equal.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_not_equal({4, 3, 2, 1}, a, "User message...", line_info_); // test ok.
    /// tunit::collection_assert::are_not_equal({1, 2, 3, 4}, a, "User message...", line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_not_equal(const TExpected& expected, const TAcutal& actual, const std::string& message, const tunit::line_info& line_info) {
      if (std::equal(expected.begin(), expected.end(), actual.begin(), actual.end()) == true)
        base_assert::fail("not " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TItem>
    static void are_not_equal(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual) {are_not_equal(expected, actual, "", line_info());}
    template<typename TItem>
    static void are_not_equal(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual, const tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
    template<typename TItem>
    static void are_not_equal(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
    template<typename TItem>
    static void are_not_equal(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual, const std::string& message, const tunit::line_info& line_info) {
      if (std::equal(expected.begin(), expected.end(), actual.begin(), actual.end()) == true)
        base_assert::fail("not " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TCollection, typename TItem>
    static void are_not_equal(const TCollection& expected, const std::initializer_list<TItem>& actual) {are_not_equal(expected, actual, "", line_info());}
    template<typename TCollection, typename TItem>
    static void are_not_equal(const TCollection& expected, const std::initializer_list<TItem>& actual, const tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
    template<typename TCollection, typename TItem>
    static void are_not_equal(const TCollection& expected, const std::initializer_list<TItem>& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
    template<typename TCollection, typename TItem>
    static void are_not_equal(const TCollection& expected, const std::initializer_list<TItem>& actual, const std::string& message, const tunit::line_info& line_info) {
      if (std::equal(expected.begin(), expected.end(), actual.begin(), actual.end()) == true)
        base_assert::fail("not " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TItem, typename TCollection>
    static void are_not_equal(const std::initializer_list<TItem>& expected, const TCollection& actual) {are_not_equal(expected, actual, "", line_info());}
    template<typename TItem, typename TCollection>
    static void are_not_equal(const std::initializer_list<TItem>& expected, const TCollection& actual, const tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
    template<typename TItem, typename TCollection>
    static void are_not_equal(const std::initializer_list<TItem>& expected, const TCollection& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
    template<typename TItem, typename TCollection>
    static void are_not_equal(const std::initializer_list<TItem>& expected, const TCollection& actual, const std::string& message, const tunit::line_info& line_info) {
      if (std::equal(expected.begin(), expected.end(), actual.begin(), actual.end()) == true)
        base_assert::fail("not " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    /// @endcond

    /// @brief Asserts that all collection items are not equivalent.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_not_equivalent({1, 2, 3, 5}, a); // test ok.
    /// tunit::collection_assert::are_not_equivalent({4, 3, 2, 1}, a); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_not_equivalent(const TExpected& expected, const TAcutal& actual) {are_not_equivalent(expected, actual, "", line_info());}
    
    /// @brief Asserts that all collection items are not equivalent.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_not_equivalent({1, 2, 3, 5}, a, "User message..."); // test ok.
    /// tunit::collection_assert::are_not_equivalent({4, 3, 2, 1}, a, "User message..."); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_not_equivalent(const TExpected& expected, const TAcutal& actual, const std::string& message) {are_not_equivalent(expected, actual, message, line_info());}
    
    /// @brief Asserts that all collection items are not equivalent.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_not_equivalent({1, 2, 3, 5}, a, line_info_); // test ok.
    /// tunit::collection_assert::are_not_equivalent({4, 3, 2, 1}, a, line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_not_equivalent(const TExpected& expected, const TAcutal& actual, const tunit::line_info& line_info) {are_not_equivalent(expected, actual, "", line_info);}
    
    /// @brief Asserts that all collection items are not equivalent.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::are_not_equivalent({1, 2, 3, 5}, a, "User message...", line_info_); // test ok.
    /// tunit::collection_assert::are_not_equivalent({4, 3, 2, 1}, a, "User message...", line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void are_not_equivalent(const TExpected& expected, const TAcutal& actual, const std::string& message, const tunit::line_info& line_info) {
      TExpected expect_sorted = expected;
      std::sort(expect_sorted.begin(), expect_sorted.end());
      TExpected actual_sorted = actual;
      std::sort(actual_sorted.begin(), actual_sorted.end());
      if (std::equal(expect_sorted.begin(), expect_sorted.end(), actual_sorted.begin(), actual_sorted.end()) == true)
        base_assert::fail("not equivalent " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TExpected, typename TActual>
    static void are_not_equivalent(const std::initializer_list<TExpected>& expected, const std::initializer_list<TActual>& actual) {are_not_equivalent(expected, actual, "", line_info());}
    template<typename TExpected, typename TActual>
    static void are_not_equivalent(const std::initializer_list<TExpected>& expected, const std::initializer_list<TActual>& actual, const tunit::line_info& line_info) {are_not_equivalent(expected, actual, "", line_info);}
    template<typename TExpected, typename TActual>
    static void are_not_equivalent(const std::initializer_list<TExpected>& expected, const std::initializer_list<TActual>& actual, const std::string& message) {are_not_equivalent(are_equivalent, actual, message, line_info());}
    template<typename TExpected, typename TActual>
    static void are_not_equivalent(const std::initializer_list<TExpected>& expected, const std::initializer_list<TActual>& actual, const std::string& message, const tunit::line_info& line_info) {
      std::vector<TExpected> expect_sorted = expected;
      std::sort(expect_sorted.begin(), expect_sorted.end());
      std::vector<TActual> actual_sorted = actual;
      std::sort(actual_sorted.begin(), actual_sorted.end());
      if (std::equal(expect_sorted.begin(), expect_sorted.end(), actual_sorted.begin(), actual_sorted.end()) == true)
        base_assert::fail("not equivalent " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TCollection, typename TItem>
    static void are_not_equivalent(const TCollection& expected, const std::initializer_list<TItem>& actual) {are_not_equivalent(expected, actual, "", line_info());}
    template<typename TCollection, typename TItem>
    static void are_not_equivalent(const TCollection& expected, const std::initializer_list<TItem>& actual, const tunit::line_info& line_info) {are_not_equivalent(expected, actual, "", line_info);}
    template<typename TCollection, typename TItem>
    static void are_not_equivalent(const TCollection& expected, const std::initializer_list<TItem>& actual, const std::string& message) {are_not_equivalent(expected, actual, message, line_info());}
    template<typename TCollection, typename TItem>
    static void are_not_equivalent(const TCollection& expected, const std::initializer_list<TItem>& actual, const std::string& message, const tunit::line_info& line_info) {
      TCollection expect_sorted = expected;
      std::sort(expect_sorted.begin(), expect_sorted.end());
      std::vector<TItem> actual_sorted = actual;
      std::sort(actual_sorted.begin(), actual_sorted.end());
      if (std::equal(expect_sorted.begin(), expect_sorted.end(), actual_sorted.begin(), actual_sorted.end()) == true)
        base_assert::fail("not equivalent " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TItem, typename TCollection>
    static void are_not_equivalent(const std::initializer_list<TItem>& expected, const TCollection& actual) {are_not_equivalent(expected, actual, "", line_info());}
    template<typename TItem, typename TCollection>
    static void are_not_equivalent(const std::initializer_list<TItem>& expected, const TCollection& actual, const tunit::line_info& line_info) {are_not_equivalent(expected, actual, "", line_info);}
    template<typename TItem, typename TCollection>
    static void are_not_equivalent(const std::initializer_list<TItem>& expected, const TCollection& actual, const std::string& message) {are_not_equivalent(expected, actual, message, line_info());}
    template<typename TItem, typename TCollection>
    static void are_not_equivalent(const std::initializer_list<TItem>& expected, const TCollection& actual, const std::string& message, const tunit::line_info& line_info) {
      std::vector<TItem> expect_sorted = expected;
      std::sort(expect_sorted.begin(), expect_sorted.end());
      TCollection actual_sorted = actual;
      std::sort(actual_sorted.begin(), actual_sorted.end());
      if (std::equal(expect_sorted.begin(), expect_sorted.end(), actual_sorted.begin(), actual_sorted.end()) == true)
        base_assert::fail("not equivalent " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
      else
        assert::succeed(message, line_info);
    }
    /// @endcond

    /// @brief Asserts that ollection contains all items.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::contains({1, 2, a); // test ok.
    /// tunit::collection_assert::contains({1, 2, 6}, a); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void contains(const TExpected& expected, const TAcutal& actual) {contains(expected, actual, "", line_info());}
    
    /// @brief Asserts that collection contains all items.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::contains({1, 2}, a, "User message..."); // test ok.
    /// tunit::collection_assert::contains({1, 2, 6}, a, "User message..."); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void contains(const TExpected& expected, const TAcutal& actual, const std::string& message) {contains(expected, actual, message, line_info());}
    
    /// @brief Asserts that collection contains all items.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::contains({1, 2}, a, line_info_); // test ok.
    /// tunit::collection_assert::contains({1, 2, 6}, a, line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void contains(const TExpected& expected, const TAcutal& actual, const tunit::line_info& line_info) {contains(expected, actual, "", line_info);}
    
    /// @brief Asserts that collection contains all items.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::contains({1, 2}, a, "User message...", line_info_); // test ok.
    /// tunit::collection_assert::contains({1, 2, 6}, a, "User message...", line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void contains(const TExpected& expected, const TAcutal& actual, const std::string& message, const tunit::line_info& line_info) {
      for (auto item : expected) {
        if (std::find(actual.begin(), actual.end(), item) == actual.end()) {
          base_assert::fail("contains " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
          return;
        }
      }
      assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TItem>
    static void contains(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual) {contains(expected, actual, "", line_info());}
    template<typename TItem>
    static void contains(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual, const tunit::line_info& line_info) {contains(expected, actual, "", line_info);}
    template<typename TItem>
    static void contains(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual, const std::string& message) {contains(expected, actual, message, line_info());}
    template<typename TItem>
    static void contains(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual, const std::string& message, const tunit::line_info& line_info) {
      for (auto item : expected) {
        if (std::find(actual.begin(), actual.end(), item) == actual.end()) {
          base_assert::fail("contains " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
          return;
        }
      }
      assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TCollection, typename TItem>
    static void contains(const TCollection& expected, const std::initializer_list<TItem>& actual) {contains(expected, actual, "", line_info());}
    template<typename TCollection, typename TItem>
    static void contains(const TCollection& expected, const std::initializer_list<TItem>& actual, const tunit::line_info& line_info) {contains(expected, actual, "", line_info);}
    template<typename TCollection, typename TItem>
    static void contains(const TCollection& expected, const std::initializer_list<TItem>& actual, const std::string& message) {contains(expected, actual, message, line_info());}
    template<typename TCollection, typename TItem>
    static void contains(const TCollection& expected, const std::initializer_list<TItem>& actual, const std::string& message, const tunit::line_info& line_info) {
      for (auto item : expected) {
        if (std::find(actual.begin(), actual.end(), item) == actual.end()) {
          base_assert::fail("contains " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
          return;
        }
      }
      assert::succeed(message, line_info);
    }
    
    /// @cond
    template<typename TItem, typename TCollection>
    static void contains(const std::initializer_list<TItem>& expected, const TCollection& actual) {contains(expected, actual, "", line_info());}
    template<typename TItem, typename TCollection>
    static void contains(const std::initializer_list<TItem>& expected, const TCollection& actual, const tunit::line_info& line_info) {contains(expected, actual, "", line_info);}
    template<typename TItem, typename TCollection>
    static void contains(const std::initializer_list<TItem>& expected, const TCollection& actual, const std::string& message) {contains(expected, actual, message, line_info());}
    template<typename TItem, typename TCollection>
    static void contains(const std::initializer_list<TItem>& expected, const TCollection& actual, const std::string& message, const tunit::line_info& line_info) {
      for (auto item : expected) {
        if (std::find(actual.begin(), actual.end(), item) == actual.end()) {
          base_assert::fail("contains " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
          return;
        }
      }
      assert::succeed(message, line_info);
    }
    /// @endcond

    /// @brief Asserts that ollection contains all items.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::does_not_contain({1, 2, a); // test ok.
    /// tunit::collection_assert::does_not_contain({1, 2, 6}, a); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void does_not_contain(const TExpected& expected, const TAcutal& actual) {does_not_contain(expected, actual, "", line_info());}
    
    /// @brief Asserts that collection contains all items.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::does_not_contain({1, 2}, a, "User message..."); // test ok.
    /// tunit::collection_assert::does_not_contain({1, 2, 6}, a, "User message..."); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void does_not_contain(const TExpected& expected, const TAcutal& actual, const std::string& message) {does_not_contain(expected, actual, message, line_info());}
    
    /// @brief Asserts that collection contains all items.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::does_not_contain({1, 2}, a, line_info_); // test ok.
    /// tunit::collection_assert::does_not_contain({1, 2, 6}, a, line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void does_not_contain(const TExpected& expected, const TAcutal& actual, const tunit::line_info& line_info) {does_not_contain(expected, actual, "", line_info);}
    
    /// @brief Asserts that collection contains all items.
    /// @param value The object to verify
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> a = {1, 2, 3, 4};
    /// tunit::collection_assert::does_not_contain({1, 2}, a, "User message...", line_info_); // test ok.
    /// tunit::collection_assert::does_not_contain({1, 2, 6}, a, "User message...", line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TExpected, typename TAcutal>
    static void does_not_contain(const TExpected& expected, const TAcutal& actual, const std::string& message, const tunit::line_info& line_info) {
      for (auto item : expected) {
        if (std::find(actual.begin(), actual.end(), item) == actual.end()) {
          assert::succeed(message, line_info);
          return;
        }
      }
      base_assert::fail("not contains " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
    }
    
    /// @cond
    template<typename TItem>
    static void does_not_contain(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual) {does_not_contain(expected, actual, "", line_info());}
    template<typename TItem>
    static void does_not_contain(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual, const tunit::line_info& line_info) {does_not_contain(expected, actual, "", line_info);}
    template<typename TItem>
    static void does_not_contain(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual, const std::string& message) {does_not_contain(expected, actual, message, line_info());}
    template<typename TItem>
    static void does_not_contain(const std::initializer_list<TItem>& expected, const std::initializer_list<TItem>& actual, const std::string& message, const tunit::line_info& line_info) {
      for (auto item : expected) {
        if (std::find(actual.begin(), actual.end(), item) == actual.end()) {
          assert::succeed(message, line_info);
          return;
        }
      }
      base_assert::fail("not contains " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
    }
    
    /// @cond
    template<typename TCollection, typename TItem>
    static void does_not_contain(const TCollection& expected, const std::initializer_list<TItem>& actual) {does_not_contain(expected, actual, "", line_info());}
    template<typename TCollection, typename TItem>
    static void does_not_contain(const TCollection& expected, const std::initializer_list<TItem>& actual, const tunit::line_info& line_info) {does_not_contain(expected, actual, "", line_info);}
    template<typename TCollection, typename TItem>
    static void does_not_contain(const TCollection& expected, const std::initializer_list<TItem>& actual, const std::string& message) {does_not_contain(expected, actual, message, line_info());}
    template<typename TCollection, typename TItem>
    static void does_not_contain(const TCollection& expected, const std::initializer_list<TItem>& actual, const std::string& message, const tunit::line_info& line_info) {
      for (auto item : expected) {
        if (std::find(actual.begin(), actual.end(), item) == actual.end()) {
          assert::succeed(message, line_info);
          return;
        }
      }
      base_assert::fail("not contains " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
    }
    
    /// @cond
    template<typename TItem, typename TCollection>
    static void does_not_contain(const std::initializer_list<TItem>& expected, const TCollection& actual) {does_not_contain(expected, actual, "", line_info());}
    template<typename TItem, typename TCollection>
    static void does_not_contain(const std::initializer_list<TItem>& expected, const TCollection& actual, const tunit::line_info& line_info) {does_not_contain(expected, actual, "", line_info);}
    template<typename TItem, typename TCollection>
    static void does_not_contain(const std::initializer_list<TItem>& expected, const TCollection& actual, const std::string& message) {does_not_contain(expected, actual, message, line_info());}
    template<typename TItem, typename TCollection>
    static void does_not_contain(const std::initializer_list<TItem>& expected, const TCollection& actual, const std::string& message, const tunit::line_info& line_info) {
      for (auto item : expected) {
        if (std::find(actual.begin(), actual.end(), item) == actual.end()) {
          assert::succeed(message, line_info);
          return;
        }
      }
      base_assert::fail("not contains " + base_assert::join_items(expected), base_assert::join_items(actual), message, line_info);
    }
    /// @endcond
    
    /// @brief Asserts that collection contains an item.
    /// @param value The value to check is empty.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> v1;
    /// std::vector<int> v2 = {0, 1, 2, 3};
    /// tunit::assert::is_empty(v1); // test ok.
    /// tunit::assert::is_empty(v2); // test throws an assertion_error exception.
    /// @endcode
    template<typename TValue>
    static void is_empty(const TValue& value) {is_empty(value, "", line_info());}
    
    /// @brief Asserts that collection contains an item.
    /// @param value The value to check is empty.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> v1;
    /// std::vector<int> v2 = {0, 1, 2, 3};
    /// tunit::assert::is_empty(v1, line_info_); // test ok.
    /// tunit::assert::is_empty(v2, line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TValue>
    static void is_empty(const TValue& value, const tunit::line_info& line_info) {is_empty(value, "", line_info);}
    
    /// @brief Asserts that collection contains an item.
    /// @param value The value to check is empty.
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> v1;
    /// std::vector<int> v2 = {0, 1, 2, 3};
    /// tunit::assert::is_empty(v1, "User message..."); // test ok.
    /// tunit::assert::is_empty(v2, "User message..."); // test throws an assertion_error exception.
    /// @endcode
    template<typename TValue>
    static void is_empty(const TValue& value, const std::string& message) {is_empty(value, message, line_info());}
    
    /// @brief Asserts that collection contains an item.
    /// @param value The value to check is empty.
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> v1;
    /// std::vector<int> v2 = {0, 1, 2, 3};
    /// tunit::assert::is_empty(v1, "User message...", line_info_); // test ok.
    /// tunit::assert::is_empty(v2, "User message...", line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TValue>
    static void is_empty(const TValue& value, const std::string& message, const tunit::line_info& line_info) {
      if (std::empty(value))
        assert::succeed(message, line_info);
      else
        base_assert::fail("<empty>", base_assert::join_items(value), message, line_info);
    }
    
    /// @cond
    template<typename TValue>
    static void is_empty(const std::initializer_list<TValue>& value) {is_empty(value, "", line_info());}
    template<typename TValue>
    static void is_empty(const std::initializer_list<TValue>& value, const tunit::line_info& line_info) {is_empty(value, "", line_info);}
    template<typename TValue>
    static void is_empty(const std::initializer_list<TValue>& value, const std::string& message) {is_empty(value, message, line_info());}
    template<typename TValue>
    static void is_empty(const std::initializer_list<TValue>& value, const std::string& message, const tunit::line_info& line_info) {
      if (std::empty(value))
        assert::succeed(message, line_info);
      else
        base_assert::fail("<empty>", base_assert::join_items(value), message, line_info);
    }
    /// @endcond
    
    /// @brief Asserts that collection does not contain any item.
    /// @param value The value to check is empty.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> v1 = {0, 1, 2, 3};
    /// std::vector<int> v2;
    /// tunit::assert::is_not_empty(v1); // test ok.
    /// tunit::assert::is_not_empty(v2); // test throws an assertion_error exception.
    /// @endcode
    template<typename TValue>
    static void is_not_empty(const TValue& value) {is_not_empty(value, "", line_info());}
    
    /// @brief Asserts that collection or traits does not contain any item.
    /// @param value The value to check is empty.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> v1 = {0, 1, 2, 3};
    /// std::vector<int> v2;
    /// tunit::assert::is_not_empty(v1, line_info_); // test ok.
    /// tunit::assert::is_not_empty(v2, line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TValue>
    static void is_not_empty(const TValue& value, const tunit::line_info& line_info) {is_not_empty(value, "", line_info);}
    
    /// @brief Asserts that collection or traits does not contain any item.
    /// @param value The value to check is empty.
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> v1 = {0, 1, 2, 3};
    /// std::vector<int> v2;
    /// tunit::assert::is_not_empty(v1, "User message..."); // test ok.
    /// tunit::assert::is_not_empty(v2, "User message..."); // test throws an assertion_error exception.
    /// @endcode
    template<typename TValue>
    static void is_not_empty(const TValue& value, const std::string& message) {is_not_empty(value, message, line_info());}
    
    /// @brief Asserts that collection or traits does not contain any item.
    /// @param value The value to check is empty.
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> v1 = {0, 1, 2, 3};
    /// std::vector<int> v2;
    /// tunit::assert::is_not_empty(v1, "User message...", line_info_); // test ok.
    /// tunit::assert::is_not_empty(v2, "User message...", line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TValue>
    static void is_not_empty(const TValue& value, const std::string& message, const tunit::line_info& line_info) {
      if (!std::empty(value))
        assert::succeed(message, line_info);
      else
        base_assert::fail("not <empty>", "<empty>", message, line_info);
    }
    
    /// @cond
    template<typename TValue>
    static void is_not_empty(const std::initializer_list<TValue>& value) {is_not_empty(value, "", line_info());}
    template<typename TValue>
    static void is_not_empty(const std::initializer_list<TValue>& value, const tunit::line_info& line_info) {is_not_empty(value, "", line_info);}
    template<typename TValue>
    static void is_not_empty(const std::initializer_list<TValue>& value, const std::string& message) {is_not_empty(value, message, line_info());}
    template<typename TValue>
    static void is_not_empty(const std::initializer_list<TValue>& value, const std::string& message, const tunit::line_info& line_info) {
      if (!std::empty(value))
        assert::succeed(message, line_info);
      else
        base_assert::fail("not <empty>", "<empty>", message, line_info);
    }
    /// @endcond
    
    /// @brief Asserts that collection is ordered.
    /// @param value The value to check is empty.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> v1 = {1, 2, 3, 4};
    /// std::vector<int> v2 = {1, 2, 4, 3};
    /// tunit::assert::is_ordered(v1); // test ok.
    /// tunit::assert::is_ordered(v2); // test throws an assertion_error exception.
    /// @endcode
    template<typename TValue>
    static void is_ordered(const TValue& value) {is_ordered(value, "", line_info());}
    
    /// @brief Asserts that collection is ordered.
    /// @param value The value to check is empty.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> v1 = {1, 2, 3, 4};
    /// std::vector<int> v2 = {1, 2, 4, 3};
    /// tunit::assert::is_ordered(v1, line_info_); // test ok.
    /// tunit::assert::is_ordered(v2, line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TValue>
    static void is_ordered(const TValue& value, const tunit::line_info& line_info) {is_ordered(value, "", line_info);}
    
    /// @brief Asserts that collection is ordered.
    /// @param value The value to check is empty.
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> v1 = {1, 2, 3, 4};
    /// std::vector<int> v2 = {1, 2, 4, 3};
    /// tunit::assert::is_ordered(v1, "User message..."); // test ok.
    /// tunit::assert::is_ordered(v2, "User message..."); // test throws an assertion_error exception.
    /// @endcode
    template<typename TValue>
    static void is_ordered(const TValue& value, const std::string& message) {is_ordered(value, message, line_info());}
    
    /// @brief Asserts that collection is ordered.
    /// @param value The value to check is empty.
    /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
    /// @param line_info Contains information about current file and current line.
    /// @exception tunit::assertion_error If bad assertion.
    /// @par Examples
    /// @code
    /// std::vector<int> v1 = {1, 2, 3, 4};
    /// std::vector<int> v2 = {1, 2, 4, 3};
    /// tunit::assert::is_ordered(v1, "User message...", line_info_); // test ok.
    /// tunit::assert::is_ordered(v2, "User message...", line_info_); // test throws an assertion_error exception.
    /// @endcode
    template<typename TValue>
    static void is_ordered(const TValue& value, const std::string& message, const tunit::line_info& line_info) {
      if (std::is_sorted(value.begin(), value.end()))
        assert::succeed(message, line_info);
      else
        base_assert::fail("<ordered>", base_assert::join_items(value), message, line_info);
    }
    
    /// @cond
    template<typename TValue>
    static void is_ordered(const std::initializer_list<TValue>& value) {is_ordered(value, "", line_info());}
    template<typename TValue>
    static void is_ordered(const std::initializer_list<TValue>& value, const tunit::line_info& line_info) {is_ordered(value, "", line_info);}
    template<typename TValue>
    static void is_ordered(const std::initializer_list<TValue>& value, const std::string& message) {is_ordered(value, message, line_info());}
    template<typename TValue>
    static void is_ordered(const std::initializer_list<TValue>& value, const std::string& message, const tunit::line_info& line_info) {
      if (std::is_sorted(value.begin(), value.end()))
        assert::succeed(message, line_info);
      else
        base_assert::fail("<ordered>", base_assert::join_items(value), message, line_info);
    }
    /// @endcond
  };
}

#define all_items_are_instances_of_(...) __CMD_ASSERT_ARGS(all_items_are_instances_of, __VA_ARGS__)

#define all_items_are_not_null_(...) __CMD_ASSERT_ARGS(all_items_are_not_null, __VA_ARGS__)

#define all_items_are_unqiue_(...) __CMD_ASSERT_ARGS(all_items_are_unqiue, __VA_ARGS__)

#define are_equivalent_(...) __CMD_ASSERT_ARGS(are_equivalent, __VA_ARGS__)

#define are_not_equivalent_(...) __CMD_ASSERT_ARGS(are_not_equivalent, __VA_ARGS__)

#define is_ordered_(...) __CMD_ASSERT_ARGS(is_ordered, __VA_ARGS__)
