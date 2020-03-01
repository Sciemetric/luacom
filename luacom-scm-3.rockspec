package = "LuaCOM"
version = "scm-3"
source = {
   url = "git://github.com/davidm/luacom.git"
}
description = {
   summary = "Use COM libraries from Lua",
   detailed = [[
LuaCOM is an add-on library to the Lua language that allows Lua programs to use and implement objects that follow Microsoft's Component Object Model (COM) specification and use the ActiveX technology for property access and method calls.   ]],
   license = "MIT/X11",
   homepage = "http://luaforge.net/projects/luacom/"
}
supported_platforms = {
  "windows"
}
dependencies = {
   "lua >= 5.1"
}
build = {
    type = "cmake",
    variables = {
      CMAKE_CXX_FLAGS = "$(CFLAGS)",
      CMAKE_PREFIX_PATH     = "$(LUA_LIBDIR)",
      CMAKE_INSTALL_PREFIX  = "$(PREFIX)",
      -- turn this on for helpful build debugging
      CMAKE_VERBOSE_MAKEFILE = "OFF",
    },
}
