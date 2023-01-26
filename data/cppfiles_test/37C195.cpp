#include <bits/stdc++.h>
using namespace std;
const long long int M = 1000000007;
const long long int MAXN = 1e7 + 1;
long long int ll_max = LLONG_MAX;
long long int gcd(long long int n1, long long int n2) {
  while (n1 != n2) {
    if (n1 > n2) {
      n1 = n1 - n2;
    } else {
      n2 = n2 - n1;
    }
  }
  return n2;
}
long long int findGCD(vector<long long int> arr, long long int n) {
  long long int result = arr[0];
  for (long long int i = 1; i < n; i++) {
    result = gcd(arr[i], result);
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
long long int lcm(long long int n1, long long int n2) {
  return ((n1 * n2) / gcd(n1, n2));
}
long long int min(long long int x, long long int y) { return (x < y) ? x : y; }
long long int max(long long int x, long long int y) { return (x > y) ? x : y; }
int getMin(int arr[], int n) {
  int res = arr[0];
  for (int i = 1; i < n; i++) res = min(res, arr[i]);
  return res;
}
long long int countDigit(long long int n) {
  long long int count = 0;
  while (n != 0) {
    n = n / 10;
    ++count;
  }
  return count;
}
int getSum(long long int n) {
  long long int sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}
bool isPerfectSquare(long long int x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool isPowerOfTwo(long long int n) {
  if (n == 0) return 0;
  while (n != 1) {
    if (n % 2 != 0) return 0;
    n = n / 2;
  }
  return 1;
}
long long int findSqrt(long long int x) {
  if (x < 2) {
    return x;
  }
  long long int result;
  long long int start = 1;
  long long int end = x / 2;
  while (start <= end) {
    long long int mid = (start + end) / 2;
    long long int sqr = mid * mid;
    if (sqr == x) {
      return mid;
    } else if (sqr < x) {
      start = mid + 1;
      result = mid;
    } else {
      end = mid - 1;
    }
  }
  return result;
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  for (long long int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
unsigned int countBits(unsigned int n) {
  unsigned int count = 0;
  while (n) {
    count++;
    n >>= 1;
  }
  return count;
}
long long int fact(long long int n) {
  long long int res = 1, i;
  for (i = 2; i <= n; i++) {
    res = (res * i);
  }
  return res;
}
long long int nCr(long long int n, long long int r) {
  return fact(n) / (((fact(r) * fact(n - r))) % M);
}
long long int nPr(long long int n, long long int r) {
  return fact(n) / (fact(n - r));
}
void swap_char(char &x, char &y) {
  char z = x;
  x = y;
  y = z;
}
void swap_no(long long int &a, long long int &b) {
  long long int c = a;
  a = b;
  b = c;
}
long long int computeXOR(long long int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
vector<long long int> primeFactors(long long int n) {
  vector<long long int> v;
  while (n % 2 == 0) {
    v.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      v.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) v.push_back(n);
  return v;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> v(n, 0);
  for (long long int i = 0; i < m; i++) {
    long long int a, b, c;
    cin >> a >> b >> c;
    v[b - 1] = 1;
  }
  for (long long int i = 0; i < n; i++) {
    if (v[i] != 1) {
      for (long long int j = 0; j < n; j++) {
        if (i != j) {
          cout << i + 1 << " " << j + 1 << endl;
        }
      }
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t > 0) {
    solve();
    t--;
  }
  return 0;
}
