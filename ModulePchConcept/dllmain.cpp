// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
import Module;

__declspec(dllexport) std::size_t baka()
{
    Lanyi::Test::Baka auto f = [](std::string_view a, std::string_view b) { return a; };
    return f("Cirno", "9").size();
}