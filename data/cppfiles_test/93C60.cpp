#include <bits/stdc++.h>
using namespace std;
int fuc(int k) {
  int fl = 0;
  int s = 0, s1 = 0, s2 = 0;
  while (k != 0) {
    int a = k % 10;
    if (a == 4) {
      s1++;
    }
    if (a == 7) {
      s2++;
    }
    s++;
    k = k / 10;
  }
  if (s1 + s2 == s) {
    fl = 1;
  }
  return fl;
}
int main() {
  long long test;
  cin >> test;
  while (test--) {
    long long a;
    long long k, res = 0;
    cin >> a >> k;
    long long s = 1;
    int flag = 1;
    while (flag) {
      if (s > a) {
        flag = 0;
      }
      if (s <= k) {
        s = s * 2;
        ++res;
      } else {
        if ((a - s) % k == 0) {
          --res;
        }
        res = res + (a + k - s) / k;
        break;
      }
    }
    long long m = res;
    cout << m << '\n';
  }
}
