#include <bits/stdc++.h>
using namespace std;
int btod(string s, int l, int r) {
  long long int ans = 0;
  int pw = 0;
  for (int i = r - 1; i >= l - 1; i--) {
    ans += (s[i] - 48) * pow(10, pw);
    pw++;
  }
  return ans;
}
void solve() {
  int n;
  cin >> n;
  char s[n];
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  int con = n / 2;
  int check = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      check = 1;
      break;
    }
  }
  if (!check) {
    cout << "1"
         << " " << n - 1 << " "
         << "2"
         << " " << n << "\n";
  } else {
    int loc = 0;
    int flag = 0;
    for (int i = 1; i <= con; i++) {
      if (s[i] == '0') {
        loc = i;
        flag = 1;
        break;
      }
    }
    if (flag) {
      cout << loc << " " << n << " " << loc + 1 << " " << n << "\n";
    } else {
      for (int i = con + 1; i <= n; i++) {
        if (s[i] == '0') {
          loc = i;
          break;
        }
      }
      cout << 1 << " " << loc << " " << 1 << " " << loc - 1 << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
