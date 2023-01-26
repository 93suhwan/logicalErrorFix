#include <bits/stdc++.h>
const uint64_t mod = 2e9 + 11;
const uint64_t pp = 919;
using ll = int64_t;
using namespace std;
ll CalculateAnswer(vector<ll>& a, ll k) {
  ll res = k;
  for (int i = 0; i + 1 < a.size(); ++i) {
    res += min(k, a[i + 1] - a[i]);
  }
  return res;
}
void solve() {
  ll n, h;
  cin >> n >> h;
  vector<ll> a(n);
  for (auto& el : a) {
    cin >> el;
  }
  ll l = 0, r = h;
  while (l + 1 < r) {
    ll c = l + (r - l) / 2;
    if (CalculateAnswer(a, c) < h) {
      l = c;
    } else {
      r = c;
    }
  }
  cout << r << endl;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
