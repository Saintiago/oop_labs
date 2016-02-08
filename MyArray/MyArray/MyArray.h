#pragma once
#include "ArrayItem.h"

template<typename T>
class CMyArray
{
	typedef std::shared_ptr<ArrayItem<T>> ItemPtr;

public:
	CMyArray() {}
	~CMyArray()	{}

	void AppendItem(T data = T())
	{
		ItemPtr newItemPtr = std::make_shared<ArrayItem<T>>(ArrayItem<T> (data));
		if (m_head == nullptr)
		{
			m_head = newItemPtr;
		}
		else
		{
			GetTail()->SetNext(newItemPtr);
		}
	}

	size_t Size()
	{
		unsigned count = 0;
		if (m_head != nullptr)
		{
			ItemPtr current = m_head;
			do
			{
				count++;
				current = current->GetNext();
			} 
			while (current != nullptr);
		}
		return count;
	}

	void Resize(size_t newSize)
	{
		size_t currentSize = Size();
		if (newSize > currentSize)
		{
			for (size_t i = currentSize; i < newSize; i++)
			{
				AppendItem();
			}
		}
		else if (newSize < currentSize)
		{
			Shrink(newSize);
		}
	}

	void Clear()
	{
		Dispose(m_head);
	}

	const T & operator[](size_t index)const
	{
		return GetNthItem(index)->GetData();
	}

	T & operator[](size_t index)
	{
		return GetNthItem(index)->GetData();
	}

private:
	ItemPtr m_head = nullptr;

	ItemPtr GetNthItem(size_t n)
	{
		ItemPtr current = m_head;

		if (current == nullptr)
		{
			ThrowOutOfRange(n);
		}

		for (size_t i = n; i > 0; i--)
		{
			if (current->GetNext() == nullptr)
			{
				ThrowOutOfRange(n);
			}
			current = current->GetNext();
		}
		return current;
	}

	ItemPtr GetTail()
	{
		size_t lastIndex = Size();
		if (lastIndex > 0) lastIndex--;
		return GetNthItem(lastIndex);
	}

	void Shrink(size_t newSize)
	{
		if (newSize > 0) newSize--;
		Dispose(GetNthItem(newSize));
	}

	void Dispose(ItemPtr & item)
	{
		if (item->GetNext() != nullptr)
		{
			Dispose(item->GetNext());
		}
		item.reset();
	}

	void ThrowOutOfRange(size_t pos)
	{
		std::stringstream ss;
		ss << "There is no " << pos << "th element in this array!";
		throw std::out_of_range(ss.str());
	}
};

