#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > vec(k);
  set<int> S;
  for (int i = 1; i <= 2 * n; i++) S.insert(i);
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    S.erase(a), S.erase(b);
    vec[i] = {a, b};
  }
  vector<int> a, b, v;
  for (auto &x : S) v.push_back(x);
  int m = v.size() / 2;
  for (int i = 0; i < m; i++) a.push_back(v[i]), b.push_back(v[i + m]);
  int i = 0, j = 0;
  while (i < a.size() && j < b.size()) vec.push_back({a[i++], b[j++]});
  sort(vec.begin(), vec.end());
  int res = 0;
  for (int i = 0; i < vec.size(); i++)
    for (int j = i + 1; j < vec.size(); j++)
      res += (vec[i].second < vec[j].second && vec[j].first < vec[i].second);
  cout << res << endl;
}
int main() {
  int T = 1;
  cin >> T;
  for (int turn = 1; turn <= T; turn++) solve();
}
