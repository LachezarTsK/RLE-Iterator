
#include <vector>
#include <iterator>
using namespace std;

class RLEIterator {
    
    inline static const int NOT_FOUND = -1;
    vector<int>::iterator iteratorCurrent;
    vector<int>::iterator end;

public:
    RLEIterator(vector<int>& encoding) {
        this->iteratorCurrent = encoding.begin();
        this->end = encoding.end();
    }

    int next(int nextNthElement) {
        while (iteratorCurrent < end - 1 && *iteratorCurrent - nextNthElement < 0) {
            nextNthElement -= *iteratorCurrent;
            iteratorCurrent += 2;
        }
        if (iteratorCurrent == end) {
            return NOT_FOUND;
        }

        *iteratorCurrent -= nextNthElement;
        return *(iteratorCurrent + 1);
    }
};
