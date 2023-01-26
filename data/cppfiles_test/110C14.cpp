#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int first = 0;
  cerr << '{';
  for (auto& i : x) cerr << (first++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
int N;
vector<int> A[2][3][2];
bool ok(int K) {
  for (int i = 0; i < (2); i++) {
    for (int a = 0; a < (3); a++) {
      for (int b = 0; b < (3); b++) {
        if (a == b) continue;
        int c = 3 - a - b;
        int lstA = A[i][a][i][K - 1];
        int pB = upper_bound(A[i][b][i].begin(), A[i][b][i].end(), lstA) -
                 A[i][b][i].begin();
        pB += K - 1;
        if (pB < N / 3) {
          int lstB = A[i][b][i][pB];
          int pC = upper_bound(A[i][c][i].begin(), A[i][c][i].end(), lstB) -
                   A[i][c][i].begin();
          pC += K - 1;
          if (pC < N / 3) {
            return true;
          }
        }
        vector<int> okA, okB;
        int capOff = A[1 - i][c][1 - i][K - 1];
        for (int x = 0; x < (N / 3); x++) {
          if (A[i][a][1 - i][x] > capOff) {
            okA.push_back(A[i][a][i][x]);
          }
          if (A[i][b][1 - i][x] > capOff) {
            okB.push_back(A[i][b][i][x]);
          }
        }
        if ((int)(okA).size() >= K && (int)(okB).size() >= K &&
            okA[K - 1] < okB[(int)(okB).size() - K]) {
          return true;
        }
        okA.clear();
        okB.clear();
        capOff = A[1 - i][c][1 - i][N / 3 - K];
        for (int x = 0; x < (N / 3); x++) {
          if (A[i][a][1 - i][x] < capOff) {
            okA.push_back(A[i][a][i][x]);
          }
          if (A[i][b][1 - i][x] < capOff) {
            okB.push_back(A[i][b][i][x]);
          }
        }
        if ((int)(okA).size() >= K && (int)(okB).size() >= K &&
            okA[K - 1] < okB[(int)(okB).size() - K]) {
          return true;
        }
      }
    }
  }
  return false;
}
void solve() {
  cin >> N;
  int X[N], Y[N], C[N];
  for (int i = 0; i < (N); i++) cin >> X[i] >> Y[i] >> C[i];
  set<int> vX, vY;
  for (int i = 0; i < (N); i++) {
    vX.insert(X[i]), vY.insert(Y[i]);
  }
  map<int, int> cX, cY;
  for (auto& a : vX) {
    cX[a] = (int)(cX).size() + 1;
  }
  for (auto& a : vY) {
    cY[a] = (int)(cY).size() + 1;
  }
  vector<pair<int, int>> xSor[3], ySor[3];
  for (int i = 0; i < (N); i++) {
    pair<int, int> cur = {cX[X[i]], cY[Y[i]]};
    xSor[C[i] - 1].push_back({cur.first, cur.second});
    ySor[C[i] - 1].push_back({cur.second, cur.first});
  }
  for (int i = 0; i < (3); i++) {
    sort(xSor[i].begin(), xSor[i].end());
    sort(ySor[i].begin(), ySor[i].end());
    for (int j = 0; j < (N / 3); j++) {
      A[0][i][0].push_back(xSor[i][j].first);
      A[0][i][1].push_back(xSor[i][j].second);
      A[1][i][0].push_back(ySor[i][j].second);
      A[1][i][1].push_back(ySor[i][j].first);
    }
  }
  int lo = 1, hi = N / 3;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (ok(mid)) {
      lo = mid;
    } else
      hi = mid - 1;
  }
  cout << lo * 3 << nl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
