#include <bits/stdc++.h>
using namespace std;
void Clearing_out() { return; }
template <typename Head, typename... Tail>
void Clearing_out(Head &H, Tail &...T) {
  H.clear();
  Clearing_out(T...);
}
long long int n;
long long int stoii(string s) {
  long long int ans = 0;
  for (long long int i = 0; i < s.length(); i++) {
    ans *= 10;
    ans += (long long int)(s[i] - '0');
  }
  return ans;
}
void testcase() {
  long long int n, x;
  cin >> x >> n;
  for (long long int i = 1; i <= n - 1; i++) cout << 1 << " ";
  cout << x - n + 1 << " ";
  cout << "\n";
  return;
}
int32_t main() {
  long long int test = 1;
  cin >> test;
  long long int t = 0;
  while (test--) {
    testcase();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
