#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  vector<int> v(1111);
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      v[i] = temp;
    }
    int counter = 0;
    while (true) {
      bool odd_swaps = false;
      bool even_swaps = false;
      for (int i = 0; i <= (n - 1) - 1; i += 2) {
        if (v[i] > v[i + 1]) {
          int temp = v[i];
          v[i] = v[i + 1];
          v[i + 1] = temp;
          odd_swaps = true;
        }
      }
      if (odd_swaps) counter++;
      for (int i = 1; i <= (n - 1) - 1; i += 2) {
        if (v[i] > v[i + 1]) {
          int temp = v[i];
          v[i] = v[i + 1];
          v[i + 1] = temp;
          even_swaps = true;
        }
      }
      if (even_swaps) counter++;
      if (odd_swaps == false && even_swaps == false) {
        break;
      }
    }
    cout << counter << '\n';
  }
  return 0;
}
