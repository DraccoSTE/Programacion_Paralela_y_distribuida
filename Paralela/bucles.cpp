#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

const int MAX = 1500;

int main() {
    cout << "Inicio del programa" << endl;

    vector<vector<double>> A(MAX, vector<double>(MAX, 1.0));
    vector<double> x(MAX, 1.0);
    vector<double> y(MAX, 0.0);

    //cout << "Matrices y vectores inicializados" << endl;

    // Primer bucle
    chrono::high_resolution_clock::time_point start1 = chrono::high_resolution_clock::now(); // Inicio del temporizador

    for (int k = 0; k < MAX; k++) {
        y[k] = 0;
    }

    //cout << "Primer bucle - Parte 1 completada" << endl;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    //cout << "Primer bucle completado" << endl;

    chrono::high_resolution_clock::time_point end1 = chrono::high_resolution_clock::now(); // Fin del temporizador
    chrono::microseconds duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

    cout << "Tiempo de ejecución del primer bucle: " << duration1.count() << " microsegundos" << endl;

    // Segundo bucle
    chrono::high_resolution_clock::time_point start2 = chrono::high_resolution_clock::now(); // Inicio del temporizador

    for (int k = 0; k < MAX; k++) {
        y[k] = 0;
    }

    //cout << "Segundo bucle - Parte 1 completada" << endl;

    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }

    //cout << "Segundo bucle completado" << endl;

    chrono::high_resolution_clock::time_point end2 = chrono::high_resolution_clock::now(); // Fin del temporizador
    chrono::microseconds duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

    cout << "Tiempo de ejecución del segundo bucle: " << duration2.count() << " microsegundos" << endl;

    cout << "Fin del programa" << endl;

    return 0;
}
