#include <iostream>

// ����� ����������� backtracking: ����� ������� ����� ����� ��������� � ������ ������ ������� ��� ��� ������� �� �������� ������ ������

/*
 procedure backtracking(vector, i /step/) {
    if (vector �� ����� ������ ���������)
        exit;
    if (vector �������� ��������) {
        �������� vector;
        exit
    }
    for (s �� s[i])
        backtracking(vector+s, i+1);
 }
*/

/*
 ������: ������� ��� �����������
        N=3 - ���-�� �������, M=2 - ���-�� �����
1 1 1 | 2 1 1
1 1 2 | 2 1 2
1 2 1 | 2 2 1
1 2 2 | 2 2 2
*/

void accommodations(int d[], int pos, int N, int M) {
    if (pos == N) {
        for (int i = 0; i < N; ++i)
            std::cout << d[i];
        std::cout << '\n';
        return;
    }
    for (int k = 1; k <= M; ++k) {
        d[pos] = k;
        accommodations(d, pos + 1, N, M);
        d[pos] = 0;
    }
}

/*
 ������: ������� ��� ������������
 N = 3 - ���-�� �����
 1 2 3
 1 3 2
 2 1 3
 2 3 1
 3 1 2
 3 2 1
*/

void permutations(int d[], int pos, int N, bool used[]) {
    if (pos == N) {
        for (int i = 0; i < N; ++i)
            std::cout << d[i];
        std::cout << '\n';
        return;
    }
    for (int k = 1; k <= N; ++k) {
        if (!used[k-1]) {
            d[pos] = k;
            used[k-1] = true;
            permutations(d, pos + 1, N, used);
            d[pos] = 0;
            used[k-1] = false;
        }
    }
}

// hometask: implement combinations

void combinations() {

}

/*
 ������: ����������� N ������ �� ��������� �����
 N = 8 - ���-�� ������

    0 1 2 3 4 5 6 7
 0: * * * q * * * *     * - ������ ������
 1: q * * * * * * *     q - ������ � �����
 2: * * * * q * * *
 3: * * * * * * * q     d[8] - ������ ������� �� ��������
 4: * q * * * * * *     d[i] - ������ ������ � ����� ��� i-�� �������
 5: * * * * * * q *     h[i] - ������ �� i-� ������
 6: * * q * * * * *     diag_add - ������ �� ������������ ��������� (i+j)
 7: * * * * * q * *     diag_sub - ������ �� ��������� ��������� (i-j+(N-1))

 d = [1, 4, 6, 0 , 2, 7, 5, 3]
*/

void queenPlacement(int d[], bool h[], bool diag_sub[], bool diag_add[], int pos, int N, bool& found) {
    if (pos == N) {
        found = true;
        for (int i = 0; i < N; ++i) {
            std::cout << d[i];
        }
        std::cout << '\n';
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (!h[i] && !diag_add[pos + i] && !diag_sub[i - pos + N - 1]) {
            d[pos] = i;
            h[i] = true;
            diag_add[pos + i] = true;
            diag_sub[i - pos + N - 1] = true;
            queenPlacement(d, h, diag_sub, diag_add, pos + 1, N, found);
            /*if (found) {
                return;
            }*/
            d[pos] = 0;
            h[i] = false;
            diag_add[pos + i] = false;
            diag_sub[i - pos + N - 1] = false;
        }
    }
}

int main() {
    const int N = 3, M = 2;
    int d[N];

    std::cout << "Accomodations: " << '\n';
    accommodations(d, 0, N, M);
    std::cout << '\n';

    std::cout << "Permutations: " << '\n';
    bool used[N] = { false, false, false };
    permutations(d, 0, N, used);
    std::cout << '\n';

    std::cout << "Queens arrangement: " << '\n';
    const int BOARD_SIZE = 8;
    int positions[BOARD_SIZE];

    bool h[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; ++i) {
        h[i] = false;
    }

    const int DIAGONALS_NUMBER = 2 * BOARD_SIZE - 1;
    bool diag_sub[DIAGONALS_NUMBER];
    bool diag_sum[DIAGONALS_NUMBER];
    for (int i = 0; i < DIAGONALS_NUMBER; ++i) {
        diag_sum[i] = false;
        diag_sub[i] = false;
    }
    bool found = false;
    queenPlacement(positions, h, diag_sub, diag_sum, 0, BOARD_SIZE, found);
    std::cout << '\n';

    return 0;
}
