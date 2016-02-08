#pragma once

template<typename T>
class ArrayItem
{
	typedef std::shared_ptr<ArrayItem<T>> ItemPtr;

public:

	ArrayItem(T data = T(), ItemPtr next = nullptr)
	{
		m_item = data;
		m_next = next;
	}

	T & GetData()
	{
		return m_item;
	}

	ItemPtr & GetNext()
	{
		return m_next;
	}

	void SetNext(ItemPtr & newNext)
	{
		m_next = newNext;
	}

private:
	T m_item;
	ItemPtr m_next;
};

