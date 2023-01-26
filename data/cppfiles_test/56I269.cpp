#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6 + 5;
long long int op;
string ask(long long int x, long long int y) {
  op++;
  if (op > 130) exit(0);
  cout << x << " " << y << endl;
  string str;
  cin >> str;
  return str;
}
bool check(string str) {
  if (str == "Done") return 1;
  return 0;
}
bool down(string str) {
  if (str[0] == 'D') return 1;
  return 0;
}
bool up(string str) {
  if (str[0] == 'U') return 1;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    string curr = ask(1, 8);
    if (check(curr)) continue;
    long long int x = 1;
    long long int y = 1;
    bool done = 0;
    op = 0;
    while (1) {
      long long int c = 1;
      bool good = 0;
      bool bad = 0;
      while (c <= 8) {
        curr = ask(x, c);
        if (check(curr)) {
          done = 1;
          break;
        }
        if (down(curr)) {
          y = c;
          good = 1;
          break;
        }
        if (up(curr)) bad = 1;
        c++;
      }
      if (done) break;
      if (!bad && c == 9) {
        good = 1;
        y = 8;
      }
      while (good) {
        x++;
        curr = ask(x, y);
        if (check(curr)) {
          done = 1;
          break;
        }
        if (down(curr))
          good = 1;
        else
          good = 0;
      }
      if (done) break;
      if (y != 8) curr = ask(x, 8);
      y = 8;
      done = check(curr);
      if (done) break;
    }
  }
}
