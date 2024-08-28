#include <iostream>
#include <vector>

using namespace std;

void multiMatBlocks(const vector<vector<double>>& A, const vector<vector<double>>& B, vector<vector<double>>& C, int N, int blockSize) {
    for (int ii = 0; ii < N; ii += blockSize) {
        for (int jj = 0; jj < N; jj += blockSize) {
            for (int kk = 0; kk < N; kk += blockSize) {
                for (int i = ii; i < min(ii + blockSize, N); ++i) {
                    for (int j = jj; j < min(jj + blockSize, N); ++j) {
                        double sum = 0;
                        for (int k = kk; k < min(kk + blockSize, N); ++k) {
                            sum += A[i][k] * B[k][j];
                        }
                        C[i][j] += sum;
                    }
                }
            }
        }
    }
}

int main() {
    int N = 500;
    int blockSize = 50;
    vector<vector<double>> A(N, vector<double>(N, 1.0));
    vector<vector<double>> B(N, vector<double>(N, 1.0));
    vector<vector<double>> C(N, vector<double>(N, 0.0));

    multiMatBlocks(A, B, C, N, blockSize);
}