#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool comp(pair<pair<long long int, long long int>, long long int> a,
          pair<pair<long long int, long long int>, long long int> b) {
  if (a.first.second == b.first.second) {
    return a.second > b.second;
  }
  return a.first.second < b.first.second;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<pair<pair<long long int, long long int>, long long int>> a(n);
    for (long long int i = 0; i < n; i++) {
      long long int u, v;
      cin >> u >> v;
      long long int dist = v - u;
      a[i].first.first = dist;
      a[i].first.second = u;
      a[i].second = v;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<long long> visited(n + 1);
    for (long long int i = 0; i < n; i++) {
      long long int l, r, d;
      l = a[i].first.second;
      r = a[i].second;
      d = a[i].second;
      vector<long long> present(n + 1);
      for (long long int j = i + 1; j < n; j++) {
        present[a[j].first.second] = 1;
        present[a[j].second] = 1;
      }
      for (long long int j = 1; j <= n; j++) {
        if (present[j] == 0 && visited[j] == 0) {
          d = j;
          visited[j] = 1;
        }
      }
      cout << l << " " << r << " " << d << "\n";
    }
    cout << "\n";
  }
  return 0;
}
