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
char grid[10][10];
int dis[10][10], vis[10][10];
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int tx, ty;
bool isValid(int x, int y) {
  if (x < 0 || x > 8 || y < 0 || y > 8) {
    return false;
  }
  if (vis[x][y] == 1) {
    return false;
  }
  return true;
}

int bfs(int srcx, int srcy) {
  queue<pair<int, int>> q;
  q.push({srcx, srcy});
  vis[srcx][srcy] = 1;
  dis[srcx][srcy] = 0;
  if (srcx == tx && srcy == ty)return dis[srcx][srcy];

  while (!q.empty()) {
    int currx = q.front().first;
    int curry = q.front().second;
    q.pop();
    for (int i = 0; i < 8; i++) {
      if (isValid(currx + dx[i], curry + dy[i]))
      {
        srcx = currx + dx[i];
        srcy = curry + dy[i];
        dis[srcx][srcy] = dis[currx][curry] + 1;
        vis[srcx][srcy] = 1;
        q.push({srcx, srcy});
        if (srcx == tx && srcy == ty)return dis[srcx][srcy];

      }
    }
  }
}
int getX(char a) {
  return a - 'a' + 1;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, x, y;
  cin >> n;
  char a, b;
  while (n--) {
    cin >> a >> b;
    x = getX(a);
    y = b - '0';

    cin >> a >> b;
    tx = getX(a);
    ty = b - '0';

    cout << bfs(x, y) << '\n';
  }


  return 0;
}
