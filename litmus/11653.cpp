// 202327942 이대현
#include <iostream>

class Account{
    private:
        int id;
        int money;
        
    public:
        Account(int id, int money): id(id), money(money) {}
        
        void showBalance(){
            std::cout << "ID: " << id << " Money: " << money << std::endl;
        }

        void deposit(){
            int Plus;
            std::cin >> Plus;

            money += Plus;
        }

        void withdraw(){
            int minus;
            std::cin >> minus;

            if(minus > money){
                std::cout <<"Error" <<std::endl;
                exit(0); 
            }

            money -= minus;
        }
};

int main() {
    int id, money;

    std::cin >> id;
    std::cin >> money;

    Account account(id, money);
    
    int n;

    do{
        std::cin >> n;
        
        if(n == 1){
            account.showBalance();
        }
        else if(n == 2){
            account.deposit();
        }
        else if(n == 3){
            account.withdraw();
        }
    }
    while(n!=0);

    return 0;
}