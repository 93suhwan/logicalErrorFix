#include <bits/stdc++.h>
using namespace std;
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> arr(n + 1);
    set<long long> s;
    for (long long i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    bool zero = false;
    for (long long i = 1; i <= n; i++) {
      s.insert(arr[i]);
      if (arr[i] == 0) zero = true;
    }
    if (s.size() < n || zero) {
      cout << "YES\n";
      continue;
    }
    bool f = false;
    for (long long k = 0; k < n; k++) {
      vector<long long> arr2;
      for (long long i = 0; i < n; i++) {
        if (i == k) continue;
        arr2.push_back(arr[i + 1]);
      }
      vector<long long> q;
      vector<long long> q2;
      q.push_back(0);
      for (long long i = 0; i < n - 1; i++) {
        for (long long nxt : q) {
          q2.push_back(nxt + arr2[i]);
          q2.push_back(nxt);
          q2.push_back(nxt - arr2[i]);
        }
        swap(q, q2);
        q2.clear();
      }
      for (long long nxt : q) {
        if (nxt == arr[k + 1]) f = true;
      }
    }
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
