#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
long long a[N];
int main() {
  clock_t c1 = clock();
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int max = 1;
    cin >> a[1];
    for (int i = 2; i <= n; i++) {
      cin >> a[i];
      if (a[max] <= a[i]) max = i;
    }
    int cnt = 0;
    for (int i = n - 1; i >= max; i--) {
      if (a[n] < a[max] && a[i] > a[n]) {
        cnt++;
        a[n] = a[i];
      }
    }
    cout << cnt << endl;
  }
end:
  cerr << "Time Used:" << clock() - c1 << "ms" << endl;
  return 0;
}
