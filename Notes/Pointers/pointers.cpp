// Jonas Fairchild, Pointers Notes

#include <iostream>

using namespace std;

int numbers[] = {4, 2, 6, 8, 14, 24, 65};
void divide(int* list, int size){
    for(int i; i < size; i++){
        list[i] = list[i]/2;
        cout << list[i] << endl;
    }
    cout << "This is my numbers list: " << *list << endl;
}

int capacity = 5;
int* sanity = new int[capacity];
int entries = 0;


int main(){
    //pointers hold addresses instead of information
    int num = 4;
    int* pnum = &num;
    int day = 5;
    int month = 9;

    const double pi = 3.141592;
    const double gpa = 3.99999;

    *pnum = 8;    
    
    // Constant pointers
    const double* ppi = &pi; //value at the location cannot be changed
    ppi = &gpa;

    int* const pday = &day; //can change value, but not location being pointed at
    *pday = 6;
    //*pday = &num;

    const int* const pmonth = &month; //location and value cannot change 

    cout << "The number is " << num << endl;
    cout << "The location of num is " << pnum << endl;
    divide(numbers, size(numbers));
    cout << (pnum > pday) << endl;

    if(pnum != nullptr){
        cout << *pnum << endl;
        pnum++;
    }
    cout << *pnum << endl;

    while (true){
        cout << "Number: ";
        cin >> sanity[entries];
        if(cin.fail()) break;
        entries++;
        if (entries == capacity){
            capacity += 5;
            int* temp = new int[capacity];
            for(int i = 0; i < entries; i++)
                temp[i] = sanity[i];
            delete[] sanity;
            sanity = temp;
        }
    }

    for (int i=0; i < entries; i++)
        cout << sanity[i] << endl;

    delete[] sanity;

    return 0; 
}