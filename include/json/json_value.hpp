#include <cstddef>
#include <string>
#include <variant>
#include <vector>
#include <unordered_map>

namespace Fruit {

/*
  TODO:
  const char* constructor
  Reassign output operators
 */
  
class JsonValue {
public:
  using list_t = std::vector<JsonValue>;
  using object_t = std::unordered_map<std::string, JsonValue>;
  using value_t =
    std::variant<std::nullptr_t, bool, int, double, std::string, list_t, object_t>;

private:
  value_t value_;

public:
  JsonValue() : value_(nullptr){};
  JsonValue(std::nullptr_t = nullptr) : value_(nullptr) {}
  explicit JsonValue(bool b) : value_(b) {};
  JsonValue(int i) : value_(i){};
  JsonValue(double d) : value_(d){};

  // String-value constructors
  JsonValue(const std::string &s) : value_(s) {};
  JsonValue(std::string &&s) : value_(std::move(s)){};

  // List-value constructors
  JsonValue(const list_t &lst) : value_(lst){};
  JsonValue(list_t &&lst) : value_(std::move(lst)){};

  // Object-value constructors
  JsonValue(const object_t &obj) : value_(obj){};
  JsonValue(object_t &&obj): value_(std::move(obj)) {};

  std::string serialize() { throw; }

};

}
