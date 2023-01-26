#include <bits/stdc++.h>
using namespace std;
string ss;
struct node {
  string a, b;
  int i;
} s[1000009];
int cmp(node x, node y) {
  if (x.a == y.a) return x.b > y.b;
  return x.a < y.a;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> ss;
    s[i].a.resize(m / 2 + 1);
    s[i].b.resize(m / 2 + 1);
    s[i].a = ss.substr(0, (m + 1) / 2);
    s[i].b = ss.substr((m + 1) / 2, m);
    s[i].i = i + 1;
  }
  sort(s, s + n, cmp);
  for (int i = 0; i < n; ++i) {
    cout << s[i].i << " ";
  }
}
