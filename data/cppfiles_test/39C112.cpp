#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int n, a[1000007], b[1000007], tot;
int ask() {
  cout << "? ";
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << endl, tot++;
  int out = 0;
  cin >> out;
  return out;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = 1;
  int p = 0;
  for (int i = 1; i <= n; i++) {
    a[n]++;
    if (i != n)
      p = ask();
    else
      p = 0;
    if (!p) {
      b[n] = n - i + 1;
      for (int j = 1; j <= n - 1; j++)
        if (b[j]) b[j] += b[n];
      break;
    } else
      b[p] = i;
  }
  a[n] = 1;
  for (int i = 1; i <= b[n] - 1; i++) {
    for (int j = 1; j <= n - 1; j++)
      if (b[j])
        a[j] = n;
      else
        a[j] = i + 1;
    b[ask()] = b[n] - i;
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << b[i] << ' ';
  cout << endl;
}
