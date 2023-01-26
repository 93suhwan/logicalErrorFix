#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7;
int const M = 2e5 + 10;
long long t, n, s[M];
map<long long, long long> cnt;
unsigned long long ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cnt.clear();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> s[i];
      ++cnt[s[i]];
    }
    ans = cnt[1];
    unsigned long long k = 1;
    while (cnt[0]--) k *= 2;
    cout << ans * k << "\n";
  }
  return 0;
}
