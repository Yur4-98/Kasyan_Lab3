#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class People
{
private:
	string FName, MName, LName;
	time_t Date;
	int Id;
public:
	People(string FName, string MName, string LName, time_t Date, int Id);
	People();
	People(int Id);
	~People();
	int GetId();
	time_t GetDate();
	string GetFName();
	string GetMName();
	string GetLName();


	friend istream& operator>> (istream& in, People& x);


	People operator+ (People y);
	People operator- (People y);
	People operator* (People y);
	People operator/ (People y);
	People& operator= (People y);
	bool operator== (People y);
	bool operator!= (People y);
	bool operator> (const People& y) const;
	bool operator< (const People& y) const;
};

People People::operator+ (People y) {
	return  People::People(this->Id + y.Id);
}
People People::operator- (People y) {
	return  People::People(this->Id - y.Id);
}
People People::operator* (People y) {
	return  People::People(this->Id * y.Id);
}
People People::operator/ (People y) {
	return People::People((this->Id) / (y.Id));
}

People& People::operator= (People y) {
	People::FName = y.FName;
	People::MName = y.MName;
	People::LName = y.LName;
	People::Date = y.Date;
	People::Id = y.Id;
	return *this;
}

bool People::operator== (People y) {
	if (this->Id == y.Id)
		return true;
	else
		return false;
}

bool People::operator!= (People y) {
	if (this->Id == y.Id)
		return false;
	else
		return true;
}

bool People::operator> (const People& y) const {
	if (this->Id > y.Id)
		return true;
	else
		return false;
}

bool People::operator< (const People& y) const {
	if (this->Id < y.Id)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, People& x) {
	os << x.GetId();
	return os;
}

istream& operator>>(istream& in, People& x)
{
	in >> x.Id;
	return in;
}

People::People()
{
	this->FName = "";
	this->MName = "";
	this->LName = "";
	this->Date = 0;
	this->Id = 0;
}

People::People(string FName, string MName, string LName, time_t Date, int id) 
{
	this->FName = FName;
	this->MName = MName;
	this->LName = LName;
	this->Date = Date;
	this->Id = id;
}

People::People(int id) {
	this->FName = "";
	this->MName = "";
	this->LName = "";
	this->Date = 0;
	this->Id = id;
}

People::~People()
{
}

int People::GetId()
{
	return this->Id;
}

time_t People::GetDate()
{
	return this->Date;
}

string People::GetFName()
{
	return this->FName;
}

string People::GetMName()
{
	return this->MName;
}

string People::GetLName()
{
	return this->LName;
}