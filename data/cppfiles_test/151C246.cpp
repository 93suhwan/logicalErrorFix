#include <bits/stdc++.h>
using namespace std;
long long int calculate(long long int p, long long int q) {
  long long int modx = 998244353, expo;
  expo = modx - 2;
  while (expo) {
    {
      if (expo & 1) p = (p * q) % modx;
    }
    q = (q * q) % modx;
    expo >>= 1;
  }
  return p % modx;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int N = 500005;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q;
  scanf("%d", &q);
  vector<int> t(q), x(q), y(q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &t[i], &x[i]);
    if (t[i] == 2) scanf("%d", &y[i]);
  }
  vector<int> p(N);
  iota(p.begin(), p.end(), 0);
  vector<int> ans;
  for (int i = q - 1; i >= 0; --i) {
    if (t[i] == 1) {
      ans.push_back(p[x[i]]);
    } else {
      p[x[i]] = p[y[i]];
    }
  }
  reverse(ans.begin(), ans.end());
  for (int &x : ans) printf("%d ", x);
  return 0;
}
