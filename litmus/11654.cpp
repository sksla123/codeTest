#include <iostream>
using namespace std;

class Account {
private:
	int id, money;
public:
	Account() {
		id = 0;
		money = 0;
	}
	void SetAccount(int name, int cash) {
		id = name;
		money = cash;
	}
	void ShowBalance() {
		cout << "ID: " << id << " " << "Money: " << money << endl;
	}
	void Deposit(int cash) {
		money += cash;
	}
	void Withdraw(int cash) {
		money -= cash;
		if (money < 0) {
			cout << "Error";
			exit(0);
		}
	}
	int GetId() {
		return id;
	}
	void Transfer(Account& name2, int cash) {
		if (money < cash) {
			cout << "Error";
			exit(0);
		}
		if (id == name2.id) {
			cout << "Error";
			exit(0);
		}
		money -= cash;
		name2.Deposit(cash);
	}
};

int main() {
	int menu, name1, name2, cash;

	Account acc1, acc2;

	cin >> name1 >> cash;
	acc1.SetAccount(name1, cash);
	cin >> name2 >> cash;
	acc2.SetAccount(name2, cash);

	while (1) {

		cin >> menu;

		switch (menu) {
		case 0:
			return 0;
		case 1:
			cin >> name1;
			if (name1 == 1) {
				acc1.ShowBalance();
			}
			else acc2.ShowBalance();
			break;
		case 2:
			cin >> name1 >> cash;
			if (name1 == 1) {
				acc1.Deposit(cash);
			}
			else acc2.Deposit(cash);
			break;
		case 3:
			cin >> name1 >> cash;
			if (name1 == 1) {
				acc1.Withdraw(cash);
			}
			else acc2.Withdraw(cash);
			break;
		case 4:
			cin >> name1 >> name2 >> cash;
			if (name1 == acc1.GetId() && name2 == acc2.GetId()) {
				acc1.Transfer(acc2, cash);
			}
			else if (name1 == acc2.GetId() && name2 == acc1.GetId()) {
				acc2.Transfer(acc1, cash);
			}
			else {
				cout << "Error";
				exit(0);
			}
			break;
		}
	}
	return 0;
}
