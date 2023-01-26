#include <bits/stdc++.h>
using namespace std;
bool myf(pair<pair<int, int>, int> first, pair<pair<int, int>, int> second) {
  return first.second < second.second;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> inp(n, {{0, 0}, 0});
  map<int, bool> check;
  for (int i = 0; i < n; i++) {
    cin >> inp[i].first.first >> inp[i].first.second;
    inp[i].second = inp[i].first.second - inp[i].first.first;
    check[i + 1] = false;
  }
  sort(inp.begin(), inp.end(), myf);
  for (int i = 0; i < n; i++) {
    int ans;
    for (int j = inp[i].first.first; j <= inp[i].first.second; j++) {
      if (check[j] == false) {
        check[j] = true;
        ans = j;
        break;
      }
    }
    cout << inp[i].first.first << " " << inp[i].first.second << " " << ans
         << endl;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
