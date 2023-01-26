#include <bits/stdc++.h>
using namespace std;
void _() {
  int n;
  cin >> n;
  auto query = [&](int num, int val) {
    vector<int> V(n, val);
    V[n - 1] = num;
    cout << "? ";
    for (auto& v : V) cout << v << ' ';
    cout << endl;
    int X;
    cin >> X;
    return X;
  };
  int O = 2;
  int X = query(1, O++);
  queue<int> smaller;
  while (X && O <= n) {
    smaller.push(X - 1);
    X = query(1, O++);
  }
  int o = 2;
  int x = query(o++, 1);
  queue<int> larger;
  while (x && o <= n) {
    larger.push(x - 1);
    x = query(o++, 1);
  }
  vector<int> ans(n);
  ans[n - 1] = (int)(smaller).size() + 1;
  int r = 1;
  while (!smaller.empty()) {
    ans[smaller.front()] = ans[n - 1] - r++;
    smaller.pop();
  }
  r = 1;
  while (!larger.empty()) {
    ans[larger.front()] = ans[n - 1] + r++;
    larger.pop();
  }
  cout << "! ";
  for (auto& a : ans) cout << a << ' ';
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) _();
  return 0;
}
