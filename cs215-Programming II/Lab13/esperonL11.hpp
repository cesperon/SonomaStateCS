#ifndef LLIST2_HPP
#define LLIST2_HPP

#include <iostream>
using namespace std;

enum dtype { FORWARD, BACKWARD };

template <class LT> class LList2;
template <class LT> ostream & operator <<(ostream & outs, const LList2<LT> & L);

template<class LT>

class LList2
{
   private:
      struct LNode
      {
         LNode ();
	//void PrintNode (ostream & output); 
         LT data;
	 LNode * next;
	 LNode * prev;
	
      };
   public:
      class Iterator
      {
      public:
	Iterator ();
	Iterator (LNode * NP);
        LT & operator * () const;
	Iterator operator ++ ();
	Iterator operator ++ (int);
	Iterator operator -- ();
	Iterator operator -- (int);
	bool operator == (const Iterator & other) const;
	bool operator != (const Iterator & other) const;
	LT & operator [] (const int & index) const;
  
      private:
	LNode * current;
      };
      LList2 ();
      LList2 (const LList2 & other);
      ~LList2 ();
      LList2 & operator = (const LList2 & other);
      bool operator == (const LList2 & other);
      int Size () const;
      LT & operator [] (const int & index) const;

  void SetDirection (dtype dir);
  dtype GetDirection () const;
  friend ostream & operator << <> (ostream & outs, const LList2<LT> & L);

      bool InsertFirst (const LT & value);
      bool InsertLast (const LT & value);
      bool DeleteFirst ();
      bool DeleteLast ();

  void Forward (void function (const LT & param));
  void Backward (void function (const LT & param));
  void PrintValue (const int & value);

  Iterator begin () const;
  Iterator rbegin () const;
  Iterator end () const;
  Iterator rend () const;
  
   private:
      LNode * first;
      LNode * last;
      dtype direction;
      int size;
};


template <class LT>
LList2<LT>::LNode::LNode ()
{ // This function will initialize LNode object.
  
  next = NULL;
  prev = NULL;
  //size = 0;
}

template <class LT>
LList2<LT>::LList2 ()
{ // This function will initialize linked list object.
  size = 0;
  first= NULL;
  last = NULL;
  direction = FORWARD;
  
}

template <class LT>
LList2<LT>::LList2 (const LList2 & other)
{ // This function will copy a linked list object.
  first = NULL;
  size = 0;
  for(LNode * n = other.first; n!=NULL; n= n->next)
    InsertLast (n->data);
  direction = other.direction;
}

template <class LT>
LList2<LT>::~LList2 ()
{ // This function will deallocated the memory of an LList object.

  while(first)
    DeleteFirst();
  
}


template <class LT>
LList2<LT> & LList2<LT>::operator = (const LList2<LT> & other)
{ // This function will allow you to use = to assign one instance to another.

  if (this == &other)
	return * this;
  while (first)
    DeleteFirst();
  for (LNode * n = other.first; n!= NULL; n = n->next)
    InsertLast (n->data);
  direction = other.direction;
  return * this;
  
}

template <class LT>
bool LList2<LT>::operator == (const LList2 & other)
{ // This function will compare linked list objects.

  if (size != other.size)
    return false;

  int j = 0;
  LNode * n = first;
  LNode * m = other.first;
  while (j < size)
    {
      if (n->data != m->data)
	{
	  return false;
	}
      n = n->next;
      m = m->next;
      j++;
    }
  return true;
      
}

template <class LT>
int LList2<LT>::Size () const
{ // This function will return the size of the linked list.

  return size;
  
}

template<class LT>
ostream & operator << (ostream & outs, const LList2<LT> & L)
{ // This function will output the data in the linked list.
  if (L.first == NULL)
    {
      return outs;
    }

  if (L.direction == FORWARD)
    {//print the list from beginning (first) to end
      outs<<L.first->data;

      typename LList2<LT>::LNode * n;
      for (n = L.first->next; n!=NULL; n= n->next)
	outs <<' '<<n->data;
    }
  else //L.direction == BACKWARD
    {//print the list from end to beginning
      outs<<L.last->data;

      typename LList2<LT>::LNode*n;
      for(n = L.last->prev; n !=NULL; n= n->prev)
	outs<<' '<< n->data;
    }
  return outs;
  

}

