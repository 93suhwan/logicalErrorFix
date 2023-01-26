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
  priority_queue<pair<long long, vector<long long>>> pq;
  map<vector<long long>, bool> mp1;
  vector<long long> curr;
  for (long long i = 0; i < n; i++) curr.push_back(v[i].size());
  long long sum = 0;
  for (long long i = 0; i < n; i++) sum += v[i][curr[i] - 1];
  pq.push({sum, curr});
  mp1[curr] = true;
  vector<long long> curr1(n);
  while (1) {
    pair<long long, vector<long long>> temp1 = pq.top();
    pq.pop();
    curr1 = temp1.second;
    long long sum1 = temp1.first;
    if (mp.find(curr1) == mp.end()) break;
    for (long long i = 0; i < n; i++) {
      if (curr1[i] > 1) {
        long long val1 = sum1 - v[i][curr1[i] - 1] + v[i][curr1[i] - 2];
        curr1[i]--;
        if (mp1.find(curr1) == mp1.end()) {
          pq.push({val1, curr1});
          mp1[curr1] = true;
        }
        curr1[i]++;
      }
    }
  }
  for (long long i = 0; i < n; i++) cout << curr1[i] << " ";
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
}
