#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < (n); i++) cin >> v[i];
    bool ans = false;
    for (int st = 1; st <= (((1 << n) - 1)); st++) {
      vi v2;
      for (int i = 0; i < (n); i++)
        if (st & (1 << i)) v2.push_back(v[i]);
      int n2 = v2.size();
      for (int st2 = 1; st2 <= (((1 << n2) - 1)); st2++) {
        int sum = 0;
        for (int i = 0; i < (n2); i++)
          sum += v2[i] * ((st2 & (1 << i)) ? 1 : -1);
        ans |= sum == 0;
      }
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
}
