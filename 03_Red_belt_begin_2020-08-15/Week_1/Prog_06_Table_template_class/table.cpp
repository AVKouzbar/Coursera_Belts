#include "test_runner.h"


#include <utility>

using namespace std;

template <typename T>
class Table {
public:
    Table(size_t _rows_number, size_t _columns_number) : rows_number(_rows_number),
                                           columns_number(_columns_number) {
        Resize(rows_number, columns_number);
    }

    vector<T>& operator[](size_t index) {
        return data[index];
    }

    const vector<T>& operator[](size_t index) const {
        return data[index];
    }

    void Resize(size_t _rows_number, size_t _columns_number) {
        rows_number = _rows_number;
        columns_number = _columns_number;
        data.resize(rows_number);
        for (auto& item : data) {
            item.resize(columns_number);
        }
    }


    pair<size_t, size_t > Size() const {
        if(!data.empty() && !data[0].empty()) {
        return make_pair(rows_number, columns_number );
        }
        return {0,0};
    }

private:
     size_t rows_number, columns_number;
     vector<vector<T>> data;
};

void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    int q = 1;
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}