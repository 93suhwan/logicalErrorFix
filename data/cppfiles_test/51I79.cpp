#include <bits/stdc++.h>
using namespace std;
long long int find(long long int n) {
  long long int l, r, mid;
  l = 0;
  r = 1000000000;
  long long int ans = 1000000000;
  while (l <= r) {
    mid = (l + r) / 2;
    if (mid * mid + mid >= n) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int r = find(2 * n);
    long long int l = ((r * (r + 1)) / 2) - n;
    long long int left = find(2 * l);
    if (left == 0) {
      cout << left << " " << r << endl;
      continue;
    }
    cout << "-" << left << " " << r << endl;
  }
}
