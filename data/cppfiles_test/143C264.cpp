#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
const int MAX_N = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;
string to_binary(long long n) {
  string s;
  for (int i = 63; i >= 0; i--) {
    long long t = (1 << i) & n;
    if (t > 0)
      s = s + "1";
    else
      s = s + "0";
  }
  return s;
}
long long modpow(long long a, long long b, long long m = mod) {
  a = a & m;
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % m;
    }
    b = b >> 1;
    a = (a * a) % m;
  }
  return ans;
}
long long modinv(long long a, long long b, long long m = mod) {
  return modpow(a, m - 2);
}
long long modadd(long long a, long long b, long long m = mod) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long modsub(long long a, long long b, long long m = mod) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long modmul(long long a, long long b, long long m = mod) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long moddiv(long long a, long long b, long long m = mod) {
  a = a % m;
  b = b % m;
  return (modmul(a, modinv(b, m), m) + m) % m;
}
int gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long msb(long long num) {
  for (int i = 31; i >= 0; i--) {
    if (num & (1 << i)) return i;
  }
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n, 0);
  unordered_map<long long, long long> mp1;
  for (int i = 0; i <= n; i++) mp1[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp1[a[i]]++;
  }
  vector<long long> tmp;
  for (int p = 0; p <= n; p++) {
    if (mp1[p] > 1) {
      for (int i = 0; i < mp1[p] - 1; i++) tmp.push_back(p);
    }
  }
  vector<long long> dp(n + 1, -1);
  sort((a).begin(), (a).end());
  sort((tmp).begin(), (tmp).end());
  if (a[0] == 0)
    dp[0] = mp1[0];
  else
    dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    long long temp = 0;
    dp[i] = mp1[i] - mp1[i - 1] + dp[i - 1];
    if (mp1[i - 1] != 0)
      continue;
    else if (tmp.size() == 0) {
      dp[i] = -1;
      break;
    } else {
      auto j2 = lower_bound(tmp.begin(), tmp.end(), i - 1);
      int index = j2 - tmp.begin();
      if (index == 0) {
        dp[i] = -1;
        break;
      }
      j2--;
      temp = abs(i - 1 - *(j2));
      tmp.erase(j2);
    }
    dp[i] += temp;
  }
  for (auto &p : dp) cout << p << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
