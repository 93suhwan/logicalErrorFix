#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int fq[n + 1];
    memset(fq, 0, sizeof fq);
    multiset<int> above;
    for (int i = 0; i < n; i++) {
      int w;
      cin >> w;
      if (w > n)
        above.insert(w);
      else
        fq[w]++;
    }
    int ops = 0;
    for (int i = n; i >= 1; i--) {
      if (fq[i])
        for (int j = 0; j < fq[i] - 1; j++) above.insert(i);
      else {
        if (above.empty()) {
          ops = -1;
          break;
        }
        int nxt = *(above.rbegin());
        if (i >= (nxt + 1) / 2) {
          ops = -1;
          break;
        }
        above.erase(above.find(nxt));
        ops++;
      }
    }
    cout << ops << '\n';
  }
}
