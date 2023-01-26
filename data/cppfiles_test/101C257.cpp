#include <bits/stdc++.h>
using namespace std;
int t, n, A[200010];
string s;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    map<int, int> m1, m2;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'B') {
        if (A[i] <= 0) continue;
        m1[min(n, A[i])]++;
      } else {
        int x = n - A[i] + 1;
        if (x <= 0) continue;
        m2[min(n, x)]++;
      }
    }
    int c1 = 1, c2 = 1;
    for (auto k : m1) {
      int num = k.first, N = k.second;
      for (int i = 0; i < N; i++) {
        c1++;
        if (c1 > num) break;
      }
    }
    for (auto k : m2) {
      int num = k.first, N = k.second;
      for (int i = 0; i < N; i++) {
        c2++;
        if (c2 > num) break;
      }
    }
    if (c1 + c2 - 2 >= n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
