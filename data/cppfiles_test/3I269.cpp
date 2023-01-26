#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, i, j, k = 0, l = 0;
  string a;
  cin >> a;
  l = a.size() - 1;
  for (i = 0; i < a.size(); i++) {
    if (a[i] >= '0' && a[i] <= '9')
      continue;
    else
      k = 1;
  }
  if (k == 0) {
    k = stoi(a);
    if (k % 25)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  } else if (a.size() == 1 && (a[0] == '0' || a[0] == '_' || a[0] == 'X'))
    cout << 1 << endl;
  else if (a.size() == 2) {
    if (a[l] == 'X' && a[l - 1] == 'X')
      cout << 1 << endl;
    else if (a[l] == '_' && a[l - 1] == '_')
      cout << 3 << endl;
    else if (a[l] == '_' &&
             (a[l - 1] == '0' || a[l - 1] == '7' || a[l - 1] == '2'))
      cout << 1 << endl;
    else if (a[l - 1] == '_' && a[l] == '5')
      cout << 2 << endl;
    else if (a[l - 1] == '_' && a[l] == '0')
      cout << 1 << endl;
    else if (a[l - 1] == 'X' && (a[l] == '0' || a[l] == '5'))
      cout << 1 << endl;
    else if (a[l] == 'X' &&
             (a[l - 1] == '0' || a[l - 1] == '7' || a[l - 1] == '2'))
      cout << 1 << endl;
    else
      cout << 0 << endl;
  } else if (a[l] >= '0' && a[l] <= '9' && a[l - 1] >= '0' && a[l - 1] <= '9') {
    j = 0;
    m = (a[l - 1] - '0') * 10 + (a[l] - '0');
    if (m % 25)
      cout << 0 << endl;
    else {
      for (i = 0; i <= l; i++) {
        if (a[i] == '_') j++;
      }
      if (a[0] == '_')
        cout << pow(9, j - 1) + 8 << endl;
      else
        cout << pow(9, j) << endl;
    }
  } else {
    j = 0;
    if (a[l] == 'X' && a[l - 1] == 'X' && a[0] != 'X' && a[0] != '_') {
      for (i = 0; i <= l; i++) {
        if (a[i] == '_') j++;
      }
      cout << pow(9, j) << endl;
    } else if (a[l] == 'X' && a[l - 1] == 'X' && a[0] == 'X')
      cout << 0 << endl;
    else if (a[l] == 'X' && a[l - 1] == 'X' && a[0] == '_') {
      for (i = 1; i <= l; i++) {
        if (a[i] == '_') j++;
      }
      cout << pow(9, j) + 8 << endl;
    }
  }
  return 0;
}
