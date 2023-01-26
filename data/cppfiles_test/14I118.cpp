#include <bits/stdc++.h>
using namespace std;
struct T {
  int lf;
  int ri;
  int off;
};
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    vector<T> ans;
    sort(b.begin(), b.end());
    if (is_sorted(a.begin(), a.end())) {
      cout << "0\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      int l = i + 1;
      for (int j = i; j < n; j++) {
        if (a[j] == b[i]) {
          int r = j + 1;
          int o = r - l;
          int k = j;
          while (k > i) {
            swap(a[k], a[k - 1]);
            k--;
          }
          if (o != 0) ans.push_back({l, r, o});
        }
      }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
      cout << x.lf << ' ' << x.ri << ' ' << x.off << '\n';
    }
  }
}
