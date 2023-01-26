#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define ar array
using pii = pair<int, int>;
using pll = pair<long , long>;
using i64 = long long;
#define X first
#define Y second
#define sz(a) ((int) a.size())
#define all(a) a.begin(), a.end()
#define mem(a, val) memset(a, val, sizeof(a))
#define F(n) for(int i=0; i<n; i++)

/*DEBUG*/
vector<string> vec_splitter(string s) {s += ',';vector<string> res;while(!s.empty()) {
res.push_back(s.substr(0, s.find(',')));s = s.substr(s.find(',') + 1);}return res;}
void debug_out(vector<string> __attribute__ ((unused)) args,__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";stringstream ss; ss << H;
cerr << args[idx] << " = " << ss.str();debug_out(args, idx + 1, LINE_NUM, T...);}
#ifdef ROHIT
#define dbg(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define dbg(...) 42 
#endif
/*********************************************************************************************/

const i64 M = (1E9)+7;
	
//i64 power(i64 a,i64 p) {
	//i64 res = 1;
	//while(p) {
		//if(p%2) res = (res * a)%M;
		//a = (a * a)%M;
		//p /= 2;	
	//}
	//
	//return res%M;
//}
	
const i64 maxn = 9 + 1000; 

int a[maxn][6];
int n;
void solve() {
	cin >> n;
	bool odd = false;
	if(n%2) odd = true;
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=5; j++)
			cin >> a[i][j];

	//observation 
	//lets say ith guy prefers some days k(1..5)
	
	//Then for an valid answer to exist there has to be
	//2 such days so that all the freuency are satisfied
	
	//so we'll iterate over all the possible days
	
	bool ans = false;	
	for(int day1=1; day1 < 5; day1++)
		for(int day2 = day1+1; day2<=5; day2++) {
			int or_array[n+1] = {};
			int cnt1=0, cnt2=0;
			for(int person = 1; person <= n; person++) {
				or_array[person] = a[person][day1] | a[person][day2];	
				if(a[person][day1]) cnt1++;
				if(a[person][day2]) cnt2++;

			}
			int AND = 1;
			for(int person; person <= n; person++)
				AND &= or_array[person];
			
			if(AND && cnt1>= n/2 && cnt2>= n/2) ans = true;
		}

	if(ans || odd)
		cout << "YES\n";
	else 
		cout << "NO\n";

}
int main() {
    cin.tie(0)->sync_with_stdio(0);
		
    int T=1;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc) {
        // cout << "Case " << tc << ": ";
        solve();
        //cout << "\n";
    }
}
