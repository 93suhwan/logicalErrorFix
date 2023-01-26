#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
void wri(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) wri(x / 10);
  putchar(x % 10 + '0');
}
void write(long long x) {
  wri(x);
  puts("");
}
long long ksc(long long a, long long b, long long mod) {
  return ((a * b -
           (long long)((long long)((long double)a / mod * b + 1e-3) * mod)) %
              mod +
          mod) %
         mod;
}
long long ksm1(long long a, long long n, long long mod) {
  long long t = 1;
  for (; n; n >>= 1, (a *= a) %= mod)
    if (n & 1) (t *= a) %= mod;
  return t;
}
long long ksm2(long long a, long long b, long long mod) {
  long long ints = 1;
  while (b) {
    if (b & 1) ints = ksc(ints, a, mod);
    b >>= 1, a = ksc(a, a, mod);
  }
  return ints % mod;
}
int is2pow(long long x) { return x > 0 ? (x & (x - 1)) == 0 : 0; }
long long lowbit(long long x) { return x & -x; }
long long myrand(long long l, long long r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<long long>(l, r)(gen);
}
const int N = 1e6 + 5;
const int M = 8192;
pair<int, int> arr[N];
int num[M];
int brr[N];
int n;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i].first, arr[i].second = i;
  sort(arr + 1, arr + 1 + n);
  memset(num, inf, sizeof(num));
  int pos = 1;
  num[0] = 0;
  while (pos <= n) {
    int tmp = 1;
    int mark = arr[pos].first;
    brr[tmp] = arr[pos].second;
    pos++;
    while (pos <= n && arr[pos].first == mark)
      brr[++tmp] = arr[pos].second, pos++;
    for (int i = 0; i < 8192; i++)
      if (num[i] < brr[tmp])
        num[i ^ mark] =
            min(num[i ^ mark],
                brr[lower_bound(brr + 1, brr + 1 + tmp, num[i]) - brr]);
  }
  int ans = 0;
  for (int i = 0; i < 8192; i++)
    if (num[i] != inf) ans++;
  cout << ans << endl;
  for (int i = 0; i < 8192; i++)
    if (num[i] != inf) cout << i << " ";
  cout << endl;
  return 0;
}
