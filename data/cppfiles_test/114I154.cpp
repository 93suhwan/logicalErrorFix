#include <bits/stdc++.h>
using namespace std;
int yh() {
  int ret = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == EOF) return -1;
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) ret = (ret << 3) + (ret << 1) + (c ^ 48), c = getchar();
  return f ? -ret : ret;
}
const int maxn = 3e5 + 5;
vector<int> a[10];
long long c[10];
long long w[10];
int n;
set<long long> il;
int hd[10];
int main() {
  n = yh();
  for (int i = 0, iss = (n); i < iss; i++) {
    c[i] = yh();
    a[i].resize(c[i]);
    for (int& x : a[i]) x = yh();
  }
  w[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) w[i] = w[i + 1] * c[i + 1];
  int m = yh();
  long long sum = 0;
  for (int i = 0, iss = (m); i < iss; i++) {
    sum = 0;
    for (int j = 0, jss = (n); j < jss; j++) sum += w[j] * (yh() - 1);
    il.insert(sum);
  }
  sum = 0;
  for (int i = 0, iss = (n); i < iss; i++)
    hd[i] = c[i] - 1, sum += hd[i] * w[i];
  while (il.count(sum)) {
    int best = -1, val = -0x3f3f3f;
    for (int i = 0, iss = (n); i < iss; i++) {
      if (best == -1 || (hd[i] > 0 && a[i][hd[i] - 1] - a[i][hd[i]] > val)) {
        val = a[i][hd[i] - 1] - a[i][hd[i]];
        best = i;
      }
    }
    sum -= w[best];
    hd[best]--;
  }
  for (int i = 0, iss = (n); i < iss; i++) cout << hd[i] + 1 << ' ';
  cout << '\n';
  return 0;
}
