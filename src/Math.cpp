#include "OcctCommon/Math.h"
#include <cfloat>
#include <cmath>

#define UNSET_VALUE -1.23432101234321e+308

using namespace OcctCommon;

namespace OcctCommon {

bool OcctMath::IsValidDouble(double x) { return x != UNSET_VALUE; }

double OcctMath::UnsetValue() { return UNSET_VALUE; }

} // namespace OcctCommon
