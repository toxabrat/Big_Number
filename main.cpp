#include <iostream>
#include <time.h>
#include "BigNumber.h"

int main() {
    //std::string PI = "3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196";
    std::cout<<"!!!\n"<<((BigNumber("11230000423242340009590834920903290438992000234.20000002342342304023424938249324") / BigNumber("-2340324920349032234903249029.234092340929423032324")) * BigNumber("-2340324920349032234903249029.234092340929423032324")) .to_string();
    return 0;
    std::cout<<"Введите точность числа Pi от 1 до 200:";
    int accuracy;
    std::cin>>accuracy;
    BigNumber pi ("0");
    BigNumber stpk("1");
    clock_t t1 = clock();
    for(int i = 0; i < 163; i ++) {
        std::string s = "";
        if(i < 10) {
            s.push_back(i + '0');
        } else if(i < 100) {
            s.push_back(i/10%10 + '0');
            s.push_back(i%10 + '0');
        } else {
            s.push_back(i/100 + '0');
            s.push_back(i/10%10 + '0');
            s.push_back(i%10 + '0');
        }
        BigNumber v = s * BigNumber("8");
        pi += stpk * (BigNumber("4") / (v + BigNumber("1")) - BigNumber("2") / (v + BigNumber("4"))
                                     - BigNumber("1") / (v + BigNumber("5")) - BigNumber("1") / (v + BigNumber("6")));
        stpk *= BigNumber("0.0625");
    }
    clock_t t2 = clock();
    double dur = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;
    std::string ans = pi.to_string();
    for(int i = 0; i < accuracy + 2; i++) {
        std::cout<<ans[i];
    }
    printf("\nCPU time used (per clock()): %.2f ms\n", dur);
    return 0; 
}