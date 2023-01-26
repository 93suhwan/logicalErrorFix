#include <bits/stdc++.h>
using namespace std;
int gcdeuclid(int a, int b) {
  if (a == 0) {
    return b;
  }
  return gcdeuclid(b % a, a);
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans[n];
  if (n % 2 == 0) {
    int count = 0;
    int i = 0;
    int j = n - 1;
    while (count <= n / 2) {
      ans[i] = -a[j];
      ans[j] = a[i];
      i++;
      j--;
      count++;
    }
  } else {
    int count = 0;
    int i = 0;
    int j = n - 1;
    while (count < ((n / 2) - 1)) {
      ans[i] = -a[j];
      ans[j] = a[i];
      i++;
      j--;
      count++;
    }
    ans[i] = -a[i + 1];
    ans[j] = a[i + 1];
    ans[i + 1] = (a[i] - a[j]);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
