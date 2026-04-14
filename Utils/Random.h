#pragma once

class Random
{
public:
	//static int will permit us to call the Range function without creating an instance of the Random class.
	static int Range(int min, int max);
};