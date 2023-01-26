#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const long long INF = LLONG_MAX;
const long long mod = 1e9 + 7;
const int MAXN = 2e5;
template <typename T>
ostream& operator<<(ostream& out, vector<T>& arr) {
  for (auto& i : arr) out << i << ' ';
  return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& arr) {
  for (auto& i : arr) in >> i;
  return in;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.rbegin(), a.rend(),
       [](const pair<int, int> a, const pair<int, int> b) {
         if (a.second - a.first == b.second - b.first) return a < b;
         return a.second - a.first > b.second - b.first;
       });
  vector<set<int>> b(n);
  set<int> er;
  b[0].insert(a[0].first);
  for (int i = 1; i < n; i++) {
    for (auto j : b[i - 1]) b[i].insert(j);
    for (int j = a[i].first; j <= a[i].second; j++) b[i].insert(j);
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int i = 0; i < n - 1; i++) {
    for (auto j : er) b[i + 1].erase(j);
    int e = 0;
    for (auto j : b[i])
      if (b[i + 1].find(j) == b[i + 1].end()) {
        e = j;
        break;
      }
    er.insert(e);
    cout << a[i].first << ' ' << a[i].second << ' ' << e << '\n';
  }
  cout << a.back().first << ' ' << a.back().first << ' ' << a.back().first
       << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TT;
  cin >> TT;
  while (TT--) solve();
  return 0;
}
