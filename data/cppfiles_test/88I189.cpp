#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b != 0) {
    return gcd(b, a % b);
  } else {
    return a;
  }
}
int cel(long long int a, long long int b) { return (a + b - 1) / b; }
long long int mul(long long int x, long long int y) {
  long long int res = x * y;
  return (res >= 1000000007 ? res % 1000000007 : res);
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x %= 1000000007;
  while (y) {
    if (y & 1) res = mul(res, x);
    y >>= 1;
    x = mul(x, x);
  }
  return res;
}
int isPali(string str) {
  string u;
  for (int i = str.length() - 1; i >= 0; i--) {
    u += str[i];
  }
  if (u == str) {
    return 1;
  }
  return 0;
}
int nearest2power(int n) {
  int x = 0;
  while ((1 << x) <= n) x++;
  return x - 1;
}
int binary_search(int* arr, int n, int element) {
  sort(arr, arr + n);
  int low = 0, high = n - 1;
  int mid;
  while (high - low > 1) {
    mid = (low + high) / 2;
    if (arr[mid] < element)
      low = mid + 1;
    else
      high = mid;
  }
  if (arr[low] == element)
    return low;
  else if (arr[high] == element)
    return high;
  else
    return -1;
}
bool prime(int n) {
  int flag = 0, i;
  if (n == 1)
    return false;
  else if (n == 2)
    return true;
  else {
    for (i = 2; i <= (int)sqrt(n); i++) {
      if (n % i == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 1)
      return false;
    else
      return true;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, sum = 0, count = 0, ans = 0;
    cin >> n;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    if (n % 2 == 0)
      cout << "YES" << endl;
    else {
      count = 0;
      for (int i = 1; i < n - 1; i += 2) {
        if (v[i] > v[i - 1]) count++;
      }
      if (count == 1 && n - 2 == 1)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  done : {};
  }
  return 0;
}
