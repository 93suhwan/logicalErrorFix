#include <bits/stdc++.h>
using namespace std;
long long int miracleAndSleeper(long long int l, long long int r) {
  long long int ans = 0;
  long long int s = l;
  long long int e = r;
  while (s != e) {
    long long int mid = (s + e) / 2;
    if (r % mid > ans) {
      e = mid;
      ans = r % mid;
    } else
      s = mid + 1;
  }
  return ans;
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    long long int l, r;
    cin >> l >> r;
    cout << miracleAndSleeper(l, r) << endl;
  }
  return 0;
}
