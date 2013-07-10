// clua.h : Includedatei für alle lua-Funktionen
// die im C++-Projekt verwendet werden sollen.

#pragma once

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class lua {

private:
public:
	lua(){}
	~lua(){}

	void run_script();
};