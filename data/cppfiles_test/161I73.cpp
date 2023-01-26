#include <bits/stdc++.h>
using namespace std;
int B[2002];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    bool A[n];
    for (int i = 0; i < n; i++) {
      A[n] = true;
    }
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      if (a == b) {
        cout << a << " " << b << " " << a;
        A[a] = false;
        continue;
      }
      v.push_back({a, b});
    }
    for (int i = 1; i <= n; i++) {
      for (auto j : v) {
        if (A[i] == false) {
          break;
        } else {
          if (i >= j.first && i <= j.second) {
            B[i]++;
          }
        }
      }
    }
    for (auto i : v) {
      int m = INT_MAX;
      for (int j = i.first; j <= i.second; j++) {
        if (A[j] == false) {
          continue;
        }
        m = min(B[j], m);
      }
      cout << i.first << " " << i.second << " " << m << endl;
      A[m] = false;
    }
  }
  return 0;
}
