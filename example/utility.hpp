#include <type_traits>

template<typename T>
bool isBool() {
    return std::is_same_v<T, bool>;
}
