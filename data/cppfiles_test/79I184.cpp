#include <bits/stdc++.h>
const long long int MOD = 1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(00), cin.tie(0), cout.tie(0);
  int tc;
  cin >> tc;
read:
  while (tc--) {
    int k;
    cin >> k;
    string str;
    cin >> str;
    vector<bool> vis(k, false);
    int count1 = 0, count2 = 0, count3 = 0, count7 = 0, count5 = 0;
    if (str.size() == 1) {
      cout << 1 << endl;
      cout << str[0] << endl;
      goto read;
    }
    for (int i = 0; i < str.size(); i++) {
      int x = str[i] - '0';
      vis[x] = true;
      if ((x % 2 == 0 || x % 3 == 0) && x != 2 && x != 3) {
        cout << 1 << endl;
        cout << x << endl;
        goto read;
      }
      if (x == 1) {
        count1++;
      }
      if (x == 2) {
        count2++;
      }
      if (x == 3) {
        count3++;
      }
      if (x == 5) {
        count5++;
      }
      if (x == 7) {
        count7++;
      }
    }
    if (count1 >= 1) {
      cout << 1 << endl;
      cout << 1 << endl;
    } else if (count3 >= 2) {
      cout << 2 << endl;
      cout << 33 << endl;
    } else if (count5 >= 2) {
      cout << 2 << endl;
      cout << 55 << endl;
      goto read;
    } else if (count7 >= 2) {
      cout << 2 << endl;
      cout << 77 << endl;
      goto read;
    } else {
      for (int i = str.size() - 1; i >= 1; i--) {
        int x = str[i] - '0';
        if (x == 2) {
          cout << 2 << endl;
          cout << str[0] << x << endl;
          goto read;
        }
        if (x == 5) {
          cout << 2 << endl;
          cout << str[0] << x << endl;
          goto read;
        }
        if (x == 1 && vis[2] == true) {
          cout << 2 << endl;
          cout << 2 << x << endl;
          goto read;
        }
        if (x == 1 && vis[5] == true) {
          cout << 2 << endl;
          cout << 5 << x << endl;
          goto read;
        }
        if (x == 7 && vis[2] == true) {
          cout << 2 << endl;
          cout << 2 << x << endl;
          goto read;
        }
      }
      cout << str.size() << endl;
      cout << str << endl;
    }
  }
end:
  return 0;
}
