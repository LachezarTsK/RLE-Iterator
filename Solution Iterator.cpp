
#include <vector>
#include <iterator>
using namespace std;

class RLEIterator {
    
    inline static const int NOT_FOUND = -1;
    vector<int>::iterator iteratorEncoding;
    vector<int>::iterator end;

public:
    RLEIterator(vector<int>& encoding) {
        this->iteratorEncoding = encoding.begin();
        this->end = encoding.end();
    }

    int next(int nextNthElement) {
        while (iteratorEncoding < end - 1 && *iteratorEncoding - nextNthElement < 0) {
            nextNthElement -= *iteratorEncoding;
            iteratorEncoding += 2;
        }
        if (iteratorEncoding == end) {
            return NOT_FOUND;
        }

        *iteratorEncoding -= nextNthElement;
        return *(iteratorEncoding + 1);
    }
};
