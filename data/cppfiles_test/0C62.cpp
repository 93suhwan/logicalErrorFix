#include <bits/stdc++.h>
using namespace std;
void print(bool n) {
  if (n)
    cout << "YES";
  else
    cout << "NO";
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  pair<string, long long> a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first;
    for (long long j = 1; j < m; j += 2) a[i].first[j] = 256 - a[i].first[j];
    a[i].second = i + 1;
  }
  sort(a, a + n);
  for (long long i = 0; i < n; i++) cout << a[i].second << ' ';
  return 0;
}
