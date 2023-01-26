#include <bits/stdc++.h>
using namespace std;
struct tri {
  long long t1, t2, t3;
};
bool comp(tri a, tri b) { return a.t1 < b.t1; }
void solvee() {
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  swap(a, b);
  if (a == 0 && b == 0) {
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << "\n";
    return;
  }
  if (abs(a - b) > 1 || max(a, b) > (n - 1) / 2) {
    cout << "-1\n";
  } else {
    int t = 0;
    int p[n];
    if (a > b) {
      p[0] = n;
      p[1] = 1;
      for (int l = 2, r = n - 1, i = 2; i < n; i++) {
        if (i % 2)
          p[i] = r--;
        else
          p[i] = l++;
        if (p[i - 2] > p[i - 1] && p[i - 1] < p[i]) t++;
        if (a == t) {
          while (l <= r) p[++i] = l++;
          break;
        }
      }
    } else {
      p[0] = 1;
      p[1] = n;
      for (int l = 2, r = n - 1, i = 2; i < n; i++) {
        if (i % 2 == 0)
          p[i] = l++;
        else
          p[i] = r--;
        if (p[i - 2] < p[i - 1] && p[i - 1] > p[i]) t++;
        if (b == t) {
          while (l <= r) p[++i] = r--;
          break;
        }
      }
    }
    for (int i = 0; i < n; i++) cout << p[i] << " ";
    cout << "\n";
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solvee();
  }
  return 0;
}
