#include <bits/stdc++.h>
using namespace std;
long long n, m;
pair<string, long long> s[1000001];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> s[i].first;
    s[i].second = i + 1;
    for (long long j = 1; j < m; j++) s[i].first[j] = 'A' + 'Z' - s[i].first[j];
  }
  sort(s, s + n);
  for (long long i = 0; i < n; i++) cout << s[i].second << ' ';
  cout << endl;
}
