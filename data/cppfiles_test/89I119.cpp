#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <deque>
#include <bitset>

using namespace std;
     
typedef long long ll;
typedef string ss;
 
#define pb push_back
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair < int, int >

const int N = 1e5 + 5, INF = int(1e9), mod = 1e9 + 7, base = 1;

int n, a[N], q;

int lcm(int n, int m){
	return n * m / __gcd(n, m);
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		bool ok = 0;
		int x = 1;
		for(int j = 2; j <= min(i + 1, 21); j++){
			x = lcm(x, j);
		}
		if(a[i] % x == 0){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
    speed;
    cin >> q;
    while(q--){
    	solve();
	}
}