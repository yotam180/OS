#include "TextMode.hpp"

volatile ColoredChar *const OS::TextDisplay::TEXT_BUFFER_ADDR = reinterpret_cast<volatile ColoredChar *>(0xb8000);
