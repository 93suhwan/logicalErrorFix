#include <bits/stdc++.h>
using namespace std;
void printarray(int arr[], int size) {
  for (int i = 0; i < size; i = i + 1) {
    cout << arr[i] << ' ';
  }
}
int main() {
  int t;
  cin >> t;
  for (int m = 0; m < t; m = m + 1) {
    int p{};
    cin >> p;
    cout << 2 << ' ' << p - 1 << '\n';
  }
}
