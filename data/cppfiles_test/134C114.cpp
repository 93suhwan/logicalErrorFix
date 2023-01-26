#include <bits/stdc++.h>
using namespace std;
long long gcd_fun(long long a, long long b) {
  if (a == 0) return b;
  return gcd_fun(b % a, a);
}
long long findGCD(vector<long long> arr) {
  long long n = arr.size();
  long long result = arr[0];
  for (long long i = 1; i < n; i++) {
    result = gcd_fun(arr[i], result);
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> o, e;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if (i % 2 == 0)
        e.push_back(x);
      else
        o.push_back(x);
    }
    long long go = findGCD(o);
    long long ge = findGCD(e);
    if (go == 1 && ge == 1) {
      cout << 0 << '\n';
    } else if (go != 1 && ge == 1) {
      bool flag = true;
      for (long long i = 0; i < e.size(); i++) {
        if (e[i] % go == 0) {
          cout << 0 << '\n';
          flag = false;
          break;
        }
      }
      if (flag) {
        cout << go << '\n';
      }
    } else if (ge != 1 && go == 1) {
      bool flag = true;
      for (long long i = 0; i < o.size(); i++) {
        if (o[i] % ge == 0) {
          cout << 0 << '\n';
          flag = false;
          break;
        }
      }
      if (flag) {
        cout << ge << '\n';
      }
    } else {
      bool flag1 = true;
      for (long long i = 0; i < e.size(); i++) {
        if (e[i] % go == 0) {
          flag1 = false;
          break;
        }
      }
      bool flag2 = true;
      for (long long i = 0; i < o.size(); i++) {
        if (o[i] % ge == 0) {
          flag2 = false;
          break;
        }
      }
      if (flag1) {
        cout << go << '\n';
      } else if (flag2) {
        cout << ge << '\n';
      } else {
        cout << 0 << '\n';
      }
    }
  }
  return 0;
}
