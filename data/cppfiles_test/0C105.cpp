#include <bits/stdc++.h>
using namespace std;
bool comp(string &a, string &b) {
  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] != b[i]) {
      if (i % 2 == 0)
        return a[i] < b[i];
      else
        return a[i] > b[i];
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tests;
  tests = 1;
  while (tests--) {
    int n, m;
    cin >> n >> m;
    string second[n];
    map<string, long long int> mp;
    for (int i = 0; i < n; i++) {
      cin >> second[i];
      mp[second[i]] = i + 1;
    }
    sort(second, second + n, comp);
    for (auto u : second) cout << mp[u] << " ";
    cout << "\n";
  }
  return 0;
}
