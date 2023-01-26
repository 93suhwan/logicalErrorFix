#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &i : v) in >> i;
  return in;
}
template <typename A, typename B>
istream &operator>>(istream &in, pair<A, B> &a) {
  in >> a.first >> a.second;
  return in;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long r) {
  uniform_int_distribution<long long> uid(l, r);
  return uid(rng);
}
const string no = "No";
const string yes = "Yes";
void solve() {
  long long a, b;
  cin >> a >> b;
  long long rounds = a + b;
  long long matcha = (rounds + 1) / 2, matchb = rounds - matcha;
  set<long long> s;
  for (long long i = 0; i <= matchb; i++) {
    long long pointsa = matcha + i;
    long long pointsb = matchb - i;
    long long breaksfroma = pointsa - a;
    pointsa -= breaksfroma;
    pointsb += breaksfroma;
    if (pointsa < i) {
      long long takeback = i - pointsa;
      breaksfroma -= takeback;
      pointsa += takeback;
      pointsb += takeback;
    };
    ;
    if (b == pointsb && a == pointsa && breaksfroma >= 0) {
      s.insert(i + breaksfroma);
    }
  };
  matcha = rounds / 2, matchb = rounds - matcha;
  for (long long i = 0; i <= matcha; i++) {
    long long pointsb = matchb + i;
    long long pointsa = matcha - i;
    long long breaksfromb = pointsb - b;
    pointsb -= breaksfromb;
    pointsa += breaksfromb;
    if (pointsb < i) {
      long long takeback = i - pointsb;
      breaksfromb -= takeback;
      pointsb += takeback;
      pointsa -= takeback;
    };
    ;
    if (b == pointsb && a == pointsa && breaksfromb >= 0) {
      s.insert(i + breaksfromb);
    }
  };
  cout << (long long)(s).size() << '\n';
  for (long long i : s) {
    cout << i << ' ';
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long tc = 1; tc <= t; tc++) {
    ;
    solve();
  }
  return 0;
}
