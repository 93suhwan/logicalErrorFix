#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long arr[n];
  map<long long, set<long long> > mp;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mp[arr[i]].insert(i);
  }
  long long res[n];
  memset(res, 0, sizeof(res));
  vector<long long> s;
  for (auto it : mp) {
    long long cnt = 0;
    set<long long> curr = it.second;
    for (auto itr : curr) {
      if (cnt < k) {
        s.push_back(itr);
      }
      cnt++;
    }
  }
  long long sz = s.size();
  long long rem = sz % k;
  while (rem--) {
    s.pop_back();
  }
  long long curr = 0;
  for (auto it : s) {
    res[it] = curr + 1;
    curr++;
    curr = curr % k;
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
