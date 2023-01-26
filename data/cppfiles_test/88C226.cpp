#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
long long powe(T base, T to) {
  long long ans = 1;
  while (to > 0) {
    if (to & 1)
      ans = ((ans) % 998244353 * (base) % 998244353) % 998244353, to--;
    else
      base = ((base) % 998244353 * (base) % 998244353) % 998244353, to /= 2;
  }
  return ans % 998244353;
}
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
bool prime(long long n) {
  if (n == 1) return 0;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
int binarySearch(int arr[], int start, int end, int val) {
  int mid;
  end--;
  while (start <= end) {
    mid = start + (end - start) / 2;
    if (arr[mid] == val)
      return mid;
    else if (arr[mid] < val)
      start = mid + 1;
    else
      end = mid - 1;
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tl = 1;
  cin >> tl;
  while (tl--) {
    int n;
    cin >> n;
    int arr[n];
    for (auto &i : arr) cin >> i;
    ;
    if (n % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    bool ok = false;
    for (int i = 0; i < n - 1; i++)
      if (arr[i] > arr[i + 1]) ok = true;
    if (ok) {
      cout << "YES\n";
      continue;
    }
    for (int i = 0; i < n - 1; i++)
      if (arr[i] == arr[i + 1]) ok = true;
    cout << ((ok) ? "YES\n" : "NO\n");
  }
}
