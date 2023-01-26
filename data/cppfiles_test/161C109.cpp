#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n], b[n];
  vector<int> v1(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    for (int j = a[i]; j <= b[i]; j++) {
      v1[j]++;
    }
  }
  for (int i = 0; i < n; i++) {
    int x = n + 1, val = -1;
    for (int j = a[i]; j <= b[i]; j++) {
      if (v1[j] < x) {
        x = v1[j];
        val = j;
      }
    }
    cout << a[i] << " " << b[i] << " " << val << endl;
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  int a;
  cin >> a;
  while (a--) {
    solve();
    cout << endl;
  }
  return 0;
}
