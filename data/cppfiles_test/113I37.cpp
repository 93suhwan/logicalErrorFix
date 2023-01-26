#include <bits/stdc++.h>
long long mypow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long mypow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
using namespace std;
int power(int x, int y) {
  int result = 1;
  while (y > 0) {
    if (y % 2 == 0) {
      x = x * x;
      y = y / 2;
    } else {
      result = result * x;
      y = y - 1;
    }
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    string x1;
    long long p1;
    cin >> x1 >> p1;
    string x2;
    long long p2;
    cin >> x2 >> p2;
    if (x1.length() + p1 > x2.length() + p2) {
      cout << ">" << endl;
      continue;
    } else if (x1.length() + p1 < x2.length() + p2) {
      cout << "<" << endl;
      continue;
    } else if (x1.length() + p1 == x2.length() + p2) {
      int t = 1;
      for (int i = 0; i < min(x1.length(), x2.length()); i++) {
        if (x1[i] > x2[i]) {
          t = 0;
          cout << ">" << endl;
          break;
        } else if (x1[i] < x2[i]) {
          t = 0;
          cout << "<" << endl;
          break;
        }
      }
      if (t) cout << "=" << endl;
    } else if (x1 == x2) {
      if (p1 > p2) {
        cout << ">" << endl;
        continue;
      } else if (p2 > p1) {
        cout << "<" << endl;
        continue;
      }
    }
  }
  return 0;
}
