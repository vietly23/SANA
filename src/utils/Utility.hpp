#ifndef SANA_UTILITY_HPP
#define SANA_UTILITY_HPP

#include <random>
namespace sana {

    struct seed {
        unsigned int value;
        constexpr operator unsigned int() const {return value;}
    };
    /**
     * WARNING! Singlethreaded operation only.
     */
    class RandomUtility {
    public:
        double randomDouble();
        int randomInteger(int low, int high);
        RandomUtility(seed initialSeed);
    private:
        std::mt19937 randomBitGenerator;
        const unsigned int initialSeed;
    };
    struct StreamUtility {
        std::vector<std::string> splitIntoWords(std::istream& in) const;
    };
}

#endif //SANA_UTILITY_HPP
