#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e18;
vector<long long> a;
vector<long long> tree;
vector<long long> lazy;
vector<long long> spf;
const long long N = 1e6 + 5;
long long add(long long x, long long y) {
  x %= mod;
  y %= mod;
  return (x + y) % mod;
}
long long mul(long long x, long long y) {
  x %= mod;
  y %= mod;
  return (x * y) % mod;
}
long long power(long long x, long long n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return power((x * x) % mod, n / 2);
  } else {
    return (x * power((x * x) % mod, n / 2)) % mod;
  }
}
long long da, xa, ya;
void extendedEuclid(long long A, long long B) {
  if (B == 0) {
    da = A;
    xa = 1;
    ya = 0;
  } else {
    extendedEuclid(B, A % B);
    long long temp = xa;
    xa = ya;
    ya = temp - (A / B) * ya;
  }
}
long long inv(long long A, long long M) {
  extendedEuclid(A, M);
  return (xa % M + M) % M;
}
struct dsu {
  long long n;
  vector<long long> sizes, marks;
  vector<vector<long long>> graph;
  void init(long long rn) {
    n = rn;
    sizes = vector<long long>(n);
    fill(sizes.begin(), sizes.end(), 1);
    marks = vector<long long>(n);
    for (long long i = 0; i < n; i++) marks[i] = i;
    graph = vector<vector<long long>>(n);
  }
  void mark(long long m, long long node) {
    if (marks[node] == m) return;
    marks[node] = m;
    for (long long i : graph[node]) mark(m, i);
  }
  bool merge(long long a, long long b) {
    if (marks[a] == marks[b]) return 0;
    graph[a].push_back(b);
    graph[b].push_back(a);
    if (sizes[marks[a]] > sizes[marks[b]]) swap(a, b);
    sizes[marks[b]] += sizes[marks[a]];
    sizes[marks[a]] = 0;
    mark(marks[b], a);
    return 1;
  }
  long long find(long long n) { return marks[n]; }
};
void spf_sieve(long long MAXN) {
  spf.resize(MAXN);
  spf[1] = 1;
  for (long long i = 2; i < MAXN; i++) spf[i] = i;
  for (long long i = 4; i < MAXN; i += 2) spf[i] = 2;
  for (long long i = 3; i * i < MAXN; i++) {
    if (spf[i] == i) {
      for (long long j = i * i; j < MAXN; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
vector<long long> spfgetFactorization(long long x) {
  vector<long long> ret;
  while (x != 1) {
    ret.push_back(spf[x]);
    x = x / spf[x];
  }
  return ret;
}
void solve() {
  string tt;
  cin >> tt;
  long long n = tt.size();
  vector<long long> l(26);
  vector<long long> freq(26, 0);
  for (long long i = 0; i < tt.size(); i++) {
    long long x = tt[i] - 'a';
    l[x] = i;
    freq[x]++;
  }
  vector<pair<long long, long long>> p;
  for (long long i = 0; i < 26; i++) {
    if (freq[i] > 0) {
      p.push_back({l[i], i});
    }
  }
  sort(p.begin(), p.end());
  long long n1 = 0;
  for (long long i = 0; i < p.size(); i++) {
    long long x = p[i].second;
    n1 += (freq[x] / (i + 1));
  }
  string ans = tt.substr(0, n1);
  string ans1;
  for (long long i = 0; i < p.size(); i++) {
    char c = char(p[i].second + 'a');
    ans1 += c;
  }
  string s = ans;
  string t = ans;
  for (long long i = 0; i < ans1.size(); i++) {
    string s1;
    for (long long j = 0; j < s.size(); j++) {
      if (s[j] != ans1[i]) {
        s1 += s[j];
      }
    }
    s = s1;
    t += s;
  }
  if (t != tt) {
    cout << "-1" << '\n';
    return;
  }
  cout << ans << " " << ans1 << '\n';
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
