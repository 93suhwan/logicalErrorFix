#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, su = 0;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    su += a[i];
  }
  if (su % 2) {
    cout << "NO\n";
    return;
  }
  long long s = 0, ind = -1;
  for (long long i = 0; i < n; ++i) {
    if (!a[i] && s % 2 == 0) {
      ind = i;
      break;
    }
    s += a[i];
  }
  vector<long long> ans;
  if (ind == -1) {
    for (long long i = n - 2; i > 0; i -= 2) {
      if (a[i - 1] && a[i]) continue;
      ans.push_back(i);
      a[i] = 1;
      if (a[i - 1]) {
        ind = i - 1;
        a[i - 1] = a[i] = a[i + 1] = 0;
        break;
      }
      a[i - 1] = 1;
    }
    if (ind == -1) {
      cout << "NO\n";
      return;
    }
  }
  for (long long i = ind - 1; i >= 0; --i) {
    if (a[i]) {
      if (a[i - 1]) {
        ans.push_back(i);
        a[i - 1] = a[i] = 0;
      } else {
        if (a[i - 2]) {
          a.push_back(i - 1);
          a[i - 2] = a[i] = 0;
        } else {
          a.push_back(i - 1);
          a.push_back(i);
          a[i - 2] = 1;
          a[i] = 0;
        }
      }
    }
  }
  for (long long i = ind + 1; i < n; ++i) {
    if (a[i]) {
      if (a[i + 1]) {
        ans.push_back(i);
        a[i + 1] = a[i] = 0;
      } else {
        if (a[i + 2]) {
          a.push_back(i + 1);
          a[i + 2] = a[i] = 0;
        } else {
          a.push_back(i + 1);
          a.push_back(i);
          a[i + 2] = 1;
          a[i] = 0;
        }
      }
    }
  }
  cout << "YES\n" << ans.size() << '\n';
  for (long long i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
