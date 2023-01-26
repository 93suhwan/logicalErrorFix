#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n, a[200001];
string s;
void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> s;
}
void solve() {
  set<int> st;
  int cnt = 0;
  for (char c : s) cnt += c == '0';
  for (int i = 1; i <= n; i++) st.insert(a[i]);
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '0') {
      if (a[i] > cnt) {
        set<int>::iterator j = st.lower_bound(cnt);
        j--;
        cout << *j << " ";
        st.erase(j);
      } else {
        set<int>::iterator j = st.lower_bound(a[i]);
        if (j == st.begin())
          cout << *j << " ";
        else {
          int d = *j - a[i];
          j--;
          if (a[i] - *j > d && d + a[i] <= cnt) {
            cout << d + a[i] << " ";
            j++;
            st.erase(j);
          } else {
            cout << *j << " ";
            st.erase(j);
          }
        }
      }
    } else {
      if (a[i] <= cnt) {
        set<int>::iterator j = st.lower_bound(cnt);
        cout << *j << " ";
        st.erase(j);
      } else {
        set<int>::iterator j = st.lower_bound(a[i]);
        if (j == st.begin())
          cout << *j << " ";
        else {
          int d = *j - a[i];
          j--;
          if (*j > cnt && a[i] - *j < d) {
            cout << *j << " ";
            st.erase(j);
          } else {
            cout << d + a[i] << " ";
            j++;
            st.erase(j);
          }
        }
      }
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for (cin >> t; t--;) {
    input();
    solve();
  }
}
