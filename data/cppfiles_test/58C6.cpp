#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long po(long long x, long long y) {
  if (y == 0) return 1;
  long long z = po(x, y / 2);
  z = (z * z) % mod;
  if (y & 1) z = (z * x) % mod;
  return z;
}
void fun() {
  int n;
  cin >> n;
  string p, q;
  cin >> p >> q;
  for (int i = 0; i < n; i++)
    if (p[i] == q[i] and p[i] == '1') {
      cout << "NO\n";
      return;
    }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(0));
  ;
  int t = 1;
  cin >> t;
  while (t--) fun();
}
