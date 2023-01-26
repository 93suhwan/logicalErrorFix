#include <bits/stdc++.h>
using namespace std;
long long big = 1000000007;
long long mod = 998244353;
double pi = 3.14159265;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
string getbin(unsigned long long x) {
  if (x == 0) return "0";
  string ret = "";
  while (x != 0) {
    ret = (char)('0' + x % 2) + ret;
    x /= 2;
  }
  return ret;
}
unsigned long long getdec(string b) {
  unsigned long long ret = 0;
  for (int i = 0; i < b.size(); i += 1) {
    ret *= 2;
    ret += b[i] - '0';
  }
  return ret;
}
int getp(unsigned long long x) {
  int ret = 0;
  while (x > 1) {
    x /= 2;
    ret += 1;
  }
  return ret;
}
unsigned long long modfact(long long x, long long modulo) {
  if (x == 0)
    return 1;
  else
    return (x * modfact(x - 1, modulo)) % modulo;
}
unsigned long long modexp(long long x, long long m, long long n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  unsigned long long y = modexp(x, m, n / 2);
  if (n & 1) {
    return ((x * y % m) * y) % m;
  } else {
    return y * y % m;
  }
}
unsigned long long modinv(int a, int m) {
  int g = gcd(a, m);
  if (g != 1) throw "Inverse doesn't exist";
  return modexp(a, m, m - 2);
}
unsigned long long binexp(long long x, long long n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  unsigned long long y = binexp(x, n / 2);
  if (n & 1) {
    return x * y * y;
  } else {
    return y * y;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<vector<bool>> g(n + 1, vector<bool>(m + 1, true));
    vector<vector<bool>> e(n + 1, vector<bool>(m + 1, true));
    vector<bool> cols(m + 1, false);
    char c;
    for (int i = 1; i < n + 1; i += 1) {
      for (int j = 1; j < m + 1; j += 1) {
        cin >> c;
        g[i][j] = (c == '.');
        e[i][j] = false;
        if (g[i][j] and (g[i - 1][j] || g[i][j - 1])) e[i][j] = true;
        if (g[i][j]) cols[j] = cols[j] || (!e[i][j]);
      }
    }
    vector<int> pref(m + 1, 0);
    for (int i = 1; i < m + 1; i += 1) pref[i] = pref[i - 1] + cols[i];
    for (int i = 1; i < m + 1; i += 1) cout << pref[i] << " ";
    cout << endl;
    int q;
    cin >> q;
    int l, r;
    while (q--) {
      cin >> l >> r;
      if (pref[r] - pref[l])
        cout << "NO";
      else
        cout << "YES";
      cout << '\n';
    }
  }
  return 0;
}
