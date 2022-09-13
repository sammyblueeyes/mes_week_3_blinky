#pragma once

#ifdef TARGET_ST32F411EDOSCO
#include <io_mapping_st32f411edisco.h>
#else
#error "No I/O map selected for the board. What is our target?"
#endif