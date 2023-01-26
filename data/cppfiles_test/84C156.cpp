#include <bits/stdc++.h>
using namespace std;
void Tez() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  Tez();
  long long i = 1;
  long long t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    long long res = (s) / (ceil((n + 1) / 2.0));
    cout << res << '\n';
  }
  return 0;
}
