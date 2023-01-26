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
long long int y;
unordered_map<long long int, long long int> m;
bool find(long long int x) {
  if (m[x] != 0) return false;
  m[x] = 1;
  if (x == y) return true;
  vector<int> temp;
  long long int z = x;
  while (z > 0) {
    temp.push_back(z % 2);
    z = z / 2;
  }
  long long int sz = temp.size();
  for (int i = 0; i < sz; i++) {
    if (temp[i] == 0)
      z = z * 2;
    else
      z = z * 2 + 1;
  }
  z = find(z);
  if (z != 0) return true;
  z = 1;
  if (sz == 63) return false;
  for (int i = 0; i < sz; i++) {
    if (temp[i] == 0)
      z = z * 2;
    else
      z = z * 2 + 1;
  }
  z = find(z);
  return z;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    long long int x;
    cin >> x >> y;
    m.clear();
    bool k = find(x);
    if (k)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
