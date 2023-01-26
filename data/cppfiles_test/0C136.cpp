#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> s;
  for (long long i = 0; i < n; i++) {
    string k;
    cin >> k;
    for (long long j = 0; j < m; j++) {
      if (j % 2 != 0) {
        k[j] = 155 - k[j];
      }
    }
    s.push_back({k, i + 1});
  }
  sort(s.begin(), s.end());
  for (long long i = 0; i < n; i++) cout << s[i].second << " ";
  return 0;
}
