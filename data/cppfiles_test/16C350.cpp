#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200004;
long long n, m, k;
long long a[maxn];
string s;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    string t = s;
    sort(t.begin(), t.end());
    long long cnt = 0;
    for (long long i = 0; i <= n - 1; i++)
      if (s[i] != t[i]) cnt++;
    cout << cnt << endl;
  }
  return 0;
}
