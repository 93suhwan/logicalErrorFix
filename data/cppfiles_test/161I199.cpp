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
    bool A[n + 10];
    for (int i = 1; i <= n; i++) {
      A[i] = true;
    }
    for (int i = 1; i <= n; i++) {
      int a, b;
      cin >> a >> b;
      if (a == b) {
        cout << a << " " << b << " " << a << endl;
        A[a] = false;
      } else
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
      int req;
      int mi;
      for (int j = i.first; j <= i.second; j++) {
        if (A[j] == false) {
          continue;
        }
        if (B[j] < m) {
          req = j;
          m = B[j];
        }
      }
      cout << i.first << " " << i.second << " " << req << endl;
      A[m] = false;
    }
    cout << endl;
  }
  return 0;
}
