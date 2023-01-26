#include <bits/stdc++.h>
using namespace std;
int a[200005];
void solve() {
  int n;
  scanf("%d", &n);
  map<int, bool> cnt;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]] = 1;
  }
  sort(a, a + n);
  int num = n / 2;
  for (int i = 0; i < n - 1; i++) {
    if (!num) return;
    int mod = a[i + 1] % a[i];
    if (!cnt[mod]) {
      cout << a[i + 1] << ' ' << a[i] << endl;
      num--;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
