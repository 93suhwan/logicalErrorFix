#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int alice;
  int bob;
  int I = 0;
  int J = n - 1;
  int f;
  int AF = 0;
  int BF = 0;
  if (a[0] <= a[n - 1]) {
    alice = a[0];
    f = 1;
    I++;
    AF = 1;
  } else {
    alice = a[n - 1];
    J--;
    f = 1;
    AF = 1;
  }
  for (int i = 1; i < n; ++i) {
    if (f == 1) {
      if (a[I] <= a[J] && alice <= a[I]) {
        bob = a[I];
        I++;
        f = 0;
        BF = 1;
        AF = 0;
      } else if (a[I] <= a[J] && alice <= a[J]) {
        bob = a[J];
        J--;
        f = 0;
        BF = 1;
        AF = 0;
      } else if (a[J] <= a[I] && alice <= a[J]) {
        bob = a[J];
        J--;
        f = 0;
        BF = 1;
        AF = 0;
      } else if (a[J] <= a[I] && alice <= a[I]) {
        bob = a[I];
        I++;
        f = 0;
        BF = 1;
        AF = 0;
      } else {
        break;
      }
    } else {
      if (a[I] <= a[J] && bob <= a[I]) {
        alice = a[I];
        I++;
        f = 1;
        BF = 0;
        AF = 1;
      } else if (a[I] <= a[J] && bob <= a[J]) {
        alice = a[J];
        J--;
        f = 1;
        BF = 0;
        AF = 1;
      } else if (a[J] <= a[I] && bob <= a[J]) {
        alice = a[J];
        J--;
        f = 1;
        BF = 0;
        AF = 1;
      } else if (a[J] <= a[I] && bob <= a[I]) {
        alice = a[I];
        I++;
        f = 1;
        BF = 0;
        AF = 1;
      } else {
        break;
      }
    }
  }
  if (AF) {
    cout << "Alice";
  } else {
    cout << "Bob";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  cout << "\n";
  return 0;
}
