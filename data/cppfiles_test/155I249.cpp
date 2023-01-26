#include <bits/stdc++.h>
using namespace std;
long long constexpr N = 200009;
long long n, m, ans[N];
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
  vector<long long> v, v1;
  for (long long i = 0; i < n; ++i)
    if (s[a[i].second] == '1')
      v.push_back(i);
    else
      v1.push_back(i);
  while (!v.empty() && !v1.empty()) {
    if (a[v.back()].first > a[v1.back()].first) {
      v.pop_back();
    } else {
      swap(a[v.back()].first, a[v1.back()].first);
      v.pop_back();
      v1.pop_back();
    }
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
