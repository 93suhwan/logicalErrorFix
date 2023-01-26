#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int f = 0;
    int count = 0;
    while (f == 0) {
      f = 1;
      for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
          swap(v[i], v[i + 1]);
          f = 0;
          if (i + 2 >= n - 1) break;
          i = i + 2;
        }
      }
      if (f == 0) count++;
    }
    cout << count << endl;
  }
  return 0;
}