template <class LT>
bool LList2<LT>::InsertFirst (const LT & value)
{ // This function will insert a new node into the first position of the
  // linked list.

  LNode* tmp = new LNode;
  
  if(tmp == NULL)
   {
     return false;
   }
  
  //tmp-> prev = NULL;
  if(size == 0)
    {
       tmp-> data = value;
  
       tmp-> next = NULL;

       tmp-> prev = NULL;

       first = tmp;

       last = tmp;

       size ++;
       return true;
    }
  if(size >=1)
    {
      tmp->data = value;
      tmp->next = first;
      tmp->prev = NULL;
      first->prev = tmp;

      first = tmp;
      size++;
      return true;
    }
      
}

template <class LT>
bool LList2<LT>::InsertLast (const LT & value)
{ // This function will insert a new node into the last position
  // of the linked list.
  
  if(size == 0)
    {
      return InsertFirst(value);
    }
  LNode * n = new LNode;
  if( n == NULL)
    return false;

  if(size == 1)
    {
      n-> next = NULL;
      n-> prev = last;
      n-> data = value;
      last->next = n;
      last = n;
      size++;
      return true;
    }

  n->data = value;
  n->next = NULL;
  n->prev = last;

  last->next = n;
  last = n;
  size++;
  return true;
  
  
}

template <class LT>
bool LList2<LT>::DeleteFirst ()
{ // This function will delete the first node in the linked list.
  
  if(size == 0)
     return false;

  if(size == 1)
    {
      LNode* tmp = first;
      first = NULL;
      last = NULL;
      delete tmp;
      size-- ;
      return true;
    }

  LNode* tmp = first;
  first = first->next;
  first->prev = NULL;
  delete tmp;
  size--;

  return true;
}

template <class LT>
bool LList2<LT>::DeleteLast ()
{ // This function will delete the last node in the linked list.
  if(size == 0)
    return false;
  if(size == 1)
    return DeleteFirst();

  LNode* n = last; 
  
  last = last->prev;
  last->next = NULL;
  n->prev = NULL;

  delete n;
  size--;
  return true;
    
}

template <class LT>
void LList2<LT>::Forward (void function (const LT & param))
{
  for (LNode * n = first; n; n= n->next)
    function (n->data);
}

template <class LT>
void LList2<LT>::Backward (void function (const LT & param))
{
  for (LNode * n = last; n; n= n->prev)
    function (n->data);
}

template <class LT>
void LList2<LT>::SetDirection (dtype dir)
{
  direction = dir;
}

template <class LT>
dtype LList2<LT>::GetDirection () const
{
  return direction;
}

 void PrintValue (const int & value)
 {
   cout<< "The value in the list is " << value << endl;
 }

template <class LT>
LT & LList2<LT>::operator [] (const int & index) const
{

 try
   {
     if(index > current.Size())
         throw("Subscript out of bounds:index is too large")
     LList2<LT>::LNode * n = first;
     for(int i = 0; i != index; i++)
        {
          n= n->next;
        }
     return n-> data;
   }
  
 catch (const char * message)
   {
     cerr<< message<< endl;
     exit(2);
   }
}


//template <class LT>

template <class LT>
LList2<LT>::Iterator::Iterator ()
{
  current =NULL;
}

template <class LT>
LList2<LT>::Iterator::Iterator (LNode * NP)
{
  current = NP;
}

template <class LT>
LT & LList2<LT>::Iterator:: operator * () const 
{
  try
    {
      if (current == NULL)
	throw("Cannot dereference a NULL pointer");
      return current->data;
    }
  catch (const char * message)
    {
      cerr<< message<< endl;
      exit(1);
    }
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::Iterator::operator ++()
{
  current = current->next;
  return * this;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::Iterator::operator ++(int)
{
 
  Iterator temp = *this;
  current = current ->next;
  return temp;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::Iterator::operator --()
{
  current = current->prev;
  return *this;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::Iterator::operator -- (int)
{
  Iterator temp = *this;
  current = current->prev;
  return temp;
}

template <class LT>
bool LList2<LT>::Iterator::operator == (const Iterator & other) const
{
  return current == other.current;
}

template <class LT>
bool LList2<LT>::Iterator::operator != (const Iterator & other) const
{
  return current != other.current;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::begin () const
{
  Iterator temp (first);
  return temp;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::rbegin () const
{
  Iterator temp (last);
  return temp;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::end () const
{
  Iterator temp;
  return temp;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::rend () const
{
  Iterator temp;
  return temp;
}



#endif
