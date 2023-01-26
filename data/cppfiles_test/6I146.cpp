#include <bits/stdc++.h>
using namespace std;
vector<set<int> > vec(200009);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  set<int> st;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) st.insert(i);
  while (m--) {
    int a, b;
    cin >> a >> b;
    if (a < b)
      st.erase(a);
    else
      st.erase(b);
    vec[a].insert(b);
    vec[b].insert(a);
  }
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    if (x == 3) {
      cout << st.size() << endl;
    }
    if (x == 2) {
      int a, b;
      cin >> a >> b;
      if (a > b) swap(a, b);
      vec[a].erase(b);
      vec[b].erase(a);
      if (vec[a].size() != 0 && *vec[a].rbegin() < a) st.insert(a);
    }
    if (x == 1) {
      int a, b;
      cin >> a >> b;
      vec[a].insert(b);
      vec[b].insert(a);
      if (a < b)
        st.erase(a);
      else
        st.erase(b);
    }
  }
  return 0;
}
