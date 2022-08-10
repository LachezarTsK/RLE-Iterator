
#include <vector>
using namespace std;

class RLEIterator {
    
    inline static const int NOT_FOUND = -1;
    vector<int>& referenceCurrent;
    int index{};

public:
    RLEIterator(vector<int>& encoding) : referenceCurrent {encoding}{}

    int next(int nextNthElement) {
        while (index < referenceCurrent.size() - 1 && referenceCurrent[index] - nextNthElement < 0) {
            nextNthElement -= referenceCurrent[index];
            index += 2;
        }
        if (index == referenceCurrent.size()) {
            return NOT_FOUND;
        }

        referenceCurrent[index] -= nextNthElement;
        return referenceCurrent[index + 1];
    }
};
