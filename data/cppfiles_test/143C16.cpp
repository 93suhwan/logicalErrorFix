#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
long long ans[maxn];
int main() {
  int t;
  cin >> t;
  for (int test = 1; test <= t; test++) {
    int n;
    cin >> n;
    int cnt[maxn] = {0};
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    stack<int> st;
    memset(ans, -1, sizeof(ans));
    long long sum = 0;
    for (int i = 0; i <= n; i++) {
      if (i > 0 && cnt[i - 1] == 0) {
        if (st.empty()) break;
        int j = st.top();
        st.pop();
        sum += i - j - 1;
      }
      ans[i] = sum + cnt[i];
      while (i > 0 && cnt[i - 1] > 1) {
        cnt[i - 1]--;
        st.push(i - 1);
      }
    }
    for (long long i = 0; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  }
}
