#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 99;
long long n, m;
pair<string, long long> a[N];
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  string s;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    for (long long j = 1; j < s.size(); j += 2) {
      s[j] = 'Z' - (s[j] - 'A');
    }
    a[i] = {s, i + 1};
  }
  sort(a, a + n);
  for (long long i = 0; i < n; i++) {
    cout << a[i].second << " ";
  }
  return 0;
}
