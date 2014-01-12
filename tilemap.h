#ifndef TILEMAP_H
#define TILEMAP_H
#include <cstdlib>
class TileInfo
{
    friend class Tilemap;
private:
    bool upL;
    bool upR;
    bool downL;
    bool downR;
    int	random(int n) { return (double)rand()/(RAND_MAX+1)*n;}
public:
    TileInfo();
    int GetID();
    void SetID(int id);
    void SetUpL(bool value){ upL = value;}
    void SetUpR(bool value){ upR = value;}
    void SetDownL(bool value){ downL = value;}
    void SetDownR(bool value){ downR = value;}
};
class Tilemap
{
private:
    bool**			mMatrixA;
    short**			mMatrixAB;
    int				mMapWidth;
    int				mMapHeight;
    void			CalculateTransition(int x, int y);
public:
    Tilemap(int width, int height);
    ~Tilemap();
    void            Resize(int width, int height);
    void			SetTileA(int x, int y);
    void			SetTileB(int x, int y);
    int				GetWidth(){ return mMapWidth;}
    int				GetHeight(){ return mMapHeight;}
    short           GetTileID(int x, int y){ return mMatrixAB[x][y];}
    void            SetTileID(int x, int y, short id){ mMatrixAB[x][y] = id;}
    bool            GetTileA(int x, int y){ return mMatrixA[x][y];}
    void            SetTileA(int x, int y, bool value){ mMatrixA[x][y] = value;}
};

#endif // TILEMAP_H
