#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  std::vector<vector<long long>> v(n);
  for (long long i = 0; i < n; i++) {
    long long val;
    cin >> val;
    while (val--) {
      long long temp;
      cin >> temp;
      v[i].push_back(temp);
    }
  }
  long long m;
  cin >> m;
  map<vector<long long>, bool> mp;
  while (m--) {
    vector<long long> curr(n);
    for (long long i = 0; i < n; i++) {
      cin >> curr[i];
    }
    mp[curr] = true;
  }
  vector<long long> curr;
  for (long long i = 0; i < n; i++) {
    curr.push_back(v[i].size());
  }
  while (1) {
    if (mp.find(curr) == mp.end()) break;
    long long index = -1, gap = INT_MAX;
    for (long long i = 0; i < n; i++) {
      if (curr[i] > 1) {
        long long temp = v[i][curr[i] - 1] - v[i][curr[i] - 2];
        if (temp < gap) {
          gap = temp;
          index = i;
        }
      }
    }
    curr[index]--;
  }
  for (long long i = 0; i < n; i++) cout << curr[i] << " ";
  cout << endl;
}
int32_t main() {
  long long t = 1;
  while (t--) {
    solve();
  }
}
