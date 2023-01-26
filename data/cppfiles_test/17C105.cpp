#include <bits/stdc++.h>
using namespace std;
const int32_t M = 1e9 + 7;
int32_t mod_inv(int32_t a, int32_t m) {
  int32_t g = m, r = a, x = 0, y = 1;
  while (r != 0) {
    int32_t q = g / r;
    g %= r;
    swap(g, r);
    x -= q * y;
    swap(x, y);
  }
  return x < 0 ? x + m : x;
}
int gcdi(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcdi(b, a % b);
}
long long gcdl(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcdl(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcdl(a, b)) * b; }
int factorial(int n) {
  if (n == 0) return 1;
  return n * factorial(n - 1);
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void FAST() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void swap_ll(long long *a, long long *b) {
  long long c;
  c = *a;
  *a = *b;
  *b = c;
}
void swap_int(int *a, int *b) {
  int c;
  c = *a;
  *a = *b;
  *b = c;
}
void swap_char(char *a, char *b) {
  char c;
  c = *a;
  *a = *b;
  *b = c;
}
bool mycomp(pair<int, int> &a, pair<int, int> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
long long fast_pow(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % 000000007;
      p /= 2;
    } else {
      res = res * 1ll * a % 000000007;
      p--;
    }
  }
  return res;
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 1; i <= n; i++) {
    res = res * 1ll * i % 000000007;
  }
  return res;
}
long long nCk(long long n, long long k) {
  return fact(n) * 1ll * fast_pow(fact(k), 000000007 - 2) % 000000007 * 1ll *
         fast_pow(fact(n - k), 000000007 - 2) % 000000007;
}
long long firstDigit(long long n) {
  long long digits = (long long)log10(n);
  n = (long long)(n / pow(10, digits));
  return n;
}
long long find(long long n, long long d) {
  while (n > 0) {
    if (n % 10 == d) return 1;
    n /= 10;
  }
  return 0;
}
struct node {
  int data;
  node *next;
  node(int d) {
    data = d;
    next = NULL;
  }
};
void ffin() { FAST(); }
long long add(vector<long long> a, long long b, long long e) {
  long long sum = 0;
  for (long long i = b; i < e; i++) {
    sum += a[i];
  }
  return sum;
}
void decToBinary(int n) {
  int binaryNum[32];
  int i = 0;
  while (n > 0) {
    binaryNum[i] = n % 2;
    n = n / 2;
    i++;
  }
  for (int j = i - 1; j >= 0; j--) cout << binaryNum[j];
}
bool isInteger(double N) {
  int X = N;
  double temp2 = N - X;
  if (temp2 > 0) {
    return false;
  }
  return true;
}
bool check(vector<int> &v) {
  int n = (int)((v).size());
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if ((v[i] >= v[j] && v[j] >= v[k]) || (v[i] <= v[j] && v[j] <= v[k])) {
          return true;
        }
      }
    }
  }
  return false;
}
bool digitscheck(long long n) {
  while (n != 0) {
    long long y = n % 10;
    if (y != 0 and y != 1) {
      return false;
    }
    n = n / 10;
  }
  return true;
}
const long long N = 5e+5;
long long a[N][5];
long long better(long long i, long long j) {
  long long cnt = 0;
  for (int k = 0; k < 5; k++) {
    cnt += (a[i][k] < a[j][k]);
  }
  return (cnt >= 3);
}
void solve() {
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++) cin >> a[i][j];
  long long best = 0;
  for (int i = 1; i < n; i++) {
    if (better(i, best)) best = i;
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (i == best) continue;
    ok &= better(best, i);
  }
  if (!ok) best = -2;
  cout << best + 1 << "\n";
}
int main() {
  ffin();
  long long tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
}
