#include <bits/stdc++.h>
using namespace std;
int fun(string &X, int i, string &Y, int j) {
  if (i == X.size()) {
    return Y.size() - j;
  }
  if (j >= Y.size()) {
    return X.size() - i;
  }
  if (X[i] == Y[j])
    return fun(X, i + 1, Y, j + 1);
  else {
    return 1 + fun(X, i + 1, Y, j);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  vector<string> pre(60);
  long long num = 1;
  for (int i = 0; i < 60; i++) {
    pre[i] = to_string(num);
    num *= 2;
  }
  while (t--) {
    long long n;
    cin >> n;
    int ans = 11;
    string num = to_string(n);
    for (int i = 0; i < pre.size(); i++) {
      int x = fun(num, 0, pre[i], 0);
      ans = min(x, ans);
    }
    cout << ans << "\n";
  }
}
