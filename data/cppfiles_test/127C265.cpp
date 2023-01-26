#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 7;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int countPrimes(int n) {
  vector<bool> isPrime(n);
  for (int i = 2; i < n; i++) {
    isPrime[i] = true;
  }
  for (int i = 2; i * i < n; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j < n; j += i) {
      isPrime[j] = false;
    }
  }
  int count = 0;
  for (int i = 2; i < n; i++) {
    if (isPrime[i]) count++;
  }
  return count;
}
bool isPerfectSquare(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
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
string decToBinary(int n, int bit) {
  string s;
  int binaryNum[bit];
  int i = 0;
  while (n > 0) {
    binaryNum[i] = n % 2;
    n = n / 2;
    i++;
  }
  for (int j = i - 1; j >= 0; j--) s[i - 1 - j] = binaryNum[j];
  return s;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long int a, long long int b) { return (a / gcd(a, b)) * b; }
long long int power(long long int a, long long int b) {
  if (a == 1 || b == 0) return 1;
  long long int c = power(a, b / 2);
  long long int res = 1;
  res = c * c;
  if (res >= 1000000007) res %= 1000000007;
  if (b % 2) res *= a;
  if (res >= 1000000007) res %= 1000000007;
  return res;
}
long long int powerNoMod(long long int a, long long int b) {
  if (a == 1 || b == 0) return 1;
  long long int c = powerNoMod(a, b / 2);
  long long int res = 1;
  res = c * c;
  if (b % 2) res *= a;
  return res;
}
long long int factorial(long long int n) {
  long long int res = 1, i;
  for (i = 2; i <= n; i++) {
    res = (res * i) % M;
  }
  return res % M;
}
long long int count_pairs(long long int a[], long long int n,
                          long long int sum) {
  vector<pair<long long int, long long int>> b;
  sort(a, a + n);
  for (int i = 0, j = n - 1; i < j;) {
    long long int x = (a[i] + a[j]);
    if (x == sum) {
      if (a[i] != a[j]) {
        long long int p = 1;
        long long int q = 1;
        while (i < j && (a[i + 1] == a[i])) {
          i++;
          p++;
        }
        while (i < j && (a[j - 1] == a[j])) {
          j--;
          q++;
        }
        i++;
        j--;
        b.push_back({p, q});
      } else {
        b.push_back({j - i + 1, -1});
        break;
      }
    } else if (x > sum) {
      j--;
    } else {
      i++;
    }
  }
  long long int count = 0;
  for (int i = 0; i < b.size(); i++) {
    if (b[i].second == -1) {
      long long int ans = b[i].first * (b[i].first - 1);
      ans = ans / 2;
      count += ans;
    } else {
      count += b[i].first * b[i].second;
    }
  }
  return count;
}
long long int fact(long long int n) {
  long long int res = 1;
  for (long long int i = 2; i <= n; i++) res = res * i;
  return res;
}
long long int nCr(long long int n, long long int r) {
  return fact(n) / (fact(r) * fact(n - r));
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2);
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  for (long long int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
void solve() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  if (t[0] != 'a') {
    cout << s << endl;
    return;
  } else {
    if (t[1] == 'c') {
      cout << s << endl;
      return;
    } else {
      int as = 0;
      int bs = 0;
      int cs = 0;
      int idx = s.size();
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'b') bs++;
        if (s[i] == 'c') cs++;
        if (s[i] == 'a') as++;
        if (s[i] - 'c' > 0) {
          idx = i;
          break;
        }
      }
      if (as != 0 && bs != 0 && cs != 0) {
        while (as--) cout << "a";
        while (cs--) cout << "c";
        while (bs--) cout << "b";
        for (int i = idx; i < s.size(); i++) cout << s[i];
        cout << endl;
        return;
      } else
        cout << s << endl;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
