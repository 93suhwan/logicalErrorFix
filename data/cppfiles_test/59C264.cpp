#include <bits/stdc++.h>
using namespace std;
long long int mult(long long int a, long long int b) {
  return ((a % int(1e9 + 7)) * (b % int(1e9 + 7))) % int(1e9 + 7);
}
long long int add(long long int a, long long int b) {
  return ((a % int(1e9 + 7)) + (b % int(1e9 + 7))) % int(1e9 + 7);
}
long long int subt(long long int a, long long int b) {
  long long int ans = ((a % int(1e9 + 7)) - (b % int(1e9 + 7))) % int(1e9 + 7);
  ans %= int(1e9 + 7);
  ans = (ans + int(1e9 + 7)) % int(1e9 + 7);
  return ans;
}
long long int exp(long long int a, long long int b) {
  long long int ans = 1;
  long long int po = a;
  while (b != 0) {
    if (b % 2) {
      ans = ((ans % int(1e9 + 7)) * (po % int(1e9 + 7))) % int(1e9 + 7);
    }
    po = ((po % int(1e9 + 7)) * (po % int(1e9 + 7))) % int(1e9 + 7);
    b /= 2;
  }
  return ans;
}
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
signed main() {
  init_code();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    bool check = true;
    vector<string> vec;
    for (int i = 0; i < n; i++) {
      string s;
      for (int j = 0; j < 5; j++) {
        char ch;
        cin >> ch;
        s += ch;
      }
      vec.push_back(s);
    }
    for (int i = 0; i < 5; i++) {
      if (check == false) {
        break;
      }
      for (int j = 0; j < 5; j++) {
        if (check == false) {
          break;
        }
        if (i != j) {
          vector<long long int> fre(4, 0);
          for (int k = 0; k < n; k++) {
            if (vec[k][i] == '1' and vec[k][j] == '1') {
              fre[3]++;
            } else if (vec[k][i] == '0' and vec[k][j] == '1') {
              fre[0]++;
            } else if (vec[k][i] == '1' and vec[k][j] == '0') {
              fre[1]++;
            } else if (vec[k][i] == '0' and vec[k][j] == '0') {
              fre[2] += 1;
            }
          }
          if (fre[2] == 0) {
            if ((fre[0] <= (n / 2)) and (fre[1] <= (n / 2))) {
              check = false;
              cout << "YES" << '\n';
              break;
            }
          }
        }
      }
    }
    if (check) {
      cout << "NO" << '\n';
    }
  }
}
