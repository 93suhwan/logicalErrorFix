#include <bits/stdc++.h>
using namespace std;
void printi(vector<int> t) {
  for (auto &x : t) cout << x;
  cout << '\n';
}
void printl(vector<long long> t) {
  for (auto &x : t) cout << x;
  cout << '\n';
}
const int INF = 1e9;
const long long LINF = 1e18;
const long long mod = 1e9 + 7;
bool cmp(array<int, 3> &a, array<int, 3> &b) { return a[1] < b[1]; }
void solve() {
  int n;
  cin >> n;
  map<int, vector<array<int, 3>>> mp;
  vector<array<int, 3>> t(n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    t[i] = {a, b, c};
    mp[a + b - c].push_back({max(0, a - c), a - max(0, c - b), i});
  }
  int ans = 0;
  vector<pair<int, int>> res(n);
  for (auto &x : mp) {
    sort(x.second.begin(), x.second.end(), cmp);
    int l = 0, r = 0;
    while (r < x.second.size()) {
      ans++;
      while (r < x.second.size() && x.second[r][0] <= x.second[l][1]) {
        res[x.second[r][2]] = {
            t[x.second[r][2]][0] - x.second[l][1],
            t[x.second[r][2]][2] - (t[x.second[r][2]][0] - x.second[l][1])};
        r++;
      }
      if (r == x.second.size()) break;
      l = r;
    }
  }
  cout << ans << '\n';
  for (auto &x : res) cout << x.first << " " << x.second << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) solve();
  return 0;
}
