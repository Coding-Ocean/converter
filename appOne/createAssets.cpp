#if( _DEBUG  )
#include "CONVERTER/CONVERT_MA.h"
#include "CONVERTER/fileUtil.h"
#endif

void createAssets() 
{
#if( _DEBUG )
    CONVERT_MA convertMa;
    convertMa.fbxToTree(
        "AssetsOrigin/saikoro/saikoro.fbx", 
        "AssetsOrigin/saikoro/saikoro.txt", 
        "Assets/textures/saikoro/");
    convertMa.fbxToTree(
        "AssetsOrigin/test/test.fbx", 
        "AssetsOrigin/test/test.txt", 
        "Assets/textures/test/");
    convertMa.fbxToAnim(
        "AssetsOrigin/test/test.fbx", 
        "AssetsOrigin/test/test_move.txt");

    const char* assetsFileName = "Assets/Assets.txt";
    delFile(assetsFileName);
    addFile(assetsFileName, "AssetsOrigin/saikoro/saikoro.txt");
    addFile(assetsFileName, "AssetsOrigin/test/test.txt");
    addFile(assetsFileName, "AssetsOrigin/test/test_move.txt");
#endif
}
