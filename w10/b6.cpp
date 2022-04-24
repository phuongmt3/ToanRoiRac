#include <iostream>
using namespace std;

int n, m, color[1001];
bool edge[1001][1001];

bool coloring(int point, int colorType)
{
    for (int i = point + 1; i <= n; i++)
    if (edge[i][point]){
        if (color[i] == colorType)
            return 0;
        else if (!color[i]){
            color[i] = 3 - colorType;
            if (!coloring(i, color[i]))
                return 0;
        }
    }
    return 1;
}

int main()
{
    freopen("draft.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if (a < b)
            edge[a][b] = 1;
        else
            edge[b][a] = 1;
    }
    for (int i = 1; i <= n; i++)
    if (!color[i]){
        color[i] = 1;
        if (!coloring(i, 1)){
            cout << "NO"; return 0;
        }
    }
    cout << "YES";
}

/*
7 11
1 3
1 5
1 6
1 7
2 6
2 3
2 5
3 4
4 5
4 6
4 7
*/
