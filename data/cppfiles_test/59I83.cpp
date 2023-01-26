#include <bits/stdc++.h>
using namespace std;
long long int n;
vector<vector<long long int>> a(1010, vector<long long int>(7));
bool help(long long int o, long long int t) {
  long long int fst = 0, snd = 0, cmn = 0;
  for (long long int i = 0; i < n; i++) {
    if (a[i][o] == 0 and a[i][t] == 0)
      return 0;
    else if (a[i][o] and a[i][t])
      cmn++;
    else if (a[i][o])
      fst++;
    else
      snd++;
  }
  if (min(fst, snd) + (cmn + 1) / 2 == n / 2)
    return 1;
  else
    return 0;
}
void start() {
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }
  for (long long int i = 0; i < 4; i++) {
    for (long long int j = i + 1; j < 5; j++) {
      if (help(i, j)) {
        cout << "YES";
        return;
      }
    }
  }
  cout << "NO";
}
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    start();
    cout << "\n";
  }
}
