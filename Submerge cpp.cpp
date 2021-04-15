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

vector<int> arr[10001];
int vis[10001], in[10001], low[10001];
set<int> AP;
int timer;
void dfs(int node, int par) {
  vis[node] = 1;
  in[node] = low[node] = timer++;
  int child_count = 0;
  for (int child : arr[node]) {
    if (child == par)continue;
    if (vis[child] == 1) {
      low[node] = min(low[node], in[child]);
    }
    else {
      dfs(child, node);
      child_count++;
      low[node] = min(low[child], low[node]);

      if (in[node] <= low[child] && par != -1) {
        AP.insert(node);
      }
    }
  }
  if (par == -1 && child_count > 1) {
    AP.insert(node);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t = 1;
  // cin >> t;
  while (1) {
    int n, m, a, b;
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    for (int i = 1; i <= n; i++) {
      arr[i].clear();
      vis[i] = 0;
      AP.clear();
      timer = 1;
    }
    while (m--) {
      cin >> a >> b;
      arr[a].pb(b);
      arr[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0)
        dfs(i, -1);
    }
    cout << AP.size() << '\n';
  }
  return 0;
}
