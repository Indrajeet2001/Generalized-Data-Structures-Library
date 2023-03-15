#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////
//
//  Structre for SinglyLL
//
///////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

///////////////////////////////////////////////////////////////////////////
//
//  Structre for DoublyLL
//
///////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

///////////////////////////////////////////////////////////////////////////
//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*

template <class T>
class SinglyLL
{
    public:
        struct nodeS<T> * First;

        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
        int SearchFirstOcc(T no);
        int SearchLastOcc(T no);
        int Addition();
        int FindMaximum();
        int FindMinimum();
        bool Checkperfect(T no);
        void DisplayPerfect();
        bool CheckPrime(T no);
        void DisplayPrime();
        int EvenSum();
        int OddSum();
        void DigitSum();
        void DisplayRev();
        bool Palindrome();
        void DisplayProduct();
        void DisplaySmall();
        void DisplayLarge();
};

///////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public:
        struct nodeS<T> * First;
        struct nodeS<T> * Last;

        SinglyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
        int SearchFirstOcc(T no);
        int SearchLastOcc(T no);
        int Addition();
        int FindMaximum();
        int FindMinimum();
        bool Checkperfect(T no);
        bool CheckPrime(T no);
        int EvenSum();
        int OddSum();
        void DigitSum();
        void DisplayRev();
        bool Palindrome();
        void DisplayProduct();
        void DisplaySmall();
        void DisplayLarge();
};

///////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public:
        struct nodeD<T> * First;
        struct nodeD<T> * Last;

        DoublyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
        int SearchFirstOcc(T no);
        int SearchLastOcc(T no);
        int Addition();
        int FindMaximum();
        int FindMinimum();
        bool Checkperfect(T no);
        bool CheckPrime(T no);
        int EvenSum();
        int OddSum();
        void DigitSum();
        void DisplayRev();
        bool Palindrome();
        void DisplayProduct();
        void DisplaySmall();
        void DisplayLarge();
};

///////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    public:
        struct nodeD<T> * First;

        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
        int SearchFirstOcc(T no);
        int SearchLastOcc(T no);
        int Addition();
        int FindMaximum();
        int FindMinimum();
        bool Checkperfect(T no);
        void DisplayPerfect();
        bool CheckPrime(T no);
        void DisplayPrime();
        int EvenSum();
        int OddSum();
        void DigitSum();
        void DisplayRev();
        bool Palindrome();
        void DisplayProduct();
        void DisplaySmall();
        void DisplayLarge();
};

//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*
//
//  Function Definitions for Singly Linear LL
//
//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*

