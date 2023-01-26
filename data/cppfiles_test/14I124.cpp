#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct T {
  long long lf;
  long long ri;
  long long off;
};
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &i : a) cin >> i;
    vector<T> ans;
    for (int i = n - 1; i > 0; i--) {
      long long mx = -inf;
      int idx = -1;
      for (int j = 0; j <= i; j++) {
        if (mx < a[j]) {
          mx = a[j];
          idx = j;
        }
      }
      if (idx != i) {
        vector<long long> t;
        vector<long long> t2(n);
        for (int j = 0; j <= i; j++) {
          t2[j] = a[(j + idx + 1) % (i + 1)];
        }
        t = t2;
        ans.push_back({1, i + 1, idx + 1});
      }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
      cout << x.lf << ' ' << x.ri << ' ' << x.off << '\n';
    }
  }
}
