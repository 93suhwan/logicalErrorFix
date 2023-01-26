#include <bits/stdc++.h>
using namespace std;
void time_assert(bool x) {
  while (!x) {
  }
}
struct test_case {
  bool win = false;
  const string DOWN = "Down";
  const string UP = "Up";
  const string DONE = "Done";
  int queries = 0;
  void place_queen(int r, int c) {
    if (++queries == 130) {
      exit(0);
    }
    assert(0 <= r && r < 8);
    assert(0 <= c && c < 8);
    r++;
    c++;
    cout << r << " " << c << endl;
  }
  string read_king() {
    string move;
    cin >> move;
    if (move == DONE) {
      win = true;
    }
    return move;
  }
  bool contains(string haystack, string needle) {
    return haystack.find(needle) != string::npos;
  }
  void solve() {
    int r = 0, c = 0;
    int dir = 1;
    int vis = 0;
    while (!win) {
      place_queen(r, c);
      vis |= 1 << c;
      string move = read_king();
      if (contains(move, DOWN)) {
        ++r;
        vis = 0;
        continue;
      }
      if (contains(move, UP)) {
        vis = 0;
      }
      if (vis == (1 << 8) - 1 && r + 2 < 8) {
        ++r;
        vis = 0;
        continue;
      }
      if (c == 7) {
        dir = -1;
      }
      if (c == 0) {
        dir = 1;
      }
      c += dir;
    }
  }
};
int main() {
  int te;
  cin >> te;
  while (te--) {
    test_case tc;
    tc.solve();
  }
  return 0;
}
