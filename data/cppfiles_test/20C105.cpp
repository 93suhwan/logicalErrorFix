#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
const int mod = 1e9 + 7;
int t, n, k, a[MAX], s[MAX], L[MAX], R[MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  int x = n;
  n *= k;
  int cap = (x + k - 2) / (k - 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (L[a[i]]) continue;
    int top = s[i];
    for (int j = i - 1; j >= 1; j--) {
      top = max(top, s[j]);
      if (top >= cap) break;
      if (a[i] == a[j]) {
        L[a[i]] = j;
        R[a[i]] = i;
        for (int k = j; k <= i; k++) s[k]++;
        break;
      }
    }
  }
  for (int i = 1; i <= x; i++) {
    cout << L[i] << ' ' << R[i] << '\n';
  }
}
