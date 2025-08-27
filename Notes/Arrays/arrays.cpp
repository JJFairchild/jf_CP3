// Jonas Fairchild, Arrays Notes

#include <iostream>
using namespace std;

string fam[6] = {"Kenneth", "Annette", "Jonas", "Landon", "William", "Spencer"};
string sibs[4] = {"Jonas", "Landon", "William", "Spencer"};

void search(string list, string item){
    cout << list << endl;
}

int main(){
    for(int i=0; i<size(fam); i++){
        cout << fam[i] << " Fairchild";
        if (fam[i] == sibs[i-2]){
            cout << " (sibling)";
        }
        cout << endl;
    }

    return 0;
}