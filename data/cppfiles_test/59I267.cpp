#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
struct node {
  int id, w[10];
} p[maxn];
int n;
int q[10];
int qq[10];
bool cmpa(node a, node b) { return a.w[1] > b.w[1]; }
bool cmpb(node a, node b) { return a.w[2] > b.w[2]; }
bool cmpc(node a, node b) { return a.w[3] > b.w[3]; }
bool cmpd(node a, node b) { return a.w[4] > b.w[4]; }
bool cmpe(node a, node b) { return a.w[5] > b.w[5]; }
void sortit(int x) {
  if (x == 1)
    sort(p + 1, p + 1 + n, cmpa);
  else if (x == 2)
    sort(p + 1, p + 1 + n, cmpb);
  else if (x == 3)
    sort(p + 1, p + 1 + n, cmpc);
  else if (x == 3)
    sort(p + 1, p + 1 + n, cmpd);
  else if (x == 5)
    sort(p + 1, p + 1 + n, cmpe);
}
void solve() {
  cin >> n;
  if (n & 1) {
    cout << "NO" << endl;
    return;
  }
  memset(q, 0, sizeof(q));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 5; j++) {
      cin >> p[i].w[j];
      if (p[i].w[j]) q[j]++;
    }
  for (int i = 1; i <= 5; i++) {
    if (q[i] < n / 2) continue;
    sortit(i);
    memset(qq, 0, sizeof(qq));
    for (int ii = n / 2 + 1; ii <= n; ii++)
      for (int j = 1; j <= 5; j++)
        if (j != i) qq[j] += p[ii].w[j];
    for (int ii = 1; ii <= 5; ii++)
      if (qq[ii] == n / 2) {
        cout << "YES" << endl;
        return;
      }
  }
  cout << "NO" << endl;
}
int main() {
  int __;
  cin >> __;
  while (__--) solve();
}
