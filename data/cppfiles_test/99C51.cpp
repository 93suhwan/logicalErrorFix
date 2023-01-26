#include <bits/stdc++.h>
using namespace std;
template <typename Kausi>
void debug(vector<Kausi> v) {
  cerr << "v = [ ";
  long long n = v.size();
  for (int i = 0; i < n; i++) {
    cerr << v[i];
    if (i < n - 1) cerr << ", ";
  }
  cerr << " ] length = " << v.size() << "\n";
}
long long stringToLong(string s) {
  stringstream raaz(s);
  long long x = 0;
  raaz >> x;
  return x;
}
string longToString(long long k) {
  stringstream ss;
  ss << k;
  string s;
  ss >> s;
  return s;
}
bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
void scanArr(int *arr, int n) {
  for (int i = 0; i < n; i++) cin >> arr[i];
}
void printArr(int *arr, int n) {
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "\n";
}
template <typename Kausi>
void scanVector(vector<Kausi> &v, int n) {
  for (int i = 0; i < n; i++) {
    Kausi temp;
    cin >> temp;
    v.push_back(temp);
  }
}
template <typename Kausi>
void printVector(vector<Kausi> v) {
  for (auto x : v) cout << x << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n, '='));
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) v[i][i] = 'X';
    bool ans = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == '2') {
        bool flg = true;
        for (int j = 0; j < n; j++) {
          if (j != i) {
            if (v[i][j] == '=' and v[j][i] == '=' and s[j] != '1') {
              v[i][j] = '+';
              v[j][i] = '-';
              flg = false;
              break;
            }
          }
        }
        if (flg) {
          cout << "NO"
               << "\n";
          ans = false;
          break;
        }
      }
    }
    if (ans) {
      cout << "YES"
           << "\n";
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << v[i][j];
        cout << "\n";
      }
    }
  }
  return 0;
}
