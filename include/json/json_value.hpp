#include <cstddef>
#include <string>
#include <variant>
#include <vector>
#include <unordered_map>

#include <json/utils.hpp>

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
  JsonValue(void) : value_(nullptr){};
  JsonValue(std::nullptr_t) : value_(nullptr) {}
  JsonValue(bool b) : value_(b) {};
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

  std::string serialize() const noexcept {
    return std::visit(overloaded{
          [](std::nullptr_t = nullptr) -> std::string { return "null"; },
          [](bool b) -> std::string { return b ? "true" : "false"; },
          [](int i) { return std::to_string(i); },
          [](double d) { return std::to_string(d); },
          [](const std::string &s) { return _serialize_string(s); },
          [](const list_t &lst) { return _serialize_list(lst); },
          [](const object_t &object) { return _serialize_object(object); },
    }, value_);
  }

 private:
  static std::string _serialize_string(const std::string &s) noexcept {
    return '\"' + s + '\"';
  }
  static std::string _serialize_list(const list_t &list) noexcept {
    std::string result = "[";
    bool isFirst = true;
    const auto &obj = list;
    for (const auto &elem : obj) {
      if (!isFirst)
        result += ",";
      result += elem.serialize();
      isFirst = false;
    }
    result += "]";
    return result;
  }

  static std::string _serialize_object(const object_t &object) noexcept {
    std::string result = "{";
    bool isFirst = true;
    const auto &obj = object;
    for (const auto &[k, v] : obj) {
      if (!isFirst)
        result += ",";
      result += _serialize_string(k) + ": " + v.serialize();
      isFirst = false;
    }
    result += "}";
    return result;
  }

};

}
