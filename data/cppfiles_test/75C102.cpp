#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n), l, r;
  for (auto &e : a) cin >> e;
  l.push_back(a[0]);
  r.push_back(a.back());
  for (int i = 1; i < n; i++)
    if (a[i] > a[i - 1])
      l.push_back(a[i]);
    else
      break;
  for (int i = n - 2; i >= 0; i--)
    if (a[i] > a[i + 1])
      r.push_back(a[i]);
    else
      break;
  int turn = 0, li = 0, ri = 0;
  while (1) {
    int l_left = l.size() - li, r_left = r.size() - ri;
    if (l[li] >= r[ri] && (l_left & 1)) break;
    if (r[ri] >= l[li] && (r_left & 1)) break;
    if (l[li] == r[ri]) {
      turn = !turn;
      break;
    }
    if (l[li] < r[ri]) {
      if (li == l.size() - 1) {
        break;
      }
      li++;
    } else {
      if (ri == r.size() - 1) {
        break;
      }
      ri++;
    }
    turn = !turn;
  }
  if (turn)
    cout << "Bob";
  else
    cout << "Alice";
}
