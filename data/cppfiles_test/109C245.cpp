#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y, ind;
  char ch;
};
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long Com[1005][1005];
void comfunc() {
  for (long long i = 0; i <= 1000; i++) {
    Com[i][0] = 1;
    for (long long j = 1; j <= i; j++) {
      Com[i][j] = (Com[i - 1][j - 1] + Com[i - 1][j]) % mod;
    }
  }
}
long long fact[13];
void factorial() {
  fact[0] = 1;
  for (long long i = 1; i < 12; i++) fact[i] = (fact[i - 1] * i);
}
bool cmp(point A, point B) {
  if (A.x != B.x) return A.x < B.x;
  return A.y < B.y;
}
long long n, m, k, ok, ans, a[200005];
string s;
vector<long long> adj[200005], vec;
int main() {
  long long _t;
  cin >> _t;
  for (long long w = 0; w < _t; w++) {
    cin >> n;
    cin >> s;
    ans = 0;
    ok = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] != '0' && i != n - 1) ok++;
      ans += (s[i] - '0');
    }
    cout << ans + ok << "\n";
  }
  return 0;
}
