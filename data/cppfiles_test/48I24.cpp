#include <bits/stdc++.h>
using namespace std;
void speed() {
  cin.tie(0);
  cin.sync_with_stdio(0);
}
long long factorial(long long x) {
  long long res = 1;
  for (int i = 2; i <= x; i++) {
    res *= i;
  }
  return res;
}
long long remove_0(long long x) {
  long long res = 0, cnt = 1;
  while (x > 0) {
    int digit = x % 10;
    if (digit != 0) {
      res += (digit * cnt);
      cnt *= 10;
    }
    x /= 10;
  }
  return res;
}
bool prime[100005];
void prime_numbers(int x) {
  memset(prime, true, sizeof(prime));
  int c = 0;
  prime[0] = prime[1] = false;
  for (int i = 2; i * i <= 100001; i++) {
    if (prime[i] == true) {
      for (int j = i * i; j <= 100001; j += i) {
        prime[j] = false;
      }
    }
  }
  return;
}
long long sum_binary(long long x) {
  long long s = 0;
  while (x > 0) {
    s += x % 2;
    x /= 2;
  }
  return s;
}
int binary_s(int a[], int l, int h, int k) {
  if (l <= h) {
    int mid = (l + h) / 2;
    if (k == a[mid]) return mid;
    if (k < a[mid]) {
      return binary_s(a, l, mid - 1, k);
    } else
      return binary_s(a, mid + 1, h, k);
  } else
    return -1;
}
void bubble_sort(char x[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (x[j] > x[j + 1]) {
        char temp = x[j];
        x[j] = x[j + 1];
        x[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << x[i];
  }
  cout << '\n';
}
long long npr(int n, int r) {
  long long res = 1;
  for (int i = n - r + 1; i <= n; i++) {
    res *= i;
  }
  return res;
}
long long cper(int n, int r) {
  long long res = 1;
  for (int i = n - r + 1; i <= n; i++) {
    res *= i;
    if (res % r == 0) {
      res /= r;
      r = 1;
    }
  }
  return res;
}
long long ncr(int n, int r) { return npr(n, r) / factorial(r); }
long long sum(long long x) { return x * (x + 1) / 2; }
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
long long mod = 1e9 + 7;
long long ipow(long long a, long long b) {
  long long answer = 1;
  for (; b--;) {
    answer *= a;
    answer %= mod;
  }
  return answer % mod;
}
int ipow(int a, int b) {
  int answer = 1;
  for (; b--;) answer *= a;
  return answer;
}
long long xorSum(int arr[], int n) {
  int bits = 0;
  for (int i = 0; i < n; ++i) bits |= arr[i];
  long long ans = bits * pow(2, n - 1);
  ans %= mod;
  return ans;
}
__int128 read() {
  __int128 x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void print(__int128 x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
__int128 f(long long x) {
  __int128 res = 1;
  for (__int128 i = 2; i <= x; i++) {
    res *= i;
  }
  return res;
}
int main() {
  speed();
  int t, n;
  static pair<int, int> arr1[500005], arr[500005];
  cin >> t;
  bool no;
  while (t--) {
    cin >> n;
    no = 0;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i].first;
      arr1[i] = {arr[i].first, i};
    }
    sort(arr1 + 1, arr1 + 1 + n);
    for (int i = 1; i <= n; i++) {
      arr[arr1[i].second].second = i;
    }
    for (int i = n; i > 2; i--) {
      pair<int, int> temp;
      if (arr1[i].second != i) {
        temp = arr[i];
        arr[i] = {arr1[i].first, i};
        if (temp.second != i - 1) {
          arr[arr1[i].second] = {arr1[i - 1].first, i - 1};
          arr[arr1[i - 1].second] = temp;
          arr1[temp.second].second = arr1[i - 1].second;
          arr1[i - 1].second = arr1[i].second;
        } else {
          arr[arr1[i].second] = {arr1[i - 2].first, i - 2};
          arr[arr1[i - 2].second] = temp;
          arr1[temp.second].second = arr1[i - 2].second;
          arr1[i - 2].second = arr1[i].second;
        }
      }
    }
    for (int i = 1; i < n; i++) {
      if (arr[i].first > arr[i + 1].first) {
        no = 1;
      }
    }
    if (no)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
  return 0;
}
