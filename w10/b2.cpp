#include <iostream>
using namespace std;

int n, m, f[1001];
bool edge[1001][1001];
int first, last;

void fillF(int cur)
{
    if (f[last])
        return;
    for (int i = 0; i <= n; i++)
        if (edge[i][cur]){
            if (f[i] == 0)
                fillF(i);
            f[cur] += f[i];
        }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        edge[a][b] = 1;
    }
    cin >> first >> last;
    f[0] = 1; edge[0][first] = 1;
    for (int i = 1; i <= n; i++)
        if (f[i] == 0)
            fillF(i);
    cout << f[last];
}
/*
10 16
1 2
1 3
1 4
2 5
4 5
3 4
3 6
5 8
5 7
6 7
6 9
7 8
7 9
7 10
8 10
9 10
1 10
*/
