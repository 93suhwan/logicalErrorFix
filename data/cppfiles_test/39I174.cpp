#include <bits/stdc++.h>
using namespace std;
int p[1010];
int r[1010];
int q[1010];
int cnt;
int main() {
  int n;
  cin >> n;
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n; j++) q[j] = 1;
    q[i] = 0;
    cout << "? ";
    for (int j = 1; j <= n; j++) {
      cout << q[j] << ' ';
    }
    cout << endl;
    int pt;
    cin >> pt;
    if (pt < i) r[pt] = i;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n; j++) q[j] = 0;
    q[i] = 1;
    cout << "? ";
    for (int j = 1; j <= n; j++) {
      cout << q[j] << ' ';
    }
    cout << endl;
    int pt;
    cin >> pt;
    if (pt < i) r[i] = pt;
  }
  int pt = r[0], cnt = 0;
  while (pt) {
    p[pt] = ++cnt;
    pt = r[pt];
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << p[i] << ' ';
  }
  return 0;
}
