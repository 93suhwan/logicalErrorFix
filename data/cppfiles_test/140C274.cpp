#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long count = 0;
    set<long long> st;
    for (long long i = 1;; i++) {
      if (i * i > n) {
        break;
      }
      st.insert(i * i);
    }
    for (long long i = 1; i < n; i++) {
      if (i * i * i > n) {
        break;
      }
      st.insert(i * i * i);
    }
    cout << st.size() << '\n';
  }
  return 0;
}
