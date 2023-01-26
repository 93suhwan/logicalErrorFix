#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 5;
const long long MOD = 1e9 + 7;
long long power(long long x, long long y, long long m) {
  long long ans = 1;
  x = x % m;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) ans = (ans * x) % m;
    y = y >> 1;
    x = (x * x) % m;
  }
  return ans;
}
long long mod_inv(long long a, long long m) { return power(a, m - 2, m); }
long long mod_(long long a, long long m) { return (a + m) % m; }
long long add(long long a, long long b, long long m) {
  return (((a + b) % m) + m) % m;
}
long long sub(long long a, long long b, long long m) {
  return (((a - b) % m) + m) % m;
}
long long mul(long long a, long long b, long long m) {
  return (((a * b) % m) + m) % m;
}
long long div_(long long a, long long b, long long m) {
  return mul(a, mod_inv(b, m), m);
}
const long long N1 = 1;
long long f[N1], invf[N1];
void fact(long long M) {
  f[0] = f[1] = 1;
  for (int i = 2; i < N1; i++) f[i] = mod_(f[i - 1] * i, M);
  invf[N1 - 1] = power(f[N1 - 1], M - 2, M);
  for (int i = N1 - 1; i > 0; i--) invf[i - 1] = mod_(invf[i] * i, M);
}
long long nCr(long long n, long long r, long long M) {
  if (r > n) return 0;
  long long ans = f[n];
  ans = mod_(ans * invf[n - r], M);
  ans = mod_(ans * invf[r], M);
  return ans;
}
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << std::fixed << setprecision(25);
  cerr << std::fixed << setprecision(10);
}
string reverse(string s) {
  int n = s.size();
  string ans = "";
  for (int i = n - 1; i >= 0; i--) {
    ans.push_back(s[i]);
  }
  return ans;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b) return gcd(b, a % b);
  return gcd(a, b % a);
}
int mySieve[1];
void sieve() {
  for (int i = 1; i < 1; i++) {
    for (int j = i; j < 1; j += i) {
      mySieve[j]++;
    }
  }
}
int n;
int k;
int f_[210];
vector<pair<int, int> > chords;
void solve() {
  for (int i = 0; i < 210; i++) {
    f_[i] = 1;
  }
  int free = 2 * n;
  for (auto pr : chords) {
    f_[pr.first] = 0;
    f_[pr.second] = 0;
    free -= 2;
  }
  int points = (n - k) * (n - k - 1) / 2;
  for (int i = 0; i < k; i++) {
    int x = chords[i].first, y = chords[i].second;
    if (x > y) swap(x, y);
    for (int j = i + 1; j < k; j++) {
      int u = chords[j].first, v = chords[j].second;
      if ((x < u && u < y) ^ (x < v && v < y)) points++;
    }
    int cnt = 0;
    for (int j = x + 1; j < y; j++) {
      if (f_[j] == 1) cnt++;
    }
    points += min(cnt, free - cnt);
  }
  cout << points;
  cout << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> k;
    chords = vector<pair<int, int> >(k);
    int x, y;
    for (int i = 0; i < k; i++) {
      cin >> x >> y;
      chords[i] = pair<int, int>(x, y);
    }
    solve();
  }
}
