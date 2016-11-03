#ifndef CURVEOPERATION_H
#define CURVEOPERATION_H

#include "operation.h"

/**
 * @brief The LineOperation class
 */
class CurveOperation : public Operation
{
public:
    /// ctor
    CurveOperation(const int &_x1, const int &_y1, const int &_x2, const int &_y2);

    /// dtor
    ~CurveOperation();



    /// Apply this operation to the current renderer
    int apply(SDL_Renderer *) const;
};

#endif // LINEOPERATION_H
