#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> vec(m);
    for (long long i = 0; i < m; i++) {
      cin >> vec[i];
    }
    multiset<long long> st;
    multiset<long long>::iterator it;
    long long ans = 0;
    for (long long i = 0; i < m; i++) {
      long long count = 0;
      st.insert(vec[i]);
      for (it = st.begin(); it != st.end(); it++) {
        if ((*it) == vec[i]) {
          break;
        } else {
          count++;
        }
      }
      ans += count;
    }
    cout << ans << endl;
  }
  return 0;
}
