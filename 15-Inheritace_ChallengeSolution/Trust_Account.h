#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H
#include "Savings_Account.h"


class Trust_Account: public Savings_Account
{
  friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
private:
  static constexpr const char *def_name = "Unnamed Trust Account";
  static constexpr double def_balance = 0.0;
  static constexpr double def_int_rate = 0.0;
  static constexpr double def_bonus_level = 5000.0;
  static constexpr double def_bonus_amount = 50.0;
  static constexpr int def_max_withdraws_amount = 3;
  static constexpr double def_max_withdraw_rate = 0.2;
protected:
  int num_withdraws = 0;

public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);
    bool withdraw(double amount);
    int getNumWithdraws();
};

#endif // TRUST_ACCOUNT_H
