#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define INF 1000000000000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define pii pair<int,int>
#define ff first
#define ss second
#define int long long
#define max3(a,b,c) max(a,max(b,c));
#define ull unsigned long long
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


using namespace std;




//debug the string and vectors
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void init_code() {
   fast_io;
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("new.txt", "w", stdout);
#endif
#ifndef ONLINE_JUDGE
   freopen("Error.txt", "w", stderr);
#endif
}


vector<int>adj[200005];

vector<int>max_seg(400005);
vector<int>pref(400005);
vector<int>suff(400005);
vector<int>t(400005);




void build(int tl, int tr, int idx, vector<int>&v) {

   if (tl == tr) {

      t[idx] = v[tl];

      return;
   }

   int m = (tl + tr) / 2;
   build(tl, m, 2 * idx, v);
   build(m + 1, tr, 2 * idx + 1, v);
   t[idx] = max(t[2 * idx] ,  t[2 * idx + 1]);


}





void update(int tl, int tr, int idx, vector<int>&v, int pos, int new_val) {

   if (tl == tr) {
   t[idx] = new_val;
    return;
   }

   int mid = (tl + tr) / 2;
   if (pos <= mid)
      update(tl, mid, 2 * idx, v, pos, new_val);
   else
      update(mid + 1, tr, 2 * idx + 1, v, pos, new_val);

   t[idx] = max(t[2 * idx] ,  t[2 * idx + 1]);



}

int atleastX(int tl, int tr, int idx, vector<int>&v,int k){
 if(k>t[idx])return 0;
 if(tl==tr){
     return tl;
 }

 int mid = (tl+tr)/2;
int max1 = t[2*idx];
int max2 = t[2*idx+1];

if(max1>=k){
return atleastX(tl,mid,2*idx,v,k);
}
else{
return atleastX(mid+1,tr,2*idx+1,v,k);
}



}

vector<int>val(100005,0);
vector<int>level(100005,0);
vector<pii>zo(100005);
vector<int>even_leaf;
int one,zero;
void dfs(int s, int par){
	
	if(par!=-1){
		val[s]  = !val[par];
	//	zo[s] = val[s]==1?{zo[p].ff+1,zo[p].ss}:{zo[p].ff+1,zo[p].ss+1};
		level[s] = level[par]+1;
	}
	
	int ch = 0;
	for(int child:adj[s]){
		if(child!=par){
			dfs(child,s);
			ch++;
		}
	}
	
	if(ch==0 && level[s]%2==0){
	//	cout<<"hii"<<" "<<s<<endl;
		even_leaf.pb(s);
		if(val[s]==1)one++;
		if(val[s]==0)zero++;
	}
	
}

void situn(int cc) {

int n;
cin>>n;
vector<int>v(n);
for(int i=0; i<n;i++){
	cin>>v[i];
}
vector<int>lcm(n);
lcm[0] = 2;
for(int i=1; i<n;i++){
	lcm[i] = (i+2)*(lcm[i-1])/__gcd(i+2,lcm[i-1]);

}
for(int i=1; i<n;i++){

if(v[i]%lcm[i]==0){
	cout<<"NO";
	return;
}

}

cout<<"YES";

}





signed main() {
  
   fast_io;

   int t = 1;
   cin >> t;
   int cc = 1;
   while (t--) {

      situn(cc);
      cc++;
      cout << endl;
      // cout << cc << endl;
   }
   return 0;
}
