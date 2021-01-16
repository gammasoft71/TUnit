/// @file
/// @brief Contains xtd::tunit::file_valid class.
#pragma once
#include "valid.h"
#include "file_assert.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The file_valid class contains a collection of static methods that implement the most file assertions used in xtd::tUnit.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class file_valid final : private base_assert {
    public:
      /// @cond
      file_valid() = delete;
      /// @endcond

      /// @brief Valids that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1); // test fails
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual) {are_equal(expected, actual, "", line_info());}
      
      /// @brief Valids that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, line_info_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, line_info_); // test fails
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      
      /// @brief Valids that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message..."); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message..."); // test fails
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      
      /// @brief Valids that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message...", line_info_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message...", line_info_); // test fails
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        try {
          file_assert::are_equal(expected, actual, message, line_info);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1); // test fails
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual) {are_equal(expected, actual, "", line_info());}
      
      /// @brief Valids that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, line_info_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, line_info_); // test fails
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      
      /// @brief Valids that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message..."); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message..."); // test fails
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      
      /// @brief Valids that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message...", line_info_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message...", line_info_); // test fails
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, line_info);}
      
      /// @cond
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const Char* actual) {are_equal(expected, actual, "", line_info());}
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const Char* actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const Char* actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const Char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, line_info);}
      template<typename Char>
      static void are_equal(const Char* expected, const std::basic_string<Char>& actual) {are_equal(expected, actual, "", line_info());}
      template<typename Char>
      static void are_equal(const Char* expected, const std::basic_string<Char>& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      template<typename Char>
      static void are_equal(const Char* expected, const std::basic_string<Char>& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      template<typename Char>
      static void are_equal(const Char* expected, const std::basic_string<Char>& actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, line_info);}
      template<typename Char>
      static void are_equal(const Char* expected, const Char* actual) {are_equal(expected, actual, "", line_info());}
      template<typename Char>
      static void are_equal(const Char* expected, const Char* actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      template<typename Char>
      static void are_equal(const Char* expected, const Char* actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      template<typename Char>
      static void are_equal(const Char* expected, const Char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, line_info);}
      /// @endcond

      /// @brief Valids that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1); // test fails
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual) {are_not_equal(expected, actual, "", line_info());}
      
      /// @brief Valids that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, line_info_); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, line_info_); // test fails
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      
      /// @brief Valids that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message..."); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message..."); // test fails
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      
      /// @brief Valids that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message...", line_info_); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message...", line_info_); // test fails
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        try {
          file_assert::are_not_equal(expected, actual, message, line_info);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1); // test fails
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual) {are_not_equal(expected, actual, "", line_info());}
      
      /// @brief Valids that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, line_info_); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, line_info_); // test fails
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      
      /// @brief Valids that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message..."); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message..."); // test fails
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      
      /// @brief Valids that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message...", line_info_); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message...", line_info_); // test fails
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_not_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, line_info);}
      
      /// @cond
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const Char* actual) {are_not_equal(expected, actual, "", line_info());}
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const Char* actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const Char* actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const Char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_not_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, line_info);}
      template<typename Char>
      static void are_not_equal(const Char* expected, const std::basic_string<Char>& actual) {are_not_equal(expected, actual, "", line_info());}
      template<typename Char>
      static void are_not_equal(const Char* expected, const std::basic_string<Char>& actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      template<typename Char>
      static void are_not_equal(const Char* expected, const std::basic_string<Char>& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      template<typename Char>
      static void are_not_equal(const Char* expected, const std::basic_string<Char>& actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_not_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, line_info);}
      template<typename Char>
      static void are_not_equal(const Char* expected, const Char* actual) {are_not_equal(expected, actual, "", line_info());}
      template<typename Char>
      static void are_not_equal(const Char* expected, const Char* actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      template<typename Char>
      static void are_not_equal(const Char* expected, const Char* actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      template<typename Char>
      static void are_not_equal(const Char* expected, const Char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_not_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, line_info);}
      /// @endcond
      
      /// @brief Valids that file exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::exists("Test1.txt"); // test ok.
      /// xtd::tunit::file_valid::exists("Test2.txt"); // test fails
      /// @endcode
      template<typename Char>
      static void exists(const std::basic_string<Char>& file) {exists(file, "", line_info());}
      
      /// @brief Valids that file exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::exists("Test1.txt", line_info_); // test ok.
      /// xtd::tunit::file_valid::exists("Test2.txt", line_info_); // test fails
      /// @endcode
      template<typename Char>
      static void exists(const std::basic_string<Char>& file, const xtd::tunit::line_info& line_info) {exists(file, "", line_info);}
      
      /// @brief Valids that file exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::exists("Test1.txt", "User message..."); // test ok.
      /// xtd::tunit::file_valid::exists("Test2.txt", "User message..."); // test fails
      /// @endcode
      template<typename Char>
      static void exists(const std::basic_string<Char>& file, const std::string& message) {exists(file, message, line_info());}
      
      /// @brief Valids that file exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::exists("Test1.txt" "User message...", line_info_); // test ok.
      /// xtd::tunit::file_valid::exists("Test2.txt", "User message...", line_info_); // test fails
      /// @endcode
      template<typename Char>
      static void exists(const std::basic_string<Char>& file, const std::string& message, const xtd::tunit::line_info& line_info) {
        try {
          file_assert::exists(file, message, line_info);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename Char>
      static void exists(const Char* file) {exists(file, "", line_info());}
      template<typename Char>
      static void exists(const Char* file, const xtd::tunit::line_info& line_info) {exists(file, "", line_info);}
      template<typename Char>
      static void exists(const Char* file, const std::string& message) {exists(file, message, line_info());}
      template<typename Char>
      static void exists(const Char* file, const std::string& message, const xtd::tunit::line_info& line_info) {exists(std::basic_string<Char>(file), message, line_info);}
      /// @endcond
      
      /// @brief Valids that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::does_not_exist("Test2.txt"); // test ok.
      /// xtd::tunit::file_valid::does_not_exist("Test1.txt"); // test fails
      /// @endcode
      template<typename Char>
      static void does_not_exist(const std::basic_string<Char>& file) {does_not_exist(file, "", line_info());}
      
      /// @brief Valids that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::does_not_exist("Test2.txt", line_info_); // test ok.
      /// xtd::tunit::file_valid::does_not_exist("Test1.txt", line_info_); // test fails
      /// @endcode
      template<typename Char>
      static void does_not_exist(const std::basic_string<Char>& file, const xtd::tunit::line_info& line_info) {does_not_exist(file, "", line_info);}
      
      /// @brief Valids that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::does_not_exist("Test2.txt", "User message..."); // test ok.
      /// xtd::tunit::file_valid::does_not_exist("Test1.txt", "User message..."); // test fails
      /// @endcode
      template<typename Char>
      static void does_not_exist(const std::basic_string<Char>& file, const std::string& message) {does_not_exist(file, message, line_info());}
      
      /// @brief Valids that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::does_not_exist("Test2.txt" "User message...", line_info_); // test ok.
      /// xtd::tunit::file_valid::does_not_exist("Test1.txt", "User message...", line_info_); // test fails
      /// @endcode
      template<typename Char>
      static void does_not_exist(const std::basic_string<Char>& file, const std::string& message, const xtd::tunit::line_info& line_info) {
        try {
          file_assert::does_not_exist(file, message, line_info);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename Char>
      static void does_not_exist(const Char* file) {does_not_exist(file, "", line_info());}
      template<typename Char>
      static void does_not_exist(const Char* file, const xtd::tunit::line_info& line_info) {does_not_exist(file, "", line_info);}
      template<typename Char>
      static void does_not_exist(const Char* file, const std::string& message) {does_not_exist(file, message, line_info());}
      template<typename Char>
      static void does_not_exist(const Char* file, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_exist(std::basic_string<Char>(file), message, line_info);}
      /// @endcond
    };
  }
}
