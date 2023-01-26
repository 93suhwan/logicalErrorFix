#include <bits/stdc++.h>
using namespace std;
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    map<long long, long long> hm;
    for (long long i = 0; i < n; i++) {
      hm[arr[i]]++;
    }
    long long last = n;
    for (long long i = 0; i < n; i++) {
      if (arr[i] > i) {
        last = i;
        break;
      }
    }
    bool good = true;
    stack<long long> st;
    long long cnt = 0;
    for (long long i = 0; i <= last; i++) {
      if (good) {
        if (hm[i] == 0) {
          good = false;
        }
        cout << hm[i] << " ";
      } else {
        cout << cnt + hm[i] << " ";
      }
      if (i == last) break;
      if (hm[i]) {
        for (long long j = 1; j < hm[i]; j++) {
          st.push(i);
        }
      } else {
        long long v = st.top();
        st.pop();
        cnt += i - v;
      }
    }
    for (long long i = last + 1; i <= n; i++) {
      cout << "-1 ";
    }
    cout << "\n";
  }
  return 0;
}
