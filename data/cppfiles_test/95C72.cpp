#include <bits/stdc++.h>
using namespace std;
vector<int> V[500500];
vector<int> SV[500500];
vector<int> MAX1[500500], MAX2[500500], MIN1[500500], MIN2[500500];
vector<pair<int, int>> T;
int R[505000];
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      V[i].clear();
      SV[i].clear();
    }
    T.clear();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        V[i].push_back(x);
      }
      T.push_back(make_pair(V[i][0], i));
    }
    sort(T.begin(), T.end());
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        SV[i].push_back(V[T[i].second][j]);
      }
      R[T[i].second] = i;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        MAX1[i].push_back(0);
        MAX2[i].push_back(0);
        MIN1[i].push_back(0);
        MIN2[i].push_back(0);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int m1 = i == 0 ? -1 : MAX1[i - 1][j];
        int m2 = j == 0 ? -1 : MAX1[i][j - 1];
        MAX1[i][j] = max(max(m1, m2), SV[i][j]);
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        int m1 = (i == n - 1) ? -1 : MAX2[i + 1][j];
        int m2 = (j == m - 1) ? -1 : MAX2[i][j + 1];
        MAX2[i][j] = max(max(m1, m2), SV[i][j]);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = m - 1; j >= 0; j--) {
        int m1 = i == 0 ? 9999999 : MIN1[i - 1][j];
        int m2 = (j == m - 1) ? 9999999 : MIN1[i][j + 1];
        MIN1[i][j] = min(min(m1, m2), SV[i][j]);
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        int m1 = (i == n - 1) ? 9999999 : MIN2[i + 1][j];
        int m2 = (j == 0) ? 9999999 : MIN2[i][j - 1];
        MIN2[i][j] = min(min(m1, m2), SV[i][j]);
      }
    }
    int ansx = -1, ansy = -1;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m - 1; j++) {
        if (MAX1[i][j] < MIN2[i + 1][j] &&
            MAX2[i + 1][j + 1] < MIN1[i][j + 1]) {
          ansx = i;
          ansy = j;
          break;
        }
      }
    }
    if (ansx == -1 && ansy == -1)
      cout << "NO\n";
    else {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        if (R[i] <= ansx)
          cout << "B";
        else
          cout << "R";
      }
      cout << " ";
      cout << ansy + 1;
      cout << "\n";
    }
  }
}
