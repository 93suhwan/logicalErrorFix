#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    map<long long, long long> used;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
      used[v[i]] = i;
    }
    sort(v.begin(), v.end());
    long long ans = n, p = 0;
    for (long long i = 1; i < n; i++) {
      if (used[v[i - 1]] + 1 == used[v[i]]) ans--;
    }
    if (ans > k)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  return 0;
}
