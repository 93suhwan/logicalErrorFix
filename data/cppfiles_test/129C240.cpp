#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 1000000007;
void solve() {
  long long int n;
  cin >> n;
  set<long long int> st;
  for (long long int i = 1; i <= n; i++) {
    st.insert(i);
  }
  vector<long long int> rem;
  for (long long int i = 0; i < n; i++) {
    long long int v;
    cin >> v;
    if (st.find(v) != st.end()) {
      st.erase(v);
    } else {
      rem.push_back(v);
    }
  }
  sort(rem.begin(), rem.end());
  reverse(rem.begin(), rem.end());
  bool err = false;
  for (auto &it : rem) {
    auto t = st.end();
    t--;
    long long int count = (*t);
    if (count > (it - 1) / 2) {
      err = true;
      break;
    }
    st.erase(t);
  }
  if (err) {
    cout << "-1\n";
  } else {
    cout << rem.size() << "\n";
  }
}
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
