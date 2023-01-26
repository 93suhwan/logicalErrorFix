#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long m, a, i, b, j, k, t, x, y, z, tc, u, v, w;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n >> k;
    if (k == 1) {
      long long ans = 9223372036854775807;
      long long len = log10(n) + 1;
      for (i = 0; i < 10; i++) {
        long long sum = 0;
        for (j = 0; j < len; j++) sum = (sum * 10 + i);
        if (sum >= n) ans = min(ans, sum);
      }
      if (ans == 9223372036854775807) {
        for (i = 0; i < len + 1; i++) cout << "1";
        cout << endl;
      } else
        cout << ans << endl;
    } else {
      set<char> st;
      long long idx = 0;
      string str = to_string(n);
      long long sz = str.size();
      for (i = 0; i < sz; i++) {
        st.insert(str[i]);
        if (st.size() <= 2)
          idx = i;
        else {
          st.erase(str[i]);
          break;
        }
      }
      if (idx == sz - 1)
        cout << n << endl;
      else {
        long long flag = 0;
        for (auto itr = st.begin(); itr != st.end(); itr++) {
          char c1 = *itr;
          if (c1 > str[idx + 1]) {
            flag = 1;
            for (i = 0; i < sz; i++) {
              if (i <= idx)
                cout << str[i];
              else if (i == idx + 1)
                cout << c1;
              else
                cout << (*(st.begin()));
            }
            cout << endl;
            break;
          }
        }
        if (flag == 0) {
          set<char> ss;
          char cc;
          long long id = 0;
          for (i = 1; i < sz; i--) {
            if (str[i] == str[i - 1])
              id = i;
            else
              break;
          }
          for (i = 0; i < sz; i++) {
            if (i <= id)
              cout << str[i];
            else if (i == id + 1) {
              u = int(str[i]) - '0';
              u++;
              cc = char(u + '0');
              cout << cc;
            } else
              cout << min(str[0], cc);
          }
          cout << endl;
        }
      }
    }
  }
}
