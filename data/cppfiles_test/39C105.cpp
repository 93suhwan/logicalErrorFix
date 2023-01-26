#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, mn, dif, id, a[N];
vector<int> v;
int tl;
void solve() {
  bool first = 1, dg = 1;
  for (int i = n; i > 1; i--) {
    cout << "? ";
    for (int j = 1; j < n; j++) cout << i << ' ';
    cout << 1 << endl;
    cin >> tl;
    if (tl) {
      if (first) a[n] = i;
      v.push_back(tl);
      first = 0;
    }
  }
  if (first) dg = 0;
  for (int i = n - 1; i > 0; i--) {
    cout << "? ";
    for (int j = 1; j < n; j++) cout << i << ' ';
    cout << n << endl;
    cin >> tl;
    if (tl) {
      v.push_back(tl);
    }
  }
  if (dg) {
    for (int i = 0, j = 1; i < v.size(); i++, j++) {
      if (j == a[n]) j++;
      a[v[i]] = j;
    }
  } else {
    a[n] = 1;
    for (int i = 0, j = 2; i < v.size(); i++, j++) {
      a[v[i]] = j;
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}
int main() {
  cin >> n;
  solve();
}
