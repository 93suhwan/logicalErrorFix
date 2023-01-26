#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt = 1;
  cin >> tt;
  while (tt--) {
    long long int n;
    cin >> n;
    long long int a[n + 1];
    for (long long int i = 1; i <= n; i++) cin >> a[i];
    map<long long int, long long int> mp;
    for (long long int i = 1; i <= n; i++) mp[a[i]]++;
    long long int fl = 1, ext = 0;
    stack<long long int> s;
    for (long long int i = 0; i <= n; i++) {
      if (fl)
        cout << mp[i] + ext << " ";
      else
        cout << "-1 ";
      if (mp[i] == 0) {
        if (s.empty()) {
          fl = 0;
        } else {
          long long int tp = s.top();
          ext += i - tp;
          mp[tp]--;
          if (mp[tp] == 1) s.pop();
        }
      }
      if (mp[i] > 1) s.push(i);
    }
    cout << "\n";
  }
  return 0;
}
