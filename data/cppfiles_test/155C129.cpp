#include <bits/stdc++.h>
using namespace std;
long long constexpr N = 200009;
long long n, m, ans[N], p[N];
pair<long long, long long> a[N];
string s;
void get_input() {
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  cin >> s;
  return;
}
void process() {
  sort(a, a + n);
  for (long long i = 0; i < n; ++i) p[a[i].first] = i;
  long long cnt = n;
  for (long long i = n - 1; ~i; --i)
    if (s[a[i].second] == '1') {
      swap(p[a[i].first], p[cnt]);
      a[p[a[i].first]].first = a[i].first;
      a[i].first = cnt;
      --cnt;
    }
  for (long long i = 0; i < n; ++i) ans[a[i].second] = a[i].first;
  return;
}
void give_output() {
  for (long long i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << '\n';
  return;
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    get_input();
    process();
    give_output();
  }
  return 0;
}
