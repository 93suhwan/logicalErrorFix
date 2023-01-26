#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tst;
  cin >> tst;
  while (tst--) {
    string a, b;
    cin >> b >> a;
    map<char, long long> freq;
    for (long long i = 0; i < 26; i++) {
      freq[b[i]] = i;
    }
    long long n = a.size();
    long long ans = 0;
    for (long long i = 1; i < n; i++) {
      ans += abs(freq[a[i]] - freq[a[i - 1]]);
    }
    cout << ans << '\n';
  }
}
