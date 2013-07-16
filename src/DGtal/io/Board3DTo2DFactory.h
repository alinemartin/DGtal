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

#pragma once

/**
 * @file   Board3DTo2DFactory.h
 * @author Aline Martin <aline.martin@insa-lyon.fr>
 * @date   mardi 2 juillet 2013
 *
 * @brief
 *
 * Header file for module Board3DTo2DFactory
 *
 * This file is part of the DGtal library.
 */

#if defined(Board3DTo2DFactory_RECURSES)
#error Recursive header files inclusion detected in Board3DTo2DFactory.h
#else // defined(Board3DTo2DFactory_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Board3DTo2DFactory_RECURSES

#if !defined Board3DTo2DFactory_h
/** Prevents repeated inclusion of headers. */
#define Board3DTo2DFactory_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions

#include "DGtal/helpers/StdDefs.h"
#include "DGtal/base/Common.h"

#include "DGtal/io/Display3DFactory.h"
#include "DGtal/io/DrawWithBoard3DTo2DModifier.h"
#include "DGtal/geometry/curves/ArithmeticalDSS3d.h"
#include "DGtal/kernel/sets/DigitalSetBySTLSet.h"
#include "DGtal/kernel/sets/DigitalSetBySTLVector.h"
#include "DGtal/kernel/domains/HyperRectDomain.h"
#include "DGtal/topology/KhalimskySpaceND.h"
#include "DGtal/topology/Object.h"
#include "DGtal/kernel/PointVector.h"
#include "DGtal/geometry/curves/GridCurve.h"
#include "DGtal/shapes/Mesh.h"
#include "DGtal/geometry/tools/SphericalAccumulator.h"
#include "DGtal/io/colormaps/HueShadeColorMap.h"
#include "DGtal/io/colormaps/CColorMap.h"
#include "DGtal/images/ImageContainerBySTLVector.h"
#include "DGtal/images/ImageContainerBySTLMap.h"
#include "DGtal/images/ConstImageAdapter.h"
#include "DGtal/images/ImageAdapter.h"

//////////////////////////////////////////////////////////////////////////////

namespace DGtal
{
/////////////////////////////////////////////////////////////////////////////
// struct Board3DTo2DFactory
/**
   * Description of struct 'Board3DTo2DFactory' <p>
   * \brief Factory for GPL Display3D:
   */

struct Board3DTo2DFactory : public Display3DFactory
{


  /**
   * set the camera position on the board
   * @param board the board where to draw
   * @param aThing the camera position to set
   */
  template <typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::CameraPosition & aThing );

