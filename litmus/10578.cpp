#include <iostream>
#include <string>
using namespace std;

class Account {
protected: // JBAccount클래스에서 변수 사용 - protected
    string acc_num;
    int balance;
public:
    Account(string id, int bal = 0) : acc_num(id), balance(bal) {} // 이니셜라이저

    void depm(int m) { // 입금
        balance += m;
        cout << "deposit complete" << endl;
    }
    void withm(int m) { // 출금
        if (balance > m) { // (출금금액 > 잔액)이면 오류
            balance -= m;
            cout << "withdraw complete" << endl;
        }
        else {
            cout << "not enough money" << endl;
        }
    }
};

class JBAccount : public Account { // Account클래스 상속
private:
    int trans_limit;
    int trans_balance;
public:
    JBAccount(string id, int tlimit) : Account(id), trans_limit(tlimit), trans_balance(0) {} // 이니셜라이저

    int getf(int bank) { // bank값에 따른 수수료
        switch (bank) {
        case 1: return 500;  // KB
        case 2: return 1000; // GB
        case 3: return 1500; // NH
        default: return 0;
        }
    }

    void transm(int bank, int& transsum) { // 이체금액 누적 - 참조자 활용
        int fee = getf(bank);
        int amount = 0; // 이체금액
        cin >> amount;

        if ((amount + fee) > balance) { // (이체금액 + 수수료)가 잔액보다 적으면 오류
            cout << "not enough money" << endl;
        }
        else if ((amount + transsum) > trans_limit) { // (이체금액 + 누적 이체금액)이 이체한도보다 크면 오류
            cout << "trans_limit exceed" << endl;
        }
        else {
            transsum += amount; // 이체금액 누적
            trans_balance = amount; // trans_balance에 마지막 이체값 저장
            balance -= (amount + fee); // 잔고에서 (이체금액 + 수수료) 차감
            cout << "transfer complete" << endl;
        }
    }
    void info(JBAccount account) { // 현재값 출력
        cout << "acc_num : " << account.acc_num << endl;
        cout << "balance : " << account.balance << endl;
        cout << "trans_limit : " << account.trans_limit << endl;
        cout << "trans_balance : " << account.trans_balance << endl;
    }
};

int main() {
    int menu;
    string id;
    int limit;

    cin >> id >> limit;

    JBAccount account(id, limit);
    int transsum = 0;

    while (true) {
        cin >> menu;

        switch (menu)
        {
        case 1:
            int m;
            cin >> m;
            account.depm(m);
            break;
        case 2:
            cin >> m;
            account.withm(m);
            break;
        case 3:
            int bank;
            cin >> bank;
            account.transm(bank, transsum);
            break;
        case 4:
            account.info(account);
            break;
        case 5:
            cout << "프로그램을 종료합니다." << endl;
            exit(0);
        default:
            break;
        }
    }
    return 0;
}