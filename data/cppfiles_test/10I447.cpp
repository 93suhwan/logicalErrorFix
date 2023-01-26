#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  map<long long int, long long int> m;
  long long int n;
  cin >> n;
  long long int k;
  cin >> k;
  vector<long long int> v;
  for (long long int i = 0; i < n; i++) {
    long long int kk;
    cin >> kk;
    v.push_back(kk);
    m[kk]++;
  }
  long long int of = 0, tf = 0;
  map<long long int, long long int> ans;
  long long int col = 0;
  map<long long int, stack<long long int>> s;
  for (auto x : m) {
    if (x.second < k) {
      of += x.second;
      for (long long int j = 0; j < x.second; j++) {
        s[x.first].push(col);
        col = (col + 1) % k;
      }
    } else {
      tf++;
      long long int j = 0;
      for (; j < k; j++) s[x.first].push(j);
      for (; j < x.second; j++) s[x.first].push(-1);
    }
  }
  vector<long long int> final(n);
  for (long long int i = 0; i < n; i++) {
    long long int val = v[i];
    final[i] = s[val].top();
    s[val].pop();
    cout << final[i] + 1 << " ";
  }
  cout << endl;
  cout << tf + of / k << endl;
}
signed main() {
  init_code();
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
