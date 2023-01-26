#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6;
vector<pair<string, long long> > v;
int32_t main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    string s, t;
    cin >> s;
    for (long long j = 0; j < m; j++) {
      if (j % 2 == 0)
        t += s[j];
      else {
        long long x = s[j] - 'A';
        x = (25 - x) + 'A';
        t += char(x);
      }
    }
    v.push_back(pair<string, long long>(t, i));
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < n; i++) cout << v[i].second << ' ';
  cout << endl;
  return 0;
}
