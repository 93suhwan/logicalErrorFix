#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> arr(n);
  unordered_map<string, int> map;
  for (int i{0}; i < n; i++) {
    cin >> arr[i];
    map[arr[i]] = i;
  }
  auto cmp{[](string &s1, string &s2) {
    for (int i{0}; i < s1.length(); i++)
      if (s1[i] != s2[i]) {
        if (i % 2 != 0)
          return s1[i] > s2[i];
        else
          return s1[i] < s2[i];
      }
    return s1 == s2;
  }};
  sort(arr.begin(), arr.end(), cmp);
  for (auto &s : arr) cout << map[s] + 1 << ' ';
}
int main() {
  solve();
  cout << '\n';
  return 0;
}
