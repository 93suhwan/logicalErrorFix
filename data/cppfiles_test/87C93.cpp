#include <bits/stdc++.h>
using namespace std;
int main() {
  int ts = 1, cs = 1;
  cin >> ts;
  while (ts--) {
    int n, m;
    cin >> n >> m;
    pair<int, int> vec[m + 2];
    for (int i = 1; i <= m; i++) {
      cin >> vec[i].first;
      vec[i].second = i;
    }
    sort(vec + 1, vec + m + 1);
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= m; j++) {
        if (vec[i].second > vec[j].second && vec[i].first > vec[j].first) ans++;
      }
    }
    cout << ans << endl;
  }
}
