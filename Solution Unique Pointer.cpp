
#include <vector>
#include <memory>
#include <iterator>
using namespace std;

class RLEIterator {
    
    inline static const int NOT_FOUND = -1;
    unique_ptr<vector<int>>pointerCurrent;
    int index{};

public:
    RLEIterator(vector<int>& encoding) {
        this->pointerCurrent = make_unique<vector<int>>(encoding);
    }

    int next(int nextNthElement) {
        while (index < pointerCurrent->size() - 1 && pointerCurrent->at(index) - nextNthElement < 0) {
            nextNthElement -= pointerCurrent->at(index);
            index += 2;
        }
        if (index == pointerCurrent->size()) {
            return NOT_FOUND;
        }

        pointerCurrent->at(index) -= nextNthElement;
        return pointerCurrent->at(index + 1);
    }
};
