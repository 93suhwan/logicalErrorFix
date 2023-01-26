#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int INF = INT_MAX;
const long long LLINF = 1000000000000000000LL;
const long long MAX = 25;
const long long MOD = 998244353;
long long N, M, K;
char mm[MAX][MAX];
bool visited[MAX][MAX];
void solve() {
  cin >> N >> M >> K;
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      cin >> mm[j][i];
    }
  }
  if (mm[N - 1][0] == '*' || mm[N - 1][M - 1] == '*') {
    cout << "NO\n";
    return;
  }
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      if (mm[j][i] == '.') {
        visited[j][i] = true;
      }
      if (mm[j][i] == '*') {
        long long L = 0;
        for (int k = 0; k <= MAX; k++) {
          if (j - k >= 0 && i - k >= 0 && mm[j - k][i - k] == '*' &&
              i + k < M && mm[j - k][i + k] == '*') {
            continue;
          } else {
            L = k;
            break;
          }
        }
        if (L - 1 >= K) {
          for (int k = 0; k < L; k++) {
            visited[j - k][i - k] = true;
            visited[j - k][i + k] = true;
          }
        }
      }
    }
  }
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      if (visited[j][i] == 0) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tc;
  cin >> tc;
  while (tc--) {
    memset(visited, 0, sizeof(visited));
    solve();
  }
  return 0;
}
