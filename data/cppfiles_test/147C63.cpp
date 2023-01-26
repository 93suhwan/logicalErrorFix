#include <bits/stdc++.h>
using namespace std;
void debug(vector<long long> vec) {
  long long n = vec.size();
  for (long long i = 0; i < (long long)n; i++) cout << vec[i] << " ";
  cout << "\n";
  return;
}
long long power(long long a, long long b, long long P = 1000000007) {
  long long res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % P)
    if (b & 1) res = 1ll * res * a % P;
  return res;
}
void solve() {
  string str;
  cin >> str;
  long long counter = 0;
  for (char ch : str) {
    if (ch == 'N') counter++;
  }
  cout << ((counter == 1) ? "NO" : "YES") << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
