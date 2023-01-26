#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T my_pow(T n, T p) {
  if (p == 0) return 1;
  T x = my_pow(n, p / 2);
  x = (x * x);
  if (p & 1) x = (x * n);
  return x;
}
template <class T>
T big_mod(T n, T p, T m) {
  if (p == 0) return (T)1;
  T x = big_mod(n, p / 2, m);
  x = (x * x) % m;
  if (p & 1) x = (x * n) % m;
  return x;
}
template <typename T>
T ModInverse(T n, T m) {
  return BigMod(n, m - 2, m);
}
string itos(long long int n) {
  string s;
  while (n) {
    s += (n % 10 + 48);
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long int stoi(string s) {
  long long int n = 0;
  for (__typeof(s.size()) i = 0; i < (s.size()); i++) n = n * 10 + (s[i] - 48);
  return n;
}
struct info {
  long long int x, y;
} arr[200003];
bool com(info a, info b) { return (a.x > b.x) or (a.x == b.x and a.y > b.y); }
const long long int N = 5e6 + 100, MOD = 1e9 + 7, inf = 1e18 * 1LL;
long long int ar[N], br[N], cr[N];
long long int a, b, c, r, rr, n, m, t = 0, ks;
string s, ss;
vector<long long int> vec;
long long int differentBit(long long int A, long long int B) {
  int count = 0;
  for (long long int i = 0; i < 32; i++) {
    if (((A >> i) & 1) != ((B >> i) & 1)) {
      count++;
    }
  }
  return count;
}
bool bs(long long int f, long long int ff) {}
vector<long long int> v;
long long int findSolA() {
  long long int cnt = 0;
  for (__typeof(n - 2) i = 0; i < (n - 2); i++) {
    if (v[i] < v[i + 1] && v[i + 1] > v[i + 2]) cnt++;
  }
  return cnt;
}
long long int findSolB() {
  long long int cnt = 0;
  for (__typeof(n - 2) i = 0; i < (n - 2); i++) {
    if (v[i] > v[i + 1] && v[i + 1] < v[i + 2]) cnt++;
  }
  return cnt;
}
void solve() {
  long long int res = 0;
  vector<long long int> v, vv;
  cin >> n;
  cin >> m;
  for (__typeof(n) i = 0; i < (n); i++) cin >> ar[i];
  sort(ar, ar + n);
  long long int mx = -1e18, cnt = 0;
  if (abs(ar[0]) > abs(ar[n - 1])) {
    for (int i = m; i < n; i++) {
      cnt++;
      if (ar[i] == 0) cnt--;
      mx = max(mx, abs(ar[i]));
      if (cnt == m) {
        res += 2LL * mx;
        mx = -1e18;
        cnt = 0;
      }
    }
    if (cnt > 0) res += mx * 2LL;
    res += abs(ar[0]);
  } else {
    for (int i = n - m - 1; i >= 0; i--) {
      cnt++;
      mx = max(mx, abs(ar[i]));
      if (ar[i] == 0) continue;
      if (cnt == m) {
        res += 2LL * mx;
        mx = -1e18;
        cnt = 0;
      }
    }
    if (cnt > 0) res += mx * 2LL;
    res += abs(ar[n - 1]);
  }
  cout << res << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
