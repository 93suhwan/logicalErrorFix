#include <bits/stdc++.h>
using namespace std;
static int mod = 1e9 + 7;
vector<int> adj[100005];
int vis[100005];
int div(string s, int n, char c) {
  vector<int> v;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == c) {
      v.push_back(i + 1);
    }
  }
  int num = -1;
  for (int i = 0; i < v.size(); i++) {
    int val = v[i];
    int f = 0;
    for (int j = val * 2; j <= n; j += val) {
      if (s[j - 1] != c) {
        f = 1;
        break;
      }
    }
    if (!f) {
      num = val;
      break;
    }
  }
  return num;
}
void solve() {
  int n;
  char c;
  cin >> n >> c;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != c) {
      cnt++;
    }
  }
  if (cnt >= 1) {
    if (s[n - 1] != c) {
      if (cnt - 1 >= 1) {
        int num = div(s, n, c);
        if (num != -1) {
          cout << "1"
               << "\n"
               << num << "\n";
        } else {
          cout << "2"
               << "\n";
          cout << n << " " << n - 1 << "\n";
        }
      } else {
        cout << "1"
             << "\n"
             << n - 1 << "\n";
      }
    } else {
      cout << "1"
           << "\n"
           << n << "\n";
    }
  } else {
    cout << "0"
         << "\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
