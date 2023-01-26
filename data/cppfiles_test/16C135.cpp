#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long M = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(15);
  long long T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    long long a[n];
    priority_queue<pair<long long, long long>> pq;
    vector<pair<long long, long long>> g;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) continue;
      pq.push(make_pair(a[i], i + 1));
    }
    while (pq.size() >= 2) {
      pair<long long, long long> x = pq.top();
      pq.pop();
      x.first--;
      pair<long long, long long> y = pq.top();
      pq.pop();
      y.first--;
      pair<long long, long long> z = make_pair(x.second, y.second);
      g.push_back(z);
      if (x.first > 0) pq.push(make_pair(x.first, x.second));
      if (y.first > 0) pq.push(make_pair(y.first, y.second));
    }
    cout << g.size() << "\n";
    for (int i = 0; i < g.size(); i++)
      cout << g[i].first << " " << g[i].second << "\n";
  }
}
