#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
	struct Element
	{
		T data;
		Element* next;
		Element* prev;
		Element(T value)
		{
			data = value;
			next = nullptr;
			prev = nullptr;
		}
	};

	int m_size;
	Element* phead;
	Element* ptail;
public:
	List()
	{
		phead = nullptr;
		ptail = nullptr;
		m_size = 0;
	}

	void Push_Back(T value)
	{
		Element* new_element = new Element(value);
		if (phead)
		{

			ptail->next = new_element;
			new_element->prev = ptail;
			ptail = new_element;
		}
		else
		{
			phead = new_element;
			ptail = new_element;
		}
		m_size++;
	}

	void Push_Front(T value)
	{
		Element* new_element = new Element(value);
		new_element->next = phead;
		phead = new_element;
		new_element->prev = nullptr;
		m_size++;
	}

	void Delete_From_Head()
	{
		Element* temp = phead;
		phead = phead->next;
		phead->prev = nullptr;
		delete temp;
		m_size--;
	}

	void Delet_From_Tail()
	{
		Element* temp = ptail;
		ptail = ptail->prev;
		ptail->next = nullptr;
		delete temp;
		m_size--;
	}

	void Show()
	{
		Element* temp = phead;
		for (int i = 0; i < m_size; i++)
		{
			cout << temp->data << ' ';
			temp = temp->next;
		}
		cout << endl;
	}

	void Delete_All()
	{
		Element* temp;
		while (phead)
		{
			temp = phead;
			phead = phead->next;
			delete temp;
		}
		m_size = 0;
	}
	~List()
	{
		Element* temp;
		while (phead)
		{
			temp = phead;
			phead = phead->next;
			delete temp;
		}
		m_size = 0;
	}
};

int main()
{
	List<int> obj_1;
	obj_1.Push_Back(10);
	obj_1.Push_Back(20);
	obj_1.Push_Back(30);
	obj_1.Push_Front(0);
	obj_1.Delete_From_Head();
	obj_1.Delet_From_Tail();
	obj_1.Show();
	obj_1.Delete_All();

	return 0;
}