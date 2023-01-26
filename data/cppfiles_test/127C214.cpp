#include <bits/stdc++.h>
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC optimize("-Ofast")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
using namespace std;
using namespace chrono;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s, t, ans = "";
    bool swapc = false, swapb = false;
    cin >> s >> t;
    sort(s.begin(), s.end());
    int bs = 0, cs = 0, as = 0;
    for (int i = 0; i < s.size(); i++) {
      bs += (s[i] == 'b');
      cs += (s[i] == 'c');
      as += (s[i] == 'a');
    }
    if (t == "abc") {
      if ((as == 0) || (bs == 0) || (cs == 0)) {
        cout << s << '\n';
        continue;
      }
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'b') {
          if (swapc == false) {
            for (int i = 0; i < cs; i++) {
              ans += 'c';
            }
            swapc = true;
          }
        } else if (s[i] == 'c') {
          if (swapb == false) {
            for (int i = 0; i < bs; i++) {
              ans += 'b';
            }
            swapb = true;
          }
        } else {
          ans += s[i];
        }
      }
    } else {
      ans = s;
    }
    cout << ans << '\n';
  }
  return 0;
}
