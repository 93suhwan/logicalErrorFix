#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long m = 1000000007) {
  if (b == 0) return 1;
  long long ans = power(a, b / 2, m);
  ans %= m;
  ans = (ans * ans) % m;
  if (b & 1) return (ans * a) % m;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long a = power(2, n) - 2;
  long long res = power(4, a);
  cout << (res * 6) % 1000000007;
  return 0;
}
