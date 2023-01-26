#include <bits/stdc++.h>
using namespace std;
void init() {}
void debug() {}
const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
void precision(int a) { cout << setprecision(a) << fixed; }
long long int helper1(long long int n) {
  long long int count = 0;
  while (n % 100 == 0) {
    n /= 100;
    count++;
  }
  if (n == 1) {
    return count;
  } else {
    return 0;
  }
}
long long int helper2(long long int n) {
  long long int t;
  long long int count = 0;
  while (n > 0) {
    t = n % 10;
    count++;
    n /= 10;
  }
  return count;
}
long long int helper3(long long int n) {
  long long int t = n % 10;
  return t;
}
const int N = 1e5 + 2;
bool isPerfectSquare(long long int x) {
  if (x >= 0) {
    long long int sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
int main() {
  init();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    long long int res = 0;
    cin >> n;
    long long int cnt = 0, same = n, p;
    vector<long long int> d, temp;
    long long int g, x, z, q;
    if (g == 0) {
      g = 0;
    } else if (g != 0) {
      z = helper1(g);
      if (z != 0) {
        q = pow(10, z) - 1;
      } else if (z == 0) {
        long long int a = helper2(g);
        if (a == 1) {
          a = g - 1;
        } else if (a == 2 || a == 3) {
          x = g % 10;
          g = 2 * x;
        } else if (a == 4 || a == 5) {
          x = g % 100;
          g = (2 * x) + 2;
        } else if (a == 6 || a == 7) {
          x = g % 1000;
          g = (2 * x) + 4;
        } else if (a == 8 || a == 9) {
          g = (2 * x) + 8;
        }
      }
    }
    while (same) {
      d.push_back(same % 10);
      same /= 10;
      cnt++;
    }
    long long int value = pow(2, cnt);
    for (long long int i = 0; i < value; i++) {
      temp = d;
      p = 1;
      for (long long int j = cnt - 1; j >= 0; j--) {
        if (i & (1 << j)) {
          if (temp[j] == 0 || j < 2) {
            p = 0;
            break;
          } else {
            temp[j]--;
            temp[j - 2] += 10;
          }
        }
      }
      if (!p) continue;
      long long int t = 1;
      for (auto x : temp) {
        long long int value = 0;
        for (long long int k = 0; k < 10; k++)
          if (x >= k && x < (10 + k)) value++;
        t *= value;
      }
      res += t;
    }
    cout << res - 2 << endl;
  }
}
