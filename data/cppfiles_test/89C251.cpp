#include <bits/stdc++.h>
using namespace std;
void pv(vector<long long int> v) {
  for (auto itr : v) cout << itr << " ";
  cout << "\n";
}
void p2d(vector<vector<long long int>> v) {
  for (auto itr : v) {
    for (auto itr1 : itr) cout << itr1 << " ";
    cout << "\n";
  }
}
void printpair(vector<pair<long long int, long long int>> v) {
  for (auto itr : v) cout << itr.first << " " << itr.second << "\n";
}
void printmap(map<long long int, long long int> m) {
  for (auto itr : m) cout << itr.first << " " << itr.second << "\n";
}
void printstringvector(vector<string> v) {
  for (auto itr : v) cout << itr << " ";
  cout << "\n";
}
long long int powers(long long int a, long long int b) {
  long long int ans = 1;
  while (b--) {
    ans *= a;
  }
  return ans;
}
long long int row;
long long int col;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v;
    for (long long int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      v.push_back(x);
    }
    vector<long long int> pos(n);
    for (long long int i = 0; i < n; i++) {
      if (v[i] % (i + 2) == 0)
        pos[i] = 0;
      else
        pos[i] = 1;
    }
    long long int ok = 1;
    long long int val = 0;
    for (long long int i = 0; i < n; i++) {
      if (pos[i] == 1)
        continue;
      else {
        val = 0;
        for (long long int j = i - 1; j >= 0; j--) {
          if (v[i] % (j + 2) != 0) {
            val++;
            break;
          }
        }
        if (val == 0) {
          ok = 0;
          break;
        }
      }
    }
    if (ok)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
