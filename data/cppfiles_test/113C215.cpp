#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
const long long llINF = 0x3f3f3f3f3f3f3f3f;
long long make_compiler_happy() { return INF ^ 3 ^ maxn ^ mod ^ llINF; }
long long fpow(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long inv(long long x) { return fpow(x, mod - 2); }
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
void solve() {
  string s[2];
  int p[2];
  for (int i = 0; i < (2); i++) cin >> s[i] >> p[i];
  if (((int)s[0].size()) + p[0] < ((int)s[1].size()) + p[1]) {
    cout << "<\n";
  } else if (((int)s[0].size()) + p[0] > ((int)s[1].size()) + p[1]) {
    cout << ">\n";
  } else {
    while (((int)s[0].size()) < ((int)s[1].size())) {
      p[0]--;
      s[0] += '0';
    }
    while (((int)s[1].size()) < ((int)s[0].size())) {
      p[1]--;
      s[1] += '0';
    }
    if (s[0] < s[1]) {
      cout << "<\n";
    } else if (s[0] > s[1]) {
      cout << ">\n";
    } else {
      cout << "=\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  for (int kase = (1); kase <= (T); kase++) {
    solve();
  }
}
