#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  set<long long> st;
  long long num = 1;
  while (num * num <= 1e9) {
    st.insert(num * num);
    num++;
  }
  num = 1;
  while (num * num * num <= 1e9) {
    st.insert(num * num * num);
    num++;
  }
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    for (auto itr = st.begin(); itr != st.end(); itr++) {
      if ((*itr) <= n) {
        ans++;
      } else {
        break;
      }
    }
    cout << ans << "\n";
  }
}