  /**
   * set the camera direction on the board
   * @param board the board where to draw
   * @param aThing the camera direction to set
   */
  template <typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::CameraDirection & aThing );

  /**
   * set the camera up vector on the board
   * @param board the board where to draw
   * @param aThing the camera up vector to set
   */
  template <typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::CameraUpVector & aThing );

  /**
   * set the near and far distance on the board
   * @param board the board where to draw
   * @param aThing the near and far distance
   */
  template <typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::CameraZNearFar & aThing );


  //----------------------------------------------------------------------------------------------
  // heritage
  // SphericalAccumulator
  /**
       * Display an spherical accumulator in 3D. Bin values are mapped
       * using a default HueShadeColorMap.
       *
       * @param board the board where to draw current board
       * @param accumulator the accumulator to board
       * @param shift translate vector for board purposes (default:
       * zero vector)
       * @param radius scale factor for the unit sphere radius (default:1)
       * @tparam TVector a vector model
       */
  template <typename TVector, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const  DGtal::SphericalAccumulator<TVector> & accumulator,
                    const typename DGtal::SphericalAccumulator<TVector>::RealVector & shift =
      typename DGtal::SphericalAccumulator<TVector>::RealVector(0,0,0),
                    const double radius=1.0);
  // SphericalAccumulator

  // Mesh
  /**
   * @brief drawAsFaces
   * @param board the board where to draw
   * @param aMesh the mesh to draw
   */
  template <typename TPoint, typename Space, typename KSpace>
  static void
  drawAsFaces( Board3DTo2D<Space, KSpace> & board, const DGtal::Mesh<TPoint> & aMesh );

  /**
   * @brief draw
   * @param board the board where to draw
   * @param aMesh the mesh to draw
   */
  template <typename TPoint, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const  DGtal::Mesh<TPoint> & aMesh );
  // Mesh



  // ArithmeticalDSS3d
  /**
   * Default drawing style object.
   * @param str
   * @param arithm the arithm to draw
   *  @return the dyn. alloc. default style for this object.
   */
  template <typename TIterator, typename TInteger, int connectivity>
  static DGtal::DrawableWithBoard3DTo2D *
  defaultStyle( std::string str, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & arithm );

  template <typename TIterator, typename TInteger, int connectivity, typename Space, typename KSpace>
  /**
   * @brief drawAsBalls
   * @param board the board where to draw
   * @param arithm the arithm to draw
   */
  static void
  drawAsBalls( Board3DTo2D<Space, KSpace> & board, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & arithm );

  /**
   * @brief drawAsBoundingBox
   * @param board the board where to draw
   * @param arithm the arithm to draw
   */
  template <typename TIterator, typename TInteger, int connectivity, typename Space, typename KSpace>
  static void
  drawAsBoundingBox( Board3DTo2D<Space, KSpace> & board, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & arithm );

  template <typename TIterator, typename TInteger, int connectivity, typename Space, typename KSpace>
  /**
   * @brief draw
   * @param board the board where to draw
   * @param arithm the arithm to draw
   */
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & arithm );
  // ArithmeticalDSS3d


  // DigitalSetBySTLSet
  /**
   * Default drawing style object.
   * @param str
   * @param aSet the set to draw
   * @return the dyn. alloc. default style for this object.
   */
  template<typename Domain>
  static DGtal::DrawableWithBoard3DTo2D *
  defaultStyle( std::string str, const DGtal::DigitalSetBySTLSet<Domain> & aSet );

  /**
   * @brief drawAsPavingTransparent
   * @param board the board where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void
  drawAsPavingTransparent( Board3DTo2D<Space, KSpace> & board, const DGtal::DigitalSetBySTLSet<Domain> & aSet );

  /**
   * @brief drawAsPaving
   * @param board the board where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void
  drawAsPaving( Board3DTo2D<Space, KSpace> & board, const DGtal::DigitalSetBySTLSet<Domain> & aSet );

  /**
   * @brief drawAsGrid
   * @param board the board where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void
  drawAsGrid( Board3DTo2D<Space, KSpace> & board, const DGtal::DigitalSetBySTLSet<Domain> & aSet );

  /**
   * @brief draw
   * @param board the board where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::DigitalSetBySTLSet<Domain> & aSet );
  // DigitalSetBySTLSet


  // DigitalSetBySTLVector
  /**
   * Default drawing style object.
   * @param str
   * @param aSet the set to draw
   * @return the dyn. alloc. default style for this object.
   */
  template<typename Domain>
  static DGtal::DrawableWithBoard3DTo2D *
  defaultStyle( std::string str, const DGtal::DigitalSetBySTLVector<Domain> & aSet );

  /**
   * @brief drawAsPavingTransparent
   * @param board the board where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void
  drawAsPavingTransparent( Board3DTo2D<Space, KSpace> & board, const DGtal::DigitalSetBySTLVector<Domain> & aSet );

  /**
   * @brief drawAsPaving
   * @param board the board where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void
  drawAsPaving( Board3DTo2D<Space, KSpace> & board, const DGtal::DigitalSetBySTLVector<Domain> & aSet );

  /**
   * @brief drawAsGrid
   * @param board the board where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void
  drawAsGrid( Board3DTo2D<Space, KSpace> & board, const DGtal::DigitalSetBySTLVector<Domain> & aSet );

  /**
   * @brief draw
   * @param board the board where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::DigitalSetBySTLVector<Domain> & aSet );
  // DigitalSetBySTLVector


  // HyperRectDomain
  /**
   * Default drawing style object.
   * @param str
   * @param aDomain the domain to draw
   * @return the dyn. alloc. default style for this object.
   */
  template<typename TSpace>
  static DGtal::DrawableWithBoard3DTo2D *
  defaultStyle( std::string str, const DGtal::HyperRectDomain<TSpace> & aDomain );

  /**
   * @brief drawAsBoundingBox
   * @param board the board where to draw
   * @param aDomain the domain to draw
   */
  template<typename TSpace, typename Space, typename KSpace>
  static void
  drawAsBoundingBox( Board3DTo2D<Space, KSpace> & board, const DGtal::HyperRectDomain<TSpace> & aDomain );

  /**
   * @brief drawAsGrid
   * @param board the board where to draw
   * @param aDomain the domain to draw
   */
  template<typename TSpace, typename Space, typename KSpace>
  static void
  drawAsGrid( Board3DTo2D<Space, KSpace> & board, const DGtal::HyperRectDomain<TSpace> & aDomain );

  /**
   * @brief drawAsPavingBalls
   * @param board the board where to draw
   * @param aDomain the domain to draw
   */
  template<typename TSpace, typename Space, typename KSpace>
  static void
  drawAsPavingBalls( Board3DTo2D<Space, KSpace> & board, const DGtal::HyperRectDomain<TSpace> & aDomain );

  /**
   * @brief drawAsPaving
   * @param board the board where to draw
   * @param aDomain the domain to draw
   */
  template<typename TSpace, typename Space, typename KSpace>
  static void
  drawAsPaving( Board3DTo2D<Space, KSpace> & board, const DGtal::HyperRectDomain<TSpace> & aDomain );



  /**
   * @brief draw
   * @param board the board where to draw
   * @param aDomain the domain to draw
   */
  template<typename TSpace, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::HyperRectDomain<TSpace> & aDomain );
  // HyperRectDomain


  // KhalimskyCell
  /**
   * Default drawing style object.
   * @param str
   * @param aCell the cell to draw
   * @return the dyn. alloc. default style for this object.
   */
  template < Dimension dim, typename TInteger>
  static DGtal::DrawableWithBoard3DTo2D *
  defaultStyle( std::string str, const DGtal::KhalimskyCell<dim, TInteger> & aCell );

  /**
   * @brief draw
   * @param board the board where to draw
   * @param aCell the cell to draw
   */
  template < Dimension dim, typename TInteger, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::KhalimskyCell<dim, TInteger> & aCell );
  // KhalimskyCell


  // Object
  /**
   * @brief defaultStyle
   * @param str
   * @param anObject the object to draw
   * @return the dyn. alloc. default style for this object.
   */
  template <typename TDigitalTopology, typename TDigitalSet>
  static DGtal::DrawableWithBoard3DTo2D *
  defaultStyle( std::string str, const DGtal::Object<TDigitalTopology, TDigitalSet> & anObject );

  /**
   * @brief drawWithAdjacencies
   * @param board the board where to draw
   * @param anObject the object to draw
   */
  template <typename TDigitalTopology, typename TDigitalSet, typename Space, typename KSpace>
  static void
  drawWithAdjacencies( Board3DTo2D<Space, KSpace> & board, const DGtal::Object<TDigitalTopology, TDigitalSet> & anObject );

  /**
   * @brief draw
   * @param board the board where to draw
   * @param anObject the object to draw
   */
  template <typename TDigitalTopology, typename TDigitalSet, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::Object<TDigitalTopology, TDigitalSet> & anObject );
  // Object


  // PointVector
  /**
   * Default drawing style object.
   * @param str
   * @param aPoint the point to draw
   * @return the dyn. alloc. default style for this object.
   */
  template<Dimension dim, typename TComponent>
  static DGtal::DrawableWithBoard3DTo2D *
  defaultStyle( std::string str, const DGtal::PointVector<dim,TComponent> & aPoint );

  /**
   * @brief drawAsGrid
   * @param board the board where to draw
   * @param aPoint the point to draw
   */
  template<Dimension dim, typename TComponent, typename Space, typename KSpace>
  static void
  drawAsGrid( Board3DTo2D<Space, KSpace> & board, const DGtal::PointVector<dim,TComponent> & aPoint );

  /**
   * @brief drawAsPaving
   * @param board the board where to draw
   * @param aPoint the point to draw
   */
  template<Dimension dim, typename TComponent, typename Space, typename KSpace>
  static void
  drawAsPaving( Board3DTo2D<Space, KSpace> & board, const DGtal::PointVector<dim,TComponent> & aPoint );

  /**
   * @brief drawAsPavingWired
   * @param board the board where to draw
   * @param aPoint the point to draw
   */
  template<Dimension dim, typename TComponent, typename Space, typename KSpace>
  static void
  drawAsPavingWired( Board3DTo2D<Space, KSpace> & board, const DGtal::PointVector<dim,TComponent> & aPoint );

  /**
   * @brief draw
   * @param board the board where to draw
   * @param aPoint the point to draw
   */
  template<Dimension dim, typename TComponent, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::PointVector<dim,TComponent> & aPoint );

  /**
   * @brief draw
   * @param board the board where to draw
   * @param aPoint the point to draw
   * @param aPoint2 the point to draw
   */
  template<Dimension dim, typename TComponent, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::PointVector<dim,TComponent> & aPoint, const DGtal::PointVector<dim,TComponent> & aPoint2 );
  // PointVector


  // SignedKhalimskyCell
  template< Dimension dim, typename TInteger>
  /**
   * Default drawing style object.
   * @param str
   * @param aSCell the signed cell to draw
   * @return the dyn. alloc. default style for this object.
   */
  static DGtal::DrawableWithBoard3DTo2D *
  defaultStyle( std::string str, const DGtal::SignedKhalimskyCell<dim, TInteger> & aSCell );

  template< Dimension dim, typename TInteger, typename Space, typename KSpace>
  /**
   * @brief draw
   * @param board the board where to draw
   * @param aSCell the signed cell to draw
   */
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::SignedKhalimskyCell<dim, TInteger> & aSCell );
  // SignedKhalimskyCell

  // GridCurve
  /**
   * @brief draw
   * @param board the board where to draw
   * @param aGrid the grid to draw
   */
  template< typename TKSpace, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::GridCurve<TKSpace> & aGrid );
  // GridCurve

  // SCellsRange
  /**
   * @brief draw
   * @param board the board where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template < typename TIterator, typename TSCell, typename Space, typename KSpace>
  static void
  draw( DGtal::Board3DTo2D<Space, KSpace> & board,
                    const DGtal::ConstRangeAdapter<TIterator, DGtal::DefaultFunctor, TSCell> & aRangeAdapter );
  // SCellsRange

  // PointsRange
  /**
   * @brief draw
   * @param board the board where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToPoint<TKSpace>, typename TKSpace::Point> & aRangeAdapter );
  // PointsRange

  // MidPointsRange
  /**
   * @brief draw
   * @param board the board where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToMidPoint<TKSpace>, typename TKSpace::Space::RealPoint> & aRangeAdapter );
  // MidPointsRange

  // ArrowsRange
  /**
   * @brief draw
   * @param board the board where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToArrow<TKSpace>, std::pair<typename TKSpace::Point, typename TKSpace::Vector > > & aRangeAdapter );
  // ArrowsRange

  // InnerPointsRange
  /**
   * @brief draw
   * @param board the board where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToInnerPoint<TKSpace>, typename TKSpace::Point> & aRangeAdapter );
  // InnerPointsRange

  // OuterPointsRange
  /**
   * @brief draw
   * @param board the board where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToOuterPoint<TKSpace>, typename TKSpace::Point> & aRangeAdapter );
  // OuterPointsRange

  // IncidentPointsRange
  /**
   * @brief draw
   * @param board the board where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToIncidentPoints<TKSpace>,std::pair<typename TKSpace::Point, typename TKSpace::Point > > & aRangeAdapter );
  // IncidentPointsRange


  /**
   * @brief draw
   * @param board the board where to draw
   * @param aMode the mode to set
   */
  template <typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::SetMode3D & aMode);

  /**
   * @brief draw
   * @param board the board where to draw
   * @param aStyle the style to set
   */
  template <typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::CustomStyle3D & aStyle);

  /**
   * @brief draw
   * @param board the board where to draw
   * @param aColor the color to set
   */
  template <typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::CustomColors3D & aColor);

  /**
   * @brief draw
   * @param board the board where to draw
   * @param aClipping the clipping plane to draw
   */
  template <typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::ClippingPlane & aClipping);

  /**
   * @brief draw
   * @param board the board where to draw
   * @param aTransformedSurfelPrism the transformed surfelprism to draw
   */
  template <typename Space, typename KSpace>
  static void
  draw( Board3DTo2D<Space, KSpace> & board, const DGtal::TransformedSurfelPrism & aTransformedSurfelPrism);

  // end heritage
  //----------------------------------------------------------------------------------------------

}; // end of struct Board3DTo2DFactory

} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions/methods
#include "DGtal/io/Board3DTo2DFactory.ih"


//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined Board3DTo2DFactory_h

#undef Board3DTo2DFactory_RECURSES
#endif // else defined(Board3DTo2DFactory_RECURSES)
