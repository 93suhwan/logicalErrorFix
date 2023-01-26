#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ppi = pair<int, pair<int, int>>;
using ppl = pair<ll, pair<ll, ll>>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
using vvpi = vector<vpi>;
using vpl = vector<pl>;
using vvl = vector<vl>;
using vvpl = vector<vpl>;
using vppl = vector<ppl>;
using vppi = vector<ppi>;
using ull = unsigned long long;
int MOD = 998244353;
mt19937 rnd(time(0));
const int N = 2e5 + 10;
int mul(int a, int b) { return (1ll * a * b) % MOD; }
int add(int a, int b) {
  int s = (a + b);
  if (s >= MOD) s -= MOD;
  return s;
}
int sub(int a, int b) {
  int s = (a + MOD - b);
  if (s >= MOD) s -= MOD;
  return s;
}
int po(int a, ll deg) {
  if (deg == 0) return 1;
  if (deg % 2 == 1) return mul(a, po(a, deg - 1));
  int t = po(a, deg / 2);
  return mul(t, t);
}
int inv(int n) { return po(n, MOD - 2); }
void solve() {
  str s;
  cin >> s;
  int ch = 1, ch2 = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0' && ch2 == 0) {
      ch = 0;
      ch2 = 1;
    } else if (s[i] == '0' && ch2 == 1 && s[i - 1] == '1') {
      ch2 = 2;
      break;
    }
  }
  cout << ch2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
