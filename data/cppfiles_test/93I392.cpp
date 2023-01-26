#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
long long int ncr(long long int n, long long int r) {
  long long int p = 1, k = 1;
  if (n - r < r) r = n - r;
  if (r != 0) {
    while (r) {
      p *= n % 1000000007;
      k *= r % 1000000007;
      long long int m = gcd(p, k);
      p /= m;
      k /= m;
      n--;
      r--;
    }
  } else
    p = 1;
  return p % 1000000007;
}
long long int mod_exp(long long int a, long long int b, long long int m) {
  a %= m;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b = b / 2;
  }
  return res;
}
long long int get_div(long long int n) {
  long long int sum = 0;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        sum += i;
      else {
        sum += i;
        sum += (n / i);
      }
    }
  }
  return sum;
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
vector<long long int> SieveOfEratosthenes(long long int n) {
  vector<long long int> arr(n + 1, 0);
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long int j = 2; j <= n; j++) {
    arr[j] = arr[j - 1];
    if (prime[j]) arr[j]++;
  }
  return arr;
}
long long int primeFactors(long long int n, long long int k) {
  if (isPrime(n)) return 1;
  long long int c = 0;
  while (n % 2 == 0) {
    c++;
    n = n / 2;
  }
  for (long long int i = 3; i <= sqrt(n) + 1; i = i + 2) {
    while (n % i == 0) {
      c++;
      n = n / i;
    }
  }
  if (n > 2) {
    c++;
  }
  return c;
}
bool isp(string s) {
  for (long long int i = 0; i < (s.size() / 2); i++) {
    if (s[i] != s[s.size() - 1 - i]) return false;
  }
  return true;
}
long long int len(long long int n) {
  long long int ans = 0;
  while (n != 0) {
    n = n / 10;
    ans++;
  }
  return ans;
}
void divisors_till_n(int n) {
  long long int divisors[100000];
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      divisors[j]++;
      divisors[j] %= 998244353;
    }
  }
}
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
bool sortbysecdesc(const pair<long long int, long long int> &a,
                   const pair<long long int, long long int> &b) {
  return a.second < b.second;
}
long long int close(long long int n, long long int a, long long int b) {
  long long int div = n / b;
  long long int no = n / a;
  while ((n - (div)*b) % a != 0 && div >= (n - (a * no))) div--;
  if (div >= 0) return div;
  return -1;
}
long long int op(long long int num1, long long int num2) {
  long long int ans = 0;
  long long int p = 0;
  while (num1 != 0) {
    long long int bin1, bin2;
    bin1 = num1 % 2;
    bin2 = num2 % 2;
    if (bin1 == 1 && bin2 == 0) {
      ans += pow(2, p);
    }
    p++;
    num1 = num1 / 2;
    num2 = num2 / 2;
  }
  return ans;
}
struct cust {
  long int ii;
  long int jj;
  long int val;
};
bool operator<(const cust &c1, const cust &c2) { return c1.ii < c2.ii; }
long long int voting_algo(vector<vector<long long int>> arr, long long int n) {
  long long int count1 = 0, count2 = 0;
  long long int first = 0, second = 1;
  for (long long int j = 0; j < arr[0].size(); j++) {
    for (long long int i = 0; i < n; i++) {
      if (arr[first][j] >= arr[i][j] && count1 != 0)
        count1++;
      else if (arr[second][j] >= arr[i][j] && count2 != 0)
        count2++;
      else if (count1 == 0) {
        count1++;
        first = i + 1;
      } else if (count2 == 0) {
        count2++;
        second = i + 1;
      } else {
        count1--;
        count2--;
      }
    }
  }
  count1 = 0;
  count2 = 0;
  for (long long int j = 0; j < arr[0].size(); j++) {
    for (long long int i = 0; i < n; i++) {
      if (arr[first][j] >= arr[i][j])
        count1++;
      else if (arr[second][j] >= arr[i][j])
        count2++;
    }
  }
  if (count1 > n / 3) return first;
  if (count2 > n / 3) return second;
  return -1;
}
long long int binarySearch(long long int p, long long int r, long long int x) {
  if (p <= r) {
    long long int mid = (p + r) / 2;
    if (mid == x)
      return mid;
    else if (mid > x)
      return binarySearch(p, mid - 1, x);
    else if (mid < x)
      return binarySearch(mid + 1, r, x);
  }
  return -1;
}
bool compi(const pair<long long int, long long int> &a,
           const pair<long long int, long long int> &b) {
  return a.first < b.first;
}
vector<long long int> leftRotate(vector<long long int> arr, long long int d,
                                 long long int n) {
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
  return arr;
}
bool fun(vector<long long int> vec) {
  for (long long int i = 0; i < vec.size() - 1; i++) {
    if (vec[i] >= vec[i + 1]) return false;
  }
  return true;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int lc = n;
    long long int ans = 0;
    long long int m = 1;
    while (lc != 0) {
      lc -= min(m, lc);
      m = min(k, m * 2);
      ans++;
    }
    cout << ans << endl;
  }
}
