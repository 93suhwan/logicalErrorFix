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
    vector<vector<int>> v;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int times = n;
    int mn = INT_MAX;
    int mn2 = INT_MAX;
    int index1 = -1;
    int index2 = -1;
    for (int i = 0; i < n; i++) {
      if (mn > arr[i]) {
        mn = arr[i];
        index1 = i;
      }
    }
    int k = 0;
    while (times--) {
      mn2 = INT_MAX;
      for (int i = 0; i < n; i++) {
        if (i != index1 && arr[i] >= mn && mn2 >= arr[i]) {
          index2 = i;
          mn2 = arr[i];
        }
      }
      vector<int> m;
      if (index2 < index1) {
        if ((index2 + 1) != (index1 + 1)) {
          m.push_back(index2 + 1);
          m.push_back(index1 + 1);
          m.push_back(1);
          int diff = index1 - index2;
          int i1 = index2;
          while (diff--) {
            int temp = arr[i1];
            arr[i1] = arr[i1 + 1];
            arr[i1 + 1] = temp;
            i1++;
          }
          v.push_back(m);
        }
      } else {
        if ((index1 + 2) != (index2 + 1)) {
          m.push_back(index1 + 2);
          m.push_back(index2 + 1);
          m.push_back(1);
          int diff = (index2) - (index1 + 1);
          int i1 = index2;
          while (diff--) {
            int temp = arr[i1];
            arr[i1] = arr[i1 - 1];
            arr[i1 - 1] = temp;
            i1--;
          }
          v.push_back(m);
        }
        index1++;
      }
      mn = mn2;
      bool isSorted = true;
      for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
          isSorted = false;
          break;
        }
      }
      if (isSorted) break;
    };
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v[i].size(); j++) cout << v[i][j] << " ";
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
