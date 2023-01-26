#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
using namespace std;
char change(char a) {
  if (a == 'R')
    return 'B';
  else if (a == 'B')
    return 'R';
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ind = -1;
  for (long long i = 0; i < n; i++) {
    if (s[i] != '?') {
      ind = i;
      break;
    }
  }
  if (ind != -1) {
    for (long long i = ind; i < n; i++) {
      if (s[i] == '?') s[i] = change(s[i - 1]);
    }
    for (long long i = ind - 1; i >= 0; i--) {
      if (s[i] == '?') s[i] = change(s[i + 1]);
    }
  } else {
    for (long long i = 0; i < n; i++) {
      if (i & 1)
        s[i] = 'R';
      else
        s[i] = 'B';
    }
  }
  cout << s << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(15) << fixed;
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
