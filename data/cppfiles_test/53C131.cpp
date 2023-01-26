#include <bits/stdc++.h>
using namespace std;
int t;
int n, k;
vector<int> a(100005), b(100005);
map<int, int> c;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    b = a;
    sort(b.begin(), b.begin() + n);
    for (int i = 0; i < n; i++) {
      c[b[i]] = i;
    }
    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
      if (c[a[i]] != c[a[i + 1]] - 1) {
        cnt++;
      }
    }
    if (cnt > k) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
    c.clear();
  }
  return 0;
}
