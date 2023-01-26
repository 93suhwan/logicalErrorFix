#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int i, j, n, k;
    cin >> n >> k;
    vector<long long int> pq(n);
    map<long long int, vector<long long int>> pm;
    set<pair<long long int, long long int>> pp;
    for (i = 0; i < k; i++) {
      pp.insert({0, i + 1});
    }
    for (i = 0; i < n; i++) {
      pq[i] = 0;
      cin >> j;
      pm[j].push_back(i);
      pq[i] = pm[j].size();
      if (pq[i] > k) pq[i] = 0;
    }
    long long int po = 0;
    for (auto it : pm) {
      if (it.second.size() > k) continue;
      po += (it.second.size());
    }
    po /= k;
    for (auto it : pm) {
      if (it.second.size() > k) continue;
      for (auto ip : it.second) {
        auto ix = pp.begin();
        if ((ix->first) == po) {
          pq[ip] = 0;
        } else {
          pq[ip] = ix->second;
          pp.insert({ix->first + 1, ix->second});
          pp.erase(ix);
        }
      }
    }
    for (i = 0; i < n; i++) {
      cout << pq[i] << " ";
    }
    cout << endl;
  }
}
