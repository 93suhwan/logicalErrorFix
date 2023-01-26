#include <bits/stdc++.h>
using namespace std;
const int INF = ((1 << 30) - 1);
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
void split(string &line, vector<string> &v, const char delimeter = ',') {
  stringstream str(line);
  string buffer;
  while (getline(str, buffer, delimeter)) {
    v.push_back(buffer);
  }
}
void test(string ans_file, string guess_file) {
  ifstream ans(ans_file);
  ifstream guess(guess_file);
  string a, g;
  int line = 1;
  while (!ans.eof()) {
    if (guess.eof()) {
      printf("There is no guess. file[%s] line : [%d]\n", ans_file.c_str(),
             line);
      exit(-1);
    }
    ans >> a;
    guess >> g;
    if (a != g) {
      printf("wrong guess! file[%s] line : [%d]\n", ans_file.c_str(), line);
      exit(-1);
    }
    line++;
  }
  if (!guess.eof()) {
    printf("There is extra guess. file[%s] line : [%d]\n", ans_file.c_str(),
           line);
    exit(-1);
  }
}
int n, s;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int sum = 0;
    int prev = -1;
    for (int i = 0; i < n; i++) {
      int a = s1[i] - '0', b = s2[i] - '0';
      int set = (1 << a) | (1 << b);
      if (set == 3) {
        sum += 2;
        if (prev == 0) {
          sum += 1;
        }
        prev = -1;
      } else if (set == 1) {
        if (prev == 1) {
          sum += 2;
          prev = -1;
        } else if (prev == 0) {
          sum += 1;
          prev = 0;
        } else {
          prev = 0;
        }
      } else {
        if (prev == -1)
          prev = 1;
        else if (prev == 0) {
          sum += 2;
          prev = -1;
        }
      }
    }
    if (prev == 0) sum++;
    cout << sum << '\n';
  }
}
