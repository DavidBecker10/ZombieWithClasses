#pragma once
#include "Entity.h"
#include <iostream>

namespace Lists
{
	template<class TL>
	class List
	{
	private:

		template<class TE>
		class Element
		{
		private:
			Element<TE>* pNext;
			Element<TE>* pPrev;
			TE* pInfo;

		public:
			Element()
			{
				pNext = NULL;
				pPrev = NULL;
				pInfo = NULL;
			}

			~Element()
			{
				pNext = NULL;
				pPrev = NULL;
				pInfo = NULL;
			}

			void setNext(Element<TE>* pN) { pNext = pN; }
			Element<TE>* getNext() { return pNext; }

			void setPrev(Element<TE>* pP) { pPrev = pP; }
			Element<TE>* getPrev() { return pPrev; }

			void setInfo(TE* pI) { pInfo = pI; }
			TE* getInfo() { return pInfo; }

		};

		Element<TL>* pFirst;
		Element<TL>* pLast;
		int size;

	public:
		List();
		~List();

		void destroy();
		int getSize() { return size; }
		void insert(TL* pInfo);
		//bool remove(TL* pR);
		void addElement(Element<TL>* pEl);
		Element<TL>* getpFirst() { return pFirst; }
		Element<TL>* getpLast() { return pLast; }

	};

	template<class TL>
	List<TL>::List():
	pFirst(),
	pLast(),
	size(0)
	{
		destroy();
	}

	template<class TL>
	List<TL>:: ~List()
	{
		destroy();
	}

	template<class TL>
	void List<TL>::destroy()
	{
		Element<TL>* aux = NULL;
		aux = pFirst;

		while (pFirst)
		{
			pFirst = pFirst->getNext();
			delete aux;
			aux = pFirst;
			size--;
		}

		pFirst = NULL;
	}

	template<class TL>
	void List<TL>::insert(TL* pInfo)
	{
		if (pInfo)
		{
			Element<TL>* pEl = NULL;
			pEl = new Element<TL>();
			pEl->setInfo(pInfo);
			addElement(pEl);
		}
		else
		{
			std::cout << "Erro! pInfo nulo em List<TL>::insert." << std::endl;
		}
	}

	/*
	template<class TL>
	bool List<TL>::remove(TL* pR)
	{

	}
	*/

	template<class TL>
	void List<TL>::addElement(Element<TL>* pEl)
	{
		if (pEl)
		{
			if (!pFirst)
			{
				pFirst = pEl;
				pLast = pEl;
			}
			else
			{
				pLast->setNext(pEl);
				pEl->setPrev(pLast);
				pLast = pEl;
			}
			size++;
		}
		else
		{
			std::cout << "Erro! pEl nulo em List<TL>::addElement." << std::endl;
		}
	}
}