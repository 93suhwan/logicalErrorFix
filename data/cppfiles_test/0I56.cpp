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
    s.push_back({k, i + 1});
  }
  sort(s.begin(), s.end());
  vector<int> ans(n);
  int j = 0;
  for (int i = 0; i < n; i += 2) {
    ans[i] = s[j].second;
    j++;
  }
  if (n >= 2) {
    for (int i = n - 2; i > 0; i -= 2) {
      ans[i] = s[j].second;
      j++;
    }
  }
  for (long long i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}
