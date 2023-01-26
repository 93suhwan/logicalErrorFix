#include <bits/stdc++.h>
using namespace std;
int ask(int a, int b, int c) {
  cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
  int r;
  cin >> r;
  return r;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int rel[n], q[n];
    q[0] = q[n - 1] = -1;
    rel[0] = rel[1] = rel[2] = 1;
    for (int i = 1; i < n - 1; ++i) q[i] = ask(i - 1, i, i + 1);
    int im1 = -1, im2 = -1;
    for (int i = 1; i < n - 2; ++i) {
      if (q[i] == q[i + 1]) {
        rel[i + 2] = rel[i - 1];
      } else {
        rel[i + 2] = -rel[i - 1];
        im1 = i - 1, im2 = i + 2;
      }
    }
    int type[n];
    type[0] = ask(im1, im2, 0);
    type[1] = ask(im1, im2, 1);
    type[2] = ask(im1, im2, 2);
    for (int i = 3; i < n; ++i) {
      type[i] =
          (rel[i - 3] == rel[i] ? type[i - 3] : (type[i - 3] == 0 ? 1 : 0));
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (type[i] == 0) ans.push_back(i);
    }
    cout << "! " << ans.size() << " ";
    for (auto u : ans) {
      cout << u + 1 << " ";
    }
    cout << endl;
  }
}
