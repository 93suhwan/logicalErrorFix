#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(deque<T> v);
template <class T>
void _print(unordered_set<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(unordered_map<T, V> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(deque<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(unordered_set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long countDigit(long long n) { return floor(log10(n) + 1); }
bool revsort(long long a, long long b) { return a > b; }
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int index = 0; index < n; index++) {
      bool isFound = false;
      for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) isFound = true;
      }
      if (!isFound) break;
      int i1 = -1;
      int mn = INT_MAX;
      for (int i = index; i < n; i++) {
        if (mn > arr[i]) {
          mn = arr[i];
          i1 = i;
        }
      }
      vector<int> temp;
      for (int i = i1; i < n; i++) {
        temp.push_back(arr[i]);
      }
      for (int i = index; i < i1; i++) {
        temp.push_back(arr[i]);
      }
      for (int i = index; i < n; i++) {
        arr[i] = temp[i - index];
      };
      if (i1 - index > 0) {
        vector<int> t;
        t.push_back(index + 1);
        t.push_back(n);
        t.push_back(i1 - index);
        ans.push_back(t);
      }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
      }
      cout << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  return 0;
}
