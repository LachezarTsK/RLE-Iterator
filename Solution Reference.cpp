
#include <vector>
using namespace std;

class RLEIterator {
    
    inline static const int NOT_FOUND = -1;
    vector<int>& referenceEncoding;
    int index{};

public:
    RLEIterator(vector<int>& encoding) : referenceEncoding {encoding}{}

    int next(int nextNthElement) {
        while (index < referenceEncoding.size() - 1 && referenceEncoding[index] - nextNthElement < 0) {
            nextNthElement -= referenceEncoding[index];
            index += 2;
        }
        if (index == referenceEncoding.size()) {
            return NOT_FOUND;
        }

        referenceEncoding[index] -= nextNthElement;
        return referenceEncoding[index + 1];
    }
};
