#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
const int Mod = 998244353;
long long n, t, k;
long long dp[N];
string s;
long long ans = 1;
long long fact[N], inv[N];
void Entekhab();
long long Tavan(long long, long long);
int Check(string);
long long Ent(long long, long long);
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k >> s;
  Entekhab();
  if (k == 0 or Check(s) < k) {
    cout << 1 << endl;
    exit(0);
  }
  for (int i = 0; i < n; i++) {
    int l = i, r = i, cnt1 = 0, cnt0 = 0;
    bool seen0 = false, seen1 = false;
    for (int j = i; j < n; j++) {
      if (s[j] == '1')
        cnt1++, seen1 = true;
      else
        seen0 = true, cnt0++;
      if (j == n - 1 or (cnt1 == k and s[j + 1] == '1')) {
        r = j;
        break;
      }
    }
    if (s[i] == '1' and seen0) {
      ans += Ent(cnt1, r - l);
      ans %= Mod;
    } else if (s[i] == '0' and seen1) {
      ans += Ent(cnt0, r - l);
      ans %= Mod;
    }
  }
  cout << ans << endl;
}
int Check(string s) {
  int res = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '1') res++;
  return res;
}
void Entekhab() {
  fact[0] = 1, inv[0] = 1;
  for (long long i = 1; i < N; i++)
    fact[i] = (fact[i - 1] * i) % Mod, inv[i] = Tavan(fact[i], (Mod - 2));
}
long long Ent(long long x, long long y) {
  if (x > y) return 0;
  if (y < 0 or x < 0) return 0;
  return (fact[y] * ((inv[x] * inv[y - x]) % Mod)) % Mod;
}
long long Tavan(long long x, long long y) {
  if (y == 0) return 1;
  long long z = Tavan(x, y / 2);
  z = (z * z) % Mod;
  if (y & 1) return (z * x) % Mod;
  return z;
}
