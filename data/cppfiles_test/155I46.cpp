#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define rep(i, n, a) for(long long i = a; i < n; i++)
#define repn(i, n, a) for(long long i = a; i > n; i--)
#define pb push_back
#define endl '\n'
#define test(x) long long t; cin>>t; while(t--) x()
#define int long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector <vector<int> >
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define in(v,n,a) rep(zq,n,a) cin >> v[zq];
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define gcd(a,b) __gcd(a,b);

using ld = long double;

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;


void reader(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" ,stdin);
		freopen("output.txt", "w" ,stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

//////////////Data Structures////////////
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//find_by_order()  order_by_key();
//////////////iostreams////////////////
template<typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2> &a) {in >> a.first >> a.second; return in;}
template<typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {out << a.first << " " << a.second; return out;}
template<typename T1>
ostream& operator<<(ostream& out, vector <T1> &a) {
	for(T1 f: a)
		out << f << ' ';
	return out;
}
string operator*(string st, int n){
	string tmp = "";
	rep(i,n,0) tmp.append(st);
	return tmp;
}

void deb_out() { 
	cout << endl; 
}
template <typename Head, typename... Tail>
void deb_out(Head H, Tail... T) {
	cout << " " << H;
	deb_out(T...);
}
#ifndef ONLINE_JUDGE
	#define deb(...) cout << "[" << #__VA_ARGS__ << "]:", deb_out(__VA_ARGS__);
#else
	#define deb(...) ;
#endif

////////////functions///////////////////
inline int _ceil(int a, int b){
	return (a + b - 1)/b;
}

int bin_search(vi &d, int l , int r){
	while(r > l){
		int m = l + (r-l)/2;
		// if(check(m,d)) r = m;
		// else l = m+1;
	}
	return l;
}
int power(int x, unsigned int y) 
{ 
	int res = 1;
	// x = x%M;
	if(x == 0) return 0;
	while (y) { 
		if (y & 1) 
			res = res*x;//%M; 
		y = y>>1;
		x = x*x;
		// x = x%M; 
	} 
	return res; 
}
///////////////////////////////////////

int ceil(int a, int b){
	return (a - b + 2 - 1)/2;
}

bool comp(char &a, char &b){
	if(a == 'b' && b == 'c') return false;
	else if(a == 'c' && b == 'b')return true;
	return a < b;
}

// check if a string has charachter 'a' 'b' and 'c'
bool check(string &s){
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	rep(i,s.size(), 0){
		if(s[i] == 'a') cnt1++;
		else if(s[i] == 'b') cnt2++;
		else if(s[i] == 'c') cnt3++;
	}
	if(cnt1 > 0 && cnt2 > 0 && cnt3 > 0) return true;
	else return false;
}

//find 2 closest odd numbers whose sum is equal to n
pair<int,int> closest_sum(int n){
	int l = 1, r = n;
	while(l < r){
		int m = l + (r-l)/2;
		if(m*(m+1) == 2*n) return {m, m+1};
		else if(m*(m+1) < 2*n) l = m+1;
		else r = m;
	}
	return {l, l+1};
}

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}

void solve(){
	int n ;
	cin >> n;
	vi arr(n);
	in(arr,n,0);
	string s;
	cin >> s;
	vector<pair<int, int>> liked, disliked;
	rep(i, n, 0){
		if(s[i] == '0') disliked.pb({i+1, arr[i]});
		else liked.pb({i+1, arr[i]});
	}
	sort(liked.begin(), liked.end(), sortbysec);
	int tmp = disliked.size();
	map <int, int> m;
	rep(i,tmp,0){
		m[disliked[i].first] = i+1;
	}
	rep(i,liked.size(),0){
		m[liked[i].first] = tmp+i+1;
	}
	rep(i,n,0){
		cout << m[i+1] << " ";
	}
	cout << endl;
}

int32_t main(){
	// reader();
	// init();
	// solve();
	int testcases;
	cin >> testcases;
	while(testcases--) solve();
	return 0;
}
