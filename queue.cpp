
/*********************************************************************
*
*   NAME:
*       queue.cpp
*
*   DESCRIPTION:
*       dynamic memory free version of std::queue. Size limited.
*
*   Copyright 2024 Nate Lenze
*
*********************************************************************/

/*--------------------------------------------------------------------
                              INCLUDES
--------------------------------------------------------------------*/
#include "queue.hpp"

/*--------------------------------------------------------------------
                          GLOBAL NAMESPACE
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*--------------------------------------------------------------------
mutex_lock()
--------------------------------------------------------------------*/
/*********************************************************************
*
*   PROCEDURE NAME:
*       utl::queue<N, T>::queue() (constructor)
*
*   DESCRIPTION:
*       queue class constructor
*
*********************************************************************/
template <int N, typename T>
utl::queue<N, T>::queue()
{
p_front_itr = p_data.begin();
p_tail_itr = p_data.begin();
} /* utl::queue<N, T>::queue() */

/*********************************************************************
*
*   PROCEDURE NAME:
*       utl::queue<N, T>::~queue() (cdeonstructor)
*
*   DESCRIPTION:
*       queue class deconstructor
*
*********************************************************************/
template <int N, typename T>
utl::queue<N, T>::~queue()
{
} /* utl::queue<N, T>::~queue() */

/*********************************************************************
*
*   PROCEDURE NAME:
*       utl::queue<N, T>::is_empty()
*
*   DESCRIPTION:
*       function for determining if queue is empty
*
*********************************************************************/
template <int N, typename T>
bool utl::queue<N, T>::is_empty( void )
{
return ( p_front_itr == p_tail_itr );
} /* utl::queue<N, T>::is_empty() */

/*********************************************************************
*
*   PROCEDURE NAME:
*       utl::queue<N, T>::is_full()
*
*   DESCRIPTION:
*       function for determining if queue is full
*
*********************************************************************/
template <int N, typename T>
bool utl::queue<N, T>::is_full( void )
{
return ( p_size >= N );
} /* utl::queue<N, T>::is_full() */

/*********************************************************************
*
*   PROCEDURE NAME:
*       utl::queue<N, T>::pop()
*
*   DESCRIPTION:
*       function for removing front of queue
*
*********************************************************************/
template <int N, typename T>
void utl::queue<N, T>::pop( void )
{
/*--------------------------------
if queue is already empty, exit
--------------------------------*/
if( p_size == 0 )
    return;

/*--------------------------------
Update iterator and size
--------------------------------*/
p_front_itr++;
p_size--;

/*--------------------------------
Account for rollover incase that
has occoured
--------------------------------*/
if( p_front_itr == p_data.end() )
    p_front_itr = p_data.begin();

} /* utl::queue<N, T>::pop() */

/*********************************************************************
*
*   PROCEDURE NAME:
*       utl::queue<N, T>::push()
*
*   DESCRIPTION:
*       function for removing front of queue
*
*********************************************************************/
template <int N, typename T>
bool utl::queue<N, T>::push( T item )
{
/*--------------------------------
return false if queue is full
--------------------------------*/
if( p_size >= N )
    return false;

/*--------------------------------
Update size and iterator location
--------------------------------*/
p_tail_itr++;
p_size++;

/*--------------------------------
Account for rollover incase that
has occoured
--------------------------------*/
if( p_tail_itr == p_data.end() )
    p_tail_itr = p_data.begin();

/*--------------------------------
Populate queue location
--------------------------------*/
*p_tail_itr = item;

/*--------------------------------
return true
--------------------------------*/
return true;

} /* utl::queue<N, T>::push() */

/*********************************************************************
*
*   PROCEDURE NAME:
*       utl::queue<N, T>::size()
*
*   DESCRIPTION:
*       function for aquiring size of queue
*
*********************************************************************/
template <int N, typename T>
int utl::queue<N, T>::size( void )
{
return p_size;
} /* utl::queue<N, T>::size() */


/*********************************************************************
*
*   PROCEDURE NAME:
*       utl::queue<N, T>::front()
*
*   DESCRIPTION:
*       function for aquiring item at front of queue
*
*********************************************************************/
template <int N, typename T>
T utl::queue<N, T>::front( void )
{
return *p_front_itr;
} /* utl::queue<N, T>::front() */

