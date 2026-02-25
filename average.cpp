#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc,char* argv[]){
    double x;
    double sum = 0.0;
    double aver;

    if(argc <= 1){
        cout << "Please input numbers to find average.\n";
        return 0;
    }
    for(int i = 1; i < argc; i++){
        x = atof(argv[i]);
        sum += x;
    }
        aver = sum/(argc-1);
        cout << "--------------------------------- \n";
        cout << "Average of " << argc-1 << " numbers = " << aver <<"\n";
        cout << "--------------------------------- \n";

    return 0;
}
