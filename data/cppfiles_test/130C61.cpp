#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, one, zer, a[N], b[3], c[N];
int query(int a, int b, int c) {
  printf("? %d %d %d\n", a + 1, b + 1, c + 1);
  fflush(stdout);
  int res;
  cin >> res;
  return res;
}
void solve0(int i) {
  if (query(i, i + 1, one) == 0) {
    if (query(i, i + 2, one) == 0)
      c[i] = c[i + 1] = c[i + 2] = 0;
    else
      c[i] = c[i + 1] = 0, c[i + 2] = 1;
  } else {
    if (query(i, i + 2, one) == 0)
      c[i] = c[i + 2] = 0, c[i + 1] = 1;
    else
      c[i] = 1, c[i + 1] = c[i + 2] = 0;
  }
}
void solve1(int i) {
  if (query(i, i + 1, zer) == 0) {
    if (query(i, i + 2, zer) == 0)
      c[i] = 0, c[i + 1] = c[i + 2] = 1;
    else
      c[i] = c[i + 2] = 1, c[i + 1] = 0;
  } else {
    if (query(i, i + 2, zer) == 0)
      c[i] = c[i + 1] = 1, c[i + 2] = 0;
    else
      c[i] = c[i + 1] = c[i + 2] = 1;
  }
}
void presolve() {
  int cnt = 0, cnt2 = 0;
  for (int j = 0; j < 3; ++j) {
    b[j] = query(one, one + 1, zer + j);
    cnt += b[j];
  }
  for (int j = 0; j < 3; ++j) {
    b[j] = query(one, one + 2, zer + j);
    cnt2 += b[j];
  }
  if (cnt == 3) {
    if (cnt2 == 3)
      c[one] = c[one + 1] = c[one + 2] = 1;
    else
      c[one] = c[one + 1] = 1, c[one + 2] = 0;
  } else {
    if (cnt2 == 3)
      c[one] = c[one + 2] = 1, c[one + 1] = 0;
    else
      c[one] = 0, c[one + 1] = c[one + 2] = 1;
  }
  if (c[one] != 1) one += 1;
  solve0(zer);
  if (c[zer] != 0) zer += 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) c[i] = -1;
    for (int i = 0; i < n; i += 3) {
      a[i] = query(i, i + 1, i + 2);
      if (a[i] == 1)
        one = i;
      else
        zer = i;
    }
    presolve();
    for (int i = 0; i < n; i += 3)
      if (c[i] == -1) {
        if (a[i] == 0)
          solve0(i);
        else
          solve1(i);
      }
    vector<int> ans;
    for (int i = 0; i < n; ++i)
      if (!c[i]) ans.push_back(i + 1);
    printf("! %d", ((int)(ans).size()));
    for (int &x : ans) printf(" %d", x);
    printf("\n");
    fflush(stdout);
  }
}
