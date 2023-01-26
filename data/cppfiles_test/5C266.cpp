#include <bits/stdc++.h>
using namespace std;
const bool read_file = false;
const char fi[] = "XX.INP";
const char fo[] = "XX.OUT";
void set_up() {
  if (read_file) {
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
  }
  cin.clear();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void just_do_it();
int main() {
  set_up();
  just_do_it();
}
int t, n;
char c;
const int ms = 2e5 + 20;
int a[ms];
int b[ms];
int res;
void query() {
  cin >> n;
  a[0] = -1;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    a[i] = c - '0';
  }
  a[n + 1] = -1;
  b[0] = -1;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    b[i] = c - '0';
  }
  b[n + 1] = -1;
  res = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i] == 1) {
      if (a[i - 1] == 1) {
        a[i - 1] = -1;
        res++;
      } else if (a[i] == 0) {
        a[i] = -1;
        res++;
      } else if (a[i + 1] == 1) {
        a[i + 1] = -1;
        res++;
      }
    }
  }
  cout << res << endl;
}
void just_do_it() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    query();
  }
}
