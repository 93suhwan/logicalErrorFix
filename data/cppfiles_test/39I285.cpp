#include <bits/stdc++.h>
using namespace std;
int p[1010];
int r[1010];
int q[1010];
int cnt;
int main() {
  int n;
  cin >> n;
  fflush(stdout);
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n; j++) q[j] = 1;
    q[i] = 0;
    cout << "? ";
    fflush(stdout);
    for (int j = 1; j <= n; j++) {
      cout << q[j] << ' ';
      fflush(stdout);
    }
    cout << endl;
    int pt;
    cin >> pt;
    fflush(stdout);
    if (pt < i) r[pt] = i;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n; j++) q[j] = 0;
    q[i] = 1;
    cout << "? ";
    fflush(stdout);
    for (int j = 1; j <= n; j++) {
      cout << q[j] << ' ';
      fflush(stdout);
    }
    cout << endl;
    fflush(stdout);
    int pt;
    cin >> pt;
    fflush(stdout);
    if (pt < i) r[i] = pt;
  }
  int pt = r[0], cnt = 0;
  while (pt) {
    p[pt] = ++cnt;
    pt = r[pt];
  }
  cout << "! ";
  fflush(stdout);
  for (int i = 1; i <= n; i++) {
    cout << p[i] << ' ';
    fflush(stdout);
  }
  return 0;
}
