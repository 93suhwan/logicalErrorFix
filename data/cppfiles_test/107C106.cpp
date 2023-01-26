#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int test_case;
  cin >> test_case;
  for (int t = 0; t < test_case; t++) {
    int n, a, b;
    vector<int> arr;
    cin >> n >> a >> b;
    if ((a + b + 2 > n) || (abs(a - b) > 1)) {
      cout << -1 << endl;
      continue;
    }
    for (int i = 1; i <= n; i++) arr.push_back(i);
    if (b > a) {
      int idx = 2;
      for (int i = 0; i < a; i++) {
        swap(arr[idx], arr[idx + 1]);
        idx += 2;
      }
      swap(arr[0], arr[1]);
    } else if (b == a) {
      int idx = 1;
      for (int i = 0; i < a; i++) {
        swap(arr[idx], arr[idx + 1]);
        idx += 2;
      }
    } else {
      int idx = 1;
      for (int i = 0; i < b; i++) {
        swap(arr[idx], arr[idx + 1]);
        idx += 2;
      }
      swap(arr[n - 2], arr[n - 1]);
    }
    for (int i : arr) cout << i << " ";
    cout << endl;
  }
}
