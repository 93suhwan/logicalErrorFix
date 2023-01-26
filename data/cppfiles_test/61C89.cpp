#include <bits/stdc++.h>
const int mod = 1e9 + 7, MAX = 1e6 + 5;
const long long inf = 1e18 + 5;
const double pi = 3.14159265358979323846;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
using namespace std;
bool correct(int i, int j, int n, int m) {
  if (i < 0 || i >= n || j < 0 || j >= m) {
    return false;
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
long long power(long long x, long long y) {
  long long temp = 1ll;
  while (y) {
    if (y & 1) temp = (temp * x);
    x = (x * x);
    y = y >> 1;
  }
  return temp;
}
bool sieve[10000002];
vector<long long> primes;
void makeSieve() {
  int N = 1e5 + 1;
  for (int i = 0; i < N; i++) {
    if (i & 1)
      sieve[i] = true;
    else
      sieve[i] = false;
  }
  sieve[1] = false;
  sieve[2] = true;
  for (int i = 3; i * i <= N; i += 2) {
    if (sieve[i]) {
      for (int j = i * i; j <= N; j += (2 * i)) sieve[j] = false;
    }
  }
  for (int i = 3; i < N; i++) {
    if (sieve[i]) primes.push_back(i);
  }
}
bool pot(long long n) {
  if (n == 0) return 0;
  while (n != 1) {
    if (n % 2 != 0) return 0;
    n = n / 2;
  }
  return 1;
}
long long w[100001];
bool comparer(pair<int, int> a, pair<int, int> b) {
  return a.second > b.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
      if (s[0] != '?') {
        cout << s << endl;
      } else {
        cout << "R" << endl;
      }
      continue;
    }
    int i = 0, j = n - 1;
    for (i = 0; i < n; i++) {
      if (s[i] != '?') {
        break;
      }
    }
    for (; j >= 0; j--) {
      if (s[j] != '?') {
        break;
      }
    }
    if (i == n) {
      for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
          cout << "B";
        } else {
          cout << "R";
        }
      }
      cout << endl;
      continue;
    }
    if (i == j) {
      for (int k = j + 1; k < n; k++) {
        if (s[k - 1] == 'B') {
          s[k] = 'R';
        } else {
          s[k] = 'B';
        }
      }
      for (int k = i - 1; k >= 0; k--) {
        if (s[k + 1] == 'B') {
          s[k] = 'R';
        } else {
          s[k] = 'B';
        }
      }
      cout << s << endl;
      continue;
    }
    for (int k = j + 1; k < n; k++) {
      if (s[k - 1] == 'B') {
        s[k] = 'R';
      } else {
        s[k] = 'B';
      }
    }
    for (int k = i - 1; k >= 0; k--) {
      if (s[k + 1] == 'B') {
        s[k] = 'R';
      } else {
        s[k] = 'B';
      }
    }
    for (int k = i; k < j; k++) {
      if (s[k] == '?') {
        if (s[k - 1] == 'B') {
          s[k] = 'R';
        } else {
          s[k] = 'B';
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
