#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target( \
    "avx2,bmi,bmi2,lzcnt,popcnt,sse,sse2,sse3,ssse3,sse4,abm,mmx,avx")
using namespace std;
using ll = long long;
int t, n;
pair<pair<int, int>, int> a[200001];
string s;
bool cmp(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
  if (x.first.second == y.first.second) return x.first.first < y.first.first;
  return x.first.second < y.first.second;
}
bool cmp2(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
  return x.second < y.second;
}
void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].first.first;
  cin >> s;
}
void solve() {
  for (int i = 1; i <= n; i++) {
    a[i].first.second = s[i - 1] - '0';
    a[i].second = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) a[i].first.second = i;
  sort(a + 1, a + n + 1, cmp2);
  for (int i = 1; i <= n; i++) cout << a[i].first.second << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for (cin >> t; t--;) {
    input();
    solve();
  }
}
