#include <bits/stdc++.h>
const int Inf = 2 * 1000 * 1000 * 1000;
long long LINF = (long long)4e18;
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
const long long mod = 1e9 + 7;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0)
    if (b & 1) {
      res = (long long)(res * 1ll * a) % mod;
      --b;
    } else {
      a = (long long)(a * 1ll * a) % mod;
      b >>= 1;
    }
  return (long long)res % mod;
}
long long get_pref(vector<long long>& pref, long long ind, long long k) {
  if (ind == 0) return 0;
  long long l = ind * k;
  return l - pref[ind - 1];
}
long long get_suf(vector<long long>& pref, long long ind, long long k) {
  if (ind == pref.size() - 1) return 0;
  long long r = ((pref.size()) - (ind + 1)) * k;
  return (pref.back() - pref[ind]) - r;
}
int n;
string s;
int ans = 0;
int rec(int id, int x, int current) {
  if (id == n) {
    if (n == 1 && current == 0) {
      return 1;
    } else {
      if (current / binpow(10, n - 1) == 0) return 0;
      if (current % 25 == 0) return 1;
      return 0;
    }
  } else if (s[id] != 'X' && s[id] != '_') {
    current += (s[id] - '0') * binpow(10, n - id - 1);
    if (id == 0)
      ans += rec(id + 1, x, current);
    else
      return rec(id + 1, x, current);
    current -= (s[id] - '0') * binpow(10, n - id - 1);
  } else if (s[id] == '_') {
    if (n - id > 3) {
      for (int i = 0; i < 10; i++) {
        char p = i + '0';
        current += (p - '0') * binpow(10, n - id - 1);
        if (id == 0)
          ans += rec(id + 1, x, current);
        else
          return rec(id + 1, x, current);
        ;
        current -= (p - '0') * binpow(10, n - id - 1);
      }
    } else {
      if (id == 0) {
        char p = '0';
        current += (p - '0') * binpow(10, n - id - 1);
        ans += rec(id + 1, x, current);
        current -= (p - '0') * binpow(10, n - id - 1);
        p = '5';
        current += (p - '0') * binpow(10, n - id - 1);
        ans += 9 * rec(id + 1, x, current);
        current -= (p - '0') * binpow(10, n - id - 1);
      } else {
        int currans = 0;
        char p = '0';
        current += (p - '0') * binpow(10, n - id - 1);
        currans += rec(id + 1, x, current);
        current -= (p - '0') * binpow(10, n - id - 1);
        p = '5';
        current += (p - '0') * binpow(10, n - id - 1);
        currans += 9 * rec(id + 1, x, current);
        current -= (p - '0') * binpow(10, n - id - 1);
        return currans;
      }
    }
  } else if (s[id] == 'X') {
    if (x == -1) {
      int currans = 0;
      for (int i = 0; i < 10; i++) {
        char p = i + '0';
        current += (p - '0') * binpow(10, n - id - 1);
        if (id == 0) {
          ans += rec(id + 1, i, current);
        } else {
          currans += rec(id + 1, i, current);
        }
        current -= (p - '0') * binpow(10, n - id - 1);
      }
      return currans;
    } else {
      char p = x + '0';
      current += (p - '0') * binpow(10, n - id - 1);
      if (id == 0)
        ans += rec(id + 1, x, current);
      else
        return rec(id + 1, x, current);
      current -= (p - '0') * binpow(10, n - id - 1);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(16);
  cin >> s;
  n = s.size();
  rec(0, -1, 0);
  cout << ans;
}
