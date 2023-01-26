#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1);
string add(string a, string b) {
  string result = "";
  int temp = 0;
  int size_a = a.size() - 1;
  int size_b = b.size() - 1;
  while (size_a >= 0 || size_b >= 0 || temp == 1) {
    temp += ((size_a >= 0) ? a[size_a] - '0' : 0);
    temp += ((size_b >= 0) ? b[size_b] - '0' : 0);
    result = char(temp % 2 + '0') + result;
    temp /= 2;
    size_a--;
    size_b--;
  }
  return result;
}
string decimalToBinary(int n) {
  string s = bitset<64>(n).to_string();
  const auto loc1 = s.find('1');
  if (loc1 != string::npos) return s.substr(loc1);
  return "0";
}
int nofdigits(int n) {
  int coun = 0;
  while (n != 0) {
    n = n / 10;
    coun++;
  }
  return coun;
}
void solve() {
  int n, k;
  cin >> n >> k;
  int num = n;
  vector<int> v;
  while (num != 0) {
    v.push_back(num % 10);
    num = num / 10;
  }
  reverse(v.begin(), v.end());
  if (k == 1) {
    int dif[2];
    memset(dif, -1, sizeof(dif));
    int number_of_digits = nofdigits(n);
    dif[0] = n / pow(10, number_of_digits - 1);
    for (int i = number_of_digits - 2; i > -1; i--) {
      int tmp = n / pow(10, i);
      if (tmp % 10 != dif[0]) {
        dif[1] = tmp % 10;
        break;
      }
    }
    if (dif[1] == -1)
      cout << n << "\n";
    else {
      if (dif[1] < dif[0]) {
        for (int i = 0; i < number_of_digits; i++) cout << dif[0];
      } else {
        for (int i = 0; i < number_of_digits; i++) cout << (dif[0] + 1);
      }
      cout << "\n";
    }
  }
  if (k == 2) {
    int dif[10];
    memset(dif, -1, sizeof(dif));
    int number_of_digits = nofdigits(n);
    dif[0] = n / pow(10, number_of_digits - 1);
    int pos[10];
    int curr = 0;
    for (int i = number_of_digits - 2; i > -1; i--) {
      int tmp = n / pow(10, i);
      if (tmp % 10 != dif[curr] && tmp % 10 != dif[0]) {
        dif[curr + 1] = tmp % 10;
        pos[curr] = number_of_digits - i - 1;
        curr++;
      }
    }
    if (dif[2] == -1)
      cout << n << "\n";
    else {
      string original_num = to_string(n);
      string current_num = to_string(dif[0]) + to_string(dif[1]);
      string right_part = "";
      string full_num = "";
      int a = min(dif[0], dif[1]);
      int b = max(dif[0], dif[1]);
      string binary_rep = "";
      for (int i = 2; i < number_of_digits; i++) {
        binary_rep = binary_rep + "0";
      }
      int variations = pow(2, number_of_digits - 2);
      for (int k = 0; k < 9; k++) {
        for (int j = 0; j < variations; j++) {
          for (int i = 0; i < number_of_digits - 2; i++) {
            if (dif[0] == dif[1] && j <= 9)
              right_part = right_part + to_string(j);
            else if (binary_rep[i] == '0')
              right_part = right_part + to_string(a);
            else
              right_part = right_part + to_string(b);
          }
          full_num = current_num + right_part;
          if (full_num >= original_num) {
            cout << full_num << "\n";
            return;
          }
          right_part = "";
          full_num = "";
          binary_rep = add(binary_rep, "1");
        }
        dif[1]++;
        a = min(dif[0], dif[1]);
        b = max(dif[0], dif[1]);
        current_num = to_string(dif[0]) + to_string(dif[1]);
        binary_rep = "";
        for (int i = 2; i < number_of_digits; i++) {
          binary_rep = binary_rep + "0";
        }
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
