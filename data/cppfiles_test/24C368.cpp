#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int maxar(int arr[], int n) {
  int res = arr[0];
  for (int i = 0; i < n; i++) {
    res = max(res, arr[i]);
  }
  return res;
}
long long maxar(long long arr[], long long n) {
  long long res = arr[0];
  for (long long i = 0; i < n; i++) {
    res = max(res, arr[i]);
  }
  return res;
}
long long minar(long long arr[], long long n) {
  long long res = arr[0];
  for (long long i = 0; i < n; i++) {
    res = min(res, arr[i]);
  }
  return res;
}
int minar(int arr[], int n) {
  int res = arr[0];
  for (int i = 0; i < n; i++) {
    res = min(res, arr[i]);
  }
  return res;
}
void inpar(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}
void inpar(long long arr[], long long n) {
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
}
template <typename T>
inline T readInt() {
  T n = 0, s = 1;
  char p = getchar();
  if (p == '-') s = -1;
  while ((p < '0' || p > '9') && p != EOF && p != '-') p = getchar();
  if (p == '-') s = -1, p = getchar();
  while (p >= '0' && p <= '9') {
    n = (n << 3) + (n << 1) + (p - '0');
    p = getchar();
  }
  return n * s;
}
bool isPalin(string s, int n) {
  int i = 0, j = n - 1;
  while (i < j) {
    if (s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}
void solve() {
  int n = readInt<int>();
  int x = (n % 10 == 9) ? 1 : 0;
  cout << n / 10 + x << endl;
}
int32_t main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
