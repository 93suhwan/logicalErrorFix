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
    vector<bool> vb(n + 1, false);
    for (int i = 1; i <= n; i++) {
      int temp;
      cin >> temp;
      v[i] = temp;
    }
    int counter = 0;
    int last_true = 0;
    while (true) {
      bool odd_swaps = false;
      bool even_swaps = false;
      for (int i = 1; i <= n - 2; i += 2) {
        if (v[i] > v[i + 1]) {
          int temp = v[i];
          v[i] = v[i + 1];
          v[i + 1] = temp;
          odd_swaps = true;
        }
      }
      counter++;
      if (odd_swaps) {
        last_true = counter;
      }
      for (int i = 2; i <= n - 1; i += 2) {
        if (v[i] > v[i + 1]) {
          int temp = v[i];
          v[i] = v[i + 1];
          v[i + 1] = temp;
          even_swaps = true;
        }
      }
      counter++;
      if (even_swaps) {
        last_true = counter;
      }
      if (odd_swaps == false && even_swaps == false) {
        break;
      }
    }
    cout << last_true << '\n';
  }
  return 0;
}