template <class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct nodeS<T> * newn = new nodeS<T>;  

    newn -> data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct nodeS<T> * newn = new nodeS<T>;  

    newn -> data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeS<T> * temp = First;
        
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: InsertAtPos(T no, int ipos)
{
    int iCnt = Count();

    if((ipos < 1) || (ipos > iCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCnt + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS<T> * newn = new nodeS<T>;

        newn->data = no;
        newn->next = NULL;

        struct nodeS<T> * temp = First;
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct nodeS<T> * temp = First;

    if(First == NULL)
    {
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    struct nodeS<T> * temp = First;
  
    if(First == NULL)  
    {
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DeleteAtPos(int ipos)
{
    int iCnt = Count();

    if((ipos < 1) || (ipos > iCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCnt)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> * temp1 = First;
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        struct nodeS<T> * temp2 = temp1->next;
        temp1 -> next = temp2->next;
        delete temp2;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: Display()
{
    struct nodeS<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T> :: Count()
{
    struct nodeS<T> *  temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    return iCnt;
}

///////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLL<T> :: SearchFirstOcc(T no)
{
    struct nodeS<T> *  temp = First;
    int iCnt = 0;
    iCnt = 1;

    while(temp != NULL)
    {
        if((temp->data) == no)
        {
            break;
        }
        else
        {
            temp = temp -> next;
        }
        iCnt++;
    }
    return iCnt;
}

///////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLL<T> :: SearchLastOcc(T no)
{
    struct nodeS<T> *  temp = First;
    int iCnt = 0, iPos = 0;
    iCnt = 1;

    while(temp != NULL)
    {
        if((temp -> data) == no)
        {
            iPos = iCnt;
        }
        temp = temp -> next;
        iCnt++;
    }
    return iPos;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T> :: Addition()
{
    struct nodeS<T> *  temp = First;
    int iAdd = 0;

    while(temp != NULL)
    {
        iAdd = iAdd + (temp->data);
        temp = temp -> next;
    }
    return iAdd;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T> :: FindMaximum()
{
    struct nodeS<T> *  temp = First;
    int iMax = 0;

    while(temp != NULL)
    {
        if(iMax < (temp->data))
        {
            iMax = (temp -> data);
        }
        temp = temp -> next;
    }
    return iMax;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T> :: FindMinimum()
{
    struct nodeS<T> *  temp = First;
    int iMin = 0;
    iMin = temp -> data;

    while(temp != NULL)
    {
        if((temp->data) < iMin)
        {
            iMin = (temp->data);
        }   
        temp = temp -> next;
    }
    return iMin;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
bool SinglyLL<T> :: Checkperfect(T no)
{
    T iTemp = no, iSum = 0; 
    int iCnt = 0;

    for(iCnt = 1; iCnt <= (no/2); iCnt++)
    {
        if(no % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    if((iSum == iTemp))
    {
        return true;
    }
    else
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DisplayPerfect()
{
    struct nodeS<T> *  temp = First;
    while(temp != NULL)
    {   
        if(CheckPerfect(temp->data) == true)
        {
            printf("%d is a perfect number\n",temp->data);
        }
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
bool SinglyLL<T> :: CheckPrime(T no)
{
    int iCnt = 0, iSum = 0;

    for(iCnt = 1; iCnt <= no; iCnt++)
    {
        if(no % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    if((iSum == (no + 1)))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DisplayPrime()
{
    struct nodeS<T> *  temp = First;
    while(temp != NULL)
    {
        if(CheckPrime(temp->data) == true)
        {
            printf("%d is a prime number\n",temp->data);
        }
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T> :: EvenSum()
{
    struct nodeS<T> *  temp = First;
    int iEvenSum = 0;

    while(temp != NULL)
    {
        if((temp->data) % 2 == 0)
        {
            iEvenSum = iEvenSum + (temp->data);
        }
        temp = temp->next;
    }
    return iEvenSum;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T> :: OddSum()
{
    struct nodeS<T> *  temp = First;
    int iOddSum = 0;

    while(temp != NULL)
    {
        if((temp->data) % 2 != 0)
        {
            iOddSum = iOddSum + (temp->data);
        }
        temp = temp->next;
    }
    return iOddSum;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DigitSum()
{
    struct nodeS<T> *  temp = First;
    int iDigit = 0;
    int iNo = 0;
    int iDigitSum = 0;

    while (temp != NULL)
    {
        iNo = temp->data;
        iDigitSum = 0;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iDigitSum = iDigitSum + iDigit;
            iNo = iNo / 10;
        }   
        printf("Sum of digits of %d is : %d\n",temp->data,iDigitSum);
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DisplayRev()
{
    struct nodeS<T> *  temp = First;
    T iDigit = 0, iRev = 0;
    int iTemp = 0;
    while (temp != NULL)
    {
        iTemp = temp->data;
        iRev = 0;
        while(iTemp != 0)
        {
            iDigit = iTemp % 10;
            iRev = iRev * 10 + iDigit;
            iTemp = iTemp / 10;
        }
        printf("| %d |->",iRev);
        temp = temp->next;
    }
    printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////

template <class T>
bool SinglyLL<T> :: Palindrome()
{
    T iDigit = 0, iTemp = First->data;
    T iRev = 0;

    while(iTemp != 0)
    {
        iDigit = iTemp % 10;
        iRev = iRev * 10 + iDigit;
        iTemp = iTemp / 10;
    }
    if(iRev == First->data)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DisplayProduct()
{ 
    struct nodeS<T> *  temp = First;
    T iDigit = 0, iNo = 0;
    T iMult = 1;

    while (temp != NULL)
    {   
        iNo = temp->data;
        iMult = 1;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit != 0)
            {
                iMult = iMult * iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMult<<"\t";
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DisplaySmall()
{ 
    struct nodeS<T> *  temp = First;
    T iDigit = 0, iNo = 0;
    T iMin = 0;

    while (temp != NULL)
    {   
        iNo = temp->data;
        iMin = temp->data;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit < iMin)
            {
                iMin = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMin<<"\t";
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T> :: DisplayLarge()
{ 
    struct nodeS<T> *  temp = First;
    T iDigit = 0, iNo = 0;
    T iMax = 0;

    while (temp != NULL)
    {   
        iNo = temp->data;
        iMax = 0;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit > iMax)
            {
                iMax = iDigit;
            }
            iNo = iNo / 10;
        }
        printf("%d\t",iMax);
        temp = temp->next;
    }
}

//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*
//
//  Function Definitions for Singly Circular LL
//
//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*

template <class T>
SinglyCL<T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct nodeS<T> * newn = new nodeS<T>;  

    newn -> data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
        (Last) -> next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct nodeS<T> * newn = new nodeS<T>;  

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL)) 
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else   
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: InsertAtPos(T no, int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct nodeS<T> * newn = new nodeS<T>;
    struct nodeS<T> * temp = First;

    if((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    struct nodeS<T> * temp = First;

    if((First == NULL) && (Last == NULL)) 
    {
        return;
    }
    else if(First == Last)  
    {
        delete First;

        First = NULL;
        Last = NULL;
    }
    else  
    {
        First = (First)->next;
        delete temp;

        (Last) ->next = First;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    struct nodeS<T> * temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node in LL
    {
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 node
    {
        while(temp->next != (Last))
        {
            temp = temp -> next;
        }

        delete temp->next;

        Last = temp; 
        (Last) ->next = First;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: DeleteAtPos(int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct nodeS<T> * temp1 = First;
    struct nodeS<T> * temp2 = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: Display()
{
    struct nodeS<T> * temp = First;

    cout<<"Elements of Linked list are : "<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T> :: Count()
{
    struct nodeS<T> *  temp = First;

    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}

///////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCL<T> :: SearchFirstOcc(T no)
{
    struct nodeS<T> *  temp = First;
    int iCnt = 0;
    iCnt = 1;

    while(temp != Last)
    {
        if((temp->data) == no)
        {
            break;
        }
        else
        {
            temp = temp -> next;
        }
        iCnt++;
    }
    return iCnt;
}

///////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCL<T> :: SearchLastOcc(T no)
{
    struct nodeS<T> *  temp = First;
    int iCnt = 0, iPos = 0;
    iCnt = 1;

    while(temp != Last)
    {
        if((temp -> data) == no)
        {
            iPos = iCnt;
        }
        temp = temp -> next;
        iCnt++;
    }
    return iPos;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T> :: Addition()
{
    struct nodeS<T> *  temp = First;
    int iAdd = 0;

    while(temp != Last)
    {
        iAdd = iAdd + (temp->data);
        temp = temp -> next;
    }
    
    return iAdd + (temp->data);
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T> :: FindMaximum()
{
    struct nodeS<T> *  temp = First;
    int iMax = 0;

    while(temp != Last)
    {
        if(iMax < (temp->data))
        {
            iMax = (temp -> data);
        }
        temp = temp -> next;
    }
    if(iMax < (temp->data))
    {
        iMax = (temp->data);
        return iMax;
    }
    else
    {
        return iMax;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T> :: FindMinimum()
{
    struct nodeS<T> *  temp = First;
    
    int iMin = 0;
    iMin = First -> data;

    while(temp != Last)
    {
        if((temp->data) < iMin)
        {
            iMin = (temp->data);
        }   
        temp = temp -> next;
    }
    if(iMin > (temp->data))
    {
        iMin = (temp->data);
        return iMin;
    }
    else
    {
        return iMin;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
bool SinglyCL<T> :: Checkperfect(T no)
{
    T iTemp = no, iSum = 0; 
    int iCnt = 0;

    for(iCnt = 1; iCnt <= (no/2); iCnt++)
    {
        if(no % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    if((iSum == iTemp))
    {
        return true;
    }
    else
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
bool SinglyCL<T> :: CheckPrime(T no)
{
    int iCnt = 0, iSum = 0;

    for(iCnt = 1; iCnt <= no; iCnt++)
    {
        if(no % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    if((iSum == (no + 1)))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T> :: EvenSum()
{
    struct nodeS<T> *  temp = First;
    int iEvenSum = 0;

    while(temp != Last)
    {
        if((temp->data) % 2 == 0)
        {
            iEvenSum = iEvenSum + (temp->data);
        }
        temp = temp->next;
    }
    if((temp->data) % 2 == 0)
    {
        iEvenSum = iEvenSum + (temp->data);
    }
        return iEvenSum;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T> :: OddSum()
{
    struct nodeS<T> *  temp = First;
    int iOddSum = 0;

    while(temp != Last)
    {
        if((temp->data) % 2 != 0)
        {
            iOddSum = iOddSum + (temp->data);
        }
        temp = temp->next;
    }
    if((temp->data) % 2 != 0)
    {
        iOddSum = iOddSum + (temp->data);
    }
    return iOddSum;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: DigitSum()
{
    struct nodeS<T> *  temp = First;
    int iDigit = 0;
    int iNo = 0;
    int iDigitSum = 0;

    while (temp != Last)
    {
        iNo = temp->data;
        iDigitSum = 0;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iDigitSum = iDigitSum + iDigit;
            iNo = iNo / 10;
        }   
        printf("Sum of digits of %d is : %d\n",First->data,iDigitSum);
        First = temp->next;
    }
        iNo = temp->data;
        iDigitSum = 0;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iDigitSum = iDigitSum + iDigit;
            iNo = iNo / 10;
        }   
        printf("Sum of digits of %d is : %d\n",First->data,iDigitSum);
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: DisplayRev()
{
    struct nodeS<T> *  temp = First;
    T iDigit = 0, iRev = 0;
    int iTemp = 0;
    while (temp != Last)
    {
        iTemp = temp->data;
        iRev = 0;
        while(iTemp != 0)
        {
            iDigit = iTemp % 10;
            iRev = iRev * 10 + iDigit;
            iTemp = iTemp / 10;
        }
        printf("| %d |->",iRev);
        temp = temp->next;
    }
        iTemp = temp->data;
        iRev = 0;
        while(iTemp != 0)
        {
            iDigit = iTemp % 10;
            iRev = iRev * 10 + iDigit;
            iTemp = iTemp / 10;
        }
        printf("| %d |->",iRev);
    printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////

template <class T>
bool SinglyCL<T> :: Palindrome()
{
    T iDigit = 0, iTemp = First->data;
    T iRev = 0;

    while(iTemp != 0)
    {
        iDigit = iTemp % 10;
        iRev = iRev * 10 + iDigit;
        iTemp = iTemp / 10;
    }
    if(iRev == First->data)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: DisplayProduct()
{ 
    struct nodeS<T> *  temp = First;
    T iDigit = 0, iNo = 0;
    T iMult = 1;

    cout<<"The Product of all the elements is : "<<"\n";
    while (temp != Last)
    {   
        iNo = temp->data;
        iMult = 1;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit != 0)
            {
                iMult = iMult * iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMult<<"\t";
        temp = temp->next;
    }
        iNo = temp->data;
        iMult = 1;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit != 0)
            {
                iMult = iMult * iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMult<<"\n";
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: DisplaySmall()
{ 
    struct nodeS<T> *  temp = First;
    T iDigit = 0, iNo = 0;
    T iMin = 0;

    cout<<"Smallest digit from each element is : "<<"\n";
    while (temp != Last)
    {   
        iNo = temp->data;
        iMin = temp->data;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit < iMin)
            {
                iMin = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMin<<"\t";
        temp = temp->next;
    }
        iNo = temp->data;
        iMin = temp->data;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit < iMin)
            {
                iMin = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMin<<"\n";
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T> :: DisplayLarge()
{ 
    struct nodeS<T> *  temp = First;
    T iDigit = 0, iNo = 0;
    T iMax = 0;

    cout<<"Largest digit from each element is : "<<"\n";
    while (temp != Last)
    {   
        iNo = temp->data;
        iMax = 0;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit > iMax)
            {
                iMax = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMax<<"\t";
        temp = temp->next;
    }
        iNo = temp->data;
        iMax = 0;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit > iMax)
            {
                iMax = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMax<<"\n";
}

//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*
//
//  Function Definitions for Doubly Linear LL
//
//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*

template <class T>
DoublyLL<T> :: DoublyLL()
{
    First = NULL;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct nodeD<T> * newn = new nodeD<T>;  

    newn->data = no;
    newn->next =  NULL;
    newn->prev = NULL;

    if(First == NULL) 
    {
        First = newn;
    }
    else    // If LL contains atleast one node
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct nodeD<T> * newn = new nodeD<T>;  

    newn->data = no;
    newn->next =  NULL;
    newn->prev = NULL;

    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
    }
    else    // If LL contains atleast one node
    {
        struct nodeD<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
        newn->prev = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: InsertAtPos(T no, int ipos)
{
    int iCount = Count();
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeD<T> * newn = new nodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        struct nodeD<T> * temp = First;
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        newn->prev = newn;
        temp->next->prev = newn;

    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeD<T> * temp = First;
        First = First -> next;            
        First->prev = NULL;
        delete temp;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeD<T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DeleteAtPos(int ipos)
{
    int iCount = Count();
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeD<T> * temp1 = First;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        struct nodeD<T> * temp2 = temp1->next;

        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;

    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    struct nodeD<T> * temp = First;

    cout<<"NULL <=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T> :: Count()
{
    int iCnt = 0;
    struct nodeD<T> * temp = First;

    if(First == NULL )
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != NULL);

    return iCnt;
}

///////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLL<T> :: SearchFirstOcc(T no)
{
    struct nodeD<T> *  temp = First;
    int iCnt = 0;
    iCnt = 1;

    while(temp != NULL)
    {
        if((temp->data) == no)
        {
            break;
        }
        else
        {
            temp = temp -> next;
        }
        iCnt++;
    }
    return iCnt;
}

///////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLL<T> :: SearchLastOcc(T no)
{
    struct nodeD<T> *  temp = First;
    int iCnt = 0, iPos = 0;
    iCnt = 1;

    while(temp != NULL)
    {
        if((temp -> data) == no)
        {
            iPos = iCnt;
        }
        temp = temp -> next;
        iCnt++;
    }
    return iPos;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T> :: Addition()
{
    struct nodeD<T> *  temp = First;
    int iAdd = 0;

    while(temp != NULL)
    {
        iAdd = iAdd + (temp->data);
        temp = temp -> next;
    }
    return iAdd;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T> :: FindMaximum()
{
    struct nodeD<T> *  temp = First;
    int iMax = 0;

    while(temp != NULL)
    {
        if(iMax < (temp->data))
        {
            iMax = (temp -> data);
        }
        temp = temp -> next;
    }
    return iMax;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T> :: FindMinimum()
{
    struct nodeD<T> *  temp = First;
    int iMin = 0;
    iMin = First -> data;

    while(temp != NULL)
    {
        if((temp->data) < iMin)
        {
            iMin = (temp->data);
        }   
        temp = temp -> next;
    }
    return iMin;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
bool DoublyLL<T> :: Checkperfect(T no)
{
    T iTemp = no, iSum = 0; 
    int iCnt = 0;

    for(iCnt = 1; iCnt <= (no/2); iCnt++)
    {
        if(no % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    if((iSum == iTemp))
    {
        return true;
    }
    else
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DisplayPerfect()
{
    struct nodeD<T> *  temp = First;
    while(temp != NULL)
    {   
        if(CheckPerfect(temp->data) == true)
        {
            printf("%d is a perfect number\n",temp->data);
        }
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
bool DoublyLL<T> :: CheckPrime(T no)
{
    int iCnt = 0, iSum = 0;

    for(iCnt = 1; iCnt <= no; iCnt++)
    {
        if(no % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    if((iSum == (no + 1)))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DisplayPrime()
{
    struct nodeD<T> *  temp = First;
    while(temp != NULL)
    {
        if(CheckPrime(temp->data) == true)
        {
            printf("%d is a prime number\n",temp->data);
        }
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T> :: EvenSum()
{
    struct nodeD<T> *  temp = First;
    int iEvenSum = 0;

    while(temp != NULL)
    {
        if((temp->data) % 2 == 0)
        {
            iEvenSum = iEvenSum + (temp->data);
        }
        temp = temp->next;
    }
    return iEvenSum;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T> :: OddSum()
{
    struct nodeD<T> *  temp = First;
    int iOddSum = 0;

    while(temp != NULL)
    {
        if((temp->data) % 2 != 0)
        {
            iOddSum = iOddSum + (temp->data);
        }
        temp = temp->next;
    }
    return iOddSum;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DigitSum()
{
    struct nodeD<T> *  temp = First;
    int iDigit = 0;
    int iNo = 0;
    int iDigitSum = 0;

    while (temp != NULL)
    {
        iNo = temp->data;
        iDigitSum = 0;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iDigitSum = iDigitSum + iDigit;
            iNo = iNo / 10;
        }   
        printf("Sum of digits of %d is : %d\n",temp->data,iDigitSum);
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DisplayRev()
{
    struct nodeD<T> *  temp = First;
    T iDigit = 0, iRev = 0;
    int iTemp = 0;
    while (temp != NULL)
    {
        iTemp = temp->data;
        iRev = 0;
        while(iTemp != 0)
        {
            iDigit = iTemp % 10;
            iRev = iRev * 10 + iDigit;
            iTemp = iTemp / 10;
        }
        printf("| %d |->",iRev);
        temp = temp->next;
    }
    printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////

template <class T>
bool DoublyLL<T> :: Palindrome()
{
    T iDigit = 0, iTemp = First->data;
    T iRev = 0;

    while(iTemp != 0)
    {
        iDigit = iTemp % 10;
        iRev = iRev * 10 + iDigit;
        iTemp = iTemp / 10;
    }
    if(iRev == First->data)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DisplayProduct()
{ 
    struct nodeD<T> *  temp = First;
    T iDigit = 0, iNo = 0;
    T iMult = 1;

    while (temp != NULL)
    {   
        iNo = temp->data;
        iMult = 1;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit != 0)
            {
                iMult = iMult * iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMult<<"\t";
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DisplaySmall()
{ 
    struct nodeD<T> *  temp = First;
    T iDigit = 0, iNo = 0;
    T iMin = 0;

    while (temp != NULL)
    {   
        iNo = temp->data;
        iMin = temp->data;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit < iMin)
            {
                iMin = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMin<<"\t";
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DisplayLarge()
{ 
    struct nodeD<T> *  temp = First;
    T iDigit = 0, iNo = 0;
    T iMax = 0;

    while (temp != NULL)
    {   
        iNo = temp->data;
        iMax = 0;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit > iMax)
            {
                iMax = iDigit;
            }
            iNo = iNo / 10;
        }
        printf("%d\t",iMax);
        temp = temp->next;
    }
}

//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*
//                                                                      //
//  Function Definitions for Doubly Circular LL                         //
//                                                                      //
//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*

template <class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    struct nodeD<T> * newn = new nodeD<T>;  

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn; 
    }

    (First)->prev = Last;
    (Last)->next = First;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: InsertLast(T no)
{
    struct nodeD<T> * newn = new nodeD<T>;  

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        (Last) -> next = newn;
        newn->prev = Last;
        Last = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: InsertAtPos(T no, int ipos)
{
    int iNodeCnt = Count();
    struct nodeD<T> * newn = NULL;
    struct nodeD<T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new nodeD<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        (First) = (First) ->next;
        delete (Last)->next;        // free((*First)->prev);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        Last = (Last) -> prev;
        delete (First)->prev;       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    int iNodeCnt = Count();
    struct nodeD<T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: Display()
{
    struct nodeD<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    do
    {
        cout<<"| " <<temp->data<<"|<=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T> :: Count()
{
    int iCnt = 0;
    struct nodeD<T> *  temp = First;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);

    return iCnt;
}

/////////////////////////////////////////////////////////////////

template<class T>
int DoublyCL<T> :: SearchFirstOcc(T no)
{
    struct nodeD<T> *  temp = First;
    int iCnt = 0;
    iCnt = 1;

    while(temp != Last)
    {
        if((temp->data) == no)
        {
            break;
        }
        else
        {
            temp = temp -> next;
        }
        iCnt++;
    }
    return iCnt;
}

///////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCL<T> :: SearchLastOcc(T no)
{
    struct nodeD<T> *  temp = First;
    int iCnt = 0, iPos = 0;
    iCnt = 1;

    while(temp != Last)
    {
        if((temp -> data) == no)
        {
            iPos = iCnt;
        }
        temp = temp -> next;
        iCnt++;
    }
    return iPos;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T> :: Addition()
{
    struct nodeD<T> *  temp = First;
    int iAdd = 0;

    while(temp != Last)
    {
        iAdd = iAdd + (temp->data);
        temp = temp -> next;
    }
    
    return iAdd + (temp->data);
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T> :: FindMaximum()
{
    struct nodeD<T> *  temp = First;
    int iMax = 0;

    while(temp != Last)
    {
        if(iMax < (temp->data))
        {
            iMax = (temp -> data);
        }
        temp = temp -> next;
    }
    if(iMax < (temp->data))
    {
        iMax = (temp->data);
        return iMax;
    }
    else
    {
        return iMax;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T> :: FindMinimum()
{
    struct nodeD<T> *  temp = First;
    
    int iMin = 0;
    iMin = First -> data;

    while(temp != Last)
    {
        if((temp->data) < iMin)
        {
            iMin = (temp->data);
        }   
        temp = temp -> next;
    }
    if(iMin > (temp->data))
    {
        iMin = (temp->data);
        return iMin;
    }
    else
    {
        return iMin;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
bool DoublyCL<T> :: Checkperfect(T no)
{
    T iTemp = no, iSum = 0; 
    int iCnt = 0;

    for(iCnt = 1; iCnt <= (no/2); iCnt++)
    {
        if(no % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    if((iSum == iTemp))
    {
        return true;
    }
    else
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
bool DoublyCL<T> :: CheckPrime(T no)
{
    int iCnt = 0, iSum = 0;

    for(iCnt = 1; iCnt <= no; iCnt++)
    {
        if(no % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    if((iSum == (no + 1)))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T> :: EvenSum()
{
    struct nodeD<T> *  temp = First;
    int iEvenSum = 0;

    while(temp != Last)
    {
        if((temp->data) % 2 == 0)
        {
            iEvenSum = iEvenSum + (temp->data);
        }
        temp = temp->next;
    }
    if((temp->data) % 2 == 0)
    {
        iEvenSum = iEvenSum + (temp->data);
    }
        return iEvenSum;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T> :: OddSum()
{
    struct nodeD<T> *  temp = First;
    int iOddSum = 0;

    while(temp != Last)
    {
        if((temp->data) % 2 != 0)
        {
            iOddSum = iOddSum + (temp->data);
        }
        temp = temp->next;
    }
    if((temp->data) % 2 != 0)
    {
        iOddSum = iOddSum + (temp->data);
    }
    return iOddSum;
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DigitSum()
{
    struct nodeD<T> *  temp = First;
    int iDigit = 0;
    int iNo = 0;
    int iDigitSum = 0;

    while (temp != Last)
    {
        iNo = temp->data;
        iDigitSum = 0;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iDigitSum = iDigitSum + iDigit;
            iNo = iNo / 10;
        }   
        printf("Sum of digits of %d is : %d\n",First->data,iDigitSum);
        First = temp->next;
    }
        iNo = temp->data;
        iDigitSum = 0;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iDigitSum = iDigitSum + iDigit;
            iNo = iNo / 10;
        }   
        printf("Sum of digits of %d is : %d\n",First->data,iDigitSum);
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DisplayRev()
{
    struct nodeD<T> *  temp = First;
    T iDigit = 0, iRev = 0;
    int iTemp = 0;
    while (temp != Last)
    {
        iTemp = temp->data;
        iRev = 0;
        while(iTemp != 0)
        {
            iDigit = iTemp % 10;
            iRev = iRev * 10 + iDigit;
            iTemp = iTemp / 10;
        }
        printf("| %d |->",iRev);
        temp = temp->next;
    }
        iTemp = temp->data;
        iRev = 0;
        while(iTemp != 0)
        {
            iDigit = iTemp % 10;
            iRev = iRev * 10 + iDigit;
            iTemp = iTemp / 10;
        }
        printf("| %d |->",iRev);
    printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////

template <class T>
bool DoublyCL<T> :: Palindrome()
{
    T iDigit = 0, iTemp = First->data;
    T iRev = 0;

    while(iTemp != 0)
    {
        iDigit = iTemp % 10;
        iRev = iRev * 10 + iDigit;
        iTemp = iTemp / 10;
    }
    if(iRev == First->data)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DisplayProduct()
{ 
    struct nodeD<T> *  temp = First;
    T iDigit = 0, iNo = 0;
    T iMult = 1;

    cout<<"The Product of all the elements is : "<<"\n";
    while (temp != Last)
    {   
        iNo = temp->data;
        iMult = 1;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit != 0)
            {
                iMult = iMult * iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMult<<"\t";
        temp = temp->next;
    }
        iNo = temp->data;
        iMult = 1;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit != 0)
            {
                iMult = iMult * iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMult<<"\n";
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DisplaySmall()
{ 
    struct nodeD<T> *  temp = First;
    T iDigit = 0, iNo = 0;
    T iMin = 0;

    cout<<"Smallest digit from each element is : "<<"\n";
    while (temp != Last)
    {   
        iNo = temp->data;
        iMin = temp->data;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit < iMin)
            {
                iMin = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMin<<"\t";
        temp = temp->next;
    }
        iNo = temp->data;
        iMin = temp->data;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit < iMin)
            {
                iMin = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMin<<"\n";
}

///////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T> :: DisplayLarge()
{ 
    struct nodeD<T> *  temp = First;
    T iDigit = 0, iNo = 0;
    T iMax = 0;

    cout<<"Largest digit from each element is : "<<"\n";
    while (temp != Last)
    {   
        iNo = temp->data;
        iMax = 0;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit > iMax)
            {
                iMax = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMax<<"\t";
        temp = temp->next;
    }
        iNo = temp->data;
        iMax = 0;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            if(iDigit > iMax)
            {
                iMax = iDigit;
            }
            iNo = iNo / 10;
        }
        cout<<iMax<<"\n";
}

///////////////////////////////////////////////////////////////////////////

int main()
{
    
    return 0;
}