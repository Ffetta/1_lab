#include <iostream>

using namespace std;
void Sort1(int array[], int length) // сортировка вставками
{
    int a,b;
    for (int i = 1; i< length; i++)
    {
        a = array[i];
        b = i-1;
        while(b >= 0 && array[b] > a)
        {
            array[b + 1] = array[b];
            array[b] = a;
            b--;
        }
    }
}


void Sort2(int array[],int l, int r) {
    if (r == l)
        return;
    if (r - l == 1) {
        if (array[r] < array[l])
        { int a=0;
            a=array[r];
            array[r]=array[l];
            array[l]=a;

        }
        return;
    }
    int m = (r + l) / 2;
    Sort2(array,l, m);
    Sort2(array,m + 1, r);
    int buf[r+1];
    int xl = l;
    int xr = m + 1;
    int cur = 0;
    while (r - l + 1 != cur) {
        if (xl > m)
            buf[cur++] = array[xr++];
        else if (xr > r)
            buf[cur++] = array[xl++];
        else if (array
                 [xl] > array[xr])
            buf[cur++] = array[xr++];
        else buf[cur++] = array[xl++];

    }
    for (int i = 0; i < cur; i++)
        array[i + l] = buf[i];
}

int main()
{
    int Array1[10]={1,3,2,4,6,4,5,25,234,56};
   int Array2[10]={1,3,2,4,6,4,5,25,234,56};
   Sort1(Array1,10);
   Sort2(Array2,0,9);
   for (int i = 0; i < 10; i++)
    {
        cout << Array1[i] << "  ";
    }
    cout<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout << Array2[i] << "  ";
    }
    return 0;
}
