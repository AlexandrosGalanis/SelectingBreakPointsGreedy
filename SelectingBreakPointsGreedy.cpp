//notes gia mena : greedy kai einai kaluteros epeidh einai kaliteros apo pleuras optimazation xwrou
//icsd14027 Alexandros Galanis
//O(n)
#include <iostream>

using namespace std;

int breakpoint(int apostasi, int cap, int st[]){
    int dp = cap,distcoverd = 0, i = 0;
    int sta[5] = {0, 0, 0, 0, 0};
    int plithos = 0;

    if(st[0] > cap){
        return -1;
    }
    dp = dp - st[0];

    while((distcoverd < apostasi) && (i < 4)){
        distcoverd = st[i];

        if((st[i + 1] - st[i]) > cap){
            return -1;
        }

        if((st[i + 1] - st[i]) > dp){
            dp = cap;
            plithos++;
            sta[i] = 1;
        }

        dp = dp - (st[i + 1] - st[i]);
        i++;
    }

    distcoverd = st[i];
    if((apostasi - st[i] > dp)){
        if((apostasi - distcoverd) > cap){
            return -1;
        }
        plithos++;
        sta[i] = 1;
    }
    for(i = 0; i < 5; i++){
        cout<<sta[i]<<endl;
    }
    return plithos;


}

int main(){
    int apostasi = 600;
    int capacity = 200;
    int stations[5] = {150, 270, 350, 500, 570};

    cout<<"\n\nPauses: "<<breakpoint(apostasi, capacity, stations);
}

