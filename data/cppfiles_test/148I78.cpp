#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    int n;
    vector<int> a;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    a.push_back((v[n - 1] - v[0]) * h);
    v.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    a.push_back((v[n - 1] - v[0]) * h);
    v.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    a.push_back((v[n - 1] - v[0]) * w);
    v.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    a.push_back((v[n - 1] - v[0]) * w);
    int ans = *max_element(a.begin(), a.end());
    cout << ans << endl;
  }
}
