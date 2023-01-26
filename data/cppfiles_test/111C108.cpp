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
long long int binarySearch(long long int p, long long int r, long long int n) {
  if (p <= r) {
    long long int mid = (p + r) / 2;
    if (mid == n) {
      return mid;
    } else if (mid > n)
      return binarySearch(p, mid - 1, n);
    else if (mid < n)
      return binarySearch(mid + 1, r, n);
  }
  return -1;
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
long long int countFreq(string &pat, string &txt) {
  long long int M = pat.length();
  long long int N = txt.length();
  long long int res = 0;
  for (int i = 0; i <= N - M; i++) {
    int j;
    for (j = 0; j < M; j++)
      if (txt[i + j] != pat[j]) break;
    if (j == M) {
      res++;
      j = 0;
    }
  }
  return res;
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
long long int func(long long int n) {
  long long int p = 0, ans = 0;
  while (n != 0) {
    long long int num = n % 10;
    if (num >= 1) {
      ans += pow(10, p);
    }
    p++;
    n = n / 10;
  }
  return ans;
}
struct cust {
  double val;
  long long int ii;
  long long int jj;
};
bool operator<(const cust &c1, const cust &c2) { return c1.val < c2.val; }
long long int solve(string n, vector<long long int> p) {
  long long int ans = 1e10;
  for (long long int i = 0; i < p.size(); i++) {
    long long int f = 0;
    string s = to_string(p[i]);
    long long int j = 0;
    for (long long int k = 0; k < n.size() && j < s.size(); k++) {
      if (s[j] == n[k]) {
        j++;
      }
    }
    long long int moves = (n.size() - j) + (s.size() - j);
    ans = min(moves, ans);
  }
  return ans;
}
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
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string brk = "()";
    for (long long int i = n; i >= 1; i--) {
      string ans{""};
      for (long long int j = i; j >= 1; j--) ans += brk;
      for (long long int j = n - i; j >= 1; j--) ans += ")";
      for (long long int j = n - i; j >= 1; j--) ans = "(" + ans;
      cout << ans << endl;
    }
  }
}
