#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int N = 2e5 + 5;
int a[N];
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int freq[N];
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    int ans = 1;
    for (int i = 0; i < x; i++) {
      cin >> a[i];
    }
    if (a[0] == 1) ans++;
    for (int i = 1; i < x; i++) {
      if (a[i] == 0 && a[i - 1] == 0) {
        ans = -1;
        break;
      } else if (a[i] == 1 and a[i - 1] == 1) {
        ans += 5;
      } else if (a[i] == 1 and a[i - 1] == 0)
        ans++;
    }
    cout << ans << endl;
  }
}
