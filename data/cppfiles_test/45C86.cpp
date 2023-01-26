#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    int a = 0;
    for (int& i : v) {
      cin >> i;
      i &= 1;
      a += i;
    }
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    if (a > (n + 1) / 2 or (n - a) > (n + 1) / 2) {
      cout << -1 << '\n';
      continue;
    }
    long long int res = 0;
    vector<int> ar;
    for (int i = 0; i < n; ++i) {
      if (v[i] == 0) ar.push_back(i);
    }
    if (n & 1) {
      long long cnt = 0, j = 0;
      if (a > n - a) j = 1;
      for (int i : ar) {
        cnt += abs(i - j);
        j += 2;
      }
      res = cnt;
    } else {
      long long cnt1 = 0, cnt2 = 0, j1 = 0, j2 = 1;
      for (int i : ar) {
        cnt1 += abs(i - j1);
        cnt2 += abs(i - j2);
        j1 += 2, j2 += 2;
      }
      res = min(cnt1, cnt2);
    }
    cout << res << '\n';
  }
  return 0;
}
