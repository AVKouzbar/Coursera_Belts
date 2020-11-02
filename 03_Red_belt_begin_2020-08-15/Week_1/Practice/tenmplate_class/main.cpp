#include <iostream>
#include <vector>
#include <set>
#include <queue>


using namespace std;

template <typename Iterator>
class IteratorRange {
private:
    Iterator first, last;
public:
    IteratorRange(Iterator f, Iterator l) : first(f), last(l) {
    }

    Iterator begin() const {
        return first;
    }
    Iterator end() const {
        return last;
    }
};

template <typename Container>
auto Head(Container& v, size_t top) {
    return IteratorRange{
      v.begin(), next(v.begin(), min(top, v.size()))
    };
}
template <typename T>
size_t RangeSize(IteratorRange<T> r) {
    return r.end() - r.begin();
}

template <typename Iterator>
IteratorRange<Iterator> MakeRange(
        Iterator begin, Iterator end) {
    return IteratorRange<Iterator>{
        begin, end
    };
}

int main() {
    vector<int> v = {1,2,3,4,5};
//    for (int& x : Head(v, 3)) {
//       x++;
//    }
//    for (int& x : v) {
//        cout << x << ' ';
//    }
    set<int> nums = {5,7,12,8,10,5,6,1};
    for (int x : Head(nums, 4)) {
        cout << x << ' ';
    }
    cout << endl;
    const deque<int> nums2 = {5,7,12,8,10,5,6,1};
    cout << "deque Range: ";
    for (int x : Head(nums2, 4)) {
        cout << x << ' ';
    }
    cout << endl;
    cout << RangeSize(Head(v, 3)) << endl;
    IteratorRange second_half(
            v.begin()   + v.size() / 2, v.end()
    );
    for (int& s : second_half) {
        cout << s << ' ';
    }
    pair p(5, true);

}