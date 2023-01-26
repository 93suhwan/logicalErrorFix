#include <bits/stdc++.h>
using namespace std;
struct fenwickTree {
  vector<long long> bit;
  fenwickTree(long long n) : bit(n, 0) {}
  void update(long long idx, long long d) {
    for (; idx < (long long)bit.size(); idx = idx | (idx + 1)) bit[idx] += d;
  }
  long long sum(long long r) const {
    long long ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }
  long long sum(long long l, long long r) const { return sum(r) - sum(l - 1); }
};
long long numIverserions(const vector<long long>& arr) {
  const long long n = arr.size();
  fenwickTree ft(n + 1);
  long long inversions = 0;
  for (long long val : arr) {
    if (val + 1 <= n) inversions += ft.sum(val + 1, n);
    ft.update(val, 1);
  }
  return inversions;
}
signed main() {
  cin.tie(0)->sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    vector<bool> cnts(n + 1, false);
    {
      bool isDup = false;
      for (long long& val : arr) {
        cin >> val;
        if (cnts[val]) {
          isDup = true;
        }
        cnts[val] = true;
      }
      if (isDup) {
        cout << "YES\n";
        continue;
      }
    }
    (numIverserions(arr) % 2 == 0 && cout << "YES\n") || cout << "NO\n";
  }
  return 0;
}
