// Jonas Fairchild, Pointers

#include <iostream>
using namespace std;

int numbers[] = {4, 2, 6, 8, 14, 24, 65};

void divide(int* list, int size){
    for(int i; i < size; i++){
        list[i] = list[i]/2;
        cout << list[i] << endl;
    }
    cout << "This is my numbers list: " << list << endl;
}

int capacity = 5;
int* sanity = new int[capacity];
int entries = 0;

int main(){
    int num = 4;




    cout << "The number is " << num << endl;
    cout << "The location of num is " << pnum << endl;
    divide(numbers, size(numbers));
    cout << (pnum > pday) << endl;

    if(pnum != nullptr){
        cout << *pnum << endl;
        pnum++;
    }
    cout << *pnum << endl;

    while(true){
        cout << "Number: ";
        cin >> sanity[entries];
        if(cin.fail()) break;
        entries++;
        if(entries == capacity){
            capacity += 5;
            int* temp = new int[capacity];
            for(int i=0; i<entries; i++){
                temp[i] = sanity[i];
            }
            delete[] sanity;
            sanity = temp;
        } 
    }

    for(int i=0; i<entries; i++){
        cout << sanity[i] << endl;
    }

    delete[] sanity;

    return 0;
}
