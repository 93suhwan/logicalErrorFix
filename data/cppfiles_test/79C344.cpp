#include <bits/stdc++.h>
using namespace std;
long long MD = 1000000007;
long long md = 998244353;
const long long INF = 1e18L + 5;
long long exp(long long a, long long b) {
  long long r = 1ll;
  while (b > 0) {
    if (b & 1) {
      r = r * (a % md);
      r = (r + md) % md;
    }
    b /= 2;
    a = (a % md) * (a % md);
    a = (a + md) % md;
  }
  return (r + md) % md;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pow_2(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
bool isPrime(long long a) {
  for (long long i = 3; (i * i) <= a; i += 2) {
    if ((a % i) == 0) return false;
  }
  if ((a != 2) && ((a % 2) == 0)) return false;
  if (a == 1) return false;
  return true;
}
string decToBinary(int n) {
  string s = "";
  for (int i = 31; i >= 0; i--) {
    int k = n >> i;
    if (k & 1)
      s = s + "1";
    else
      s = s + "0";
  }
  return s;
}
int decimalToBinary(int N) {
  unsigned long long int B_Number = 0;
  int cnt = 0;
  while (N != 0) {
    int rem = N % 2;
    unsigned long long int c = pow(10, cnt);
    B_Number += rem * c;
    N /= 2;
    cnt++;
  }
  return B_Number;
}
string toString(unsigned long long int num) {
  std::string number;
  std::stringstream strstream;
  strstream << num;
  strstream >> number;
  return number;
}
const double PI = acos(-1);
bool isPrime(int n) {
  if (n == 1) return false;
  if (n == 2 || n == 3) return true;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int comp = 0;
    int two = 0;
    int three = 0;
    int five = 0;
    int seven = 0;
    char num;
    int pos = -1;
    for (int i = 0; i < k; i++) {
      int x = (int)s[i] - 48;
      if (!isPrime(x) || s[i] == '1') {
        comp++;
        num = s[i];
      } else if (x == 2) {
        two++;
        pos = i;
      } else if (x == 3)
        three++;
      else if (x == 5)
        five++;
      else if (x == 7)
        seven++;
    }
    if (comp > 0) {
      cout << "1" << '\n';
      cout << num << '\n';
    } else {
      if (s.size() == 1) {
        cout << "1" << '\n';
        cout << s << '\n';
      } else {
        if (two >= 2 || three >= 2 || five >= 2 || seven >= 2) {
          cout << "2" << '\n';
          if (two >= 2)
            cout << "22" << '\n';
          else if (three >= 2)
            cout << "33" << '\n';
          else if (five >= 2)
            cout << "55" << '\n';
          else if (seven >= 2)
            cout << "77" << '\n';
        } else if (two > 0 && pos > 0) {
          cout << "2" << '\n';
          cout << s[pos - 1] << s[pos] << '\n';
        } else if (two > 0 && (five > 0 || seven > 0)) {
          cout << "2" << '\n';
          cout << "2";
          if (five > 0)
            cout << "5" << '\n';
          else
            cout << "7" << '\n';
        } else {
          if (five > 0) {
            if (s[0] != '5') {
              cout << "2" << '\n';
              cout << s[0] << "5" << '\n';
            } else if (s[0] == '5') {
              if (seven > 0) {
                cout << "2" << '\n';
                cout << "57" << '\n';
              }
            }
          } else {
            cout << s.size() << '\n';
            cout << s << '\n';
          }
        }
      }
    }
  }
  return 0;
}
