#include <bits/stdc++.h>
using namespace std;
int T, n, kkk, acdasc;
int a[100];
void swap(int ll, int rr) {
  int tmp = a[ll];
  for (int i = ll; i < rr; i++) {
    a[i] = a[i + 1];
  }
  a[rr] = tmp;
}
queue<pair<int, int> > q1;
int main() {
  cin >> T;
  for (int kk = 1; kk <= T; kk++) {
    cin >> n;
    memset(a, 0, sizeof(a));
    int jkads = 26 + 7;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = n; i >= 1; --i) {
      for (int j = i - 1; j >= 1; j--) {
        if (a[i] < a[j]) {
          swap(j, i);
          q1.push(make_pair(j, i));
        }
      }
    }
    int oo = 111;
    cout << q1.size() << endl;
    while (q1.size()) {
      cout << q1.front().first << " " << q1.front().second << " " << 1 << endl;
      q1.pop();
    }
  }
}
