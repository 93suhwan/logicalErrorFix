#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long int binarySearch(long long int arr[], long long int l,
                           long long int r, long long int x) {
  if (r >= l) {
    long long int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
long long int power(long long int a, long long int b) {
  long long int result = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      result *= a;
    }
    a *= a;
    b /= 2;
  }
  return result;
}
long long int powermod(long long int a, long long int b, int M) {
  if (a == 1 || b == 0) return 1;
  long long int c = powermod(a, b / 2, M);
  long long int res = 1;
  res = c * c;
  if (res >= M) res %= M;
  if (b % 2) res *= a;
  if (res >= M) res %= M;
  return res;
}
bool isPerfectSquare(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
bool sortbydec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.first > b.first);
}
int binaryToDecimal(string n) {
  string num = n;
  int dec_value = 0;
  int base = 1;
  int len = num.length();
  for (int i = len - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
void decToBinary(int n, int bit) {
  int binaryNum[bit];
  int i = 0;
  while (n > 0) {
    binaryNum[i] = n % 2;
    n = n / 2;
    i++;
  }
  for (int j = 1; j <= bit - i; j++) {
    cout << 0;
  }
  for (int j = i - 1; j >= 0; j--) cout << binaryNum[j];
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
long long int computeXOR(long long int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long int a, long long int b) { return (a / gcd(a, b)) * b; }
bool cmp(int a, int b) { return a > b; }
void leftRotate(long long int arr[], long long int n, long long int d) {
  d = d % n;
  long long int g_c_d = gcd(d, n);
  for (long long int i = 0; i < g_c_d; i++) {
    long long int temp = arr[i];
    long long int j = i;
    while (1) {
      long long int k = j + d;
      if (k >= n) k = k - n;
      if (k == i) break;
      arr[j] = arr[k];
      j = k;
    }
    arr[j] = temp;
  }
}
void showdq(deque<long long int> g) {
  deque<long long int>::iterator it;
  for (it = g.begin(); it != g.end(); ++it) cout << *it << " ";
  cout << '\n';
}
long long int nozeroes(vector<pair<long long int, long long int>> v) {
  long long int ans = 0;
  for (long long int i = 0; i < v.size(); i++) {
    if (v[i].first != 0) ans++;
  }
  return ans;
}
long long int getInvCount(deque<long long int> g) {
  deque<long long int>::iterator it;
  deque<long long int>::iterator j;
  long long int inv_count = 0;
  for (it = g.begin(); it != g.end(); it++)
    for (j = it + 1; j != g.end(); j++)
      if (*it > *j) inv_count++;
  return inv_count;
}
long long int findXOR(long long int n) {
  long long int m = n % 4;
  if (m == 0)
    return n;
  else if (m == 1)
    return 1;
  else if (m == 2)
    return n + 1;
  else
    return 0;
}
long long int F(long long int l, long long int r) {
  long long int x = min(l, r);
  long long int y = max(l, r);
  return (findXOR(x - 1) ^ findXOR(y));
}
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
bool isPalindrome(string S) {
  string P = S;
  reverse(P.begin(), P.end());
  if (S == P) {
    return true;
  } else {
    return false;
  }
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
bool vowelOrConsonant(char x) {
  if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
    return true;
  else
    return false;
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  long long int s = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  if ((s % n) == 0) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
}
int main() {
  fast();
  long long int T = 1;
  cin >> T;
  for (long long int z = 1; z <= T; z++) {
    solve();
  }
}
