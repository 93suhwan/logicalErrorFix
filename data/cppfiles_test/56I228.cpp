#include <bits/stdc++.h>
using namespace std;
void time_assert(bool x) {
  while (!x) {
  }
}
struct test_case {
  bool win = false;
  const string DOWN = "Down";
  const string UP = "UP";
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
    int last_up = 0;
    while (!win) {
      place_queen(r, c);
      string move = read_king();
      if (contains(move, DOWN) && r + 2 < 8) {
        ++r;
        continue;
      }
      if (contains(move, UP)) {
        last_up = 0;
      } else {
        last_up += 1;
      }
      if (last_up == 8 && r + 2 < 8) {
        ++r;
        last_up = 0;
        continue;
      }
      ++c;
      c %= 8;
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
