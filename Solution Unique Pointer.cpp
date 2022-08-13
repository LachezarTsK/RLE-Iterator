
#include <vector>
#include <memory>
#include <iterator>
using namespace std;

class RLEIterator {
    
    inline static const int NOT_FOUND = -1;
    unique_ptr<vector<int>> pointerEncoding;
    int index{};

public:
    RLEIterator(vector<int>& encoding) {
        this->pointerEncoding = make_unique<vector<int>>(encoding);
    }

    int next(int nextNthElement) {
        while (index < pointerEncoding->size() - 1 && pointerEncoding->at(index) - nextNthElement < 0) {
            nextNthElement -= pointerEncoding->at(index);
            index += 2;
        }
        if (index == pointerEncoding->size()) {
            return NOT_FOUND;
        }

        pointerEncoding->at(index) -= nextNthElement;
        return pointerEncoding->at(index + 1);
    }
};
