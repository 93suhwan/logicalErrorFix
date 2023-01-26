#include <bits/stdc++.h>
using namespace std;
vector<long long> factors(long long n) {
  vector<long long> first;
  long long tem = 1;
  for (long long x = 2; x * x <= n; x++) {
    while (n % x == 0) {
      first.push_back(x);
      n /= x;
    }
  }
  if (n > 1) first.push_back(n);
  return first;
}
long long stringToint(string str) {
  int num = stoi(str);
  return num;
}
int bin_search(int arr[], int target, int n) {
  int l = 0, r = n - 1, mid = 0;
  while (l <= r) {
    mid = l + ((r - l) / 2);
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}
vector<int> computeLPSArray(string str) {
  int n = str.size(), i = 0, j = 1;
  vector<int> a(n, 0);
  while (j < n) {
    if (str[i] != str[j]) {
      while (str[i] != str[j] && i > 0) i = a[i - 1];
      if (str[i] == str[j])
        a[j++] = ++i;
      else
        a[j++] = 0;
    } else
      a[j++] = ++i;
  }
  return a;
}
int hamming(int a, int b) { return __builtin_popcount(a ^ b); }
bool cmp(int a, int b) { return a > b; }
void reset() {
  for (int i = 0; i < 200000 + 100; i++) {
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n, ans = 0;
    cin >> n;
    if (n < 6)
      ans = 15;
    else if (n % 6 == 0) {
      ans = (n / 6) * 15;
    } else if (n % 6 == 1 || n % 6 == 2) {
      ans = ((n / 6) - 1) * 15;
      ans += 20;
    } else if (n % 6 == 3 || n % 6 == 4) {
      ans = ((n / 6) - 1) * 15;
      ans += 25;
    }
    cout << ans << "\n";
  }
  return 0;
}
