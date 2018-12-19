# ifndef __comm_h
# define __comm_h

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <stdexcept>
# include <boost/spirit/home/support/detail/hold_any.hpp>
# include <boost/program_options.hpp>
# include <boost/program_options/options_description.hpp>
# include <boost/algorithm/string/split.hpp>
# include <boost/algorithm/string/classification.hpp>


// namespace structure:
// lf::base
// --------::comm
// --------------::variables (for global variables)
// --------------::check (for debug & verify messages)
// --------------::input (for reading variables from cmdline & files)

namespace lf::base {

namespace bs = boost::spirit; // faster, templated version of boost::any
namespace po = boost::program_options; // keep in lf::base to avoid conflicts

namespace comm {

namespace variables {

// (key, (value, comment)) = (string, (hold_any, string))
extern std::map<std::string, std::pair<bs::hold_any, std::string>> kGlobalVars;

template <typename T>
void Add(const std::string&, const T&, const std::string& comment = "");

template <typename T>
T Get(const std::string&);

extern void ListVariables();

extern bool IsSet(const std::string&);

extern bool Remove(const std::string&);

/**
 * @brief Add a the value `value` to the global variables with key `key` Handle
 *        description `comment`.
 * @param key The key of the variable.
 * @param value The value.
 * @param comment (optional) Description of the variable.
 */
template <typename T>
void Add(const std::string& key, const T& value, const std::string& comment) {
  kGlobalVars[key] = std::make_pair(bs::hold_any(value), comment);
}

/**
 * @brief Get the value of the variable `key`.
 * @param key The key of the variable.
 * @note Throws an invalid_argument exception if `key` doens't exist.
 */
template <typename T>
T Get(const std::string& key) {
  if (kGlobalVars.count(key)) {
    return bs::any_cast<T>(kGlobalVars[key].first);
  }
  else {
    throw std::invalid_argument("The key " + key + " couldn't be found.");
  }
}

} // namespace variables

namespace check {

extern int kDebugCode;

extern int CountBits(const int);

extern int ExtractDebugCode(const std::string&);

extern void Debug(const int, const std::string&);

extern void SetDebugCode(const int);

extern int GetDebugCode();

extern void Verify(const bool, const std::string&);

} // namespace check

namespace input {

extern int kArgc;
extern char** kArgv;
extern std::string kConfigFile;
extern po::variables_map kVM;
extern po::options_description kDesc;

extern void Init(int, char**, std::string);
extern void Init(int, char**);
extern void Init(std::string);
extern void Init();

extern po::options_description_easy_init Add();
extern void Add(const std::string&, const std::string&);
template <typename T>
void Add(const std::string&, const std::string&);
template <typename T>
void Add(const std::string&, const std::string&, const T&);

template <typename T>
T Get(const std::string&);
template <typename T>
T Get(const std::string&, const T&);

extern bool Help();

extern bool IsSet(const std::string&);

extern void ParseCommandLine(int argc = 0, char** argv = nullptr);

extern void ParseFile(const std::string& file = "");

/**
 * @brief Add possible input for variable called `name` with description
 *        `comment`.
 * @param name The name of the variable.
 * @param comment Description of the variable.
 */
template <typename T>
void Add(const std::string& name, const std::string& comment) {
  kDesc.add_options()(name.c_str(), po::value<T>(), comment.c_str());
}

/**
 * @brief Add possible input for variable called `name` with description
 *        `comment` with default value `def`.
 * @param name The name of the variable.
 * @param comment Description of the variable.
 * @param def T The default value.
 */
template <typename T>
void Add(const std::string& name, const std::string& comment, const T& def) {
  kDesc.add_options()
    (name.c_str(), po::value<T>()->default_value(def), comment.c_str());
}

/**
 * @brief Get the value of the variable `name`.
 * @param name The name of the variable.
 * @note Throws an invalid_argument exception if `name` doens't exist.
 */
template <typename T>
T Get(const std::string& name) {
  if (kVM.count(name) > 0) {
    return kVM[name].as<T>();
  }
  else {
    throw std::invalid_argument("In template Get<T>(const std::string&): " \
                                "Value ``" + name + "'' not set. Terminating.");
    return T();
  }
}

/**
 * @brief Get the value of the variable `name`, return `alt` if `name` doesn't
 *        exist. 'Safe' version of Get<T>(name).
 * @param name The name of the variable.
 * @param alt T Value that's returned, if `name` doesn't exist.
 */
template <typename T>
T Get(const std::string& name, const T& alt) {
  try {
    return Get<T>(name);
  }
  catch (const std::invalid_argument& e) {
    return alt;
  }
}

} // namespace input

} // namespace comm

namespace ci = comm::input;
namespace cc = comm::check;
namespace cv = comm::variables;

} // namespace lf::base

# endif // __comm_h