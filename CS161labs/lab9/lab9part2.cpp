#include <iostream>
#include <string>

using namespace std;

void towers (int disks, int** b, int from_col, int to_col, int spare, int length);

void move(int** b, int from_col, int to_col, int length);

void print_towers(int** b, int length);

int main(int argc, char** argv) {
        cout << "number of arguments: " << argv[1][0] << endl;
        int x;
    if(argc != 2) {
            return 0;
    }
    x = argv[1][0] - 48;

    int** b = new int* [x];

    for(int i = 0; i < x; i++) {
        b[i] = new int[3];
        for(int j = 0; j < 3; j++) {
            b[i][j] = 0;
        }
        b[i][0] = i + 1;
    }
    print_towers(b, x);
    towers(x, b, 0, 2, 1, x);

    for(int z = 0; z < x; z++) {
        delete[] b[z];
    }
    delete[] b;
}

void move(int **b, int from_col, int to_col, int length) {

    int save = 0;
    for(int i = 0; i < length; i++) {
            if(b[i][from_col] != 0) {
                save = b[i][from_col];
                b[i][from_col] = 0;
                break;
            }   
        }
        for(int j = length-1; j >= 0; j--) {
            if(b[j][to_col] == 0) {
                b[j][to_col] = save;
                return;
            }
        }
}

void towers(int disks, int** b, int from_col, int to_col, int spare, int length) {

    
    if(disks >= 1) {
        
        towers(disks-1, b, from_col, spare, to_col, length);
        move(b, from_col, to_col, length);
        print_towers(b, length);
        towers(disks-1, b, spare, to_col, from_col, length);

    }
}




void print_towers(int** b, int length) {
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < 3; j++) {
            cout << b[i][j];
        }
        cout << endl;

    }
    cout << "---" << endl;
}
