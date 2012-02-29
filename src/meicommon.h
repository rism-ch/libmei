/** \mainpage
 *
 * \htmlinclude README.html
 */

#ifndef MEICOMMON_H_
#define MEICOMMON_H_

#include <string>

#if defined _WIN32 || defined __CYGWIN__
    #ifdef BUILDING_DLL
        #define MEI_EXPORT __declspec(dllexport)
    #else
        #define MEI_EXPORT __declspec(dllimport)
    #endif
#else
    #if __GNUC__ >= 4
        #define MEI_EXPORT __attribute__ ((visibility ("default")))
    #else
        #define MEI_EXPORT
    #endif
#endif

const std::string MEI_VERSION = "2012";
const std::string MEI_NS = "http://www.music-encoding.org/ns/mei";
const std::string MEI_PREFIX = "mei";
const std::string MEI_ENCODING = "UTF-8";

#endif  // MEICOMMON_H_