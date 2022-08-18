#if( _DEBUG  )
#include "CONVERTER/CONVERT_MA.h"
#include "CONVERTER/fileUtil.h"
#endif

void createAssets() 
{
#if( _DEBUG )
    CONVERT_MA convertMa;
    convertMa.fbxToTree("Assets/saikoro.fbx", "Assets/saikoro.txt", "Assets/");
    convertMa.fbxToTree("Assets/test.fbx", "Assets/test.txt", "Assets/");
    convertMa.fbxToAnim("Assets/test.fbx", "Assets/test_move.txt");

    const char* assetsFileName = "Assets/Assets.txt";
    delFile(assetsFileName);
    addFile(assetsFileName, "Assets/saikoro.txt");
    addFile(assetsFileName, "Assets/test.txt");
    addFile(assetsFileName, "Assets/test_move.txt");
#endif
}
