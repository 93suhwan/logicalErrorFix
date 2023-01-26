#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7, inf = 1e15 + 7;
long long dirx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
long long diry[8] = {0, 0, 1, -1, 1, -1, 1, -1};
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long quik_pow(long long a, long long n, long long p) {
  if (n == 1) return a % p;
  if (n == 0) return 1;
  if (n % 2 == 0) {
    long long b = quik_pow(a, n / 2, p);
    return (b * b) % p;
  } else
    return (a * quik_pow(a, n - 1, p)) % p;
}
long long gcd(long long a, long long b, long long &first, long long &second) {
  if (a == 0) {
    first = 0;
    second = 1;
    return b;
  }
  long long x1, y1;
  long long g = gcd(b % a, a, x1, y1);
  first = y1 - (b / a) * x1;
  second = x1;
  return g;
}
vector<long long> calc(long long n) {
  vector<long long> a;
  if (n == 0) a.push_back(0);
  while (n > 0) {
    a.push_back(n % 2);
    n /= 2;
  }
  return a;
}
vector<long long> pw(20, 1);
vector<long long> f(vector<long long> a) {
  long long n = a.size();
  vector<long long> b(n, 0);
  if (n == 1) b[0] = 1;
  if (n == 2) b[0] = 2;
  if (n > 2) b[0] = 2 + pw[n - 2];
  long long cur = a[0] * 1;
  for (long long i = 1; i < n - 1; i++) {
    if (a[i] == 1) {
      a[i] += pw[n - 2];
    } else {
      a[i] += pw[n - 2] - (pw[i] - 1 - cur);
    }
    cur += a[i] * pw[i];
  }
  for (long long i = 0; i < n - 1; i++) {
    for (long long j = i + 2; j < n; j++) {
      b[i] += pw[j - 2];
    }
  }
  return b;
}
void solve() {
  long long n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  if (a == b) {
    cout << "0\n";
    return;
  }
  long long c = 0;
  bool f = false;
  for (long long i = 0; i < n; i++) {
    if (a[i] == b[i]) c++;
    if (a[i] == '1') f = true;
  }
  if (f == false) {
    cout << "-1\n";
    return;
  }
  queue<pair<long long, long long> > q;
  vector<long long> was(n + 100, 0);
  long long mn = inf;
  q.push({c, 0});
  while (!q.empty()) {
    pair<long long, long long> p = q.front();
    q.pop();
    if (was[p.first]) {
      continue;
    }
    was[p.first] = 1;
    if (n - p.first + 1 == n) {
      mn = p.second + 1;
      break;
    } else {
      q.push({n - p.first + 1, p.second + 1});
    }
    if (n - p.first - 1 == n) {
      mn = p.second + 1;
      break;
    } else {
      q.push({n - p.first - 1, p.second + 1});
    }
  }
  if (mn == inf) {
    cout << "-1\n";
    return;
  } else {
    cout << mn << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 1; i < 20 - 1; i++) pw[i] = pw[i - 1] * 2;
  long long _;
  cin >> _;
  while (_--) {
    solve();
  }
}
