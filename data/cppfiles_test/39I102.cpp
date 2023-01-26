#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n, -1);
  int s = -1;
  for (int i = 0; i < n; i++) {
    cout << "? ";
    for (int j = 0; j < i; j++) cout << "1 ";
    cout << "2 ";
    for (int j = i + 1; j < n; j++) cout << "1 ";
    cout << endl;
    int k;
    cin >> k;
    if (k != i + 1) {
      if (k)
        a[k - 1] = i;
      else
        s = i;
    }
    cout << "? ";
    for (int j = 0; j < i; j++) cout << "2 ";
    cout << "1 ";
    for (int j = i + 1; j < n; j++) cout << "2 ";
    cout << endl;
    cin >> k;
    if (k) a[i] = k - 1;
  }
  vector<int> b(n);
  b[s] = n;
  int cur = n - 1, j = a[s];
  while (j) {
    b[j] = cur--;
    j = a[j];
  }
  b[j] = 1;
  cout << "! ";
  for (int i = 0; i < n; i++) cout << b[i] << ' ';
  cout << endl;
  return 0;
}
