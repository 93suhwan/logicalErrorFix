#include <bits/stdc++.h>
using namespace std;
bool fun(long long int *a, int n, long long int mid, long long int h) {
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    if ((i + 1) < n && (a[i + 1] - a[i]) <= mid) {
      sum += (a[i + 1] - a[i]);
    } else {
      sum += mid;
    }
  }
  return sum >= h;
}
long long int power2(long long int a, long long int b, long long int p) {
  long long int result = 1;
  while (b > 0) {
    int lastbit = (b & 1);
    if (lastbit) {
      result = (result * a) % p;
    }
    a = (a * a) % p;
    b = b >> 1;
  }
  return result % p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tttttt = 1;
  cin >> tttttt;
  for (int ttttt = 1; ttttt <= tttttt; ttttt++) {
    int n;
    long long int k;
    cin >> n >> k;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int l = 0, r = k + 1;
    long long int ans = k;
    while (l <= r) {
      long long int mid = l + ((r - l) / 2);
      if (fun(a, n, mid, k)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans;
    cout << endl;
  }
  return 0;
}
