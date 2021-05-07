#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int max_size = 100;
int n,m;
char mas[max_size][max_size];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        getchar();   // переход на новую строку
        for (int j = 0; j < m; j++)
        {
            mas[i][j] = getchar();
        }
    }
}

struct point   //координата точки
{
    int x, y;
    point() {}
    point(int X, int Y)
    {
        x = X; y = Y;
    }
};

int moveX[4] = {0, 1, 0, -1};
int moveY[4] = {1, 0, -1, 0};   //для номера куска
bool correct(int x, int y)
{
    if (x < 0 || y < 0)
        return false;
    if (x >= n || y >= m)
        return false;
    return true;
}
void bfs(int x, int y)    //обход в ширину
{
    queue<point> q;
    q.push(point(x,y));
    while (!q.empty())
    {
        point cur = q.front();   //текущий элемент 1-й
        q.pop();  //удаляем 1-й элемент
        for (int i = 0; i < 4; i++)
        {
            int x = cur.x + moveX[i];  //координата по х
            int y = cur.y + moveY[i];  //координата по у
            if (correct(x,y) && mas[x][y] == '#')
            {
                q.push(point(x,y));
                mas[x][y] = '.';
            }
        }
    }
}
void solve()  //считаем кол-во островков
{
    int amount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mas[i][j] == '#')
            {
                mas[i][j] = '.';
                bfs(i,j);
                amount++;
            }
        }
    }
    cout << amount;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();
    solve();
    return 0;
}
