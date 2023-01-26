#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
string s[N];
int n;
int a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      maxx = max(a[i], maxx);
    }
    int cnt = 0;
    for (int i = n; i > 0; i--) {
      if (a[i] == maxx - 1) {
        cnt++;
        break;
      }
      if (a[i] == maxx) break;
      cnt++;
    }
    cout << cnt << endl;
  }
}
