#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
const long long inf = 1e18;
long long res[maxn];
void eastred() {
  string s, t;
  cin >> s >> t;
  long long a = s.length(), b = t.length();
  for (long long i = 0; i < a; i++) {
    for (long long j = i; j < a; j++) {
      string c = s.substr(i, j - i + 1);
      if (j - i + 1 > b) break;
      long long num = b - (j - i + 1);
      string ne;
      if (j >= num) {
        ne = s.substr(j - num, num);
        reverse(ne.begin(), ne.end());
      }
      if (c + ne == t) {
        cout << "YES" << '\n';
        return;
      }
    }
  }
  cout << "NO" << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) eastred();
  return 0;
}
