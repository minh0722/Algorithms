#include "util.h"

namespace util
{
    int getBit(int number, int bitIdx)
    {
        return (number >> bitIdx) & 1;
    }
}