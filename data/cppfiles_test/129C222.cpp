#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
long long powe(T base, T to) {
  long long ans = 1;
  while (to > 0) {
    if (to & 1)
      ans = ((ans) * (base)), to--;
    else
      base = ((base) * (base)), to /= 2;
  }
  return ans;
}
template <typename T>
T gcd(T a, T b) {
  return (b == 0) ? a : gcd(b, a % b);
}
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
long long fun(int arr[], int n, int x) {
  long long ans = x;
  for (int i = 0; i < n - 1; i++) ans += min(x, arr[i + 1] - arr[i]);
  return ans;
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
    sort(arr, arr + n);
    bool ok = true;
    for (int i = 0; i < n; i++)
      if (arr[i] < (i + 1)) {
        ok = false;
        break;
      }
    if (!ok) {
      cout << "-1\n";
      continue;
    }
    vector<bool> tmp(n, 0);
    int ans = n;
    int val = 1;
    for (int i = 0; i < n; i++) {
      if (arr[i] >= 1 && arr[i] <= n && !tmp[arr[i] - 1]) {
        tmp[arr[i] - 1] = 1, ans--;
        while (tmp[val - 1] && val <= n) val++;
        continue;
      }
      if (arr[i] == val) {
        tmp[val - 1] = 1;
        while (tmp[val - 1] && val <= n) val++;
        continue;
      }
      if ((arr[i] - val) <= val) {
        ans = -1;
        break;
      }
      tmp[val - 1] = 1;
      while (tmp[val - 1] && val <= n) val++;
    }
    cout << ans << "\n";
  }
}
