#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  map<long long, long long> m;
  for (int i = 1; i <= 5 * pow(10, 5); i++) {
    m[i] = i;
  }
  long long q;
  cin >> q;
  vector<pair<long long, pair<long long, long long>>> v;
  long long n = 0;
  for (int i = 0; i < q; i++) {
    long long inp1;
    cin >> inp1;
    if (inp1 == 1) {
      n++;
      long long inp2, inp3;
      cin >> inp2;
      inp3 = inp2;
      v.push_back({inp1, {inp2, inp3}});
    } else {
      long long inp2, inp3;
      cin >> inp2 >> inp3;
      v.push_back({inp1, {inp2, inp3}});
    }
  }
  long long ans[n];
  long long m1 = n;
  n--;
  set<long long> st;
  for (int i = q - 1; i >= 0; i--) {
    if (v[i].first == 1) {
      ans[n] = m[v[i].second.first];
      n--;
    } else {
      if (st.find(v[i].second.second) != st.end()) {
        m[v[i].second.first] = m[v[i].second.second];
        st.insert(v[i].second.first);
        continue;
      } else {
        m[v[i].second.first] = m[v[i].second.second];
        st.insert(v[i].second.first);
      }
    }
  }
  for (int i = 0; i < m1; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
