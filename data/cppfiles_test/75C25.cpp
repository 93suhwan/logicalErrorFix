#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> x, y;
  x.push_back(a[0]);
  y.push_back(a[n - 1]);
  int xx = 0, yy = n - 1;
  for (int i = 1; i < n; ++i)
    if (a[i] > a[i - 1])
      x.push_back(a[i]);
    else {
      xx = i - 1;
      break;
    }
  for (int i = n - 2; i >= 0; --i)
    if (a[i] > a[i + 1])
      y.push_back(a[i]);
    else {
      yy = i + 1;
      break;
    }
  bool overlap = (xx == yy);
  int i = 0, j = 0, lenx = x.size(), leny = y.size();
  bool alice = true;
  while (i < lenx && j < leny) {
    if (x[i] == y[j]) {
      if (((lenx - i) % 2 == 0) && ((leny - j) % 2 == 0)) alice = !alice;
      break;
    } else if (x[i] > y[j]) {
      if ((lenx - i) % 2 == 1) break;
      alice = !alice;
      j++;
    } else if (x[i] < y[j]) {
      if ((leny - j) % 2 == 1) break;
      alice = !alice;
      i++;
    }
  }
  if (i == lenx) {
    int t = leny - j - overlap;
    if (t % 2 == 0) alice = !alice;
  } else if (j == leny) {
    int t = lenx - i - overlap;
    if (t % 2 == 0) alice = !alice;
  }
  cout << (alice ? "Alice" : "Bob") << endl;
  return 0;
}
