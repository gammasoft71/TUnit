/// @file
/// @brief Contains tunit::settings class.
#pragma once
#include <chrono>
#include <cstdlib>
#include <string>

/// @brief The tunit namespace contains a unit test library.
namespace tunit {
  /// @brief The settings class contains tunit settings.
  class settings final {
  public:
    /// @brief Creates new instance of settings.
    settings() = default;
    
    /// @cond
    settings(const settings&) = default;
    settings& operator=(const settings&) = default;
    /// @endcond

    /// @brief Get default settings intance.
    /// @return Default settings instance.
    static tunit::settings& default_settings() noexcept {
      static tunit::settings settings;
      return settings;
    }

    /// @brief Gets also run ignored test.
    /// @return true if also run ignored test; otherwise false.
    bool also_run_ignored_tests() const noexcept {return this->also_run_ignored_tests_;}

    /// @brief Sets also run ignored test.
    /// @param also_run_ignored_tests  true if also run ignored test; otherwise false.
    void also_run_ignored_tests(bool also_run_ignored_tests) noexcept {this->also_run_ignored_tests_ = also_run_ignored_tests;}
    
    /// @brief Gets exit status.
    /// @return exit status.
    /// @remarks The value by default is EXIT_SUCCESS.
    /// @remarks When an error occured in unit test the value is set to EXIT_FAILURE.
    int exit_status() const noexcept {return this->exit_status_;}
    
    /// @brief Sets exit status.
    /// @param exit_status exit status.
    /// @remarks The value by default is EXIT_SUCCESS.
    /// @remarks When an error occured in unit test the value is set to EXIT_FAILURE.
    void exit_status(int exit_status) noexcept {this->exit_status_ = exit_status;}
    
    /// @brief Gets filter tests.
    /// @return filter tests.
    /// @remarks The value by default is "*.*".
    const std::string& filter_tests() const noexcept {return this->filter_tests_;}

    /// @brief Sets filter tests.
    /// @param filter_tests filter tests.
    /// @remarks The value by default is "*.*".
    void filter_tests(const std::string& filter_tests) noexcept {this->filter_tests_ = filter_tests;}

    /// @brief Return true if a specified test class name and specified test name match with the current filter tests.
    /// @return Return true if class name and test name match with the current filter tests; otherwise false.
    bool is_match_test_name(const std::string& test_class_name, const std::string& test_name) const noexcept {return this->pattern_compare(test_class_name + "." + test_name, this->filter_tests_);}

    /// @brief Gets list tests.
    /// @return true if list tests; otherwise false.
    bool list_tests() const noexcept {return this->list_tests_;}

    /// @brief Sets list tests.
    /// @param list_tests true if list tests; otherwise false.
    void list_tests(bool list_tests) noexcept {this->list_tests_ = list_tests;}
    
    /// @brief Gets output color.
    /// @return true for colored output; otherwise false.
    bool output_color() const noexcept {return this->output_color_;}
    
    /// @brief Sets output color.
    /// @param output_color true for colored output; otherwise false.
    void output_color(bool output_color) noexcept {this->output_color_ = output_color;}
    
    /// @brief Gets output xml.
    /// @return true for generate xml report; otherwise false.
    bool output_xml() const noexcept {return this->output_xml_;}
    
    /// @brief Sets output xml.
    /// @param output_xml true for generate xml report; otherwise false.
    void output_xml(bool output_xml) noexcept {this->output_xml_ = output_xml;}
    
    /// @brief Gets output xml path.
    /// @return Output xml path.
    std::string output_xml_path() const noexcept {return this->output_xml_path_;}
    
    /// @brief Sets output xml path.
    /// @param output_xml_path Output xml path.
    void output_xml_path(const std::string& output_xml_path) noexcept {this->output_xml_path_ = output_xml_path;}
    
    /// @brief Gets shuffle tests.
    /// @return Shuffle test.
    /// @remarks By default is set to false (no shuffle).
    bool shuffle_test() const noexcept {return this->shuffle_tests_;}
    
    /// @brief Sets shuffle tests.
    /// @param shuffle_test Shuffle test.
    /// @remarks By default is set to false (no shuffle).
    void shuffle_test(bool shuffle_test) noexcept {this->shuffle_tests_ = shuffle_test;}
    
    /// @brief Gets random seed value.
    /// @return Random seed value.
    /// @remarks By default is set to 0 (no seed).
    int random_seed() const noexcept {return this->random_seed_;}
    
    /// @brief Sets random seed value.
    /// @param random_seed Random seed value.
    /// @remarks By default is set to 0 (no seed).
    void random_seed(int random_seed) noexcept {this->random_seed_ = random_seed;}
    
    /// @brief Gets repeat tests count.
    /// @return Repeat test count.
    /// @remarks By default is set to 1 (no repeat).
    int repeaat_test() const noexcept {return this->repeat_tests_;}
    
    /// @brief Sets repeat tests count.
    /// @param repeat_tests Repeat test count.
    /// @remarks By default is set to 1 (no repeat).
    void repeat_tests(int repeat_tests) noexcept {this->repeat_tests_ = repeat_tests;}

    /// @brief Gets if show duration for each test.
    /// @return true if show duration for each test; otherwise false.
    bool show_duration() const noexcept {return this->show_duration_;}
    
    /// @brief Sets if show duration for each test.
    /// @param show_duration true if show duration for each test; otherwise false.
    void show_duration(bool show_duration) noexcept {this->show_duration_ = show_duration;}

    /// @brief Gets unit test end time.
    /// @return Unit test end time.
    std::chrono::time_point<std::chrono::system_clock> end_time() const noexcept {return this->end_time_;}

    /// @brief Gets unit test start time.
    /// @return Unit test start time.
    std::chrono::time_point<std::chrono::system_clock> start_time() const noexcept {return this->start_time_;}

  private:
    friend class unit_test;
    
    bool pattern_compare(const std::string& name, const std::string& pattern) const noexcept {
      if (pattern == "") return name == "";
      if (name == "") return false;
      if (pattern == "*" || pattern == "*.*") return true;
      if (pattern[0] == '*') return this->pattern_compare(name, pattern.substr(1)) || this->pattern_compare(name.substr(1), pattern);
      return ((pattern[0] == '?') || (name[0] == pattern[0])) && this->pattern_compare(name.substr(1), pattern.substr(1));
    }

    void end_time(const std::chrono::time_point<std::chrono::system_clock>& end_time) noexcept {this->start_time_ = end_time;}
    void start_time(const std::chrono::time_point<std::chrono::system_clock>& start_time) noexcept {this->start_time_ = start_time;}

    bool also_run_ignored_tests_ = false;
    std::string filter_tests_ = "*.*";
    int exit_status_ = EXIT_SUCCESS;
    bool list_tests_ = false;
    bool output_color_ = true;
    bool output_xml_;
    std::string output_xml_path_ = "tests.xml";
    bool show_duration_ = true;
    bool shuffle_tests_ = false;
    int random_seed_ = 0;
    int repeat_tests_ = 1;
    std::chrono::time_point<std::chrono::system_clock> start_time_;
    std::chrono::time_point<std::chrono::system_clock> end_time_;
  };
}
