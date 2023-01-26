#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long i, n;
  cin >> n;
  vector<long long> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  string s;
  cin >> s;
  priority_queue<long long> pq1, pq2;
  for (i = 0; i < n; i++)
    if (s[i] == '1')
      pq1.push(a[i]);
    else
      pq2.push(a[i]);
  long long val = n;
  map<long long, long long> mp;
  while (pq1.empty() == false) {
    mp[pq1.top()] = val;
    val--;
    pq1.pop();
  }
  while (pq2.empty() == false) {
    mp[pq2.top()] = val;
    val--;
    pq2.pop();
  }
  for (i = 0; i < n; i++) cout << mp[a[i]] << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  cin >> T;
  while (T--) solve();
  return 0;
}
