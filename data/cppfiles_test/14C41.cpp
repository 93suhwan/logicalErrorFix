#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> result;
  vector<long long> result2;
  int k = 0;
  for (long long i = 0; i < n; i++) {
    int mini = min_element(a.begin() + i, a.end()) - a.begin();
    vector<long long> tmp;
    for (int j = i; j <= mini; j++) {
      tmp.push_back(a[j]);
    }
    int val = mini - i;
    if (val > 0) {
      result.push_back({i + 1, mini + 1});
      result2.push_back(val);
      k++;
      int x = tmp.size();
      for (int j = 0; j < x; j++) {
        if (j + val < x) {
          a[j + i] = tmp[j + val];
        } else {
          a[j + i] = tmp[j + val - x];
        }
      }
    }
    if (is_sorted(a.begin(), a.end())) {
      break;
    }
  }
  int y = result2.size();
  cout << y << endl;
  for (int i = 0; i < result2.size(); i++) {
    cout << result[i].first << " " << result[i].second << " " << result2[i]
         << endl;
  }
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
