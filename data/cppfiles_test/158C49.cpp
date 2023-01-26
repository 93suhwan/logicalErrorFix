#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    long long exp[n];
    long long score[n];
    int tempscore[m];
    for (int i = 0; i < n; i++) {
      cin >> exp[i];
      score[i] = 0;
    }
    string answers[n];
    for (int i = 0; i < n; i++) {
      cin >> answers[i];
    }
    long long currVal = -1;
    long long bestVal = -1;
    int currPerm[m];
    int bestPerm[m];
    int maxmask = 1 << n;
    for (int mask = 0; mask < maxmask; mask++) {
      memset(tempscore, 0, sizeof(tempscore));
      for (int i = 0; i < n; i++) score[i] = 0;
      currVal = 0;
      for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) {
          for (int j = 0; j < m; j++) {
            tempscore[j] += answers[i][j] == '1';
          }
        } else {
          for (int j = 0; j < m; j++) {
            tempscore[j] -= answers[i][j] == '1';
          }
        }
      }
      vector<pair<int, int> > myVec;
      for (int j = 0; j < m; j++) {
        myVec.push_back({tempscore[j], j});
      }
      sort(myVec.begin(), myVec.end());
      for (int j = 0; j < m; j++) {
        currPerm[myVec[j].second] = j + 1;
        for (int i = 0; i < n; i++) {
          score[i] += (answers[i][myVec[j].second] == '1') * (j + 1);
        }
      }
      for (int i = 0; i < n; i++) {
        currVal += abs(score[i] - exp[i]);
      }
      if (currVal > bestVal) {
        bestVal = currVal;
        for (int j = 0; j < m; j++) {
          bestPerm[j] = currPerm[j];
        }
      }
    }
    for (int j = 0; j < m; j++) {
      cout << bestPerm[j] << " ";
    }
    cout << "\n";
  }
}
