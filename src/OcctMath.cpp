#include <OcctCommon/OcctMath.h>

namespace OcctCommon {

bool OcctMath::IsValidDouble(double x) { return x != OCCTCOMMON_UNSET_VALUE; }

double OcctMath::UnsetValue() { return OCCTCOMMON_UNSET_VALUE; }

} // namespace OcctCommon
