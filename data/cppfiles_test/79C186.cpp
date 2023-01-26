#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int k;
  cin >> k;
  string s;
  cin >> s;
  char c;
  long long int flag = 0;
  vector<char> v;
  for (long long int i = 0; i < k; i++) {
    if (s[i] != '2' && s[i] != '3' && s[i] != '5' && s[i] != '7') {
      c = s[i];
      flag = 1;
      break;
    } else {
      v.push_back(s[i]);
    }
  }
  vector<char> ans;
  long long int final = 0;
  for (long long int i = 0; i < v.size(); i++) {
    if (v[i] == '2') {
      for (long long int j = i + 1; j < v.size(); j++) {
        if (v[j] != '3') {
          ans.push_back(v[i]);
          ans.push_back(v[j]);
          final = 1;
          break;
        }
      }
    }
    if (final) break;
    if (v[i] == '3') {
      for (long long int j = i + 1; j < v.size(); j++) {
        if (v[j] != '7') {
          ans.push_back(v[i]);
          ans.push_back(v[j]);
          final = 1;
          break;
        }
      }
    }
    if (final) break;
    if (v[i] == '5') {
      for (long long int j = i + 1; j < v.size(); j++) {
        if (v[j] != '3') {
          ans.push_back(v[i]);
          ans.push_back(v[j]);
          final = 1;
          break;
        }
      }
    }
    if (final) break;
    if (v[i] == '7') {
      for (long long int j = i + 1; j < v.size(); j++) {
        if (v[j] != '3') {
          ans.push_back(v[i]);
          ans.push_back(v[j]);
          final = 1;
          break;
        }
      }
    }
    if (final) break;
  }
  if (flag) {
    cout << 1 << '\n';
    cout << c << '\n';
  } else {
    cout << 2 << '\n';
    cout << ans[0] << ans[1] << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
