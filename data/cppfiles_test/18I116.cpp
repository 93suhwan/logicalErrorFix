#include <bits/stdc++.h>
using namespace std;
const long long INFLL = LLONG_MAX;
const int INF = INT_MAX;
const long long MAXLL = 0x3f3f3f3f3f3f3f3f;
const int MAX = 0x3f3f3f3f;
const long long MOD = 1000000007;
const long long mod = 998244353;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T> >;
template <class T>
void sort(vector<T>& v) {
  sort(v.begin(), v.end());
}
template <class T, class U>
void sort(vector<T>& v, U func) {
  sort(v.begin(), v.end(), func);
}
template <class T>
void rsort(vector<T>& v) {
  sort(v.rbegin(), v.rend());
}
template <class T>
int lb_index(vector<T>& v, T k) {
  return lower_bound(v.begin(), v.end(), k) - v.begin();
}
template <class T>
int ub_index(vector<T>& v, T k) {
  return upper_bound(v.begin(), v.end(), k) - v.begin();
}
template <class T>
bool is_sorted(vector<T>& v) {
  return is_sorted(v.begin(), v.end());
}
template <class T>
bool sorted(vector<T>& v) {
  return is_sorted(v);
}
void precompute() { return; }
void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) v.emplace_back(v[i]);
  int ans = 0;
  vector<bool> vis(n + n);
  for (int i = 0; i < n + n; i++) {
    if (vis[i]) continue;
    int cnt = 0;
    int mx = 0;
    for (int j = i; j < n + n; j += d) {
      vis[j] = 1;
      if (v[j])
        cnt++;
      else
        cnt = 0;
      mx = max(mx, cnt);
    }
    if (n % d != 0 && cnt > n) {
      cout << "-1\n";
      return;
    } else if (n % d == 0 && cnt > n / d) {
      cout << "-1\n";
      return;
    }
    ans = max(mx, ans);
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(0);
  int numberofsubtestcases = 1;
  cin >> numberofsubtestcases;
  precompute();
  for (int looping = 1; looping <= numberofsubtestcases; looping++) {
    solve();
  }
  return 0;
}
