#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>,
                   greater<pair<long long, long long>>>
        pq;
    for (long long i = 1; i <= n; i++) {
      pq.push({0, i});
    }
    while (k--) {
      vector<vector<pair<long long, long long>>> v;
      long long left = n % m;
      long long groups = m;
      while (groups--) {
        vector<pair<long long, long long>> arr;
        long long z = n / m;
        bool inc = false;
        while (z--) {
          arr.push_back(pq.top());
          pq.pop();
        }
        if (left) {
          left--;
          inc = true;
          arr.push_back(pq.top());
          pq.pop();
        }
        if (inc)
          for (auto &[cnt, x] : arr) {
            cnt++;
          }
        v.push_back(arr);
      }
      for (auto it : v) {
        cout << it.size() << ' ';
        for (auto [cnt, it] : it) {
          cout << it << ' ';
          pq.push({cnt, it});
        }
        cout << endl;
      }
    }
  }
}
