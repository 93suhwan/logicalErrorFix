#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
mt19937 rnd(time(nullptr));
const long long mod = 1e9 + 7;
long long ppow(long long first, long long second) {
  long long res = 1;
  while (second) {
    if (second & 1) res = res * first % mod;
    first = first * first % mod;
    second >>= 1LL;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long k;
  cin >> k;
  long long cnt = 1;
  for (int i = 1; i <= k; ++i) cnt <<= 1LL;
  cnt -= 2;
  cout << ppow(4, cnt) * 6 % mod;
}
