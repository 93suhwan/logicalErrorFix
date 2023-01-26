#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
bool isPo2(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
int toint(const string &s) {
  stringstream second;
  second << s;
  int x;
  second >> x;
  return x;
}
string tostring(int number) {
  stringstream second;
  second << number;
  return second.str();
}
long long xorUptoN(long long n) {
  if (n % 4 == 0)
    return n;
  else if (n % 4 == 1)
    return 1;
  else if (n % 4 == 2)
    return n + 1;
  return 0;
}
long long modExpo(long long x, long long y, int p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long mod_Inv(long long a, long long p) { return modExpo(a, p - 2, p); }
long long combination(long long n, long long r, long long m, long long *fact,
                      long long *ifact) {
  long long val1 = fact[n];
  long long val2 = ifact[n - r];
  long long val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long x1, p1, x2, p2;
    cin >> x1 >> p1;
    cin >> x2 >> p2;
    string n1 = tostring(x1), n2 = tostring(x2);
    long long td1 = n1.length() + p1;
    long long td2 = n2.length() + p2;
    if (td1 > td2) {
      cout << ">\n";
    } else if (td1 < td2) {
      cout << "<\n";
    } else if (td1 == td2) {
      bool isequal = true;
      long long p1 = 0, p2 = 0;
      while ((p1 < n1.length()) and (p2 < n2.length())) {
        if (n1[p1] != n2[p2]) {
          isequal = false;
          if (n1[p1] > n2[p2]) {
            cout << ">\n";
          } else if (n1[p1] < n2[p2]) {
            cout << "<\n";
          }
          break;
        } else {
          p1++;
          p2++;
        }
      }
      if (isequal) cout << "=\n";
    }
  }
}
