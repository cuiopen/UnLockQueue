#ifndef __UNLOCK_QUEUE_H__
#define __UNLOCK_QUEUE_H__

template<class QElmType>
struct unlock_queue_node
{
	struct unlock_queue_node *next;
	QElmType data;
};
template<class QElmType>
class unlock_queue
{
public:
	unlock_queue() {}
	~unlock_queue() {}
	
	bool init()
	{
		m_front = m_rear = new unlock_queue_node<QElmType>;
		if (!m_front)
			return false;
		m_front->next = 0;
		return true;
	}
	void destroy()
	{
		while (m_front)
		{
			m_rear = m_front->next;
			delete m_front;
			m_front = m_rear;
		}
	}
	bool push(QElmType e)
	{
		struct unlock_queue_node<QElmType> *p = new unlock_queue_node<QElmType>;
		if (!p)
			return false;
		p->next = 0;
		m_rear->next = p;
		m_rear->data = e;
		m_rear = p;
		return true;
	}
	bool pop(QElmType *e)
	{
		if (m_front == m_rear)
			return false;
	
		struct unlock_queue_node<QElmType> *p = m_front;		
		*e = p->data;
		m_front = p->next;
		delete p;
		return true;
	}
private:
	struct unlock_queue_node<QElmType> * volatile m_front, * volatile m_rear;
};

#endif //__UNLOCK_QUEUE_H__