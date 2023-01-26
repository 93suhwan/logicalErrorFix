#include <bits/stdc++.h>
using namespace std;
using std::ofstream;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long P = 1e9 + 7;
ofstream out;
ifstream in;
long long const max_value = (1 << 13);
vector<long long> g[max_value];
long long ans[max_value], r[max_value];
bool func(vector<long long>& v, long long n, long long k, long long l1) {
  if (l1 > (n / 2) * (n)) return 0;
  long long l2 = v[l1];
  long long l3 = (l1 / (n / 2));
  long long l4 = l1 % (n / 2);
  for (long long i = 0; i < l3 - 1; i++) {
    l2 += v[l1 + i + 1];
  }
  long long cnt = n - l3;
  if (cnt == 0) {
    return l2 <= k;
  }
  long long i1 = l1 + (l3) + 1;
  long long k1 = i1 + (n / 2 - (l4));
  l3++;
  l2 += v[k1];
  for (long long i = k1 + n / 2 + 1; i < n * n && l3 < n; i += n / 2 + 1) {
    l2 += v[i];
    l3++;
  }
  return l2 <= k;
}
unsigned long long power(unsigned long long x, long long y, long long p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long func(long long pos, vector<long long>& v) {
  if (pos <= 10) return v[pos - 1];
  return v[9] * power(10, pos - 10, LLONG_MAX);
}
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long>> v(n, vector<long long>(3));
  for (long long i = 0; i < n; i++) {
    cin >> v[i][0] >> v[i][1] >> v[i][2];
  }
  map<long long, vector<vector<long long>>> dp;
  for (long long i = 0; i < n; i++) {
    dp[v[i][0] + v[i][1] - v[i][2]].push_back(
        {max(v[i][0] - v[i][2], 0LL), v[i][0], i});
  }
  long long cnt = 0;
  vector<pair<long long, long long>> ans(n);
  for (auto v1 : dp) {
    vector<vector<long long>> dp1 = v1.second;
    long long n1 = dp1.size();
    vector<pair<long long, long long>> a(n1), b(n1);
    for (long long i = 0; i < n1; i++) {
      a[i] = {dp1[i][0], dp1[i][2]};
      b[i] = {dp1[i][1], dp1[i][2]};
    }
    sort((b).begin(), (b).end());
    sort((a).begin(), (a).end());
    set<long long> h1;
    long long i = 0;
    long long j = 0;
    long long mx = -1;
    long long idx = -1;
    while (i < n1) {
      if (a[i].first <= b[j].first) {
        h1.insert(a[i].second);
        if ((long long)h1.size() > mx) {
          mx = h1.size();
          idx = a[i].first;
        }
        i++;
      } else {
        h1.erase(b[j++].second);
      }
    }
    for (long long i = 0; i < n1; i++) {
      if (idx >= dp1[i][0] && idx <= dp1[i][1]) {
        long long l1 = v[dp1[i][2]][2] - (v[dp1[i][2]][0] - idx);
        ans[dp1[i][2]].first = v[dp1[i][2]][0] - idx;
        ans[dp1[i][2]].second = v[dp1[i][2]][2] - v[dp1[i][2]][0] + idx;
      } else {
        long long l1 = v[dp1[i][2]][2] - v[dp1[i][2]][0];
        ans[dp1[i][2]].first = 0;
        ans[dp1[i][2]].second = v[dp1[i][2]][1];
        if (l1 < 0) {
          ans[dp1[i][2]].first += abs(l1);
        }
        if (l1 > 0) {
          ans[dp1[i][2]].second -= abs(l1);
        }
        ans[dp1[i][2]].first = v[dp1[i][2]][0] - ans[dp1[i][2]].first;
        ans[dp1[i][2]].second = v[dp1[i][2]][1] - ans[dp1[i][2]].second;
      }
    }
    cnt += mx;
  }
  cout << n - cnt + dp.size() << "\n";
  for (long long i = 0; i < n; i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  cin >> tc;
  for (long long t1 = 1; t1 <= tc; t1++) {
    solve();
  }
}
