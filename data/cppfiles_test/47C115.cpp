#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void __logger(string vars, Args &&...values) {
  cerr << "\n" << vars << " = ";
  string delim = "";
  (..., (cerr << delim << values, delim = ", "));
  cerr << "\n";
}
long long go(const vector<long long> &d1, const vector<long long> &d2,
             long long k) {
  if (d1.empty()) return 1e18;
  long long cost = d1[0];
  long long cur = 1;
  long long bag = k - 1;
  long long n = d1.size();
  long long m = d2.size();
  while (cur < n) {
    if (bag == 0) {
      cost += d1[cur] + d1[cur];
      bag = k;
    }
    bag--;
    cur++;
  }
  cur = 0;
  bag = 0;
  while (cur < m) {
    if (bag == 0) {
      cost += d2[cur] + d2[cur];
      bag = k;
    }
    bag--;
    cur++;
  }
  return cost;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> neg, pos;
    for (long long i = 0; i < n; ++i) {
      long long x;
      cin >> x;
      if (x < 0)
        neg.push_back(abs(x));
      else if (x > 0)
        pos.push_back(x);
    }
    sort(neg.begin(), neg.end());
    reverse(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    reverse(pos.begin(), pos.end());
    if (pos.empty() && neg.empty()) {
      cout << "0\n";
      continue;
    }
    long long ans = min(go(neg, pos, k), go(pos, neg, k));
    cout << ans << "\n";
  }
  return 0;
}
