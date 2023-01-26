#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  long long n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> mini(1200, 1e9);
  set<int> st = {0};
  for (auto& x : a) {
    for (int i = 0; i <= 1100; i++) {
      if (mini[i] < x) {
        st.insert(x ^ i);
        mini[x ^ i] = min(x, mini[x ^ i]);
      }
    }
    mini[x] = min(x, mini[x]);
    st.insert(x);
  }
  cout << st.size() << '\n';
  for (auto& x : st) cout << x << " ";
  cout << '\n';
}
