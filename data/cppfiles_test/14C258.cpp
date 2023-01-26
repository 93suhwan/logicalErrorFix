#include <bits/stdc++.h>
using namespace std;
const int N = 53, Mod = 1e9 + 7;
vector<pair<int, pair<int, int>>> ans;
pair<int, int> a[N];
void solve(int t) {
  ans.clear();
  int n, temp;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    a[i].first = temp;
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    int idx = a[i].second;
    for (int j = i - 1; j >= 0; --j) {
      if (a[j].second > a[i].second) ++idx;
    }
    if (idx > i) ans.push_back({idx - i, {i + 1, idx + 1}});
  }
  int sz = ans.size();
  cout << sz << "\n";
  for (auto i : ans)
    cout << i.second.first << " " << i.second.second << " " << i.first << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) solve(t);
  return 0;
}
