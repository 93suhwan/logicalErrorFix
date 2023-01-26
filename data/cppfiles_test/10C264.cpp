#include <bits/stdc++.h>
using namespace std;
char local = 'O';
template <typename T>
void read(T &p) {
  cin >> p;
}
template <typename T, typename T1>
void read(pair<T, T1> &p) {
  read(p.first);
  read(p.second);
}
template <typename T>
void read(T arr[], long long n) {
  for (long long i = 0; i < n; i++) {
    read(arr[i]);
  }
}
template <typename T>
void read(vector<T> &arr) {
  for (long long i = 0; i < arr.size(); i++) {
    read(arr[i]);
  }
}
template <typename T>
void out(T &n) {
  cout << n;
}
template <typename T, typename T1>
void out(pair<T, T1> &p) {
  cout << "(";
  out(p.first);
  cout << ",";
  out(p.second);
  cout << ")";
}
template <typename T>
void out(T arr[], long long n) {
  for (long long i = 0; i < n; i++) {
    out(arr[i]);
    cout << " ";
  }
}
template <typename T>
void out(vector<T> &arr) {
  cout << "[ ";
  for (long long i = 0; i < arr.size(); i++) {
    out(arr[i]);
    if (i != arr.size() - 1) cout << ", ";
  }
  cout << " ]";
}
template <typename T>
void out(set<T> &arr) {
  for (auto i : arr) {
    out(i);
    cout << " ";
  }
}
template <typename T>
void out(multiset<T> &arr) {
  for (auto i : arr) {
    out(i);
    cout << " ";
  }
}
template <typename T, typename T1>
void out(map<T, T1> &m) {
  for (auto i : m) {
    out(i.first);
    cout << " -> ";
    out(i.second);
    cout << ", ";
  }
}
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cout << name << " : ";
  out(arg1);
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : ";
  out(arg1);
  cout << " | ";
  __f(comma + 1, args...);
}
void cal() {}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  read(v);
  int c = 0;
  map<int, vector<int>> m;
  for (int i = 0; i < n; i++) {
    m[v[i]].push_back(i);
  }
  vector<int> res(n, 0);
  int make_pair = 0;
  for (auto i : m) {
    int ic = k;
    for (auto x : i.second) {
      if (ic == 0) {
        break;
      }
      res[x] = c + 1;
      c++;
      make_pair += c / k;
      c %= k;
      ic--;
    }
  }
  map<int, int> mc;
  for (auto &i : res) {
    if (mc[i] == make_pair) {
      i = 0;
    } else {
      mc[i]++;
    }
    cout << i << " ";
  }
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t1;
  t1 = 1;
  long long k = 1;
  cin >> t1;
  cal();
  while (t1--) {
    solve();
  }
}
