#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long mod = 998244353;
long long ceil(long long a, long long b) {
  long long res = a / b + (a % b != 0);
  return res;
}
void solve() {
  long long n;
  cin >> n;
  string p = to_string(n);
  n = p.size();
  string a = "", b = "";
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0)
      a.push_back(p[i]);
    else
      b.push_back(p[i]);
  }
  int z;
  if (a == "") {
    z = 0;
  } else if (a != "") {
    z = stoi(a);
  }
  int w;
  if (b == "") {
    w = 0;
  } else if (b != "") {
    w = stoi(b);
  }
  int x = 0, q = 0;
  if (z == 0)
    x = 1;
  else if (z == 1)
    x = 2;
  else
    x = (z + 1);
  if (w == 0)
    q = 1;
  else if (w == 1)
    q = 2;
  else
    q = (w + 1);
  long long res = x * q;
  cout << res - 2 << "\n";
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
