#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long MOD = long long(9e18)) {
  long long res = 1;
  a %= MOD;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
    a %= MOD;
    res %= MOD;
  }
  return res % MOD;
}
template <typename T>
void umax(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void umin(T& a, T b) {
  a = min(a, b);
}
clock_t startTime;
double getTime() { return (double)(clock() - startTime) / CLOCKS_PER_SEC; }
template <typename T>
ostream& operator<<(ostream& s, vector<T>& v) {
  for (auto el : v) {
    s << el << ' ';
  }
  return s;
}
int T = 1;
long long n, m;
vector<pair<long long, long long> > a[12];
set<vector<long long> > bad;
vector<long long> lst;
vector<long long> km;
vector<long long> ans;
long long mxANS = 0;
vector<long long> curP;
set<vector<long long> > was;
struct seg {
  long long ans;
  vector<pair<long long, long long> > p;
};
struct comp {
  bool operator()(const seg& b, const seg& a) { return b.ans < a.ans; }
};
void solve() {
  cin >> n;
  for (long long i = (0); i < (n); i++) {
    long long k;
    cin >> k;
    for (long long j = (0); j < (k); j++) {
      long long x;
      cin >> x;
      a[i].push_back({x, j});
    }
  }
  ans.resize(n, 0);
  for (long long i = (0); i < (n); i++) {
    sort((a[i]).rbegin(), (a[i]).rend());
  }
  lst.resize(n, 0);
  km.resize(n, 0);
  cin >> m;
  vector<long long> cur(n);
  long long q = m;
  while (q--) {
    for (long long i = (0); i < (n); i++) {
      cin >> cur[i];
    }
    bad.insert(cur);
  }
  priority_queue<seg, vector<seg>, comp> pq;
  vector<pair<long long, long long> > CUR(n);
  long long curAns = 0;
  for (long long i = (0); i < (n); i++) {
    curAns += a[i][0].first;
    CUR[i] = {a[i][0].second, 0};
  }
  seg f;
  f.ans = curAns;
  f.p = CUR;
  pq.push(f);
  vector<long long> curV(n, 0);
  while (!pq.empty()) {
    seg t = pq.top();
    pq.pop();
    for (long long i = (0); i < (n); i++) {
      curV[i] = t.p[i].first + 1;
    }
    if (bad.find(curV) == bad.end()) {
      cout << curV;
      return;
    } else {
      for (long long i = (0); i < (n); i++) {
        seg s = t;
        s.ans -= a[i][s.p[i].second].first;
        if (s.p[i].second + 1 < long long((a[i]).size())) s.p[i].second++;
        s.p[i].first = a[i][s.p[i].second].second;
        s.ans += a[i][s.p[i].second].first;
        curV[i] = s.p[i].first + 1;
        if (was.find(curV) == was.end()) {
          pq.push(s);
          was.insert(curV);
        }
        curV[i] = a[i][t.p[i].second].second + 1;
      }
    }
  }
  return;
}
signed main() {
  startTime = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (T--) {
    solve();
    cout << "\n";
  };
  return 0;
}
