#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e4 + 10;
map<int, int> mp;
bool st[300];
int a[300];
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<pair<int, int> > chord;
    memset(st, false, sizeof st);
    memset(a, 0, sizeof a);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      int a, b;
      cin >> a >> b;
      if (a > b) swap(a, b);
      chord.push_back({a, b});
      st[a] = st[b] = true;
    }
    int k = 0;
    for (int i = 1; i <= n * 2; i++)
      if (!st[i]) a[++k] = i;
    for (int i = 1; i <= n - m; i++) {
      chord.push_back({a[i], a[i + n - m]});
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (chord[i].first > chord[j].first) swap(chord[i], chord[j]);
        if (chord[i].second < chord[j].second &&
            chord[i].second > chord[j].first)
          ans++;
      }
    }
    cout << ans << endl;
  }
}
