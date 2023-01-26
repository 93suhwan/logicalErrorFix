#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18;
const int MX = INT_MAX;
const int MN = INT_MIN;
const int N = 3e5 + 5;
const int mod = 1e9 + 7;
vector<long long> v, v1;
void build(long long val, long long i, long long x, long long y) {
  if (1) {
    v.push_back(val);
  }
  if (i > 11) return;
  long long ret = val + (x * pow(10, i));
  long long ret1 = val + (y * (pow(10, i)));
  build(ret1, i + 1, x, y);
  build(ret, i + 1, x, y);
}
int main() {
  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) build(0, 0, i, j);
  }
  for (int i = 1; i < 10; i++) {
    long long val = i;
    while (val <= 1e11) {
      v1.push_back(val);
      val *= 10;
      val += i;
    }
  }
  sort(v.begin(), v.end());
  sort(v1.begin(), v1.end());
  bool f = 0;
  int test_cases = 1;
  cin >> test_cases;
  while (test_cases--) {
    long long x, k;
    cin >> x >> k;
    if (k == 1) {
      int s = 0, e = v1.size() - 1, mid;
      long long val;
      while (s <= e) {
        mid = (s + e) / 2;
        if (v1[mid] >= x) {
          val = v1[mid];
          e = mid - 1;
        } else
          s = mid + 1;
      }
      cout << val << "\n";
    } else {
      int s = 0, e = v.size() - 1, mid;
      long long val;
      while (s <= e) {
        mid = (s + e) / 2;
        if (v[mid] >= x) {
          val = v[mid];
          e = mid - 1;
        } else
          s = mid + 1;
      }
      cout << val << "\n";
    }
  }
  return 0;
}
