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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(16);
  string s;
  cin >> s;
  int n = s.size();
  if (n == 1) {
    if (s == "0" || s == "_" || s == "X")
      cout << 1;
    else
      cout << 0;
    return 0;
  }
  if (s[0] == '0') {
    cout << 0;
    return 0;
  }
  long long ans = 1;
  char f = 0;
  if ((s[n - 1] != '_' && s[n - 1] != 'X') &&
      (s[n - 2] != '_' && s[n - 2] != 'X')) {
    string ch = "";
    ch += s[n - 2];
    ch += s[n - 1];
    if (ch != "00" && ch != "25" && ch != "50" && ch != "75") {
      cout << 0;
      return 0;
    }
  } else if ((s[n - 1] == 'X') && (s[n - 2] != '_' && s[n - 2] != 'X')) {
    if (s[n - 2] != '2' && s[n - 2] != '5' && s[n - 2] != '7' &&
        s[n - 2] != '0') {
      cout << 0;
      return 0;
    }
    if (s[n - 2] == '2' || s[n - 2] == '7') {
      f = 1;
    } else {
      if (s[0] != 'X')
        f = 1;
      else {
        cout << 0;
        return 0;
      }
    }
  } else if ((s[n - 1] == '_') && (s[n - 2] != '_' && s[n - 2] != 'X')) {
    if (s[n - 2] != '2' && s[n - 2] != '5' && s[n - 2] != '7' &&
        s[n - 2] != '0') {
      cout << 0;
      return 0;
    }
  } else if ((s[n - 1] != '_' && s[n - 1] != 'X') && (s[n - 2] == 'X')) {
    if (s[n - 1] != '0' && s[n - 1] != '5') {
      cout << 0;
      return 0;
    }
    if (s[n - 1] == '5') {
      f = 1;
      ans *= 2LL;
    } else {
      f = 1;
      if (s[0] != 'X') {
        ans *= 2LL;
      }
    }
  } else if ((s[n - 1] != '_' && s[n - 1] != 'X') && (s[n - 2] == '_')) {
    if (s[n - 1] != '0' && s[n - 1] != '5') {
      cout << 0;
      return 0;
    }
    if (s[n - 1] == '5') {
      ans *= 2LL;
    } else {
      if (n - 2 != 0) {
        ans *= 2LL;
      }
    }
  } else if (s[n - 2] == 'X' && s[n - 1] == '_') {
    f = 1;
    if (s[0] != 'X')
      ans *= 4LL;
    else
      ans *= 3LL;
  } else if (s[n - 2] == 'X' && s[n - 1] == 'X') {
    if (s[0] == 'X') {
      cout << 0;
      return 0;
    }
  } else if (s[n - 2] == '_' && s[n - 1] == 'X') {
    f = 1;
    if (s[0] != 'X')
      ans *= 4LL;
    else
      ans *= 2LL;
  } else {
    if (n - 2 == 0)
      ans *= 3LL;
    else
      ans *= 4LL;
  }
  for (int i = 0; i < n - 2; i++) {
    if (s[i] == 'X') {
      if (!f) {
        f = 1;
        if (i == 0)
          ans *= 9LL;
        else
          ans *= 10LL;
      }
    }
    if (s[i] == '_') {
      if (i == 0)
        ans *= 9LL;
      else
        ans *= 10LL;
    }
  }
  cout << ans;
  return 0;
}
