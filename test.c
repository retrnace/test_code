#include <iostream>
using namespace std;

int fetch_bit(int num, int pos)
{
    int ret = (num & (1 << pos)) >> pos;
    return ret;
}

// len is the length of array, and maximum is len + 1;
int missing_num(int a[100], int len)
{
    int b[32];
    int i, j;
    int num = 0;

    for(j = 0; j < 32; j++){
        b[j] = 0;
    }

    for(i = 0; i < len; i++ ){
	cout <<"------"<< i <<"---------\n"; 
        for(j = 0; j < 32; j++){
            b[j] ^= fetch_bit(a[i], j);
	//	cout.setf(ios::bin);
		cout << b[j] <<"\n";
	//	cout.setf(ios::dec);

        }
 

    }

    for(j = 0; j < 32; j++){
        num += (fetch_bit(b[j], 0) << j);
    }

    return num;
}

int main(int argc, char* argv[])
{
  //  cout.unsetf(ios::dec);
  //  cout.setf(ios::hex);
  //  cout.setf(ios::showbase);

    int a[100];
    int i;

    for(i = 0; i < 50; i++)
        a[i] = i + 1;

    for(i = 50; i < 60; i++)
        a[i] = i + 2;

    cout << missing_num(a, 60) << endl;

    return 0;
}

