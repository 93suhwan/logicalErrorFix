/*                              _______                                _________
    |\     |         /\         |      |        /\        |\     |    |
    | \    |        /  \        |      |       /  \       | \    |    |
    |  \   |       /    \       |\-----       /    \      |  \   |    |
    |   \  |      /======\      | \          /======\     |   \  |    |     ====|
    |    \ |     /        \     |  \        /        \    |    \ |    |         |
    |     \|    /          \    |   \      /          \   |     \|    |_________|
*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
//#define int ll
#define vi vector<int>
#define vb vector<bool>
#define vvb vector<vb >
#define pii pair<int,int>
#define ss second
#define ff first
#define vpii vector<pii>
#define vvi vector<vi >
#define vs vector<string>
#define vvs vector<vs >
#define pqi priority_queue <int>
#define minpqi priority_queue <int, vector<int>, greater<int> >
#define all(x) x.begin(),x.end()
#define mii map<int,int>
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define per1(i,n) for(ll i=n;i>0;i--)
#define repeat(i,start,n) for(ll i=start;i<n;i++)
#define inp(arr,n) ll arr[n];rep(i,n){ cin>>arr[i];}
#define inp1(arr,n) ll arr[n+1];rep1(i,n){ cin>>arr[i];}
#define inp2d(arr,n,m) ll arr[n][m];rep(i,n)rep(j,m)cin>>arr[i][j];
#define inpg(adj,m) rep(i,m){int a,b;cin>>a>>b;adj[a].pb(b);adj[b].pb(a);}
#define print(a,n) for(ll i=0;i<n;i++){ cout<<a[i]<<" ";}
#define print1(a,n) for(ll i=1;i<=n;i++){ cout<<a[i]<<" ";}
#define mod 1000000007
#define maxx 1000000000000000000
#define PI 3.141592653589793238462643383279
#define mmax(a,b,c) max(a,max(b,c))
#define mmin(a,b,c) min(a,min(b,c))
#define init(arr,a) memset(arr,a,sizeof(arr))
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define maxe *max_element
#define mine *min_element
string convert_to_bit(int a,int bit){
	string s;
	while(a>0){
		s+=(a%2)+48;
		a/=2;
	}
	int n=s.size();
	while(n<bit)
		s+='0';
	reverse(s.begin(),s.end());
	return s;
}
int to_int(string s)
{
    int ans=0;
    string temp;
    int i=0;
    while(s[i]=='0')
    {
        i++;
    }
    if(i==s.size())
        return 0;
    temp.assign(s,i,s.size());
    int mul=1;
    for(i=temp.size()-1;i>=0;i--)
    {
        int a=temp[i]-'0';
        ans+=mul*a;
        mul*=10;
    }
    return ans;

}
string to_string(int n)
{
    string ans="";
    if(n==0)
        return "0";
    while(n>0)
    {
        int a=n%10;
        n/=10;
        char temp=a+'0';
        ans+=temp;
    }
    reverse(all(ans));
    return ans;
}
int bin_to_dec(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    return dec_value;
}
int binstr_to_dec(string s)
{
    int ans=0;
    rep(i,s.size())
        if(s[i]=='1')
            ans+=pow(2,s.size()-i-1);
    return ans;
}

//------------------Codejam------------------//
//cout<<"Case #"<<T<<": "<<ans<<endl;
//------------------------------------------//

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void faltu()
{
    int a=2;
    while(a>0)a--;
}
//------------------------------------Code Starts here------------------------------------//
int st[1000000];
void update(int ss,int se,int ind,int pos)
{
    if(pos<ss||pos>se)return;
    if(ss==se)
    {
        st[ind]+=1;
        return;
    }
    int mid=(ss+se)/2;
    update(ss,mid,ind*2+1,pos);
    update(mid+1,se,ind*2+2,pos);
    st[ind]=st[ind*2+1]+st[ind*2+2];
}
int query(int ss,int se,int ind,int qs,int qe)
{
    if(qe<ss||qs>se)return 0;
    if(qs<=ss&&qe>=se)return st[ind];
    int mid=(ss+se)/2;
    return query(ss,mid,ind*2+1,qs,qe)+query(mid+1,se,ind*2+2,qs,qe);
}
void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<=4*n+100;i++)st[i]=0;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    set<int> v;
    for(int i=0;i<n;i++)v.insert(arr[i]);
    map<int,int> temp;
    int i1=0;
    for(auto i:v)
    {
        temp[i]=i1;
        i1++;
    }
    for(int i=0;i<n;i++)arr[i]=temp[arr[i]];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int l1=query(0,n-1,0,0,arr[i]-1);
        int g1=i-query(0,n-1,0,0,arr[i]);
        update(0,n-1,0,arr[i]);
        ans+=min(l1,g1);
    }
    cout<<ans<<endl;
}
main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
        //cout<<solve()<<endl;
    }
}
