#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
using namespace std;
const double pi = acos(-1);
bool isVowel(char ch) {
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
    return 1;
  }
  return 0;
}
bool compare(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second < b.second;
}
bool isPrime(long long n) {
  if (n % 2 == 0 && n != 2) {
    return false;
  }
  for (long long i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long binary_exp(long long x, long long n, long long mod) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return x % mod;
  } else {
    long long temp = binary_exp(x, n / 2, mod);
    temp = (temp * temp) % mod;
    if (n % 2 == 0) {
      return temp;
    } else {
      return ((x % mod) * temp) % mod;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long px = 0, nx = 0, py = 0, ny = 0;
    long long len = s.length();
    long long x = 0, y = 0;
    for (long long i = 0; i < len; i++) {
      if (s[i] == 'D') {
        y++;
        py = max(py, y);
        if (abs(py) + abs(ny) == n) {
          py--;
          break;
        }
      }
      if (s[i] == 'U') {
        y--;
        ny = min(ny, y);
        if (abs(py) + abs(ny) == n) {
          ny++;
          break;
        }
      }
      if (s[i] == 'L') {
        x--;
        nx = min(nx, x);
        if (abs(nx) + abs(px) == m) {
          nx++;
          break;
        }
      }
      if (s[i] == 'R') {
        x++;
        px = max(px, x);
        if (abs(px) + abs(nx) == m) {
          px--;
          break;
        }
      }
    }
    cout << abs(ny) + 1 << " " << abs(nx) + 1 << endl;
  }
}
