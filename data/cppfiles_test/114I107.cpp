#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
map<int, int> v;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = n; i > n / 2; i--) {
      cout << a[i] << ' ' << a[1] << endl;
    }
  }
}
