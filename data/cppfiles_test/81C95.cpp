#include <bits/stdc++.h>
using namespace std;
char prime[] = {'2', '3', '5', '7'};
void solveA() {
  int l, r;
  cin >> l >> r;
  if (r == l) {
    cout << 0 << "\n";
    return;
  }
  if (l <= r / 2 + 1) {
    cout << (r + 1) / 2 - 1 << "\n";
    return;
  }
  cout << r % l << "\n";
  return;
}
void solveB() {
  int k;
  cin >> k;
  string n;
  cin >> n;
  int check[11] = {};
  int ret = 0, jj;
  for (int i = 0; i < k; i++) {
    int che = 1;
    for (int j = 0; j < 4; j++) {
      if (n[i] == prime[j]) {
        che = 0;
        if ((prime[j] == '2' || prime[j] == '5') && i != 0) {
          ret = 1;
          jj = j;
        }
        check[prime[j] - '0']++;
      }
    }
    if (che) {
      cout << 1 << "\n";
      cout << n[i] << "\n";
      return;
    }
  }
  if (ret) {
    cout << 2 << "\n";
    cout << n[0] << prime[jj] << "\n";
    return;
  }
  for (int i = 0; i < 10; i++) {
    if (check[i] >= 2) {
      cout << 2 << "\n";
      cout << i << i << "\n";
      return;
    }
  }
  if (check[5] == 1 && check[7] == 1) {
    cout << 2 << "\n";
    cout << 57 << "\n";
    return;
  } else {
    cout << 2 << "\n";
    cout << 27 << "\n";
    return;
  }
}
void solveC() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  for (int i = 0; i < n; i++) {
    if (a[i] == '0') {
      if (i >= n / 2) {
        cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
        return;
      } else {
        cout << i + 2 << " " << n << " " << i + 1 << " " << n << "\n";
        return;
      }
    }
  }
  cout << "1 " << n - 1 << " 2 " << n << "\n";
}
void solveD() {
  int n, q, a;
  cin >> n >> q;
  int prefix[n + 1];
  char c;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    a = -1;
    if (c == '+') a = 1;
    a = (i % 2 == 1 ? a : -a);
    prefix[i] = prefix[i - 1] + a;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if ((r - l + 1) % 2 == 1) {
      cout << "1\n";
      continue;
    }
    if (prefix[r] - prefix[l - 1] == 0) {
      cout << "0\n";
      continue;
    }
    cout << "2\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solveD();
  }
}
