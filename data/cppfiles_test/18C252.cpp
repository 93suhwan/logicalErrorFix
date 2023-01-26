#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long MX = 1e6;
const long double PI = 3.141592654;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    set<long long> AA;
    vector<long long> A;
    vector<pair<long long, long long>> V;
    long long n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= 2 * n; i++) {
      AA.insert(i);
    }
    long long x[k], y[k];
    for (int i = 0; i < k; i++) {
      cin >> x[i] >> y[i];
      V.push_back(make_pair(x[i], y[i]));
      AA.erase(x[i]);
      AA.erase(y[i]);
    }
    for (auto v : AA) {
      A.push_back(v);
    }
    for (int i = 0; i < (n - k); i++) {
      V.push_back(make_pair(A[i], A[i + n - k]));
    }
    for (auto el : V) {
      long long mn = min(el.first, el.second), mx = max(el.first, el.second);
      for (auto v : V) {
        long long mn1 = min(v.first, v.second), mx1 = max(v.first, v.second);
        if (mn1 > mn) {
          if (mn1 < mx) {
            if (mx1 < mx) {
              continue;
            } else {
              ans++;
            }
          } else {
            continue;
          }
        } else {
          if (mx1 < mn) {
            continue;
          } else {
            if (mx1 < mx) {
              ans++;
            } else {
              continue;
            }
          }
        }
      }
    }
    cout << ans / 2 << endl;
  }
}
