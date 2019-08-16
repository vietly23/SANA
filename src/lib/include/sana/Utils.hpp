#ifndef UTILS_HPP
#define UTILS_HPP

/*
   Auxiliary functions oblivious to SANA or network alignment but that can come helpful.
*/

/*
Static Util Class for all utility functions
*/
class Utils {
public:
    static void checkFileExists(const std::string &fileName);

    static int RandInt(int low, int high);

    static std::vector<std::vector<std::string>> fileToStringsByLines(const std::string &fileName);
};
#endif
