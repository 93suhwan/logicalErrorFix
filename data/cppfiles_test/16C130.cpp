#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    priority_queue<pair<long long, long long> > pq;
    for (long long i = 0; i < n; i++) {
      if (arr[i] > 0) pq.push({arr[i], i});
    }
    vector<pair<long long, long long> > vp;
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      if (pq.empty()) break;
      auto q = pq.top();
      pq.pop();
      vp.push_back({p.second + 1, q.second + 1});
      p.first--;
      q.first--;
      if (p.first > 0) pq.push(p);
      if (q.first > 0) pq.push(q);
    }
    cout << vp.size() << endl;
    for (auto p : vp) cout << p.first << " " << p.second << endl;
  }
}
