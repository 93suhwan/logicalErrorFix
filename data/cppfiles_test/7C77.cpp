#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long st[20][200005];
long long getset(long long a) {
  long long temp = -1;
  while (a) {
    temp++;
    a /= 2;
  }
  return temp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    n--;
    for (long long i = 0; i < n; i++) {
      st[0][i] = abs(arr[i + 1] - arr[i]);
    }
    for (long long i = 1; i < 20; i++) {
      for (long long j = 0; j < n - (1 << (i - 1)); j++) {
        st[i][j] = gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    long long ans = 1;
    for (long long i = 0; i < n; i++) {
      long long l = 1, r = n - i;
      while (l <= r) {
        long long mid = (l + r) / 2;
        long long x = getset(mid);
        if (gcd(st[x][i], st[x][i + mid - (1 << x)]) > 1) {
          ans = max(ans, mid + 1);
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }
    cout << ans << endl;
  }
}
