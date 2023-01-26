#include <bits/stdc++.h>
using namespace std;
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
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void usaco(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
const long double pi = 3.14159265358979323846;
const long long mod = 1000000007;
long long n, m, q, k, l, r, x, y, z;
const long long template_array_size = 1e6 + 17323;
long long a[template_array_size];
long long b[template_array_size];
long long c[template_array_size];
string second, t;
void solve(int tc = 0) {
  cin >> n >> second;
  long long lp = 0;
  for (long long rp = 0; rp < n; rp++) {
    if (second[rp] != '?') {
      if (lp < rp) {
        if (lp != 0) {
          char targ = second[lp - 1];
          for (long long i = lp; i < rp; i++) {
            targ = (targ == 'B' ? 'R' : 'B');
            second[i] = targ;
          }
        } else if (rp != n - 1) {
          char targ = second[rp];
          for (long long i = rp - 1; i >= lp; i--) {
            targ = (targ == 'B' ? 'R' : 'B');
            second[i] = targ;
          }
        }
      }
      lp = rp + 1;
    }
  }
  if (lp < n) {
    char targ;
    if (lp == 0) {
      targ = 'B';
    } else {
      targ = second[lp - 1];
    }
    for (long long i = lp; i < n; i++) {
      targ = (targ == 'B' ? 'R' : 'B');
      second[i] = targ;
    }
  }
  cout << second << '\n';
}
int main() {
  { ios_base::sync_with_stdio(false); }
  { cin.tie(NULL); }
  cout << setprecision(15) << fixed;
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) {
    solve(t);
  }
}
