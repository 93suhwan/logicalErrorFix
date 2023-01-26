#include <bits/stdc++.h>
using namespace std;
long long b[10];
bool pick[10];
void solve(int index, int left) {}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    char word[128][5];
    n -= 2;
    for (int i = 0; i < n; ++i) cin >> word[i];
    int where = -1;
    for (int i = 1; i < n; ++i) {
      if (word[i - 1][1] != word[i][0]) {
        where = i;
        break;
      }
    }
    if (where < 0) {
      cout << word[0];
      for (int i = 1; i < n; ++i) cout << word[i][1];
      cout << word[n - 1][1];
      cout << '\n';
    } else {
      cout << word[0];
      for (int i = 1; i < n; ++i) {
        if (i == where)
          cout << word[i];
        else
          cout << word[i][1];
      }
      cout << '\n';
    }
  }
  return 0;
}
