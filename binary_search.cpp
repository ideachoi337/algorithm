#include <iostream>

using namespace std;

int my_data[10] = {0,0,0,0,0,0,1,1,1,1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int low = 0;
    int high = 9;
    while (high > low + 1) {
        int mid = (low + high) / 2;
        if (my_data[mid] == 0) low = mid;
        else high = mid;
    } 
    cout << high << '\n';
}