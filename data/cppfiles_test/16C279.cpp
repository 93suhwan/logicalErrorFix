#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    priority_queue<pair<long long, long long> > pq;
    for (long long i = 0; i < n; i++) {
      pq.push({a[i], i + 1});
    }
    vector<vector<long long> > ans;
    pair<long long, long long> s = pq.top();
    pq.pop();
    pair<long long, long long> t = pq.top();
    pq.pop();
    bool fl = true;
    while (fl) {
      if (s.first <= 0 || t.first <= 0) {
        break;
      }
      vector<long long> temp;
      temp.push_back(s.second);
      temp.push_back(t.second);
      ans.push_back(temp);
      s.first--;
      t.first--;
      if (s.first > 0) {
        pq.push(s);
      }
      if (t.first > 0) {
        pq.push(t);
      }
      if (pq.empty()) {
        break;
      }
      if (!pq.empty()) {
        s = pq.top();
        pq.pop();
      }
      if (!pq.empty()) {
        t = pq.top();
        pq.pop();
      }
    }
    cout << ans.size() << "\n";
    if (ans.size() != 0) {
      for (auto i : ans) {
        for (auto j : i) {
          cout << j << " ";
        }
        cout << "\n";
      }
    }
  }
  return 0;
}
