#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long a[55];
long long b[55];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l[55];
    int r[55];
    int d[55];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      long long minn = a[i];
      int mini = i;
      for (int j = i + 1; j <= n; j++) {
        if (a[j] < minn) {
          minn = a[j];
          mini = j;
        }
      }
      long long temp = a[mini];
      for (int k = mini; k > i; k--) {
        a[k] = a[k - 1];
      }
      a[i] = temp;
      if (mini != i) {
        l[cnt] = i;
        r[cnt] = mini;
        d[cnt] = mini - i;
        cnt++;
      }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
      cout << l[i] << " " << r[i] << " " << d[i] << endl;
    }
  }
}
