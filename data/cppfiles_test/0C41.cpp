#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5, MOD = 1e9 + 7, INF = LONG_MAX;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long n, m, a[N], sz = 1, lazy[N * 4];
bool cmp(string a, string b) {
  for (int i = 0; i < m; ++i) {
    if (i % 2 == 0 && a[i] != b[i])
      return (a[i] < b[i]);
    else if (i & 1 && a[i] != b[i])
      return (a[i] > b[i]);
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  map<string, deque<int>> mp;
  cin >> n >> m;
  vector<string> v;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    v.push_back(s);
    mp[s].push_back(i + 1);
  }
  sort(v.begin(), v.end(), cmp);
  for (auto it : v) {
    cout << mp[it][0] << ' ';
    mp[it].pop_front();
  }
}
