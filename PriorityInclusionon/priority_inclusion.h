#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <algorithm>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

class ProiritInlusiononyQueue
{
	string* data;
	int* priorities;
	int max_count;
	int real_count;
public:
	ProiritInlusiononyQueue(unsigned int max_count)
	{
		this->max_count = max_count;
		data = new string[max_count];
		priorities = new int[max_count];
		real_count = 0;
	}

	~ProiritInlusiononyQueue()
	{
		if (data != nullptr) delete[] data;
		if (priorities != nullptr) delete[] priorities;
	}

	void Clear()
	{
		real_count = 0;
	}

	bool IsEmpty() const
	{
		return real_count == 0;
	}

	bool IsFull() const
	{
		return real_count == max_count;
	}

	int GetCount() const
	{
		return real_count;
	}

	void Enqueue(string value, int priority)
	{
		if (!IsFull())
		{
			data[real_count] = value;
			priorities[real_count] = priority;
			real_count++;
		}
		else
		{
			throw "Queue is full!";
		}
		for (int pr = 0; pr < real_count; pr++)
		{
			for (int k = real_count - 1; k > 0; k--)
			{
				if (priorities[k - 1] > priorities[k])
				{
					int temp = priorities[k];
					string result = data[k];
					data[k] = data[k - 1];
					priorities[k] = priorities[k - 1];
					data[k - 1] = result;
					priorities[k - 1] = temp;
				}
			}
		}
		
	}
	void Dequeue()
	{
		if (!IsEmpty())
		{
			real_count--;
		}
		else
		{
			throw "Queue is empty!";
		}
	}

	void Print() const
	{
		cout << "-----------------------------------------------------\n";
		for (int i = 0; i < real_count; i++)
			cout << priorities[i] << "(Priority) " << data[i] << "\n";
		cout << "-----------------------------------------------------\n";
	}


};