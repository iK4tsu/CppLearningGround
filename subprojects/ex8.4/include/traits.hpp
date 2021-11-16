#pragma once

#include <type_traits>

/**
@brief Checks if T1 with all qualifiers removed, if any, is the same type as T2
@param T1 actual type
@param T2 expected type
@returns std::true_type if types are the same, std::false_type otherwise
*/
template<typename T1, typename T2>
inline constexpr bool is_same_unqual = std::is_same_v<std::remove_cvref_t<T1>, T2>;
