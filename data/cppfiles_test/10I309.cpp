#include <bits/stdc++.h>
using namespace std;
const int W = 1e7 + 10;
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
void _print(set<T> v);
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
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
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
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
inline void AlPoris() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long input[W];
long long Sum_Of[W];
int main() {
  AlPoris();
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> output(n), input(n);
    vector<pair<int, int>> left;
    unordered_map<int, vector<int>> hashIndex;
    for (long long i = 0; i < n; i++) {
      cin >> input[i];
      hashIndex[input[i]].emplace_back(i);
    }
    for (auto itr : hashIndex) {
      if (itr.second.size() >= k) {
        for (long long i = 0; i < k; i++) output[itr.second[i]] = i + 1;
      } else
        left.push_back({itr.second.size(), itr.first});
    }
    sort((left).begin(), (left).end());
    int Lptr = left.size() - 1, cur = 1, Rptr = 0;
    while (Rptr < Lptr) {
      if (left[Rptr].first + left[Lptr].first >= k) {
        int n = left[Rptr].second, m = left[Lptr].second;
        for (int x : hashIndex[n]) output[x] = cur++;
        for (long long i = 0; i < k - hashIndex[n].size(); i++)
          output[hashIndex[m][i]] = cur++;
        cur = 1, Lptr--;
      }
      Rptr++;
    }
    for (long long z = 0; z < output.size(); z++) cout << output[z] << " ";
    cout << "\n";
  }
  return 0;
}
