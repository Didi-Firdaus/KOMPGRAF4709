#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int A[2][2] = {{1, 3}, {2, 4}};
    int B[2][2] = {{1, 0}, {1, 0}};
    int C[2][2];
    int D[2][2];

    int pilihan;

    cout << "-----------------------" << endl;
    cout << "TUGAS MATRIKS KOMGRAF" << endl;
    cout << "-----------------------" << endl;
    cout << "1. Penjumlahan A+B" << endl;
    cout << "2. Pengurangan A-B" << endl;
    cout << "3. Perkalian AxB" << endl;
    cout << "4. Input matriks" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan;

    int result[2][2];

    switch(pilihan) {
        case 1:
            if (C[0][0] == 0 || D[0][0] == 0) {
                cout << "Matriks C dan D belum terisi. Harap isi matriks C dan D terlebih dahulu (pilihan 4)." << endl;
                return 1;
            }

            for(int i=0; i <2; i++ ){
                for(int j =0; j<2; j++){
                    result[i][j] = A[i][j] + B[i][j];
                }
            }
            cout << "Hasil penjumlahan Matriks A+B:" << endl;
            break;
        case 2:
            if (C[0][0] == 0 || D[0][0] == 0) {
                cout << "Matriks C dan D belum terisi. Harap isi matriks C dan D terlebih dahulu (pilihan 4)." << endl;
                return 1;
            }

            for(int i=0; i< 2; i++){
                for(int j = 0; j<2; j++){
                    result[i][j] = A[i][j] - B[i][j];
                }
            }
            cout << "Hasil pengurangan Matriks A-B:" << endl;
            break;
        case 3:
            if (C[0][0] == 0 || D[0][0] == 0) {
                cout << "Matriks C dan D belum terisi. Harap isi matriks C dan D terlebih dahulu (pilihan 4)." << endl;
                return 1;
            }

            for(int i = 0; i < 2; i++){
                for (int j = 0; j < 2; j++){
                    result[i][j]=0;
                    for (int k = 0; k < 2; k++){
                        result[i][j] += A[i][j] * B[k][j];
                    }
                }
            }
            cout << "Hasil perkalian Matriks AxB:" << endl;
            break;
        case 4:
            cout << "Masukkan matriks C : ";
            cin >> C[0][0];
            cout << "Masukkan matriks C : ";
            cin >> C[0][1];
            cout << "Masukkan matriks C : ";
            cin >> C[1][0];
            cout << "Masukkan matriks C : ";
            cin >> C[1][1];

            cout << "Masukkan matriks D : ";
            cin >> D[0][0];
            cout << "Masukkan matriks D : ";
            cin >> D[0][1];
            cout << "Masukkan matriks D : ";
            cin >> D[1][0];
            cout << "Masukkan matriks D : ";
            cin >> D[1][1];

            cout << "Matriks C dan D telah diisi." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            return 1;
    }

    if (pilihan >= 1 && pilihan <= 3) {
        for(int i = 0; i<2; i++){
            for(int j=0; j<2; j++){
                cout << setw(3)<< result[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
