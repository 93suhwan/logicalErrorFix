#include <bits/stdc++.h>
using namespace std;
bool compare(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first != b.first) return a.first > b.first;
  return a.second > b.second;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long TC;
  cin >> TC;
  while (TC--) {
    long long n;
    cin >> n;
    n -= 2;
    vector<string> s(n);
    for (long long i = 0; i < n; i++) cin >> s[i];
    for (long long i = 0; i < n; i++) cout << s[i][0];
    cout << s[n - 1][1] << 'b' << "\n";
  }
  return 0;
}
