#include <bits/stdc++.h>
const long long MXN = 1e5 + 7;
const long long mod = 1e9 + 7;
const long long inf = 1e9;
using namespace std;
long long t, a[MXN], b[MXN], sum, id;
bool used[MXN];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    int n, id = 0;
    cin >> n;
    set<int> st;
    for (int i = 1; i <= sqrt(n); i++) {
      if (st.find(i * i) == st.end()) {
        id++;
        st.insert(i * i);
      }
    }
    for (int i = 1; i <= cbrt(n); i++) {
      if (st.find(i * i * i) == st.end()) {
        id++;
        st.insert(i * i * i);
      }
    }
    cout << id << '\n';
  }
}
