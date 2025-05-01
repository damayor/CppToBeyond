#include "Trust_Account.h"


Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate} {
}


// Deposit
//  Any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account.

bool Trust_Account::deposit(double amount) {
  amount = ( amount > 5000 ) ? amount + 50.0 : amount ;
  return Savings_Account::deposit(amount);
}

// Withdraw:
//   withdrawal should only allow 3 withdrawals per year
//   and each of these must be less than 20% of the account balance

bool Trust_Account::withdraw(double amount) {
  std::cout << "Amount to widthdraw of " << amount << std::endl;

  if(amount > 0.2 * get_balance() )
  {
    std::cout << "Withdraw exception: Amount is greater than 20%" << std::endl;
    return false;
  }
  else if(num_withdraws >= def_max_withdraws_amount) {
    std::cout << "Withdraw exception: Withdraws of the last year is " <<  num_withdraws << ". Year limt is " << def_max_withdraws_amount <<  std::endl;
    return false;
  }
  else
  {
    num_withdraws++;
    return Savings_Account::deposit(amount);
  }

}

int Trust_Account::getNumWithdraws() {
    return num_withdraws;
}
