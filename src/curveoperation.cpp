#include "curveoperation.h"

/**
 * @brief CurveOperation::CurveOperation
 * @param _x1
 * @param _y1
 * @param _x2
 * @param _y2
 */
CurveOperation::CurveOperation(const int &_x1, const int &_y1, const int &_x2, const int &_y2)
    : Operation(_x1, _y1, _x2, _y2)
{
  x3=_x1;
  y3=_y1;
  x4=_x1;
  y4=_x1;
}

/**
 * @brief CurveOperation::~CurveOperation
 */
CurveOperation::~CurveOperation() {
}


/**
 * @brief CurveOperatio::apply
 * @param r
 */

//int CurveOperation::apply(SDL_Renderer *r) const {
//    // Set the draw colour of our renderer
//    SDL_SetRenderDrawColor(r, m_colour[0], m_colour[1], m_colour[2], m_colour[3]);

//    int n = 40;
//    matrix_3d_t G;
//    matrix_3d_t M;

//    G[0][0]=m_x1;
//    G[0][1]=m_y1;
//    G[0][2]=0;
//    G[0][3]=0;
//    G[1][0]=x3;
//    G[1][1]=y3;
//    G[1][2]=0;
//    G[1][3]=0;
//    G[2][0]=x4;
//    G[2][1]=y4;
//    G[2][2]=0;
//    G[2][3]=0;
//    G[3][0]=m_x2;
//    G[3][1]=m_y2;
//    G[3][2]=0;
//    G[3][3]=0;

//    M[0][0]=-1.0/6.0;
//    M[0][1]=3.0/6.0;
//    M[0][2]=-3.0/6.0;
//    M[0][3]=1.0/6.0;
//    M[1][0]=3.0/6.0;
//    M[1][1]=-6.0/6.0;
//    M[1][2]=3.0/6.0;
//    M[1][3]=0;
//    M[2][0]=-3.0/6.0;
//    M[2][1]=0;
//    M[2][2]=3.0/6.0;
//    M[2][3]=0;
//    M[3][0]=1.0/6.0;
//    M[3][1]=4.0/6.0;
//    M[3][2]=1.0/6.0;
//    M[3][3]=0;


//    matrix_3d_t C; /* Coefficient Matrix */
//    double t1, t2, t3, dt,
//    x1, y1, z1, w1,
//    x2, y2, z2, w2;
//    int ci;
//    dt = 1.0 / n;
//    /* Compute_Coefficient_Matrix: C = M * G */

//    for (int r = 0; r < 4; r++)
//    {
//      for (int c = 0; c < 4; c++) \
//      {
//        C[r][c] = 0.0;

//        for (int i = 0; i < 4; i++)
//        {
//          C[r][c] += ((M)[r][i] * (G)[i][c]);
//        }
//      }
//    }

//    x1 = (C)[3][0]; y1 = (C)[3][1]; z1 = (C)[3][2]; w1 = (C)[3][3];
//    if (!(fabs(w1) > 0)) w1 = 1;
//    for (ci = 1; ci <= n; ci++)
//    {
//    t1 = ci * dt;
//    t2 = t1 * t1;
//    t3 = t2 * t1;
//    x2 = t3 * C[0][0] + t2 * C[1][0] + t1 * C[2][0] + C[3][0];
//    y2 = t3 * C[0][1] + t2 * C[1][1] + t1 * C[2][1] + C[3][1];
//    z2 = t3 * C[0][2] + t2 * C[1][2] + t1 * C[2][2] + C[3][2];
//    w2 = t3 * C[0][3] + t2 * C[1][3] + t1 * C[2][3] + C[3][3];
//    if (!(fabs(w2) > 0)) w2 = 1;

//    int result = SDL_RenderDrawLine(r, x1, y1, x2, y2);
//    if (result != 0)
//      {
//        printf( "CurveOperation::apply(SDL_Renderer*) - Operation Failed! SDL_Error: %s\n", SDL_GetError() );
//        return EXIT_FAILURE;
//      }
//    x1 = x2; y1 = y2; z1 = z2; w1 = w2;
//    }
//     /* draw_cubic_curve_segment */

//    // Attempt to draw a line onto the renderer

//    return EXIT_SUCCESS;
//}

int CurveOperation::apply(SDL_Renderer *r) const {
    // Set the draw colour of our renderer
    SDL_SetRenderDrawColor(r, m_colour[0], m_colour[1], m_colour[2], m_colour[3]);

    int n = 40;
    matrix_3d_t G;
    matrix_3d_t M;

    G[0][0]=m_x1;
    G[0][1]=m_y1;
    G[0][2]=0;
    G[0][3]=0;
    G[1][0]=x3;
    G[1][1]=y3;
    G[1][2]=0;
    G[1][3]=0;
    G[2][0]=x4;
    G[2][1]=y4;
    G[2][2]=0;
    G[2][3]=0;
    G[3][0]=m_x2;
    G[3][1]=m_y2;
    G[3][2]=0;
    G[3][3]=0;

    M[0][0]=-1.0/6.0;
    M[0][1]=3.0/6.0;
    M[0][2]=-3.0/6.0;
    M[0][3]=1.0/6.0;
    M[1][0]=3.0/6.0;
    M[1][1]=-6.0/6.0;
    M[1][2]=3.0/6.0;
    M[1][3]=0;
    M[2][0]=-3.0/6.0;
    M[2][1]=0;
    M[2][2]=3.0/6.0;
    M[2][3]=0;
    M[3][0]=1.0/6.0;
    M[3][1]=4.0/6.0;
    M[3][2]=1.0/6.0;
    M[3][3]=0;


    matrix_3d_t C; /* Coefficient Matrix */
    double t1, t2, t3, dt,
    x1, y1, z1, w1,
    x2, y2, z2, w2;
    int ci;
    dt = 1.0 / n;
    /* Compute_Coefficient_Matrix: C = M * G */

    for (int r = 0; r < 4; r++)
    {
      for (int c = 0; c < 4; c++) \
      {
        C[r][c] = 0.0;

        for (int i = 0; i < 4; i++)
        {
          C[r][c] += ((M)[r][i] * (G)[i][c]);
        }
      }
    }

    x1 = (C)[3][0]; y1 = (C)[3][1]; z1 = (C)[3][2]; w1 = (C)[3][3];
    if (!(fabs(w1) > 0)) w1 = 1;
    for (ci = 1; ci <= n; ci++)
    {
    t1 = ci * dt;
    t2 = t1 * t1;
    t3 = t2 * t1;
    x2 = t3 * C[0][0] + t2 * C[1][0] + t1 * C[2][0] + C[3][0];
    y2 = t3 * C[0][1] + t2 * C[1][1] + t1 * C[2][1] + C[3][1];
    z2 = t3 * C[0][2] + t2 * C[1][2] + t1 * C[2][2] + C[3][2];
    w2 = t3 * C[0][3] + t2 * C[1][3] + t1 * C[2][3] + C[3][3];
    if (!(fabs(w2) > 0)) w2 = 1;

    int result = SDL_RenderDrawLine(r, x1, y1, x2, y2);
    if (result != 0)
      {
        printf( "CurveOperation::apply(SDL_Renderer*) - Operation Failed! SDL_Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
      }
    x1 = x2; y1 = y2; z1 = z2; w1 = w2;
    }
     /* draw_cubic_curve_segment */

    // Attempt to draw a line onto the renderer

    return EXIT_SUCCESS;
}
