#include <bits/stdc++.h>
using namespace std;
template <class T>
void _print(T x) {
  cerr << x << endl;
}
template <class S, class T>
void _print(pair<S, T> x) {
  cerr << "{" << x.first << "," << x.second << "}" << endl;
}
template <class T>
void _print(vector<T> x) {
  cerr << "[";
  for (auto i : x) cerr << i << ", ";
  cerr << "]\n";
}
template <class S, class T>
void _print(vector<pair<S, T>> x) {
  for (auto i : x) cerr << "[" << i.first << "," << i.second << "]" << endl;
}
template <class T>
void _print(set<T> x) {
  cerr << "{ ";
  for (auto i : x) cerr << i << ", ";
  cerr << "}\n";
}
template <class S, class T>
void _print(map<S, T> x) {
  for (auto i : x) {
    cerr << i.first << ": " << i.second << endl;
  }
}
long long exp(int a, int b, int p) {
  long long res = 1;
  a = a % p;
  while (b) {
    if (b & 1) res = (res * a) % p;
    a = ((long long)a * a) % p;
    b = b >> 1;
  }
  return res;
}
long long mmiPrime(int a, int p) { return exp(a, p - 2, p); }
pair<int, int> extendedGCD(int a, int b) {
  if (b == 0) {
    pair<int, int> ans;
    ans.first = 1;
    ans.second = 0;
    return ans;
  }
  pair<int, int> temp = extendedGCD(b, a % b);
  pair<int, int> ans;
  ans.first = temp.second;
  ans.second = temp.first - (a / b) * temp.second;
  return ans;
}
int mmi(int a, int m) {
  pair<int, int> tmp = extendedGCD(a, m);
  return tmp.first;
}
int ncr(int n, int r, int p, int fact[]) {
  return ((fact[n] * mmiPrime(fact[r], p) % p) * mmiPrime(fact[n - r], p)) % p;
}
int n, m, k;
int **mat;
void solve() {
  cin >> n >> m >> k;
  mat = new int *[n];
  for (int i = 0; i < n; i++) {
    mat[i] = new int[m];
    for (int j = 0; j < m; j++) cin >> mat[i][j];
  }
  int c;
  int ans[k];
  for (int i = 0; i < k; i++) {
    cin >> c;
    --c;
    int row = 0;
    while (row < n) {
      if (mat[row][c] == 2)
        row++;
      else if (mat[row][c] == 1) {
        mat[row][c] = 2;
        c++;
      } else {
        mat[row][c] = 2;
        c--;
      }
    }
    ans[i] = c + 1;
  }
  for (int i : ans) cout << i << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t time = clock();
  solve();
  time = clock() - time;
  return 0;
}
