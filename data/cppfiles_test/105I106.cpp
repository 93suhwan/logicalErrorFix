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
pair<long long, vector<pair<long long, long long>>> solve1(
    long long n, vector<vector<long long>>& v) {
  map<long long, vector<vector<long long>>> dp;
  for (long long i = 0; i < n; i++) {
    dp[v[i][0] + v[i][1] - v[i][2]].push_back(
        {max(v[i][0] - v[i][2], 0LL), (v[i][0] - max(v[i][2] - v[i][1], 0LL)),
         i});
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
    long long i = 0;
    long long j = 0;
    long long prev = 0;
    while (i < n1) {
      if (a[i].first <= b[j].first) {
        i++;
      } else {
        cnt++;
        for (long long k = prev; k < i; k++) {
          ans[a[k].second].first = v[a[k].second][0] - b[j].first;
          ans[a[k].second].second = v[a[k].second][1] - v1.first + b[j].first;
        }
        j++;
        prev = i;
      }
    }
    cnt++;
    for (long long k = prev; k < i; k++) {
      ans[a[k].second].first = v[a[k].second][0] - b[j].first;
      ans[a[k].second].second = v[a[k].second][1] - v1.first + b[j].first;
    }
  }
  return {cnt, ans};
}
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long>> v1(n, vector<long long>(3)),
      v2(n, vector<long long>(3));
  for (long long i = 0; i < n; i++) {
    cin >> v1[i][0] >> v1[i][1] >> v1[i][2];
    v2[i] = v1[i];
    swap(v2[i][0], v2[i][1]);
  }
  auto l1 = solve1(n, v1);
  vector<pair<long long, long long>> ans1 = l1.second;
  long long ans = l1.first;
  cout << ans << "\n";
  ;
  for (long long i = 0; i < n; i++) {
    cout << ans1[i].first << " " << ans1[i].second << "\n";
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
