#include <bits/stdc++.h>
using namespace std;
int t;
int n, k;
vector<int> a(100005);
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        cnt++;
      }
    }
    if (cnt > k) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
