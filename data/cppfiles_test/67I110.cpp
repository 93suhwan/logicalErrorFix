#include <bits/stdc++.h>
using namespace std;
int n;
double p;
int combine(int first, int second) {
  int result = 1;
  for (int i = 0; i < first; i++) {
    result *= (second - i);
  }
  for (int i = 1; i <= first; i++) {
    result /= i;
  }
  return result;
}
bool judge(int no) {
  double t = 1;
  if (no >= 2) {
    t -= 0.5 * combine(2, no) * combine(1, n - no) / combine(3, n);
  }
  if (no >= 3) {
    t -= combine(3, no) / combine(3, n);
  }
  return t >= p;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> p;
  int left = 0, right = n;
  while (left < right) {
    int mid = (left + right) / 2;
    if (judge(n - mid) == true) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << left << '\n';
  return 0;
}
