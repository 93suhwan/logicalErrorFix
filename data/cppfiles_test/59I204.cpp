#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int imax = INT_MAX;
const int imin = INT_MIN;
const int mod = 1e9 + 7;
template <class T>
void _print(vector<T> arr) {
  cerr << "[ ";
  for (auto x : arr) {
    cerr << x << " ";
  }
  cerr << "]";
  cerr << "\n";
}
template <class T, class V>
void _print(map<T, V> map) {
  cerr << "{ \n";
  for (auto x : map) {
    cerr << "\t" << x.first << " : " << x.second << "\n";
  }
  cerr << "}";
  cerr << "\n";
}
template <class T, class V>
void _print(unordered_map<T, V> map) {
  cerr << "{ \n";
  for (auto x : map) {
    cerr << "\t" << x.first << " : " << x.second << "\n";
  }
  cerr << "}";
  cerr << "\n";
}
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{ " << p.first << " " << p.second << " }"
       << "\n";
}
template <class T>
void _print(T x) {
  cerr << x << "\n";
}
void solve() {
  int n;
  cin >> n;
  int ar[n][5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> ar[i][j];
    }
  }
  int sum;
  vector<int> days;
  for (int j = 0; j < 5; j++) {
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += ar[i][j];
    }
    days.push_back(sum);
  };
  for (int i = 0; i < 4; i++) {
    if (days[i] >= n / 2) {
      for (int j = 1 + i; j < 5; j++) {
        if (days[j] >= n / 2) {
          ;
          vector<int> d1;
          vector<int> d2;
          for (int k = 0; k < n; k++) {
            if (ar[k][i] == 1) d1.push_back(k);
          }
          for (int k = 0; k < n; k++) {
            if (ar[k][j] == 1) d2.push_back(k);
          };
          ;
          bool flag = false;
          set<int> s;
          for (int k = 0; k < d1.size(); k++) s.insert(d1[k]);
          for (int k = 0; k < d2.size(); k++) s.insert(d2[k]);
          vector<int> d3;
          for (auto z : s) {
            d3.push_back(z);
          };
          for (int k = 0; k < d3.size(); k++) {
            if (d3[k] != k) {
              flag = true;
              break;
            }
          };
          if (!flag) {
            cout << "YES" << endl;
            return;
          }
        }
      }
    }
  }
  cout << "NO" << endl;
  return;
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
  return 0;
}
