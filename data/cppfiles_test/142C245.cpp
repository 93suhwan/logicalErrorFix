#include <bits/stdc++.h>
using namespace std;
const bool kami_loc = false;
const string kami_fi = "kamirulez.inp";
const string kami_fo = "kamirulez.out";
void file_io(string fi, string fo) {
  if (fi != "" && (!kami_loc || fi == kami_fi)) {
    freopen(fi.c_str(), "r", stdin);
  }
  if (fo != "" && (!kami_loc || fo == kami_fo)) {
    freopen(fo.c_str(), "w", stdout);
  }
}
void set_up() {
  if (kami_loc) {
    file_io(kami_fi, kami_fo);
  }
  cin.clear();
  cout.clear();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void just_do_it();
void just_exec_it() {
  if (kami_loc) {
    auto pstart = chrono::steady_clock::now();
    just_do_it();
    auto pend = chrono::steady_clock::now();
    int ptime =
        chrono::duration_cast<chrono::milliseconds>(pend - pstart).count();
    string bar(50, '=');
    cout << '\n' << bar << '\n';
    cout << "Time: " << ptime << " ms" << '\n';
  } else {
    just_do_it();
  }
}
int main() {
  set_up();
  just_exec_it();
}
void query() {
  int m, n;
  cin >> m >> n;
  int a[m][n];
  int t = 1e9 + 7;
  int s, f1, f2;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 0; j < n; j++) {
    s = -1;
    for (int i = 0; i < m; i++) {
      s = max(s, a[i][j]);
    }
    t = min(s, t);
  }
  int res = -1;
  for (int i = 0; i < m; i++) {
    f1 = -1;
    f2 = -1;
    for (int j = 0; j < n; j++) {
      if (a[i][j] > f1) {
        f2 = f1;
        f1 = a[i][j];
      } else if (a[i][j] > f2) {
        f2 = a[i][j];
      }
    }
    if (f2 > t) {
      res = max(res, t);
    } else {
      res = max(res, f2);
    }
  }
  cout << res << '\n';
}
void just_do_it() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    query();
  }
}
