#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> nums(n);
  for (long long i = 0; i < n; i++) {
    cin >> nums[i];
  }
  vector<long long> res(n);
  if (n & 1) {
    long long a = nums[0];
    long long b = nums[1];
    long long c = nums[2];
    if (a > 0 and b > 0) {
      long long Bc = a + b;
      long long Ba = -c;
      long long Bb = -c;
      res[0] = Ba;
      res[1] = Bb;
      res[2] = Bc;
    } else if (a > 0 and c > 0) {
      long long Bb = a + c;
      long long Ba = -b;
      long long Bc = -b;
      res[0] = Ba;
      res[1] = Bb;
      res[2] = Bc;
    } else if (b > 0 and c > 0) {
      long long Ba = b + c;
      long long Bb = -a;
      long long Bc = -a;
      res[0] = Ba;
      res[1] = Bb;
      res[2] = Bc;
    } else if (a < 0 and b < 0) {
      long long Bc = a + b;
      long long Ba = -c;
      long long Bb = -c;
      res[0] = Ba;
      res[1] = Bb;
      res[2] = Bc;
    } else if (a < 0 and c < 0) {
      long long Bb = a + c;
      long long Ba = -b;
      long long Bc = -b;
      res[0] = Ba;
      res[1] = Bb;
      res[2] = Bc;
    } else if (b < 0 and c < 0) {
      long long Ba = b + c;
      long long Bb = -a;
      long long Bc = -a;
      res[0] = Ba;
      res[1] = Bb;
      res[2] = Bc;
    }
    for (long long i = 3; i < n; i += 2) {
      long long a = nums[i];
      long long b = nums[i + 1];
      res[i] = -b;
      res[i + 1] = a;
    }
  } else {
    for (long long i = 0; i < n; i += 2) {
      long long a = nums[i];
      long long b = nums[i + 1];
      res[i] = -b;
      res[i + 1] = a;
    }
  }
  for (auto r : res) {
    cout << r << " ";
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
