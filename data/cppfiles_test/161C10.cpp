#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool comp(pair<pair<long long int, long long int>, long long int> a,
          pair<pair<long long int, long long int>, long long int> b) {
  if (a.first.first == b.first.first) {
    return a.first.second > b.first.second;
  }
  return a.first.first < b.first.first;
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
      a[i].first.first = u;
      a[i].first.second = v;
      a[i].second = dist;
    }
    sort(a.begin(), a.end(), comp);
    for (long long int i = 0; i < n - 1; i++) {
      long long int l, r, d;
      l = a[i].first.first;
      r = a[i].first.second;
      d = a[i].first.first;
      for (long long int j = d; j <= r; j++) {
        if (j > a[i + 1].first.second || j < a[i + 1].first.first) {
          d = j;
          break;
        }
      }
      cout << l << " " << r << " " << d << "\n";
    }
    long long int l, r, d;
    l = a[n - 1].first.first;
    r = a[n - 1].first.second;
    d = a[n - 1].first.first;
    cout << l << " " << r << " " << d << "\n";
    cout << "\n";
  }
  return 0;
}
