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
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  if (a < 2 && b < 2 && c < 2 && m > 0) {
    cout << "NO\n";
    return;
  }
  vector<int> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  sort((v).begin(), (v).end());
  if (v[2] <= (v[1] + v[0] + 1 + m) && m <= (a + b + c - 3)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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
