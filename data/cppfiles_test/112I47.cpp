#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI = acos(-1);
int strtoint(string str) {
  stringstream ss(str);
  int x = 0;
  ss >> x;
  return x;
}
string intostr(int x) {
  stringstream ss;
  ss << x;
  string str = ss.str();
  return str;
}
void rem(string &s, const string &c) {
  auto pos = s.find(c);
  if (pos == string::npos) {
    cout << -1 << "\n";
    exit(0);
  }
  s.erase(0, pos + 1);
}
void println(int n) { cout << n << "\n"; }
void printvec(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
void printgraph(vector<int> g[], int e) {
  for (int i = 0; i < e; i++) {
    cout << i << " --> ";
    for (int j = 0; j < g[i].size(); j++) {
      cout << g[i][j] << " ";
    }
    cout << "\n";
  }
}
void printmap(map<int, int> &mymap) {
  for (auto itr = mymap.begin(); itr != mymap.end(); ++itr) {
    cout << '\t' << itr->first << '\t' << itr->second << '\n';
  }
  cout << "\n";
}
void solve() {
  int m;
  cin >> m;
  int n = m;
  for (int i = 0; i < m; i++) {
    for (int x = 0; x < n; x++) {
      cout << '(';
    }
    for (int x = 0; x < n; x++) {
      cout << ')';
    }
    n--;
    int o = 2 * n + 2;
    while (o < 2 * m) {
      cout << "()";
      o += 2;
    }
    cout << "\n";
  }
}
int main() {
  int tc;
  scanf("%d", &tc);
  for (int t = 0; t < tc; t++) {
    solve();
  }
  return 0;
}
