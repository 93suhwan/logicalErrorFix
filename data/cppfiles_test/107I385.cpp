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
  if (a == 0 && b == 0) {
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << "\n";
    return;
  }
  if (abs(a - b) > 1 || max(a, b) > (n - 1) / 2) {
    cout << "-1\n";
  } else {
    int t = 0;
    int p[n + 1];
    if (a > b) {
      for (int i = 1, k = 1; k <= a; i += 2, k++) p[i] = k;
      for (int i = 2, k = n; k > n - a; i += 2, k--) p[i] = k;
      for (int i = a * 2 + 1, k = n - a; i <= n; i++, k--) p[i] = k;
    }
    if (a <= b) {
      for (int i = 2, k = 1; k <= b; i += 2, k++) p[i] = k;
      for (int i = 1, k = n; k > n - b; i += 2, k--) p[i] = k;
      if (a == b)
        for (int i = b * 2 + 1, k = n - b; i <= n; k--, i++) p[i] = k;
      else
        for (int i = b * 2 + 1, k = b + 1; i <= n; k++, i++) p[i] = k;
    }
    for (int i = 1; i <= n; i++) cout << p[i] << " ";
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
