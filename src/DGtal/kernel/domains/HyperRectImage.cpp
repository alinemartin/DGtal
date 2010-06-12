/**
 * @file HyperRectImage.cpp
 * @author David Coeurjolly (\c david.coeurjolly@liris.cnrs.fr )
 * Laboratoire d'InfoRmatique en Image et Systèmes d'information - LIRIS (CNRS, UMR 5205), CNRS, France
 *
 * @date 2010/06/09
 *
 * Implementation of methods defined in HyperRectImage.h
 *
 * This file is part of the DGtal library.
 */

///////////////////////////////////////////////////////////////////////////////
#include "DGtal/kernel/domains/HyperRectImage.h"

///////////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// class HyperRectImage
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Standard services - public :



/**
* Destructor.
*/
template <class THyperRectDomain, typename T>
DGtal::HyperRectImage<THyperRectDomain,T>::HyperRectImage(const typename THyperRectDomain::PointType &aPointA, const  typename THyperRectDomain::PointType &aPointB ) : myDomain(aPointA,aPointB)
{    
    myImageMap.reserve(myDomain.extent());
}


/**
 * Destructor.
 */
template <class THyperRectDomain, typename T>
DGtal::HyperRectImage<THyperRectDomain,T>::~HyperRectImage()
{
}



///////////////////////////////////////////////////////////////////////////////
// Interface - public :

/**
 * Writes/Displays the object on an output stream.
 * @param out the output stream where the object is written.
 */
template <class THyperRectDomain, typename T>
void
DGtal::HyperRectImage<THyperRectDomain,T>::selfDisplay ( std::ostream & out ) const
{
    out << "[HyperRectImage]";
}

/**
 * Checks the validity/consistency of the object.
 * @return 'true' if the object is valid, 'false' otherwise.
 */
template <class THyperRectDomain, typename T>
bool
DGtal::HyperRectImage<THyperRectDomain,T>::isValid() const
{
    return true;
}


/**
* Overloads 'operator<<' for displaying objects of class 'HyperRectImage'.
* @param out the output stream where the object is written.
* @param object the object of class 'HyperRectImage' to write.
* @return the output stream after the writing.
*/
template<class THyperRectDomain, typename T>
std::ostream&
DGtal::operator<< ( std::ostream & out,
                    const HyperRectImage<THyperRectDomain,T> & object )
{
    object.selfDisplay ( out );
    return out;
}


///////////////////////////////////////////////////////////////////////////////
// Internals - private :

//                                                                           //
///////////////////////////////////////////////////////////////////////////////