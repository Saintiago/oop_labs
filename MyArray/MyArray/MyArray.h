#pragma once
#include "ArrayItem.h"

using namespace std;

template<typename T>
class CMyArray
{
	typedef shared_ptr<ArrayItem<T>> ItemPtr;

public:
	CMyArray(size_t initialSize = 1) 
	{
		m_head = make_unique<T[]>(initialSize);
		RecalcTail(initialSize);
	}
	~CMyArray()	{}

	void AppendItem(T data = T())
	{
		size_t oldSize = Size();
		size_t newSize = oldSize + 1;
		Resize(newSize);
		m_head[oldSize] = data;
	}

	size_t Size() const
	{
		return m_tail - m_head.get();
	}

	void Resize(size_t newSize)
	{
		size_t oldSize = Size();
		if (newSize > oldSize)
		{
			auto resizedArray = make_unique<T[]>(newSize);
			for (size_t i = 0; i < oldSize; i++)
			{
				resizedArray[i] = m_head[i];
			}
			m_head.swap(resizedArray);
		}
		else if (newSize < oldSize)
		{
			Shrink(newSize);
		}
		RecalcTail(newSize);
	}

	void Clear()
	{
		Shrink(0);
	}

	const T & operator[](size_t index)const
	{
		if (index >= Size())
		{
			ThrowOutOfRange(index);
		}
		return m_head[index];
	}

	T & operator[](size_t index)
	{
		if (index >= Size())
		{
			ThrowOutOfRange(index);
		}
		return m_head[index];
	}

	CMyArray & operator = (CMyArray const& other)
	{
		size_t size = other.Size();
		auto copy = make_unique<T[]>(size);
		for (size_t i = 0; i < size; i++)
		{
			copy[i] = other[i];
		}
		m_head.swap(copy);
		RecalcTail(size);
		return *this;
	}

private:
	unique_ptr<T[]> m_head;
	T *m_tail;

	void Shrink(size_t newSize)
	{
		if (newSize > 0) newSize--;
		for (int i = newSize; i >= 0; i--)
		{
			m_head[i].~T();
		}
		RecalcTail(newSize);
	}

	void RecalcTail(size_t newSize)
	{
		m_tail = &m_head[newSize];
	}

	void ThrowOutOfRange(size_t pos) const
	{
		stringstream ss;
		ss << "There is no " << pos << "th element in this array!";
		throw out_of_range(ss.str());
	}
};

