#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 1000000007;
const char nl = '\n';
const long long MX = 200001;
void solve() {
  long long n, k, x;
  cin >> n >> k >> x;
  string s;
  cin >> s;
  vector<long long> v;
  long long cnt = 0;
  for (long long i = 0; i < s.size(); ++i) {
    if (s[i] != '*') {
      if (cnt) v.push_back(cnt * k);
      cnt = 0;
      continue;
    } else
      cnt++;
  }
  if (cnt) v.push_back(cnt * k);
  vector<long long> ans(v.size(), 0);
  while (!v.empty() && x != 0) {
    if (x <= v.back() + 1) {
      if (!v.empty()) ans[v.size() - 1] = min(x - 1, 1ll * v.back());
      break;
    }
    long long cur = v.back() + 1;
    for (long long i = v.size() - 2; i >= 0; --i) {
      if ((x - cur) / (v[i]) <= cur) {
        long long d = (x - cur) / (cur) + (((x - cur) % (cur)) > 0);
        ans[i] = d;
        x = x - (d * (cur));
        break;
      }
      cur += (v[i]) * (cur);
    }
  }
  long long idx = 0;
  for (long long i = 0; i < s.size(); ++i) {
    if (s[i] != '*') {
      if (i && s[i - 1] == '*') {
        while (ans[idx]--) cout << 'b';
        idx++;
      }
      cout << s[i];
    }
  }
  if (idx < v.size()) {
    while (ans[idx]--) cout << 'b';
    idx++;
  }
  cout << nl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
