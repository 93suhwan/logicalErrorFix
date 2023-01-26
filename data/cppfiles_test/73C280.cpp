#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int count = 0;
    while (1) {
      if (is_sorted(a.begin(), a.end())) {
        break;
      }
      count++;
      if (count % 2 == 1) {
        for (int i = 0; i < n; i += 2) {
          if (i < n - 1 && a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        }
      } else {
        for (int i = 1; i < n; i += 2) {
          if (i < n - 1 && a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        }
      }
    }
    printf("%d\n", count);
  }
}
int main() { solve(); }
