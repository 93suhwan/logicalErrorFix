#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long int
#define ld long double
#define max3(a, b, c)   max(max(a, b), c)
#define min3(a, b, c)   min(min(a, b), c)
#define test int t; cin>>t; while(t--)
#define lo_bo(a, x) ((int)(lower_bound(a.begin(), a.end(), x) - a.begin()))
#define up_bo(a, x) ((int)(upper_bound(a.begin(), a.end(), x) - a.begin()))
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define MAX 1000001
#define mod 1000000007
#define endl "\n"
#define prq priority_queue

ll fexp(long long a, long long b) { long long res = 1; a=a%mod; if(a==0)return 0; while (b > 0) { if (b & 1) res = (res * a)%mod; a = (a*a)%mod; b = b>>1; } return res; }
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
ll inverse(ll a, ll p){return fexp(a, p-2);}
bool IsVowel(char ch){return (ch=='A'||ch=='E'||ch=='I'||ch =='O'||ch=='U'||ch=='Y'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='y');}//included Y


int main(){
	test{
		int W,H;cin>>W>>H;
		int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
		int w,h;cin>>w>>h;
		int dist = INT_MAX;
		if(abs(x2-x1)+w>W&&abs(y2-y1)+h>H){
			cout<<-1<<endl;
			continue;
		}
		if(abs(x2-x1)+w<=W){
		if((x1>=0&&x1<=w)&&(y1>=0&&y1<=h)){dist=min(dist,abs(w-x1));}
		if((x1>=0&&x1<=w)&&(y2>=H-h&&y2<=h)){dist=min(dist,abs(w-x1));}
		if((x2>W-w&&x2<=W)&&(y2>H-h&&y2<=H)){dist=min(dist,abs(W-w-x2));}
		if((x2>W-w&&x2<W)&&(y1>=0&&y1<h)){dist=min(dist,abs(W-w-x2));}
		}
		if(abs(y2-y1)+h<=H){
		if((x1>=0&&x1<w)&&(y1>=0&&y1<=h)){dist=min(dist,abs(h-y1));}
		if((x1>=0&&x1<w)&&(y2>=H-h&&y2<=h)){dist=min(dist,abs(H-h-y2));}
		if((x2>=W-w&&x2<=W)&&(y2>=H-h&&y2<=H)){dist=min(dist,abs(H-h-y2));}
		if((x2>=W-w&&x2<=W)&&(y1>=0&&y1<=h)){dist=min(dist,abs(h-y1));}
		}
		cout.precision(8);
		cout<<dist<<endl;
		}
return 0;
}
