#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> BIT;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        BIT.resize(n + 1, 0);
    }

    void update(int i, int x) {
        while (i <= n) {
            BIT[i] += x;
            i += i & (-i);
        }
    }

    int prefixSum(int i) {
        int sum = 0;
        while (i > 0) {
            sum += BIT[i];
            i -= i & (-i);
        }
        return sum;
    }

    int rangeSum(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }
};

int main() {
    int n = 10; // Array size
    FenwickTree ft(n);

    // Example updates
    ft.update(1, 3);
    ft.update(4, 5);
    ft.update(7, 2);

    // Example queries
    cout << "Sum of [1, 4]: " << ft.rangeSum(1, 4) << endl; // Output: 8
    cout << "Sum of [4, 7]: " << ft.rangeSum(4, 7) << endl; // Output: 7

    return 0;
}
