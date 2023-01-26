#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long t;
  cin >> t;
  while (t--) {
    long n, k;
    cin >> n >> k;
    vector<pair<long, long>> a(n);
    map<long, long> m;
    set<long> s;
    for (long i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
      s.insert(a[i].first);
      if (m[a[i].first] < k) {
        m[a[i].first]++;
      }
    }
    sort(a.begin(), a.end());
    long long count = 0;
    for (auto i : s) {
      if (m[i] <= k) {
        count += m[i];
      } else {
        count += k;
      }
    }
    count = (count / k) * k;
    vector<long> b(n, 0);
    long long k1 = 1;
    for (long i = 0; i < n; i++) {
      if (k1 > k) {
        k1 = 1;
      }
      if (m[a[i].first] > 0) {
        b[i] = k1;
        m[a[i].first]--;
        k1++;
      }
    }
    long temp = 0;
    for (long i = 0; i < n; i++) {
      if (temp >= count) {
        b[i] = 0;
      }
      if (b[i] > 0) {
        temp++;
      }
    }
    for (long i = 0; i < n; i++) {
      a[i].first = a[i].second;
      a[i].second = b[i];
    }
    sort(a.begin(), a.end());
    for (long i = 0; i < n; i++) {
      cout << a[i].second << " ";
    }
    cout << endl;
  }
  return 0;
}
