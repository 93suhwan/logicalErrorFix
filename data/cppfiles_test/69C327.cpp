#include <bits/stdc++.h>
using namespace std;
char tabla[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
vector<string> potencias;
long long int num;
int t;
string convierte(long long int num) {
  string ans = "";
  while (num > 0) {
    ans += tabla[num % 10];
    num /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int costo(string a, string b) {
  int ite_a = 0;
  int ite_b = 0;
  int movs = 0;
  while (ite_a < a.length() and ite_b < b.length()) {
    if (a[ite_a] == b[ite_b]) {
      ite_a++;
      ite_b++;
    } else {
      ite_a++;
      movs++;
    }
  }
  movs += (b.length()) - ite_b;
  movs += (a.length()) - ite_a;
  return movs;
}
string query;
int responde(string cadena) {
  int minimo = cadena.length() + 1;
  for (int i = 0; i < potencias.size(); i++) {
    minimo = min(minimo, costo(query, potencias[i]));
  }
  return minimo;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  num = 1;
  potencias.push_back("1");
  for (int i = 1; i < 63; i++) {
    num *= 2;
    potencias.push_back(convierte(num));
  }
  cin >> t;
  while (t--) {
    cin >> num;
    query = convierte(num);
    cout << responde(query) << '\n';
  }
}
