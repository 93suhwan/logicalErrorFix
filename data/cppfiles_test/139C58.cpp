#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 520;
long long A[N];
map<long long, long long> st;
void solve() {
  string S;
  cin >> S;
  long long n = S.size();
  if (n % 2 != 0) {
    cout << "NO" << endl;
    return;
  }
  for (long long i = 0; i < n / 2; i++) {
    if (S[i] != S[i + n / 2]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
