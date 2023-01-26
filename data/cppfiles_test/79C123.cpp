#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int first = 0;
  cerr << '{';
  for (auto &i : x) cerr << (first++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long INF = 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string no;
    cin >> no;
    map<int, int> m;
    bool check1 = false;
    bool check2 = false;
    int nocheck2 = -1;
    int nocheck1 = -1;
    for (int i = 0; i < no.size(); i++) {
      int x = no[i] - '0';
      if (x == 1 or x == 4 or x == 6 or x == 8 or x == 9) {
        nocheck1 = x;
        check1 = true;
        break;
      }
      m[x]++;
      if (m[x] == 2) {
        check2 = true;
        nocheck2 = x;
      }
    }
    if (check1) {
      cout << 1 << "\n" << nocheck1 << "\n";
    } else if (check2) {
      cout << 2 << "\n" << nocheck2 << nocheck2 << "\n";
    } else {
      string ans;
      bool fi = false;
      bool tw = false;
      bool th = false;
      bool sv = false;
      for (int i = 0; i < no.size(); i++) {
        int x = no[i] - '0';
        if (x == 2) {
          tw = true;
          ans += no[i];
        } else if (tw) {
          if (x == 5) {
            ans += no[i];
            break;
          } else if (x == 7) {
            ans += no[i];
            break;
          }
        }
      }
      if (ans.size() == 2) {
        cout << 2 << "\n" << ans << "\n";
        continue;
        ;
      } else {
        ans = "";
      }
      for (int i = 0; i < no.size(); i++) {
        int x = no[i] - '0';
        if (x == 3) {
          th = true;
          ans += no[i];
        } else if (th) {
          if (x == 2) {
            ans += no[i];
            break;
          } else if (x == 5) {
            ans += no[i];
            break;
          }
        }
      }
      if (ans.size() == 2) {
        cout << 2 << "\n" << ans << "\n";
        continue;
      } else {
        ans = "";
      }
      for (int i = 0; i < no.size(); i++) {
        int x = no[i] - '0';
        if (x == 5) {
          fi = true;
          ans += no[i];
        } else if (fi) {
          if (x == 2) {
            ans += no[i];
            break;
          } else if (x == 7) {
            ans += no[i];
            break;
          }
        }
      }
      if (ans.size() == 2) {
        cout << 2 << "\n" << ans << "\n";
        continue;
      } else {
        ans = "";
      }
      for (int i = 0; i < no.size(); i++) {
        int x = no[i] - '0';
        if (x == 7) {
          sv = true;
          ans += no[i];
        } else if (sv) {
          if (x == 5) {
            ans += no[i];
            break;
          } else if (x == 2) {
            ans += no[i];
            break;
          }
        }
      }
      if (ans.size() == 2) {
        cout << 2 << "\n" << ans << "\n";
        continue;
      } else {
        ans = "";
      }
    }
  }
  return 0;
}
