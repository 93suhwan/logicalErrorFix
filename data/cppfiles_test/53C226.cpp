#include <bits/stdc++.h>
using namespace std;
int maxint = numeric_limits<int>::max();
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}
bool cmp(pair<char, long long int>& a, pair<char, long long int>& b) {
  return a.second > b.second;
}
long long int distance1(long long int x1, long long int y1, long long int x2,
                        long long int y2) {
  return sqrt(pow(x2 - x1, 2) * 1.0 + pow(y2 - y1, 2) * 1.0);
}
long long int distance2(long long int x1, long long int y1, long long int x2,
                        long long int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}
long long binpoww(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int binpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long int digSum(long long int n) {
  long long int sum = 0;
  while (n > 0 || sum > 9) {
    if (n == 0) {
      n = sum;
      sum = 0;
    }
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
bool prime[20000002];
void SieveOfEratosthenes(long long int n) {
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
void solve() {
  long long int n;
  cin >> n;
  char ch;
  cin >> ch;
  string s;
  cin >> s;
  long long int o = 0, e = 0;
  for (long long int i = 0; i < n; i++) {
    o += s[i] != ch;
    i++;
  }
  for (long long int i = 1; i < n; i++) {
    e += s[i] != ch;
    i++;
  }
  if (o == 0 && e == 0) {
    cout << 0 << endl;
  } else if (e == 0 || o == 0) {
    if (o > 0) {
      cout << 1 << endl << 2 << endl;
    } else if (e > 0) {
      if (n % 2 == 0) {
        cout << 1 << endl << n - 1 << endl;
      } else if (n % 2 == 1) {
        cout << 1 << endl << n << endl;
      }
    }
  } else if (e != 0 && o != 0) {
    long long int sz = (n / 2) + 1, f = -1;
    for (int i = sz - 1; i < n; i++) {
      if (s[i] == ch) {
        f = i + 1;
        break;
      }
    }
    if (f > 0) {
      cout << 1 << endl << f << endl;
    } else if (f == -1) {
      cout << 2 << endl;
      cout << n - 1 << " " << n << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
