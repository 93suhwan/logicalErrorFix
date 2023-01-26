#include <bits/stdc++.h>
using namespace std;
int a[10006];
vector<int> vx;
void test() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];
  if (a[N] == 0) {
    for (int i = 1; i <= N; i++) {
      cout << i << ' ';
    }
    cout << N + 1 << endl;
  } else {
    int Q = -1;
    for (int i = N; i >= 1; i--) {
      if (a[i] == 0) {
        Q = i;
        break;
      }
    }
    if (Q == -1) {
      cout << -1 << endl;
    } else {
      vx.clear();
      for (int i = 1; i <= Q; i++) vx.push_back(i);
      vx.push_back(N + 1);
      for (int i = Q + 1; i <= N; i++) vx.push_back(i);
      for (int i = 0; i <= N; i++) {
        cout << vx[i];
        if (i == N)
          cout << endl;
        else
          cout << ' ';
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) test();
}
