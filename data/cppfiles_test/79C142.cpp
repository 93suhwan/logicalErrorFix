#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
vector<char*> tokenizer(const char* args) {
  char* token = new char[111];
  strcpy(token, args);
  token = strtok(token, ", ");
  vector<char*> v({token});
  while (token = strtok(NULL, ", ")) v.push_back(token);
  return reverse(v.begin(), v.end()), v;
}
void debugg(vector<char*> args) { cerr << "\b "; }
template <typename Head, typename... Tail>
void debugg(vector<char*> args, Head H, Tail... T) {
  debug() << " [" << args.back() << ": " << H << "] ";
  args.pop_back();
  debugg(args, T...);
}
const double PI = acos(-1);
bool isprime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void help(vector<int>& v) {
  for (int i = 10; i < 100; i++) {
    if (!isprime(i)) v.push_back(i);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  cin >> test;
tpo:
  while (test--) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    vector<int> a;
    for (auto it : s) a.push_back(it - '0');
    vector<int> v{1, 4, 6, 8, 9};
    for (auto it : v) {
      for (int i = 0; i < k; i++) {
        if (a[i] == it) {
          cout << 1 << "\n" << it << "\n";
          goto tpo;
        }
      }
    }
    vector<int> vv;
    help(vv);
    for (auto it : vv) {
      for (int i = 0; i < k; i++) {
        if (a[i] == it / 10) {
          for (int j = i + 1; j < k; j++) {
            if (a[j] == it % 10) {
              cout << 2 << "\n" << it << "\n";
              goto tpo;
            }
          }
        }
      }
    }
  }
  return 0;
}
