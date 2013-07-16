

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
 * @file   Viewer3DFactory.h
 * @author Aline Martin <aline.martin@insa-lyon.fr>
 * @date   mardi 2 juillet 2013
 *
 * @brief
 *
 * Header file for module Viewer3DFactory
 *
 * This file is part of the DGtal library.
 */

#if defined(Viewer3DFactory_RECURSES)
#error Recursive header files inclusion detected in Viewer3DFactory.h
#else // defined(Viewer3DFactory_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Viewer3DFactory_RECURSES

#if !defined Viewer3DFactory_h
/** Prevents repeated inclusion of headers. */
#define Viewer3DFactory_h

//////////////////////////////////////////////////////////////////////////////
// Inclusions

#include "DGtal/helpers/StdDefs.h"
#include "DGtal/base/Common.h"

#include "DGtal/io/Display3DFactory.h"
#include "DGtal/io/DrawWithViewer3DModifier.h"
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
// struct Viewer3DFactory
/**
   * Description of struct 'Viewer3DFactory' <p>
   * \brief Factory for GPL Viewer3D:
   */

struct Viewer3DFactory : public Display3DFactory
{


  /**
   * set the camera position on the board
   * @param board the board where to draw
   * @param aThing the camera position to set
   */
  template <typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & board, const DGtal::CameraPosition & aThing );

  /**
   * set the camera direction on the board
   * @param board the board where to draw
   * @param aThing the camera direction to set
   */
  template <typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & board, const DGtal::CameraDirection & aThing );

  /**
   * set the camera up vector on the board
   * @param board the board where to draw
   * @param aThing the camera up vector to set
   */
  template <typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & board, const DGtal::CameraUpVector & aThing );

  /**
   * set the near and far distance on the board
   * @param board the board where to draw
   * @param aThing the near and far distance
   */
  template <typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & board, const DGtal::CameraZNearFar & aThing );

  //----------------------------------------------------------------------------------------------
  // heritage
  // SphericalAccumulator
  /**
     * Display an spherical accumulator in 3D. Bin values are mapped
     * using a default HueShadeColorMap.
     *
     * @param viewer the viewer where to draw current viewer
     * @param accumulator the accumulator to viewer
     * @param shift translate vector for viewer purposes (default:
     * zero vector)
     * @param radius scale factor for the unit sphere radius (default:1)
     * @tparam TVector a vector model
     */
  template <typename TVector,typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const  DGtal::SphericalAccumulator<TVector> & accumulator,
                    const typename DGtal::SphericalAccumulator<TVector>::RealVector & shift =
      typename DGtal::SphericalAccumulator<TVector>::RealVector(0,0,0),
                    const double radius=1.0);
  // SphericalAccumulator

  // Mesh
  /**
   * @brief drawAsFaces
   * @param viewer the viewer where to draw
   * @param aMesh the mesh to draw
   */
  template <typename TPoint, typename Space, typename KSpace>
  static void drawAsFaces( Viewer3D<Space,KSpace> & viewer, const DGtal::Mesh<TPoint> & aMesh );

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aMesh the mesh to draw
   */
  template <typename TPoint, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const  DGtal::Mesh<TPoint> & aMesh );
  // Mesh



  // ArithmeticalDSS3d
  /**
  * Default drawing style object.
  * @param str
  * @param arithm the arithm to draw
  * @return the dyn. alloc. default style for this object.
  */
  template <typename TIterator, typename TInteger, int connectivity>
  static DGtal::DrawableWithViewer3D * defaultStyle( std::string str, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & arithm );

  /**
   * @brief drawAsBalls
   * @param viewer the viewer where to draw
   * @param arithm the arithm to draw
   */
  template <typename TIterator, typename TInteger, int connectivity, typename Space, typename KSpace>
  static void drawAsBalls( Viewer3D<Space,KSpace> & viewer, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & arithm );

  /**
   * @brief drawAsBoundingBox
   * @param viewer the viewer where to draw
   * @param arithm the arithm to draw
   */
  template <typename TIterator, typename TInteger, int connectivity, typename Space, typename KSpace>
  static void drawAsBoundingBox( Viewer3D<Space,KSpace> & viewer, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & arithm );

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param arithm the arithm to draw
   */
  template <typename TIterator, typename TInteger, int connectivity, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const DGtal::ArithmeticalDSS3d<TIterator,TInteger,connectivity> & arithm );
  // ArithmeticalDSS3d


  // DigitalSetBySTLSet
  /**
   * @brief Default drawing style object.
   * @param str
   * @param aSet the set to draw
   * @return the dyn. alloc. default style for this object.
   */
  template<typename Domain>
  static DGtal::DrawableWithViewer3D * defaultStyle( std::string str, const DGtal::DigitalSetBySTLSet<Domain> & aSet );

  /**
   * @brief drawAsPavingTransparent
   * @param viewer the viewer where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void drawAsPavingTransparent( Viewer3D<Space,KSpace> & viewer, const DGtal::DigitalSetBySTLSet<Domain> & aSet );

  /**
   * @brief drawAsPaving
   * @param viewer the viewer where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void drawAsPaving( Viewer3D<Space,KSpace> & viewer, const DGtal::DigitalSetBySTLSet<Domain> & aSet );

  /**
   * @brief drawAsGrid
   * @param viewer the viewer where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void drawAsGrid( Viewer3D<Space,KSpace> & viewer, const DGtal::DigitalSetBySTLSet<Domain> & aSet );

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const DGtal::DigitalSetBySTLSet<Domain> & aSet );
  // DigitalSetBySTLSet


  // DigitalSetBySTLVector
  /**
  * Default drawing style object.
  * @param str
  * @param aSet the set to draw
  * @return the dyn. alloc. default style for this object.
  */
  template<typename Domain>
  static DGtal::DrawableWithViewer3D * defaultStyle( std::string str, const DGtal::DigitalSetBySTLVector<Domain> & aSet );

  /**
   * @brief drawAsPavingTransparent
   * @param viewer the viewer where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void drawAsPavingTransparent( Viewer3D<Space,KSpace> & viewer, const DGtal::DigitalSetBySTLVector<Domain> & aSet );

  /**
   * @brief drawAsPaving
   * @param viewer the viewer where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void drawAsPaving( Viewer3D<Space,KSpace> & viewer, const DGtal::DigitalSetBySTLVector<Domain> & aSet );

  /**
   * @brief drawAsGrid
   * @param viewer the viewer where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void drawAsGrid( Viewer3D<Space,KSpace> & viewer, const DGtal::DigitalSetBySTLVector<Domain> & aSet );

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aSet the set to draw
   */
  template<typename Domain, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const DGtal::DigitalSetBySTLVector<Domain> & aSet );
  // DigitalSetBySTLVector


  // HyperRectDomain
  /**
   * Default drawing style object.
   * @param str
   * @param aDomain the domain to draw
   * @return the dyn. alloc. default style for this object.
   */
  template<typename TSpace>
  static DGtal::DrawableWithViewer3D * defaultStyle( std::string str, const DGtal::HyperRectDomain<TSpace> & aDomain );

  /**
   * @brief drawAsBoundingBox
   * @param viewer the viewer where to draw
   * @param aDomain the domain to draw
   */
  template<typename TSpace, typename Space, typename KSpace>
  static void drawAsBoundingBox( Viewer3D<Space,KSpace> & viewer, const DGtal::HyperRectDomain<TSpace> & aDomain );

  /**
   * @brief drawAsGrid
   * @param viewer the viewer where to draw
   * @param aDomain the domain to draw
   */
  template<typename TSpace, typename Space, typename KSpace>
  static void drawAsGrid( Viewer3D<Space,KSpace> & viewer, const DGtal::HyperRectDomain<TSpace> & aDomain );

  template<typename TSpace, typename Space, typename KSpace>
  /**
   * @brief drawAsPavingBalls
   * @param viewer the viewer where to draw
   * @param aDomain the domain to draw
   */
  static void drawAsPavingBalls( Viewer3D<Space,KSpace> & viewer, const DGtal::HyperRectDomain<TSpace> & aDomain );

  /**
   * @brief drawAsPaving
   * @param viewer the viewer where to draw
   * @param aDomain the domain to draw
   */
  template<typename TSpace, typename Space, typename KSpace>
  static void drawAsPaving( Viewer3D<Space,KSpace> & viewer, const DGtal::HyperRectDomain<TSpace> & aDomain );

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aDomain the domain to draw
   */
  template<typename TSpace, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const DGtal::HyperRectDomain<TSpace> & aDomain );
  // HyperRectDomain


  // KhalimskyCell
  /**
   * Default drawing style object.
   * @param str
   * @param aCell the cell to draw
   * @return the dyn. alloc. default style for this object.
   */
  template < Dimension dim, typename TInteger>
  static DGtal::DrawableWithViewer3D * defaultStyle( std::string str, const DGtal::KhalimskyCell<dim, TInteger> & aCell );

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aCell the cell to draw
   */
  template < Dimension dim, typename TInteger, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const DGtal::KhalimskyCell<dim, TInteger> & aCell );
  // KhalimskyCell


  // Object
  /**
   * @brief defaultStyle
   * @param str
   * @param anObject the object to draw
   * @return
   */
  template <typename TDigitalTopology, typename TDigitalSet>
  static DGtal::DrawableWithViewer3D * defaultStyle( std::string str, const DGtal::Object<TDigitalTopology, TDigitalSet> & anObject );

  /**
   * @brief drawWithAdjacencies
   * @param viewer the viewer where to draw
   * @param anObject the object to draw
   */
  template <typename TDigitalTopology, typename TDigitalSet, typename Space, typename KSpace>
  static void drawWithAdjacencies( Viewer3D<Space,KSpace> & viewer, const DGtal::Object<TDigitalTopology, TDigitalSet> & anObject );

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anObject the object to draw
   */
  template <typename TDigitalTopology, typename TDigitalSet, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const DGtal::Object<TDigitalTopology, TDigitalSet> & anObject );
  // Object


  // PointVector
  /**
   * Default drawing style object.
   * @param str
   * @param aPoint the point to draw
   * @return the dyn. alloc. default style for this object.
   */
  template<Dimension dim, typename TComponent>
  static DGtal::DrawableWithViewer3D * defaultStyle( std::string str, const DGtal::PointVector<dim,TComponent> & aPoint );

  /**
   * @brief drawAsGrid
   * @param viewer the viewer where to draw
   * @param aPoint the point to draw
   */
  template<Dimension dim, typename TComponent, typename Space, typename KSpace>
  static void drawAsGrid( Viewer3D<Space,KSpace> & viewer, const DGtal::PointVector<dim,TComponent> & aPoint );

  template<Dimension dim, typename TComponent, typename Space, typename KSpace>
  /**
   * @brief drawAsPaving
   * @param viewer the viewer where to draw
   * @param aPoint the point to draw
   */
  static void drawAsPaving( Viewer3D<Space,KSpace> & viewer, const DGtal::PointVector<dim,TComponent> & aPoint );

  /**
   * @brief drawAsPavingWired
   * @param viewer the viewer where to draw
   * @param aPoint the point to draw
   */
  template<Dimension dim, typename TComponent, typename Space, typename KSpace>
  static void drawAsPavingWired( Viewer3D<Space,KSpace> & viewer, const DGtal::PointVector<dim,TComponent> & aPoint );

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aPoint the point to draw
   */
  template<Dimension dim, typename TComponent, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const DGtal::PointVector<dim,TComponent> & aPoint );

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aPoint the point to draw
   * @param aPoint2 the point to draw
   */
  template<Dimension dim, typename TComponent, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const DGtal::PointVector<dim,TComponent> & aPoint, const DGtal::PointVector<dim,TComponent> & aPoint2 );
  // PointVector


  // SignedKhalimskyCell
  /**
   * Default drawing style object.
   * @param str
   * @param aSCell the signed cell to draw
   * @return the dyn. alloc. default style for this object.
   */
  template< Dimension dim, typename TInteger >
  static DGtal::DrawableWithViewer3D * defaultStyle( std::string str, const DGtal::SignedKhalimskyCell<dim, TInteger> & aSCell );

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aSCell the signed cell to draw
   */
  template< Dimension dim, typename TInteger , typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const DGtal::SignedKhalimskyCell<dim, TInteger> & aSCell );
  // SignedKhalimskyCell

  // GridCurve
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aGrid the grid to draw
   */
  template< typename TKSpace , typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const DGtal::GridCurve<TKSpace> & aGrid );
  // GridCurve

  // SCellsRange
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template < typename TIterator, typename TSCell, typename Space, typename KSpace>
  static void draw( DGtal::Viewer3D<Space, KSpace> & viewer,
                    const DGtal::ConstRangeAdapter<TIterator, DGtal::DefaultFunctor, TSCell> & aRangeAdapter );
  // SCellsRange

  // PointsRange
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToPoint<TKSpace>, typename TKSpace::Point> & aRangeAdapter );
  // PointsRange

  // MidPointsRange
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToMidPoint<TKSpace>, typename TKSpace::Space::RealPoint> & aRangeAdapter );
  // MidPointsRange

  // ArrowsRange
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
  static void draw( Viewer3D<Space, KSpace> & viewer,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToArrow<TKSpace>, std::pair<typename TKSpace::Point, typename TKSpace::Vector > > & aRangeAdapter );
  // ArrowsRange

  // InnerPointsRange
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToInnerPoint<TKSpace>, typename TKSpace::Point> & aRangeAdapter );
  // InnerPointsRange

  // OuterPointsRange
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToOuterPoint<TKSpace>, typename TKSpace::Point> & aRangeAdapter );
  // OuterPointsRange

  // IncidentPointsRange
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aRangeAdapter the range adapter to draw
   */
  template <typename TIterator, typename TKSpace, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer,
                    const DGtal::ConstRangeAdapter<TIterator, SCellToIncidentPoints<TKSpace>,std::pair<typename TKSpace::Point, typename TKSpace::Point > > & aRangeAdapter );
  // IncidentPointsRange


  // ImageContainerBySTLVector  (2D)
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anImage the image to draw
   */
  template <typename TValue, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const  ImageContainerBySTLVector<DGtal::Z2i::Domain, TValue>  & anImage );
  // ImageContainerBySTLVector  (2D)

  // ImageContainerBySTLMap  (2D)
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anImage the image to draw
   */
  template <typename TValue, typename Space, typename KSpace>
  static void draw( Viewer3D<Space, KSpace> & viewer, const  ImageContainerBySTLMap<DGtal::Z2i::Domain, TValue>  & anImage );
  // ImageContainerBySTLMap  (2D)

  // ConstImageAdapter  (2D)
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anImage the image to draw
   */
  template <typename TImageContainer, typename TFunctorD, typename TNewValue, typename TFunctorValue, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const  ConstImageAdapter<TImageContainer, DGtal::Z2i::Domain, TFunctorD, TNewValue, TFunctorValue>  & anImage );
  // ConstImageAdapter  (2D)

  // ImageAdapter  (2D)
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anImage the image to draw
   */
  template <typename TImageContainer, typename TFunctorD, typename TNewValue, typename TFunctorValue, typename TFunctorValueVm1, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const  ImageAdapter<TImageContainer, DGtal::Z2i::Domain, TFunctorD,
                    TNewValue, TFunctorValue, TFunctorValueVm1>  & anImage );
  // ImageAdapter  (2D)


  // ImageContainerBySTLVector  (3D)
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anImage the image to draw
   */
  template <typename TValue, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const   ImageContainerBySTLVector<DGtal::Z3i::Domain, TValue>  & anImage );
  // ImageContainerBySTLVector (3D)


  // ImageContainerBySTLMap  (3D)
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anImage the image to draw
   */
  template <typename TValue, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const   ImageContainerBySTLMap<DGtal::Z3i::Domain, TValue>  & anImage );
  // ImageContainerBySTLMap  (3D)

  // ConstImageAdapter  (3D)
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anImage the image to draw
   */
  template <typename TImageContainer, typename TFunctorD, typename TNewValue, typename TFunctorValue, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const  ConstImageAdapter<TImageContainer, DGtal::Z3i::Domain, TFunctorD,
                    TNewValue, TFunctorValue>  & anImage );
  // ConstImageAdapter  (3D)

  // ImageAdapter  (3D)
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anImage the image to draw
   */
  template <typename TImageContainer, typename TFunctorD, typename TNewValue, typename TFunctorValue, typename TFunctorValueVm1, typename Space, typename KSpace>
  static void draw( Viewer3D<Space,KSpace> & viewer, const  ImageAdapter<TImageContainer, DGtal::Z3i::Domain, TFunctorD,
                    TNewValue, TFunctorValue, TFunctorValueVm1>  & anImage );
  // ImageAdapter  (3D)


  /**
   * @brief drawImage2D
   * @param viewer the viewer where to draw
   * @param anImage the image to draw
   * @param aFunctor the functor to draw
   * @param aTextureMode
   */
  template < typename TImageType2D, typename TFunctor, typename Space, typename KSpace>
  static void
  drawImage2D( Viewer3D<Space,KSpace> & viewer, const TImageType2D & anImage, const TFunctor & aFunctor,
   //            typename Viewer3D<Space,KSpace>::TextureMode aTextureMode= Viewer3D<Space,KSpace>::GrayScaleMode );
               typename Viewer3D<Space,KSpace>::TextureMode aTextureMode= 1 );

  /**
   * @brief drawImage3D
   * @param viewer the viewer where to draw
   * @param anImage3D the image to draw
   * @param aFunctor the functor to draw
   * @param aTextureMode the mode to set
   */
  template < typename TImageType3D, typename TFunctor, typename Space, typename KSpace>
  static void
  drawImage3D( Viewer3D<Space,KSpace> & viewer, const TImageType3D & anImage3D, const TFunctor & aFunctor,
     //          typename Viewer3D<Space,KSpace>::TextureMode aTextureMode=Viewer3D<Space,KSpace>::GrayScaleMode );
                typename Viewer3D<Space,KSpace>::TextureMode aTextureMode= 1 );


  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aMode the mode to set
   */
  template < typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & viewer, const DGtal::SetMode3D & aMode);

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aStyle the style to set
   */
  template < typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & viewer, const DGtal::CustomStyle3D & aStyle);

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aColor the color to set
   */
  template < typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & viewer, const DGtal::CustomColors3D & aColor);

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aClipping the clipping plane to draw
   */
  template < typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & viewer, const DGtal::ClippingPlane & aClipping);


  // AddTextureImage3DWithFunctor
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aFunctor the functor to draw
   */
  template<typename TImageType, typename TFunctor, typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & viewer, const DGtal::AddTextureImage3DWithFunctor<TImageType, TFunctor, Space, KSpace> & aFunctor );
  // AddTextureImage3DWithFunctor

  // AddTextureImage2DWithFunctor
  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aFunctor the functor to draw
   */
  template<typename TImageType, typename TFunctor, typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & viewer, const DGtal::AddTextureImage2DWithFunctor<TImageType, TFunctor, Space, KSpace> & aFunctor );
  // AddTextureImage2DWithFunctor

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anUpdate the update to set
   */
  template < typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & viewer, const DGtal::UpdateImagePosition<Space, KSpace> & anUpdate);

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anUpdate the update to set
   */
  template < typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & viewer, const DGtal::UpdateLastImagePosition<Space, KSpace> & anUpdate );

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anUpdate the update to set
   */
  template < typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> &viewer, const DGtal::Update2DDomainPosition<Space, KSpace> & anUpdate);

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anTranslation the translation to apply
   */
  template < typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> &viewer, const DGtal::Translate2DDomain & anTranslation);

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param anUpdate the update to set
   */
  template<typename TImageType, typename TFunctor, typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & viewer, const DGtal::UpdateImageData<TImageType, TFunctor> & anUpdate);

  /**
   * @brief draw
   * @param viewer the viewer where to draw
   * @param aTransformedSurfelPrism the transformed surfelprism to draw
   */
  template < typename Space, typename KSpace>
  static void
  draw( Viewer3D<Space,KSpace> & viewer, const DGtal::TransformedSurfelPrism & aTransformedSurfelPrism);

  // end heritage
  //----------------------------------------------------------------------------------------------

}; // end of struct Viewer3DFactory

} // namespace DGtal


///////////////////////////////////////////////////////////////////////////////
// Includes inline functions/methods
#include "DGtal/io/Viewer3DFactory.ih"


//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#endif // !defined Viewer3DFactory_h

#undef Viewer3DFactory_RECURSES
#endif // else defined(Viewer3DFactory_RECURSES)
