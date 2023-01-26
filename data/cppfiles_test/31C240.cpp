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
bool check(string str) {
  bool ans = true;
  for (int i = 0; i < str.size() / 2; i++)
    if (str[i] != str[str.size() - i - 1]) ans = false;
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
    int end = n;
    if (n & 1) end = n - 3;
    vector<int> b(n, 0);
    for (int i = 0; i < end; i += 2) {
      b[i] = -arr[i + 1];
      b[i + 1] = arr[i];
    }
    if (end != n) {
      if ((arr[n - 2] + arr[n - 3]) != 0)
        b[n - 1] = arr[n - 2] + arr[n - 3], b[n - 2] = -arr[n - 1],
              b[n - 3] = -arr[n - 1];
      else if ((arr[n - 2] + arr[n - 1]) != 0)
        b[n - 3] = arr[n - 2] + arr[n - 1], b[n - 2] = -arr[n - 3],
              b[n - 1] = -arr[n - 3];
      else
        b[n - 2] = arr[n - 3] + arr[n - 1], b[n - 3] = -arr[n - 2],
              b[n - 1] = -arr[n - 2];
    }
    for (int i : b) cout << i << " ";
    cout << "\n";
  }
}
