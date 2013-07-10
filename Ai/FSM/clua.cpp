#include "clua.h"

void lua::run_script() {

		lua_State *L = lua_open();

		// load the libs
		luaL_openlibs(L);

		//run a Lua scrip here
		luaL_dofile(L,"script.lua");

		printf("\nI am done with Lua in C++.\n");

		lua_close(L);
	}