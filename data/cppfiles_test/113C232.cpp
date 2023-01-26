#include <bits/stdc++.h>
using namespace std;
long long lilt(vector<long long> &a, long long val) {
  long long start = 0;
  long long end = a.size() - 1;
  long long ans = -1;
  while (start <= end) {
    long long mid = (start + end) / 2;
    if (a[mid] <= val) {
      ans = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return ans;
}
long long sigt(vector<long long> &a, long long val) {
  long long start = 0;
  long long end = a.size() - 1;
  long long ans = -1;
  while (start <= end) {
    long long mid = (start + end) / 2;
    if (a[mid] >= val) {
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long n, p, m, x, y;
  cin >> n;
  vector<long long> a;
  long long sum = 0ll;
  for (long long i = 0ll; i < n; i++) {
    cin >> p;
    a.push_back(p);
    sum += p;
  }
  sort(a.begin(), a.end());
  cin >> m;
  for (long long i = 0ll; i < m; i++) {
    long long ans = 0ll;
    cin >> x >> y;
    long long in = lilt(a, x);
    if (in == -1ll) {
      if (sum - a[0] < y) {
        ans = y - sum + a[0];
      }
    } else {
      ans += (x - a[in]);
      if (sum - a[in] < y) {
        ans += (y - sum + a[in]);
      }
      long long ans2 = 0ll;
      long long in2 = sigt(a, x);
      if (in2 != -1) {
        if (sum - a[in2] < y) {
          ans2 = y - sum + a[in2];
        }
        if (ans2 < ans) {
          ans = ans2;
        }
      }
    }
    cout << ans << endl;
  }
}
