#include <iostream>
#include <string.h>
using namespace std;

struct Carro{
    float gas;
    float gasMax;
    int pass;
    int passMax;
    float km;

    void show(){
        cout<< "    pass: "<< pass<< ", gas: "<< gas<< ", km: "<< km<< endl;
    }

    bool in(){
        pass++;
        if  (pass > passMax){
            pass= passMax;
            return false;
        } else return true;
    }
    
    bool out(){
        pass--;
        if  (pass < 0){
            pass= 0;
            return false;
        } else return true;
    }

    void fuel(float value){
        gas= gas + value;
        if(gas > gasMax)
            gas= gasMax;
        cout<< "    done"<< endl;
    }

    void drive(float distance){
        if(pass== 0){
            cout<< "    fail: nao ha ninguem no carro"<< endl;
        }   else{
            if(gas < distance/10){
                cout<< "    fail: gasolina insuficiente"<< endl;
            }   else{
                km= km + distance;
                gas= gas - distance/10;
                cout<< "    done"<< endl;
            }
        }
    }
};

int main(){
    Carro karro={0, 10, 0, 2, 0};
    string op;
    float value=0, distance=0;

    while   (true){
        cin>> op;
        if(op=="show")
            karro.show();
        if(op=="in"){
            if(karro.in()== true)
                cout<< "    done"<< endl;
            else    cout<< "    fail: limite de pessoas atingido"<< endl;
        }
        if(op== "out"){
            if(karro.out()== true)
                cout<< "    done"<< endl;
            else    cout<< "    fail: nao ha ninguem no carro"<< endl;
        }
        if(op== "fuel"){
            cin>> value;
            karro.fuel(value);
        }
        
        if(op== "drive"){
            cin>> distance;
            karro.drive(distance);
        }

        if(op=="end")
            break;
    }
    return 0;
}
