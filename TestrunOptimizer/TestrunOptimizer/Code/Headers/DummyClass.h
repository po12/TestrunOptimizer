#pragma once

class Dummy {
	int val = 0;
public:
	Dummy();
	~Dummy();
	
	void change(int value) noexcept { val += value; }
	int get() const noexcept { return val; }
};
