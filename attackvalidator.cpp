#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;

int AfromActual,BfromActual,XfromActual,YfromActual;
int AfromAttacker,BfromAttacker,XfromAttacker,YfromAttacker;

void func1(){
std::ifstream inputfile("actuallog.txt");
    inputfile >> AfromActual;
    inputfile >> BfromActual;
    inputfile >> XfromActual;
    inputfile >> YfromActual;
    inputfile.close();
}
void func2(){
std::ifstream inputfile2("attackerlog.txt");
    inputfile2 >> AfromAttacker;
    inputfile2 >> BfromAttacker;
    inputfile2 >> XfromAttacker;
    inputfile2 >> YfromAttacker;
    inputfile2.close();
}

int main(){
    //Set the values to the global variables defined above
    func1();
    func2();
    //Now to calculate the keys
    int keyOneofActual=((int)(pow(BfromAttacker,XfromActual))%101);
    int keyTwoofAttacker=((int)(pow(AfromActual,YfromAttacker))%101);
    bool flag=false; //Attack set unsuccessful
    if(keyOneofActual == keyTwoofAttacker){
        flag=true;
    }
    int keyOneofAttacker=((int)(pow(BfromActual,XfromAttacker))%101);
    int keyTwoofActual=((int)(pow(AfromAttacker,YfromActual))%101);
    if(keyOneofAttacker!=keyTwoofActual){
        flag=false;
    }
    if(flag){
        cout << "Attack successful!";
    }
    else{
        cout << "Keys not matched. Attack unsuccessful.";
    }
}