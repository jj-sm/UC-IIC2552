#include <filesystem>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector<int> A = {1, 2, 2, 3, 5, 7};

    int target = 2;
    int n = A.size();

    // Look for the first index
    int l = 0;
    int r = n - 1;

    while (l < r) {
        int mid = (l + r) / 2;

        if (A[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    // Look for the last index
    int first = l;

    l = 0;
    r = n - 1;

    while (l < r) {
        int mid = (l + r + 1) / 2;

        if (A[mid] <= target) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    int last = l;

    cout << "primer indice >= x: " << first << endl;
    cout << "ultimo indice <= x: " << last << endl;

    return 0;
}
