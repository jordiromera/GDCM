#ifndef GDCMSURFACEHELPER_H
#define GDCMSURFACEHELPER_H

#include "gdcmTypes.h"  // for GDCM_EXPORT

#include <vector>
#include <iostream>

namespace gdcm
{

class GDCM_EXPORT SurfaceHelper
{
public:

  /**
    * \brief  Minimal structure which define a color array with 3 components.
    */
  typedef std::vector< unsigned short > ColorArray;

  template <typename T, typename U>
  static unsigned short RGBToRecommendedDisplayGrayscale(const std::vector<T> & RGB,
                                                         const U rangeMax = 255);

  template <typename T, typename U>
  static ColorArray RGBToRecommendedDisplayCIELab(const std::vector<T> & RGB,
                                                  const U rangeMax = 255);

  template <typename T, typename U>
  static std::vector<T> RecommendedDisplayCIELabToRGB(const ColorArray & CIELab,
                                                      const U rangeMax = 255);

  template <typename U>
  static std::vector<float> RecommendedDisplayCIELabToRGB(const ColorArray & CIELab,
                                                      const U rangeMax = 255);

private:

  static std::vector< float > RGBToXYZ(const std::vector<float> & RGB);

  static std::vector< float > XYZToRGB(const std::vector<float> & XYZ);

  static std::vector< float > XYZToCIELab(const std::vector<float> & XYZ);

  static std::vector< float > CIELabToXYZ(const std::vector<float> & CIELab);
};

template <typename T, typename U>
unsigned short SurfaceHelper::RGBToRecommendedDisplayGrayscale(const std::vector<T> & RGB,
                                                               const U rangeMax/* = 255*/)
{
  assert(RGB.size() > 2);

  unsigned short Grayscale = 0;

  const float inverseRangeMax = 1. / (float) rangeMax;

  // 0xFFFF "=" 255 "=" white
  Grayscale = (unsigned short) ((0.2989 * RGB[0] + 0.5870 * RGB[1] + 0.1140 * RGB[2])
                                * inverseRangeMax
                                * 0xFFFF);

  return Grayscale;
}

template <typename T, typename U>
SurfaceHelper::ColorArray SurfaceHelper::RGBToRecommendedDisplayCIELab(const std::vector<T> & RGB,
                                                                       const U rangeMax/* = 255*/)
{
  assert(RGB.size() > 2);

  ColorArray CIELab(3);
  std::vector<float> tmp(3);

  const float inverseRangeMax = 1. / (float) rangeMax;
  tmp[0] = (float) (RGB[0] * inverseRangeMax);
  tmp[1] = (float) (RGB[1] * inverseRangeMax);
  tmp[2] = (float) (RGB[2] * inverseRangeMax);

  tmp = SurfaceHelper::XYZToCIELab( SurfaceHelper::RGBToXYZ( tmp ) );

  // 0xFFFF "=" 127, 0x8080 "=" 0, 0x0000 "=" -128
  CIELab[0] = (unsigned short) (          0xFFFF           * (tmp[0]*0.01));
  CIELab[1] = (unsigned short) (0x8080 + (0xFFFF - 0x8080) * (tmp[1]*0.01));
  CIELab[2] = (unsigned short) (0x8080 + (0xFFFF - 0x8080) * (tmp[2]*0.01));

  return CIELab;
}

template <typename T, typename U>
std::vector<T> SurfaceHelper::RecommendedDisplayCIELabToRGB(const ColorArray & CIELab,
                                                            const U rangeMax/* = 255*/)
{
  assert(CIELab.size() > 2);

  std::vector<T> RGB(3);
  std::vector<float> tmp(3);

  tmp[0] = (float) ( CIELab[0]                    / (float)(0xFFFF)          * 100 );
  tmp[1] = (float) ((CIELab[1] - (float)(0x8080)) / (float)(0xFFFF - 0x8080) * 100 );
  tmp[2] = (float) ((CIELab[2] - (float)(0x8080)) / (float)(0xFFFF - 0x8080) * 100 );

  tmp = SurfaceHelper::XYZToRGB( SurfaceHelper::CIELabToXYZ( tmp ) );

  RGB[0] = (T) (tmp[0] * rangeMax);
  RGB[1] = (T) (tmp[1] * rangeMax);
  RGB[2] = (T) (tmp[2] * rangeMax);

  return RGB;
}

template <typename U>
std::vector<float> SurfaceHelper::RecommendedDisplayCIELabToRGB(const ColorArray & CIELab,
                                                            const U rangeMax/* = 255*/)
{
  return RecommendedDisplayCIELabToRGB<float>(CIELab, rangeMax);
}

} // end namespace gdcm

#endif // GDCMSURFACEHELPER_H
