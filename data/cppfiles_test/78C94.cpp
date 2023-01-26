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
long long m;
long long fast_power(long long base, long long power) {
  if (power == 0) {
    return 1;
  }
  long long res = fast_power(base, power / 2) % m;
  res *= res;
  res %= m;
  if (power % 2 == 0) {
    return res;
  } else {
    return (res * (base % m)) % m;
  }
}
long long sum(long long x) { return x * (x + 1) / 2; }
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
long long mod = 1e9 + 7;
long long ipow(long long a, long long b) {
  long long answer = 1;
  for (; b--;) answer *= a;
  return answer;
}
int main() {
  speed();
  int t, n, arr[200005], arr1[31] = {0}, c;
  vector<int> ans;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 31; j++) {
        if ((arr[i] >> j) & 1) arr1[j]++;
      }
    }
    for (int i = 1; i <= n; i++) {
      c = 0;
      for (int j = 0; j < 31; j++) {
        if (arr1[j] % i == 0) {
          c++;
        }
      }
      if (c == 31) {
        ans.push_back(i);
      }
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    for (int j = 0; j < 31; j++) {
      arr1[j] = 0;
    }
    ans.clear();
    cout << '\n';
  }
  return 0;
}
