#pragma once

#include <iostream>

namespace Lists {
    template<class TL>
    class List {
    private:

        template<class TE>
        class Element {
        private:
            Element<TE>* pNext;
            Element<TE>* pPrev;
            TE* pInfo;

        public:
            Element() {
                pNext = NULL;
                pPrev = NULL;
                pInfo = NULL;
            }

            ~Element() {
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
        Element<TL>* pCurrent;
        Element<TL>* pLast;
        int size;

    public:
        List();

        ~List();

        void destroy();

        int getSize() { return size; }

        void insert(TL* pInfo);

        void remove(TL* pTL);

        void addElement(Element<TL>* pEl);

        Element<TL>* getpFirst() { return pFirst; }

        Element<TL>* getpLast() { return pLast; }

        Element<TL>* getpCurrent() { return pCurrent; }

        TL* backStart();

        TL* goNext();

        TL* operator[](int x);

    };

    template<class TL>
    List<TL>::List() :
        pFirst(),
        pLast(),
        size(0) {
    }

    template<class TL>
    List<TL>::~List() {
        destroy();
    }

    template<class TL>
    void List<TL>::destroy() {

        Element<TL>* paux1;
        Element<TL>* paux2;

        paux1 = pFirst;
        paux2 = paux1;

        while (paux1 != NULL) {

            if (paux1->getInfo())
                delete (paux1->getInfo());

            paux2 = paux1->getNext();
            delete (paux1);
            paux1 = paux2;
            size--;

        }

        pFirst = NULL;
        pLast = NULL;
        pCurrent = NULL;
    }

    template<class TL>
    void List<TL>::insert(TL* pInfo) {
        if (pInfo) {
            Element<TL>* pEl = NULL;
            pEl = new Element<TL>();
            pEl->setInfo(pInfo);
            addElement(pEl);
        }
        else {
            std::cout << "Erro! pInfo nulo em List<TL>::insert." << std::endl;
        }
    }

    template<class TL>
    void List<TL>::remove(TL* pTL) {
        Element<TL>* pAux = pFirst;
        Element<TL>* pPrev = NULL;

        while (pAux && pAux->getInfo() != pTL) {
            pPrev = pAux;
            pAux = pAux->getNext();
        }
        if (pAux == pFirst)
            pFirst = pAux->getNext();
        else if (pAux == pLast) {
            pPrev->setNext(nullptr);
            pLast = pPrev;
        }
        else if (pAux) {
            pPrev->setNext(pAux->getNext());
        }
        if (pAux)
            size--;
        if (pAux->getInfo())
            delete pAux->getInfo();
        delete pAux;
    }

    //        while (pAux != NULL) {
    //            if (pAux->getInfo() == pTL) {
    //                if (pAux == pFirst)
    //                    pFirst = pAux->getNext();
    //                else if (pAux == pLast)
    //                    pLast = pPrev;
    //                else
    //                    pPrev->setNext(pAux->getNext());
    //
    //                //delete (pTL);
    //                delete (pAux->getInfo());
    //                delete (pAux);
    //                size--;
    //                return true;
    //            }
    //            pPrev = pAux;
    //            pAux = pAux->getNext();
    //        }
    //        return false;
    //    }


    template<class TL>
    void List<TL>::addElement(Element<TL>* pEl) {
        if (pEl) {
            if (!pFirst) {
                pFirst = pEl;
                pLast = pEl;
            }
            else {
                pLast->setNext(pEl);
                pEl->setPrev(pLast);
                pLast = pEl;
            }
            size++;
        }
        else {
            std::cout << "Erro! pEl nulo em List<TL>::addElement." << std::endl;
        }
    }

    template<class TL>
    TL* List<TL>::operator[](int x) {
        if (x < 0 || x >= getSize()) {
            std::cerr << "Erro. Segmentation fault em List<TL>::operator[]." << std::endl;
            exit(555);
        }
        else {
            Element<TL>* pAux = NULL;
            pAux = pFirst;
            for (int i = 0; i < x; i++) {
                pAux = pAux->getNext();
            }

            if (!pAux) {
                std::cerr << "Erro. Ponteiro pAux nulo em List<TL>::operator[]." << std::endl;
                exit(1235);
            }

            return pAux->getInfo();
        }
    }

    template<class TL>
    TL* List<TL>::backStart() {
        pCurrent = pFirst;
        if (pCurrent) return pCurrent->getInfo();
        else return nullptr;
    }

    template<class TL>
    TL* List<TL>::goNext() {
        pCurrent = pCurrent->getNext();
        return (pCurrent) ? pCurrent->getInfo() : nullptr;
    }

}