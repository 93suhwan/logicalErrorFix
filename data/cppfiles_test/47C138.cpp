#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }
ll sum(ll n) { return ((n * (n + 1)) / 2); }
ll ceil(ll a, ll b) { return ((a + (b - 1)) / b); }
void InputOutput() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
ll calculation(vector<ll> &v, ll k) {
  ll dis, cnt, len, index;
  dis = cnt = 0;
  len = (ll)v.size();
  len -= k;
  index = len - 1;
  for (ll i = len - 1; i >= 0; i--) {
    cnt++;
    if (cnt == k) {
      dis += (v[index] * 2);
      cnt = 0;
      index = i - 1;
    }
  }
  if (cnt) dis += (v[index] * 2);
  return dis;
}
void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> pos, neg;
  ll temp, dis;
  for (ll i = 0; i < n; i++) {
    cin >> temp;
    if (temp < 0)
      neg.push_back(abs(temp));
    else if (temp > 0)
      pos.push_back(temp);
  }
  if (pos.empty() and neg.empty()) {
    cout << 0 << "\n";
    return;
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  dis = 0;
  dis += calculation(pos, k);
  dis += calculation(neg, k);
  if (pos.empty())
    dis += neg.back();
  else if (neg.empty())
    dis += pos.back();
  else {
    if (pos.back() < neg.back()) {
      dis += (pos.back() * 2);
      dis += neg.back();
    } else {
      dis += (neg.back() * 2);
      dis += pos.back();
    }
  }
  cout << dis << "\n";
}
int main() {
  InputOutput();
  int t = 1;
  cin >> t;
  for (int test_case = 1; test_case <= t; test_case++) {
    solve();
  }
  return 0;
}
