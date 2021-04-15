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
char grid[1001][1001];
bool vis[1001][1001];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool isValid(int x, int y, int n, int m)
{
  if (x < 0 || x > n - 1 || y < 0 || y > m - 1) {
    return false;
  }
  if (vis[x][y] == true || grid[x][y] == '#') {
    return false;
  }
  return true;
}

void dfs(int x, int y, int n, int m) {
  vis[x][y] = true;
  for (int i = 0; i < 4; i++) {
    if (isValid(x + dx[i], y + dy[i], n, m)) {
      dfs(x + dx[i], y + dy[i], n, m);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;
  // char grid[n][m];
  char ch;
  for (int i = 0; i < n; i++) {
    // deb2(n, m);

    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      // grid[i][j].push_back(ch);

    }
  }
  int connected_component = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] == false && grid[i][j] == '.') {
        connected_component++;
        dfs( i, j, n, m);
      }
    }
  }
  cout << connected_component << '\n';
  return 0;
}
