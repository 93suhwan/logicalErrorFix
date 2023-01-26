#include <bits/stdc++.h>
using namespace std;
bool comp(pair<string, int> a, pair<string, int> b) {
  for (int i = 0; i < a.first.length(); i++) {
    if (a.first[i] == b.first[i]) continue;
    if (i % 2 == 0) return a.first[i] < b.first[i];
    return a.first[i] > b.first[i];
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i].first;
    s[i].second = i + 1;
  }
  sort(s.begin(), s.end(), comp);
  for (int i = 0; i < n; i++) cout << s[i].second << " ";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(6);
  solve();
  return 0;
}
