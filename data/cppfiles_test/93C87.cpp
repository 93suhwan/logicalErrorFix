#include <bits/stdc++.h>
using namespace std;
mt19937_64 rndGen(chrono::steady_clock::now().time_since_epoch().count());
inline long long read() {
  long long ret;
  scanf("%lld", &ret);
  return ret;
}
vector<int> xorsum;
inline int wk() {
  int a = read(), b = read();
  int xr = xorsum[a - 1];
  if (xr == b) return a;
  if ((xr ^ b) != a) return a + 1;
  return a + 2;
}
int main() {
  xorsum.push_back(0);
  for (int i = (1), __i = (300005); i <= __i; ++i)
    xorsum.push_back(xorsum.back() ^ i);
  for (int _ = (0), ___ = (read()); _ < ___; ++_) cout << wk() << endl;
  return 0;
}
