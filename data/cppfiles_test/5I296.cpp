#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n == 1) {
    return false;
  } else if (n == 2 || n == 3) {
    return true;
  } else {
    for (long long i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) {
        return false;
      }
    }
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
long long lcm(long long a, long long b) {
  return (max(a, b) / gcd(a, b)) * min(a, b);
}
bool isEven(long long a) {
  if (a % 2 == 0) {
    return true;
  }
  return false;
}
bool isSquare(long long x) {
  long long n1 = sqrt(x);
  double n2 = sqrt(x);
  if (n2 - n1 == 0) {
    return true;
  }
  return false;
}
bool isPowerOfTwo(int x) { return x && (!(x & (x - 1))); }
void solve(void) {
  long long t;
  cin >> t;
  while (t--) {
    long long x;
    cin >> x;
    if (x == 5) {
      cout << 2 << " " << 4;
    } else {
      cout << 2 << " " << x / 2;
    }
    cout << endl;
  }
}
void solve1(void) {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
      if (s2[i] == '1') {
        if (i == 0) {
          if (s1[i] == '0') {
            s1[i] = '1';
            s2[i] = '0';
            cnt++;
          } else {
            if (s1[i + 1] == '1' && i + 1 < n) {
              s1[i + 1] = '1';
              s2[i] = '0';
              cnt++;
            }
          }
        } else {
          if (s1[i - 1] == '1') {
            s1[i - 1] = '1';
            s2[i] = '0';
            cnt++;
          } else if (s1[i] == '0') {
            s1[i] = '1';
            s2[i] = '0';
            cnt++;
          } else {
            if (s1[i + 1] == '1' && i + 1 < n) {
              s1[i + 1] = '1';
              s2[i] = '0';
              cnt++;
            }
          }
        }
      }
    }
    cout << cnt << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  solve1();
}
