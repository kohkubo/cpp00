#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	if (initial_deposit > 0)
		_amount = initial_deposit;
	else
		_amount = 0;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	// [19920104_091532] index:0;amount:42;created
	_displayTimestamp();
	std::cout << "index:"
			  << _accountIndex
			  << ";amount:"
			  << _amount
			  << ";created"
			  << std::endl;
}

// 19920104_091532] index:0;amount:47;closed
Account::~Account() {
	_displayTimestamp();
	std::cout << "index:"
			  << _accountIndex
			  << ";amount:"
			  << _amount
			  << ";closed"
			  << std::endl;
}

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:"
			  << _nbAccounts
			  << ";total:"
			  << _totalAmount
			  << ";deposits:"
			  << _totalNbDeposits
			  << ";withdrawals:"
			  << _totalNbWithdrawals
			  << std::endl;
}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;

	_displayTimestamp();
	std::cout << "index:"
			  << _accountIndex
			  << ";p_amount:"
			  << p_amount
			  << ";deposit:"
			  << deposit
			  << ";amount:"
			  << _amount
			  << ";nb_deposits:"
			  << _nbDeposits
			  << std::endl;
}

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << "index:"
				  << _accountIndex
				  << ";p_amount:"
				  << _amount
				  << ";withdrawal:refused"
				  << std::endl;
		return false;
	}
	int p_amount = _amount;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;

	// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	_displayTimestamp();
	std::cout << "index:"
			  << _accountIndex
			  << ";p_amount:"
			  << p_amount
			  << ";withdrawal:"
			  << withdrawal
			  << ";amount:"
			  << _amount
			  << ";nb_withdrawals:"
			  << _nbWithdrawals
			  << std::endl;
	return true;
}

int Account::checkAmount() const
{
	return _totalAmount;
}

// [19920104_091532] index:7;amount:16576;deposits:0;withdrawals:0
void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

// [19920104_091532]
void Account::_displayTimestamp()
{
	time_t now = time(0);
	const tm *local = localtime(&now);
	std::cout << "["
			  << 1900 + local->tm_year
			  << std::setw(2) << std::setfill('0')
			  << 1 + local->tm_mon
			  << std::setw(2) << std::setfill('0')
			  << local->tm_mday
			  << "_"
			  << std::setw(2) << std::setfill('0')
			  << local->tm_hour
			  << std::setw(2) << std::setfill('0')
			  << local->tm_min
			  << std::setw(2) << std::setfill('0')
			  << local->tm_sec
			  << "] ";
}
