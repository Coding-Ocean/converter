//Releaseモードの時は変換を行わない
#if( _DEBUG  )
    #include "CONVERTER/CONVERT_MA.h"
    #include "CONVERTER/fileUtil.h"
#endif

void createAssets() 
{
#if( _DEBUG )
    CONVERT_MA convertMa;
    //階層モデル
    convertMa.fbxToTree(
        "AssetsOrigin/tank/tank.fbx", //入力ファイル名
        "AssetsOrigin/tank/tank.txt", //出力ファイル名
        "Assets/textures/tank/"); //テクスチャ保存フォルダ名
    //アニメーション
    convertMa.fbxToAnim(
        "AssetsOrigin/tank/tank.fbx", //入力ファイル名
        "AssetsOrigin/tank/tank_move.txt");//出力。拡張子をとった名前がアニメーション名となる。

    //階層なしのモデル(BATCH)でもfbxToTreeで変換
    convertMa.fbxToTree(
        "AssetsOrigin/saikoro/saikoro.fbx", 
        "AssetsOrigin/saikoro/saikoro.txt", 
        "Assets/textures/saikoro/");

    //上記のデータをAssets.txtにまとめる
    const char* assetsFileName = "Assets/Assets.txt";
    delFile(assetsFileName);
    addFile(assetsFileName, "AssetsOrigin/saikoro/saikoro.txt");
    addFile(assetsFileName, "AssetsOrigin/tank/tank.txt");
    addFile(assetsFileName, "AssetsOrigin/tank/tank_move.txt");
#endif
}
