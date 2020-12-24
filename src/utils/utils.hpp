#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include <map>
#include <ostream>
#include <unordered_map>

#include "utils/templateUtils.cpp"

using namespace std;

//low-level functions (**oblivious** to SANA or network alignment) but that are useful in multiple places.

//folder where any part of the codebase can save autogenerated files
extern const string AUTOGENEREATED_FILES_FOLDER;

typedef uint16_t ushort;
typedef uint32_t uint;

bool myNan(double x);

double randDouble();
int randInt(int low, int high);
int randMod(int n);
void randomShuffle(vector<uint>& v);

string extractDecimals(double value, int count);
string toLowerCase(const string& s);
vector<string> nonEmptySplit(const string& s, char c); //keeps only non-empty strings

double vectorMean(const vector<double>& v);
void normalizeWeights(vector<double>& weights);

void printTable(const vector<vector<string>>& table, int colSeparation, ostream& stream);

string currentDateTime();

string exec(string cmd);
string execWithoutPrintingErr(string cmd);
void execPrintOutput(string cmd);

#endif /* UTILS_H */
