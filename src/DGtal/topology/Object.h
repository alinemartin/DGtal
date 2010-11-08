/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/
//LICENSE-END
#pragma once

/**
 * @file Object.h
 * @author Jacques-Olivier Lachaud (\c jacques-olivier.lachaud@univ-savoie.fr )
 * Laboratory of Mathematics (CNRS, UMR 5807), University of Savoie, France
 *
 * @date 2010/07/07
 *
 * Header file for module Object.cpp
 *
 * This file is part of the DGtal library.
 */

#if defined(Object_RECURSES)
#error Recursive header files inclusion detected in Object.h
#else // defined(Object_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Object_RECURSES

#if !defined Object_h
/** Prevents repeated inclusion of headers. */
#define Object_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include <string>
#include "DGtal/base/Common.h"
#include "DGtal/base/CowPtr.h"
#include "DGtal/kernel/sets/CDigitalSet.h"
#include "DGtal/kernel/sets/DigitalSetSelector.h"
//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{

  /////////////////////////////////////////////////////////////////////////////
  // template class Object
  /**
   * Description of template class 'Object' <p> \brief Aim: An object
   * (or digital object) represents a set in some digital space
   * associated with a digital topology.
   *
   * The digital topology induces a connectedness relation on the
   * object (transitive closure of the foreground adjacency) and a
   * connectedness relation on the complement of the set (transitive
   * closure of the background adjacency).
   *
   * Objects may be connected or not. The connectedness is stored with
   * the object, if it is known. Objects have a border, which are the
   * points which touch the complement in the sense of background
   * adjacency.
   *
   * @tparam TDigitalTopology any realization of DigitalTopology.
   * @tparam TDigitalSet any model of CDigitalSet.
   */
  template <typename TDigitalTopology, typename TDigitalSet>
  class Object
  {
    // ----------------------- Standard services ------------------------------
  public:
    typedef TDigitalSet DigitalSet;
    typedef TDigitalTopology DigitalTopology;
    typedef typename DigitalTopology::ReverseTopology ReverseTopology;
    typedef typename DigitalSet::Size Size;
    typedef typename DigitalSet::Point Point;
    // should be the same as Point.
    typedef typename DigitalTopology::Point DTPoint;

    typedef typename DigitalSet::DomainType Domain;
    typedef typename Domain::Space Space;
    typedef 
    typename DigitalSetSelector< Domain,  
				 SMALL_DS + HIGH_ITER_DS >::Type SmallSet;
    typedef typename DigitalTopology::ForegroundAdjacency ForegroundAdjacency;
    typedef typename DigitalTopology::BackgroundAdjacency BackgroundAdjacency;
    typedef Object<ReverseTopology,DigitalSet> ComplementObject;
    typedef Object<DigitalTopology,SmallSet> SmallObject;
    typedef Object<ReverseTopology,SmallSet> SmallComplementObject;

    /**
     * Kind of connectedness of this object.
     */
    enum Connectedness {
      DISCONNECTED = 0, CONNECTED = 1, UNKNOWN = 2
    };

    /**
     * Constructor. The object is not valid.
     */
    Object();

    /**
     * Constructor. 
     *
     * @param aTopology the digital topology chosen for this set, a copy of
     * which is stored in the object.
     *
     * @param aPointSet the set of points of the object. It is copied
     * in the object.
     * 
     * @param cxn the connectedness (default is UNKNOWN).
     */
    Object( const DigitalTopology & aTopology, 
	    const DigitalSet & aPointSet,
	    Connectedness cxn = UNKNOWN );

    /**
     * Constructor. 
     *
     * @param aTopology the digital topology chosen for this set,
     * smartly copied.
     *
     * @param aPointSet the set of points of the object. It is copied
     * in the object.
     * 
     * @param cxn the connectedness (default is UNKNOWN).
     */
    Object( const CowPtr<DigitalTopology> & aTopology, 
	    const DigitalSet & aPointSet,
	    Connectedness cxn = UNKNOWN );

    /**
     * Constructor. 
     *
     * @param aTopology the digital topology chosen for this set, a copy of
     * which is stored in the object.
     *
     * @param aPointSet the set of points of the object. It is smartly
     * reference in the object.
     * 
     * @param cxn the connectedness (default is UNKNOWN).
     */
    Object( const DigitalTopology & aTopology, 
	    const CowPtr<DigitalSet> & aPointSet,
	    Connectedness cxn = UNKNOWN );

    /**
     * Constructor by attachment of a dynamically allocated point set. 
     *
     * @param aTopology the digital topology chosen for this set, a copy of
     * which is stored in the object.
     *
     * @param aPointSetPtr a dynamically allocated pointer on a set of
     * points which is afterwards handled by this (which will take
     * care of its deletion).
     * 
     * @param cxn the connectedness (default is UNKNOWN).
     */
    Object( const DigitalTopology & aTopology, 
	    DigitalSet* aPointSetPtr,
	    Connectedness cxn = UNKNOWN );

    /**
     * Constructor of an empty object by providing a domain.
     *
     * @param aTopology the digital topology chosen for this set, a copy of
     * which is stored in the object.
     *
     * @param aDomain any domain related to the given topology.
     */
    Object( const DigitalTopology & aTopology, 
	    const Domain & domain );

    /**
     * Constructor of an empty object by providing a domain.
     *
     * @param aTopology the digital topology chosen for this set,
     * smartly copied.
     *
     * @param aDomain any domain related to the given topology.
     */
    Object( const CowPtr<DigitalTopology> & aTopology, 
	    const Domain & aDomain );
 
    /**
     * Copy constructor.
     * @param other the object to clone.
     *
     * The copy is smart in the sense that the digital set is
     * referenced, and will be copied only if the set is changed.
     */
    Object ( const Object & other );

    /**
     * Destructor.
     */
    ~Object();

    /**
     * Assignment.
     * @param other the object to copy.
     * @return a reference on 'this'.
     */
    Object & operator= ( const Object & other );

    /**
     * @return the number of elements in the set.
     */
    Size size() const;

    /**
     * A const reference to the embedding domain.
     */
    const Domain & domain() const;

    /**
     * A const reference on the point set defining the points of the
     * digital object.
     */
    const DigitalSet & pointSet() const;

    /**
     * A reference on the point set defining the points of the
     * digital object (may duplicate the set).
     */
    DigitalSet & pointSet();

    /**
     * @return a const reference to the topology of this object.
     */
    const DigitalTopology & topology() const;

    /**
     * @return a const reference to the adjacency of this object.
     */
    const ForegroundAdjacency & adjacency() const;

    // ----------------------- Object services --------------------------------
  public:

    /**
     * Let A be this object with foreground adjacency k and N_k(p) the
     * k-neighborhood of p. Returns the set A intersected with N_k(p).
     *
     * @param p any point (in the domain of the digital object, not
     * necessarily in the object).
     *
     * @return the kappa-neighborhood of [p] in this object.
     *
     * @see neighborhoodSize
     *
     * NB: if you need only the size of neighborhood, use neighborhoodSize.
     */
    SmallObject neighborhood( const Point & p ) const;

    /**
     * @param p any point (in the domain of the digital object, not
     * necessarily in the object).
     *
     * @return the cardinal of the kappa-neighborhood of [p] in this object.
     *
     * @see neighborhood
     *
     * NB: faster than computing the neighborhood then computing its cardinal.
     */
    Size neighborhoodSize( const Point & p ) const;

    /**
     * Let A be this object with foreground adjacency k and N*_k(p)
     * the proper k-neighborhood of p. Returns the set A intersected
     * with N*_k(p).
     *
     * @param p any point (in the domain of the digital object, not
     * necessarily in the object).
     *
     * @return the kappa-neighborhood of [p] in this object, without p.
     *
     * @see properNeighborhoodSize
     *
     * NB: if you need only the size of the proper neighborhood, use
     * properNeighborhoodSize.
     */
    SmallObject properNeighborhood( const Point & p ) const;

    /**
     * @param p any point (in the domain of the digital object, not
     * necessarily in the object).
     *
     * @return the cardinal of the kappa-neighborhood of [p] in this object.
     *
     * @see properNeighborhood
     *
     * NB: faster than computing the proper neighborhood then
     * computing its cardinal.
     */
    Size properNeighborhoodSize( const Point & p ) const;


    // ----------------------- border services -------------------------------
  public:

 
    /**
     * @return the border of this object (the set of points of this
     * which is lambda()-adjacent with some point of the background).
     *
     * NB : the background adjacency should be a symmetric relation.
     */
    Object border() const;


    // ----------------------- Connectedness services -------------------------
  public:

    /**
     * Computes the connected components of the object and writes
     * them on the output iterator [it].
     *
     * @tparam TOutputObjectIterator the type of an output iterator in
     * a container of Object s.
     *
     * @param it the output iterator. *it is an Object.
     * @return the number of components.
     *
     * NB: Be careful that the [it] should not be an output iterator
     * pointing in the same container containing 'this'. The following
     * example might make a 'bus error' because the vector might be
     * resized() during insertion.
     *
     * @code
     * vector<ObjectType> objects;
     * objects[ 0 ] = ... some object;
     * ...
     * back_insert_iterator< vector<ObjectType> > it( objects );
     * objects[ 0 ].writeComponents( it ); // it points in same container as this.
     * // might 'bus error'.
     * @endcode
     * 
     * If you wish to use an output iterator (like a
     * std::back_insert_iterator) in the same container containing
     * your object, you can write:
     *
     * @code
     * ObjectType( objects[ 0 ] ).writeComponents( it );
     * @endcode
     *
     * It is nearly as efficient (the clone uses smart copy on write
     * pointers) and works in any case. You might even overwrite your
     * object while doing this.
     */
    template <typename TOutputObjectIterator>
    Size writeComponents( TOutputObjectIterator & it ) const;

    /**
     * @return the connectedness of this object. Either CONNECTED,
     * DISCONNECTED, or UNKNOWN.
     *
     * @see computeConnectedness
     */
    Connectedness connectedness() const;

    /**
     * If 'connectedness() == UNKNOWN', computes the connectedness of
     * this object. After that, the connectedness of 'this' is either
     * CONNECTED or DISCONNECTED.
     *
     * @return the connectedness of this object. Either CONNECTED or
     * DISCONNECTED.
     *
     * @see connectedness
     */
    Connectedness computeConnectedness() const;


    // ----------------------- Simple points -------------------------------
  public:

    /**
     * Geodesic neighborhood of point [p] and order [k] in the object
     * for the given metric adjacency.
     */
    template <typename TAdjacency>
    SmallObject 
    geodesicNeighborhood( const TAdjacency & adj,
			  const Point & p, unsigned int k ) const;

    /**
     * Geodesic neighborhood of point [p] and order [k] in the
     * complemented object for the given metric adjacency.
     */
    template <typename TAdjacency>
    SmallComplementObject 
    geodesicNeighborhoodInComplement( const TAdjacency & adj,
				      const Point & p, unsigned int k ) const;


    /**
     * [Bertrand, 1994] A voxel v is simple for a set X if #C6 [G6 (v,
     * X)] = #C18[G18(v, X^c)] = 1, where #Ck [Y] denotes the number
     * of k-connected components of a set Y.
     *
     * We adapt this definition to (kappa,lambda) connectednesses. Be
     * careful, such a definition is valid only for Jordan couples in
     * dimension 2 and 3.
     *
     * @return 'true' if this point is simple.
     */
    bool isSimple( const Point & v ) const;

    // ----------------------- Interface --------------------------------------
  public:

    /**
     * Writes/Displays the object on an output stream.
     * @param out the output stream where the object is written.
     */
    void selfDisplay ( std::ostream & out ) const;

    /**
     * Checks the validity/consistency of the object.
     * @return 'true' if the object is valid, 'false' otherwise.
     */
    bool isValid() const;

    // ------------------------- Protected Datas ------------------------------
  private:
    // ------------------------- Private Datas --------------------------------
  private:

    /**
     * the digital topology of the object.
     */
    CowPtr<DigitalTopology> myTopo;

    /**
     * A copy on write pointer on the associated (owned or not) point set
     */
    CowPtr<DigitalSet> myPointSet;

    /**
     * Connectedness of this object. Either CONNECTED, DISCONNECTED, or UNKNOWN.
     */
    mutable Connectedness myConnectedness;

    // ------------------------- Hidden services ------------------------------
  protected:

  private:

    /** 
     * Default Style Functor for selfDraw methods
     */
    struct SelfDrawStyle
    {
      SelfDrawStyle(LibBoard::Board & aBoard) 
      {
	aBoard.setFillColorRGBi(160,160,160);
	aBoard.setPenColorRGBi(80,80,80);
      }
    };

    /** 
     * Default style.
     */
    struct DefaultDrawStyle : public DrawableWithBoard
    {
      virtual void selfDraw(LibBoard::Board & aBoard) const
      {
	aBoard.setFillColorRGBi(160,160,160);
	aBoard.setPenColorRGBi(80,80,80);
      }
    };


    // --------------- CDrawableWithBoard realization -------------------------
  public:

    /**
     * Default drawing style object.
     * @return the dyn. alloc. default style for this object. 
     */
    DrawableWithBoard* defaultStyle( std::string mode = "" ) const;

    /**
     * @return the style name used for drawing this object.
     */
    std::string styleName() const;

    /**
     * Draw the object on a LibBoard board.
     * @param board the output board where the object is drawn.
     */
    void selfDraw( LibBoard::Board & board ) const;

    /**
     * Draw the object on a LibBoard board.
     * @param board the output board where the object is drawn.
     */
    void selfDraw( DGtalBoard & board ) const;

    /**
     * Draw the object on a LiBoard board.
     * @param board the output board where the object is drawn.
     * @tparam Functor a Functor to specialize the Board style
     */
    template<typename Functor>
    void selfDraw(LibBoard::Board & board ) const;


    /**
     * Draw the object (with Adjacency relationships) on a LiBoard board.
     * @param board the output board where the object is drawn.
     * @tparam Functor a Functor to specialize the Board style
     */
    template<typename Functor>
    void selfDrawWithAdjacencies(LibBoard::Board & board ) const;

    /**
     * Draw the object (with Adjacency relationships) on a LiBoard board.
     * @param board the output board where the object is drawn.
     */
    void selfDrawWithAdjacencies(LibBoard::Board & board ) const;


    // ------------------------- Internals ------------------------------------
  private:

  }; // end of class Object


  /**
   * Overloads 'operator<<' for displaying objects of class 'Object'.
   * @param out the output stream where the object is written.
   * @param object the object of class 'Object' to write.
   * @return the output stream after the writing.
   */
  template <typename TDigitalTopology, typename TDigitalSet>
  std::ostream&
  operator<< ( std::ostream & out, 
	       const Object<TDigitalTopology, TDigitalSet> & object );

  /**
   * Modifier class in a DGtalBoard stream. Realizes the concept
   * CDrawableWithDGtalBoard.
   */
  struct DrawObjectAdjacencies : public DrawWithBoardModifier {
    DrawObjectAdjacencies( bool drawAdj = true )
      : myDrawAdj( drawAdj )
    {}
    void selfDraw( DGtalBoard & board ) const
    {
      board.myModes[ "Object" ] = myDrawAdj ? "DrawAdjacencies" : "";
    }
    bool myDrawAdj;
  };



} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions.
#include "DGtal/topology/Object.ih"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined Object_h

#undef Object_RECURSES
#endif // else defined(Object_RECURSES)
