#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<string, int>> v;
bool cmp(pair<string, int> a, pair<string, int> b) {
  string s1 = a.first, s2 = b.first;
  for (int i = 0; i < m; ++i) {
    if (i % 2 == 0) {
      if (s1[i] != s2[i]) return s1[i] < s2[i];
    } else {
      if (s1[i] != s2[i]) return s1[i] > s2[i];
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    v.push_back({s, i});
  }
  sort(v.begin(), v.end(), cmp);
  for (auto p : v) {
    cout << p.second << " ";
  }
  cout << endl;
}
