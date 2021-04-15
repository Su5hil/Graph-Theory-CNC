#include<bits/stdc++.h>
using namespace std;
#define loop(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define lli long long int
#define sci(x) scanf("%d",&x)
#define scii(x,y) scanf("%d %d",&x,&y)
#define scl(x) scanf("%lld",&x)
#define scs(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;

vi arr[100001];
int in[100001], low[100001], vis[100001], timer;
bool isBridge;
vector<pair<int, int>> edgeList;

void dfs(int node , int par) {
  vis[node] = 1;
  in[node] = low[node] = timer;
  timer++;
  for (int child : arr[node]) {
    if (par == child)continue;
    if (vis[child] == 1) {
      low[node] = min(in[child], low[node]);
      if (in[node] > in[child])
        edgeList.pb({node, child});
    }
    else
    {
      dfs(child, node);
      if (low[child] > in[node]) {
        isBridge = true;
        return;
      }
      edgeList.pb({node, child});
      low[node] = min(low[node], low[child]);
    }
  }

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    int n, m, a, b;
    cin >> n >> m;
    while (m--) {
      cin >> a >> b;
      arr[a].pb(b);
      arr[b].pb(a);
    }
    dfs(1, -1);
    if (isBridge) {
      cout << 0 << '\n';

    }
    else {
      for (pair<int, int> p : edgeList) {
        cout << p.first << " " << p.second << '\n';
      }
    }
  }
  return 0;
}
