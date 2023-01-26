#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1e12;
const int maxnnn = 2e8 + 30;
const long long zero = 0;
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (a % b == 0)
    return b;
  else
    gcd(b, a % b);
}
string ntos(long long a) {
  string str;
  stringstream ss;
  ss << a;
  ss >> str;
  return str;
}
long long ston(string a) {
  long long x;
  stringstream ss;
  ss << a;
  ss >> x;
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  bool flag;
  long long zimu[26];
  long long n, m, a, b, t, y, fans, c, x, z, sw;
  string s, s1, s2;
  cin >> m >> n;
  vector<long long> py(m + 1);
  sw = 0;
  py.clear();
  for (long long i = 0; i < n; ++i) {
    cin >> a >> b;
    py[min(a, b)]++;
    if (py[min(a, b)] == 1) sw++;
  }
  cin >> c;
  while (c--) {
    cin >> x;
    if (x == 3) {
      cout << m - sw << endl;
    } else if (x == 1) {
      cin >> y >> z;
      py[min(y, z)]++;
      if (py[min(y, z)] == 1) sw++;
    } else {
      cin >> y >> z;
      py[min(y, z)]--;
      if (py[min(y, z)] == 0) sw--;
    }
  }
}
