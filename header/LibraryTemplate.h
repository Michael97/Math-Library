#pragma once

#include <array>
#include <cmath>
#include <math.h>
#include <limits>
#include <time.h>
#include <iostream>


//x is columns and y is rows
template<typename T, size_t X, size_t Y>
using array2d_t = std::array<std::array<T, X>, Y>;