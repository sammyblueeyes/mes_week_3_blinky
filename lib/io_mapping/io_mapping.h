#pragma once

#ifdef STM32F411xE
#include <io_mapping_st32f411edisco.h>
#else
#error "No I/O map selected for the board. What is our target?"
#endif