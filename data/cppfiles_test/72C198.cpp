#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
const long long N = 1e5 + 1, mod = 1e9 + 7;
long long itos(long long n, long long ch[]) {
  long long j = n, l = 0;
  while (j) {
    j /= 10;
    l++;
  }
  for (long long i = l - 1; i >= 0; i -= 1) {
    ch[i] = n % 10;
    n /= 10;
  }
  return l;
}
long long stoi(long long ch[], long long l) {
  long long n = 0;
  for (long long i = 0; i < l; i += 1) {
    n *= 10;
    n += ch[i];
    ;
  }
  return n;
}
void solve() {
  string n;
  long long k;
  cin >> n >> k;
  while (true) {
    set<char> s;
    for (auto x : n) {
      s.insert(x);
    }
    if (s.size() <= k) {
      cout << n << "\n";
      return;
    }
    s.clear();
    for (long long i = 0; i < n.size(); i += 1) {
      s.insert(n[i]);
      if (s.size() > k) {
        while (n[i] == '9') i--;
        n[i]++;
        i++;
        for (; i < n.size(); i += 1) {
          n[i] = '0';
        }
      }
    }
  }
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
