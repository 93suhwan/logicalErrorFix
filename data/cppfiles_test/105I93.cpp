#include <bits/stdc++.h>
using namespace std;
void fail(string s) {
  cout << s;
  exit(0);
}
void fail(long long s) {
  cout << s;
  exit(0);
}
long long read() {
  long long n;
  cin >> n;
  return n;
}
template <typename T>
void Mx(T &a, T b) {
  a = max(a, b);
}
template <typename T>
void Mi(T &a, T b) {
  a = min(a, b);
}
const long long dx[4] = {-1, 1, 0, 0};
const long long dy[4] = {0, 0, -1, 1};
bool cmp(pair<pair<long long, long long>, pair<long long, long long> > a,
         pair<pair<long long, long long>, pair<long long, long long> > b) {
  return a.first.second < b.first.second;
}
void run_test_case() {
  long long n;
  cin >> n;
  map<long long,
      vector<pair<pair<long long, long long>, pair<long long, long long> > > >
      v;
  for (long long i = (0); i < (n); i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    v[a - b + c].push_back(
        make_pair(make_pair(max(0ll, c - b), min(a, c)), make_pair(i, c)));
  }
  vector<pair<long long, long long> > ans(n);
  long long num = 0;
  for (auto x = v.begin(); x != v.end(); x++) {
    long long id = x->first;
    sort(v[id].begin(), v[id].end(), cmp);
    long long mi = -1;
    long long nn = ((long long)v[id].size());
    for (long long i = (0); i < (nn); i++) {
      if (mi < v[id][i].first.first) mi = v[id][i].first.second, num++;
      ans[v[id][i].second.first] = make_pair(mi, v[id][i].second.second - mi);
    }
  }
  cout << num << "\n";
  for (long long i = (0); i < (n); i++)
    cout << ans[i].first << ' ' << ans[i].second << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test_cases = 1;
  cin >> test_cases;
  while (test_cases--) run_test_case();
  return 0;
}
