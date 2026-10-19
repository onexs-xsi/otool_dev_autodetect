#pragma once
#include "M5Autodetect_DeviceData.h"
#include <algorithm>

namespace m5::autodetect {
inline bool warmResetSdPin(board_t board, bool warm_reset, int pin) {
    const bool tab5=board==board_M5Tab5_ST7121 || board==board_M5Tab5_ST7123 || board==board_M5Tab5_IlI9881c;
    return tab5 && warm_reset && pin>=39 && pin<=44;
}
inline int requiredIdentityPins(int configured, int total, int ignored) {
    if (!ignored) return configured;
    // Keep the original allowance for mismatches on the remaining pins. Never
    // allow an empty pin set to count as identity. Bus/register/panel probes
    // remain mandatory in the detector after this preliminary check.
    return std::max(1,total-ignored-std::max(0,total-configured));
}
}
