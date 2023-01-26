#include <bits/stdc++.h>
using namespace std;
void print(bool n) {
  if (n) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
long long mpow(long long base, long long exp);
void ipgraph(long long m);
void dfs(long long u, long long par);
const long long mod = 1000000007;
void sol() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, long long> make_pair;
    for (long long i = 0; i < s.size(); i++) {
      make_pair[s[i]]++;
    }
    long long ans = 0;
    cout << min(s.size() / 2, make_pair.size()) << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  sol();
  return 0;
}
long long mpow(long long base, long long exp) {
  base %= mod;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}
