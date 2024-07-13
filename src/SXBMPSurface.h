/*
@brief BMP surface
@author KiritoOvO
@time 2024-07-13
*/

#ifndef SXBMPSURFACE_H
#define SXBMPSURFACE_H

#include "SXSurface.h"
sx_namespace_begin

class SXBMPSurface : public SXSurface
{
public:
    SXBMPSurface(const std::string & file);
    ~SXBMPSurface();
};

sx_namespace_end
#endif

