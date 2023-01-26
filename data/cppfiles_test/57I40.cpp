#include <bits/stdc++.h>
using namespace std;
vector<int> a(2021), b(2021), ans(0);
void rev(int x) {
  ans.push_back(x);
  for (int i = (0); i < (x / 2); i++) {
    swap(a[i], a[x - 1 - i]);
    swap(b[a[i]], b[a[x - 1 - i]]);
  }
}
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    bool f = false;
    for (int i = (0); i < (n); i++) {
      cin >> a[i];
      a[i]--;
      b[a[i]] = i;
      if ((i + a[i]) % 2) f = true;
    }
    if (f) {
      cout << -1 << endl;
      continue;
    }
    for (int i = n - 1; i > 0; i -= 2) {
      if (a[i] == i && a[i - 1] == i - 1) continue;
      if (b[i - 1] < b[i]) {
        rev(b[i] + 1);
      }
      if (b[i - 1] != 1) {
        rev(b[i - 1]);
        rev(b[i - 1] + 2);
        rev(3);
      }
      rev(i + 1);
    }
    cout << ans.size() << endl;
    for (int i = (0); i < (ans.size()); i++) {
      cout << ans[i];
      if (i < ans.size() - 1) cout << " ";
    }
    cout << endl;
  }
}
