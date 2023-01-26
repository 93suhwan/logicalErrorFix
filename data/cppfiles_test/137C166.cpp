#include <bits/stdc++.h>
using namespace std;
long long x, y;
map<long long, bool> memo;
long long reverse(long long n) {
  int bits = 0;
  for (int i = 63; i >= 0; --i) {
    bits = i;
    if ((1LL << i) & n) break;
  }
  long long ret = 0;
  while (n) {
    ret += ((n % 2) << bits);
    bits--;
    n /= 2;
  }
  return ret;
}
bool sol(long long n) {
  if (n > 1e18) return 0;
  if (n == y) return 1;
  if (memo.find(n) != memo.end()) return memo[n];
  memo[n] = sol(reverse(n * 2 + 1));
  if (n != reverse(n)) memo[n] |= sol(reverse(n));
  return memo[n];
}
int main() {
  cin >> x >> y;
  cout << (sol(x) ? "YES\n" : "NO\n");
}
