#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename... Args>
void logger(string vars, Args &&...values) {
  cerr << vars << " = ";
  string delim = "";
  (..., (cerr << delim << values, delim = ", "));
  cerr << endl;
}
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const long long int INF = 1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-8;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
typedef array<long long int, 2> edge;
long long int N;
long long int get_next(long long int cur, vector<bool> &vis) {
  long long int ans = N + 1;
  for (long long int i = cur; i <= N; i++) {
    if (!vis[i]) {
      ans = i;
      break;
    }
  }
  return ans;
}
void solve() {
  cin >> N;
  vector<long long int> vec(N);
  for (long long int i = 0; i < (N); i++) cin >> vec[i];
  ;
  vector<bool> vis(N + 1, false);
  map<long long int, long long int> mp;
  for (long long int i : vec) {
    mp[i]++;
    if (i <= N) vis[i] = true;
  }
  vector<long long int> temp;
  for (auto pp : mp) {
    long long int num = pp.first, freq = pp.second;
    if (num <= N && vis[num]) freq--;
    for (long long int i = 0; i < freq; i++) temp.push_back(num);
  }
  if (temp.empty()) {
    cout << 0 << '\n';
    return;
  }
  sort(temp.begin(), temp.end());
  long long int vptr = 0;
  long long int ans = 0;
  for (long long int i : temp) {
    vptr = get_next(vptr + 1, vis);
    ans++;
    if (vptr >= (i + 1) / 2) {
      ans = -1;
      break;
    }
  }
  cout << ans << '\n';
}
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T = 1;
  cin >> T;
  for (long long int _t = 1; _t <= T; _t++) {
    solve();
  }
  return 0;
}
