#pragma once
#include<iostream>
#include<string>
class Description
{
private:
	std::string content;
	void Print(std::ostream& out) const;
protected:
	friend std::ostream& operator<<(std::ostream& os, const Description& desc);
public:
	Description();
};

