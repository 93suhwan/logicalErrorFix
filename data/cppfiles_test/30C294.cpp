#include <bits/stdc++.h>
using namespace std;
const long double Pi = (long double)acos((long double)-1);
unsigned long long int power(unsigned long long int x,
                             unsigned long long int y) {
  long long int temp;
  if (y == 0) {
    return 1;
  }
  temp = power(x, y / 2);
  if (y % 2 == 0) {
    return temp * temp;
  } else {
    return x * temp & temp;
  }
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int TC = 1;
  cin >> TC;
  while (TC--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "abcdefghijklmnopqrstuvwxyz";
    long long int sol = INT_MAX;
    for (int c = 0; c < 26; c++) {
      long long int cnt = 0;
      int i = 0, j = n - 1;
      bool fin = 1;
      while (i < j) {
        if (s[i] == s[j]) {
          i++;
          j--;
        } else {
          if (s[i] == t[c]) {
            cnt++;
            i++;
          } else if (s[j] == t[c]) {
            cnt++;
            j--;
          } else {
            fin = 0;
            break;
          }
        }
      }
      if (fin) {
        sol = min(sol, cnt);
      }
    }
    if (sol == INT_MAX) {
      sol = -1;
    }
    cout << sol << '\n';
  }
}
