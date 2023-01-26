#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
bool comp(pair<string, int> &a, pair<string, int> &b) {
  int id = 0;
  for (int i = 0; i < m; i++) {
    if (a.first[i] != b.first[i]) {
      id = i;
      break;
    }
  }
  if (id % 2 == 0) {
    return a.first[id] < b.first[id];
  } else {
    return a.first[id] > b.first[id];
  }
}
void TEST_CASES() {
  cin >> n >> m;
  vector<pair<string, int> > a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a.begin(), a.end(), comp);
  for (auto &it : a) {
    cout << it.second << " ";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    TEST_CASES();
  }
  return 0;
}
