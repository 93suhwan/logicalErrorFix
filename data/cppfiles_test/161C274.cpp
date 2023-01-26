#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  if (a.first == b.first) {
    if (a.second.first < b.second.first) return true;
    return false;
  }
  if (a.first < b.first) return true;
  return false;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, pair<int, int>>> vec;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vec.push_back({b - a, {a, b}});
  }
  sort(vec.begin(), vec.end());
  unordered_map<int, int> make_pair;
  for (int i = 0; i < n; i++) {
    cout << vec[i].second.first << " " << vec[i].second.second << " ";
    for (int j = vec[i].second.first; j <= vec[i].second.second; j++) {
      if (make_pair[j])
        continue;
      else {
        cout << j << endl;
        make_pair[j] = 1;
        break;
      }
    }
  }
  cout << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
