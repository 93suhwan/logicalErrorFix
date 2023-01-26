#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void usaco(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
const long double pi = 3.14159265358979323846;
const long long mod = 1000000007;
const long long tas = 1e6 + 585;
string second, t;
long long ans = 0;
void solve(int tc = 0) {
  long long second, n, k;
  cin >> second >> n >> k;
  long long val = n / k;
  if (k == second)
    cout << "YES" << endl;
  else if (val < 1 || (k > second)) {
    cout << "NO" << endl;
  } else {
    long long pt = val * k;
    val = 2 * val * k;
    if (second < val) {
      cout << "YES" << endl;
    } else {
      long long md = n % k;
      val += (md);
      pt += (md);
      if (pt == n && second >= val) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
}
int main() {
  { ios_base::sync_with_stdio(false); }
  {
    cin.tie(NULL);
    cout.tie(NULL);
  }
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}
