#ifndef __VERSION_H
#define __VERSION_H


#define VERSION_MAJOR 1
#define VERSION_MINOR 1
#define VERSION_BUILD 0


#define _NAME "uClite"
#define _NAME_BETA_ "ucl_c"


#define RELEASE "development"


#define _STR(x) #x
#define STR(x) _STR(x)
#define VERSION_STR STR(VERSION_MAJOR) "." STR(VERSION_MINOR) "." STR(VERSION_BUILD)
#define VERSION_NUM VERSION_MAJOR, VERSION_MINOR, VERSION_BUILD


#endif
