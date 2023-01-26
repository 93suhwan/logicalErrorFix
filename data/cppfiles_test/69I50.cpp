#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
long long pow_t(long long a, long long b) {
  long long ans = 1;
  for (int i = 1; i <= b; i++) {
    ans *= a;
  }
  return ans;
}
long long quick_m(long long a, long long b, long long MOD) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ans;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
bool cmp(long long x, long long y) { return x < y; }
string b2[60];
void strlen_(long long i, long long j) {
  string b;
  while (j) {
    b += (j % 10 + '0');
    j /= 10;
  }
  for (int g = b.length() - 1; g >= 0; g--) b2[i] += b[g];
}
void solve() {
  string n;
  cin >> n;
  int minn = INF;
  for (int i = 0; i <= 50; i++) {
    int p = 0, q = 0, cnt = 0;
    while (1) {
      if (n[p] == b2[i][q]) {
        q++;
        p++;
      } else {
        p++;
        cnt++;
      }
      if (p == n.length() || q == b2[i].length()) break;
    }
    if (q != b2[i].length()) {
      cnt += b2[i].length() - q;
    }
    if (p != n.length()) {
      cnt += n.length() - p;
    }
    minn = min(minn, cnt);
  }
  cout << minn << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 0; i <= 50; i++) {
    strlen_(i, pow_t(2, i));
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
