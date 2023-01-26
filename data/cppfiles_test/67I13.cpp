#include <bits/stdc++.h>
int a[200005], b[200005];
using namespace std;
inline double cal_possible(int n, int learned_num) {
  int unpre_num = n - learned_num;
  return static_cast<double>(unpre_num) / n * (unpre_num - 1) / (n - 1);
}
int main() {
  ios::sync_with_stdio(false);
  if (0) freopen("data.in", "r", stdin);
  int n;
  double p;
  cin >> n >> p;
  int l = 0, r = n - 1;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (cal_possible(n, mid) >= p) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;
}
