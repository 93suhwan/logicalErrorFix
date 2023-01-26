#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
const double PI = acos(-1.0);
const int mx = 3e5 + 5;
const int M = 1e9 + 7;
const int mod = 998244353;
int dr[] = {0, -1, 0, 1, -1, -1, 1, 1};
int dc[] = {1, 0, -1, 0, 1, -1, -1, 1};
int kx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int ky[] = {2, 1, -1, -2, -2, -1, 1, 2};
bool valid(int row, int col) {
  return (row >= 1) && (row <= 8) && (col >= 1) && (col <= 8);
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll bigmod(ll a, ll b) {
  if (b == 0) return 1;
  ll x = bigmod(a, b / 2);
  x = (x * x) % M;
  if (b % 2 == 1) x = (x * a) % M;
  return x;
}
ll powmod(ll x, ll y) {
  ll res = 1;
  for (ll i = 0; i < y; i++) {
    res = (res * x) % M;
  }
  return res;
}
int computeXOR(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
void Solve() {
  ll i = 0, j = 0, x, y, z, sum = 0, ans = 0, n, m, k = 0, l = 0, p = 0, q = 0,
     r = 0;
  string s, t;
  cin >> s >> t;
  map<char, ll> mp;
  sort((s).begin(), (s).end());
  for (int i = 0; i < (s.size()); ++i) {
    mp[s[i]]++;
  }
  if (t[1] == 'b' && t[2] == 'c' && mp['a'] > 0) {
    while (mp['a'] > 0) {
      cout << 'a';
      mp['a']--;
    }
    while (mp['c'] > 0) {
      cout << 'c';
      mp['c']--;
    }
    while (mp['b'] > 0) {
      cout << 'b';
      mp['b']--;
    }
  }
  for (i = 0; i < s.size(); i++) {
    while (mp[s[i]] > 0) {
      cout << s[i];
      mp[s[i]]--;
    }
  }
  cout << "\n";
  return;
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int TC;
  cin >> TC;
  while (TC--) {
    Solve();
  }
  return 0;
}
