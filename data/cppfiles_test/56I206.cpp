#include <bits/stdc++.h>
using namespace std;
mt19937 rng(10);
const bool DEBUG = 0;
const int N = 8;
const vector<int> di_king = {1, 1, 1, -1, -1, -1, 0, 0};
const vector<int> dj_king = {-1, 0, 1, -1, 0, 1, -1, 1};
const vector<string> s_king = {"Down-Left", "Down",     "Down-Right", "Up-Left",
                               "Up",        "Up-Right", "Left",       "Right"};
int ok_cell(int x, int y) { return x >= 0 && y >= 0 && x < 8 && y < 8; }
int can_queen(int x, int y, int nx, int ny) {
  if (x == nx && y == ny) {
    return false;
  }
  return (x + y == nx + ny || x - y == nx - ny || x == nx || y == ny);
}
int fight(int x, int y, int kx, int ky) {
  return (x + y == kx + ky || x - y == kx - ky || x == kx || y == ky);
}
int i_queen;
int j_queen;
int i_king;
int j_king;
namespace INTERACTOR {
void init() {
  if (DEBUG) {
    i_king = rng() % N;
    j_king = rng() % N;
  }
}
int make_turn() {
  if (DEBUG) {
    vector<int> poss;
    for (int i = 0; i < 8; i++) {
      int ni = i_king + di_king[i];
      int nj = j_king + dj_king[i];
      if (ok_cell(ni, nj) && !fight(i_queen, j_queen, ni, nj)) {
        poss.push_back(i);
      }
    }
    if (poss.empty()) {
      return -1;
    } else {
      int i = poss[rng() % (int)poss.size()];
      i_king += di_king[i];
      j_king += dj_king[i];
      return i;
    }
  } else {
    string s;
    cin >> s;
    if (s == "Done") {
      return -1;
    }
    for (int i = 0; i < 8; i++) {
      if (s == s_king[i]) {
        return i;
      }
    }
    assert(false);
    return -1;
  }
}
}  // namespace INTERACTOR
void solve() {
  i_queen = 4;
  j_queen = 4;
  if (!DEBUG) {
    cout << i_queen + 1 << ' ' << j_queen + 1 << endl;
  }
  INTERACTOR::init();
  vector<vector<int>> can(N, vector<int>(N, 1));
  can[i_queen][j_queen] = 0;
  int i_go_king = 0;
  int j_go_king = 0;
  int IT = 0;
  while (true) {
    int d = INTERACTOR::make_turn();
    if (d == -1) {
      break;
    }
    i_go_king += di_king[d];
    j_go_king += dj_king[d];
    int cs = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (!ok_cell(i + i_go_king, j + j_go_king) ||
            fight(i_queen, j_queen, i + i_go_king, j + j_go_king)) {
          can[i][j] = 0;
        }
        cs += can[i][j];
      }
    }
    int best_i = -1;
    int best_j = -1;
    int best_score = N * N;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (!can_queen(i_queen, j_queen, i, j)) continue;
        int worst = 0;
        for (int nd = 0; nd < 8; nd++) {
          auto ncan = can;
          int c = 0;
          for (int ni = 0; ni < N; ni++) {
            for (int nj = 0; nj < N; nj++) {
              if (!ok_cell(ni + i_go_king + di_king[nd],
                           nj + j_go_king + dj_king[nd]) ||
                  fight(i, j, ni + i_go_king + di_king[nd],
                        nj + j_go_king + dj_king[nd])) {
                ncan[ni][nj] = 0;
              }
              c += ncan[ni][nj];
            }
          }
          worst = max(worst, c);
        }
        if (best_score > worst || (best_score == worst && rng() % 2 == 0)) {
          best_score = worst;
          best_i = i;
          best_j = j;
        }
      }
    }
    assert(can_queen(i_queen, j_queen, best_i, best_j));
    i_queen = best_i;
    j_queen = best_j;
    if (!DEBUG) {
      cout << i_queen + 1 << ' ' << j_queen + 1 << endl;
    }
    IT++;
  }
  if (DEBUG) {
    cerr << "done in " << IT << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  if (DEBUG) {
    while (true) {
      solve();
    }
  } else {
    int q;
    cin >> q;
    while (q--) {
      solve();
    }
  }
}
