#include <iostream>
using namespace std;

// Verifica si un número es válido en una posición del sudoku
bool esValido(int t[9][9], int f, int c, int n)
{
    for (int i = 0; i < 9; i++)
        if (t[f][i] == n) return false;
    
    for (int i = 0; i < 9; i++)
        if (t[i][c] == n) return false;
    
    int sf = f - f % 3;
    int sc = c - c % 3;
    for (int i = sf; i < sf + 3; i++)
        for (int j = sc; j < sc + 3; j++)
            if (t[i][j] == n) return false;
    
    return true;
}

// Resuelve el sudoku usando backtracking recursivo
bool resolver(int t[9][9])
{
    for (int f = 0; f < 9; f++)
    {
        for (int c = 0; c < 9; c++)
        {
            if (t[f][c] == 0)
            {
                for (int n = 1; n <= 9; n++)
                {
                    if (esValido(t, f, c, n))
                    {
                        t[f][c] = n;
                        if (resolver(t)) return true;
                        t[f][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Imprime el tablero de forma legible
void imprimir(int t[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && i != 0)
            cout << "------+-------+------\n";
        
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0 && j != 0)
                cout << "| ";
            cout << t[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    
    int t[9][9] = {};
    int x, y, v;
    
    while (cin >> x >> y >> v)
        t[x-1][y-1] = v;
    
    cout << "Inicial:\n";
    imprimir(t);
    
    cout << "\nResolviendo...\n\n";
    resolver(t);
    
    cout << "Resuelto:\n";
    imprimir(t);
    
    return 0;
}
