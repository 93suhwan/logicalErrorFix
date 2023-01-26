#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const long long MAXN = 1600010;
void fast_stream() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
ll power(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b % 2) {
      res = (res * a);
      --b;
    } else {
      a = (a * a);
      b = b >> 1;
    }
  }
  return res;
}
ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
bool myCmp(pair<int, string>& a, pair<int, string>& b) {
  return a.second < b.second;
}
bool isPrime(int x) {
  if (x <= 1) {
    return false;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % (i + 2) == 0) {
      ++cnt;
    }
  }
  if (a[0] % 2 == 0) {
    cout << "NO" << '\n';
    return;
  }
  if (cnt == n) {
    cout << "NO" << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    ll x = a[i - 1];
    int j = 2;
    bool flag = false;
    while (j < 22 and j <= i + 1) {
      if (x % j != 0) {
        flag = true;
        break;
      }
      ++j;
    }
    if (flag == false) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
}
int main() {
  fast_stream();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
