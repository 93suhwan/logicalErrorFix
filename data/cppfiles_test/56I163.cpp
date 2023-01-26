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
  const int XX = 8;
  void place_queen(int r, int c) {
    if (++queries == 130) {
      cout << "Oh no :(\n";
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
    int r = 0, c = 1;
    int last_up = -100;
    int dir = 1;
    while (!win) {
      place_queen(r, c);
      string move = read_king();
      if (contains(move, DOWN)) {
        ++r;
        assert(r + 1 < 8);
        last_up = 0;
        continue;
      }
      if (contains(move, UP)) {
        last_up = 0;
      } else {
        last_up += 1;
      }
      if (last_up == 2 * XX && r + 2 < 8) {
        ++r;
        last_up = 0;
        continue;
      }
      c += dir;
      if (c == 6) {
        dir = -1;
      }
      if (c == 1) {
        dir = 1;
      }
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
