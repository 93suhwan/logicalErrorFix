#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];
  vector<int> l(n);
  int f = n - 1;
  l[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    if (p[i] >= p[i + 1]) f = i;
    l[i] = f;
  }
  vector<int> r(n);
  f = 0;
  r[0] = 0;
  for (int i = 1; i < n; ++i) {
    if (p[i] >= p[i - 1]) f = i;
    r[i] = f;
  }
  int g = 0;
  int left = 0;
  int right = n - 1;
  int lst = -1;
  while (left <= right) {
    if (left != right) {
      if (p[left] <= p[right]) {
        int d = right - r[right];
        if (d % 2 == 0) {
          g++;
          break;
        }
        if (p[left] <= lst) break;
        lst = p[left];
        left++;
      } else {
        int d = l[left] - left;
        if (d % 2 == 0) {
          g++;
          break;
        }
        if (p[right] <= lst) break;
        lst = p[right];
        right--;
      }
    } else {
      left++;
    }
    g++;
  }
  if (g & 1)
    cout << "Alice" << endl;
  else
    cout << "Bob";
}
int main() {
  solve();
  return 0;
}
