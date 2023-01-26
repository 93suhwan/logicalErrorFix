#include <bits/stdc++.h>
using namespace std;
map<int, int> mp, tp;
int a[200050];
int main() {
  int t;
  cin >> t;
  while (t--) {
    mp.clear();
    tp.clear();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mp[a[i]] = 1;
    }
    sort(a + 1, a + n + 1);
    int num = n / 2;
    for (int i = 1; i <= n; i++) {
      if (num == 0) break;
      for (int j = 1; j <= n; j++) {
        if (mp[a[i] % a[j]]) {
          break;
        }
        if (tp[a[i]] == a[j] || tp[a[j]] == a[i]) {
          continue;
        }
        tp[a[i]] = a[j];
        tp[a[j]] = a[i];
        if (a[i] == a[j]) {
          continue;
        }
        cout << a[i] << " " << a[j] << endl;
        num--;
        if (num == 0) break;
      }
    }
  }
  return 0;
}
