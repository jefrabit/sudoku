#include <iostream>

#define MAX 9

using namespace std;

// Backtracking
void SolucionarSudoku(int tablero[9][9])
{
}

void Imprimir(int tablero[9][9])
{
    for (int fila = 0; fila < 9; fila++)
    {
        if (fila % 3 == 0 && fila != 0)
        {
            cout << "------+-------+------" << endl;
        }

        for (int col = 0; col < 9; col++)
        {
            if (col % 3 == 0 && col != 0)
            {
                cout << "| ";
            }

            cout << tablero[fila][col] << " ";
        }

        cout << endl;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);

    // Ingresamos los valores del sudoku
    // Finaliza cuando termine de leer la entrada
    int tablero[9][9] = {};

    int pos_x, pos_y, valor;

    while (cin >> pos_x >> pos_y >> valor)
    {
        tablero[pos_x - 1][pos_y - 1] = valor;
    }

    Imprimir(tablero);

    SolucionarSudoku(tablero);

    Imprimir(tablero);

    return 0;
}