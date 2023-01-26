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
    int col = 0;
    for (int row = 0; row + 1 < 8; row++) {
      for (; col < 8; col++) {
        place_queen(row, col);
        string move = read_king();
        if (win) return;
        if (contains(move, DOWN)) {
          goto hell;
        }
      }
      for (col -= 2; col > 0; --col) {
        place_queen(row, col);
        string move = read_king();
        if (win) return;
        if (contains(move, DOWN)) {
          goto hell;
        }
      }
    hell:;
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
