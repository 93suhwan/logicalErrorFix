#include <bits/stdc++.h>
using namespace std;
void yes() { cout << "YES"; }
void no() { cout << "NO"; }
int main() {
  clock_t tStart = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<long long> adj[n + 1];
  vector<long long> a(n + 1, 0);
  map<pair<long long, long long>, bool> mp;
  mp.clear();
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    adj[min(u, v)].push_back(max(u, v));
    mp[{min(u, v), max(u, v)}] = true;
    int sz = min(u, v);
    a[sz]++;
  }
  long long tot = 0;
  for (long long &i : a) {
    if (i) tot++;
  }
  long long q;
  cin >> q;
  while (q--) {
    long long t, u, v;
    cin >> t;
    if (t != 3) {
      cin >> u >> v;
      if (t == 1) {
        adj[min(u, v)].push_back(max(u, v));
        a[min(u, v)]++;
        if (a[min(u, v)] == 1) tot++;
        mp[{min(u, v), max(u, v)}] = true;
      } else {
        mp[{min(u, v), max(u, v)}] = false;
        a[min(u, v)]--;
        if (a[min(u, v)] == 0) tot--;
      }
    } else {
      cout << n - tot;
      cout << "\n";
    }
  }
  return 0;
}
