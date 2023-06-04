#include "OcctCommon/Math.h"
#include <cfloat>
#include <cmath>

#define UNSET_VALUE -1.23432101234321e+308

using namespace OcctCommon;

inline bool OcctMath::IsValidDouble(double x) { return x != UNSET_VALUE; }

inline double OcctMath::UnsetValue() { return UNSET_VALUE; }
