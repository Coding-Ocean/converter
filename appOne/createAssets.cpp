//Release���[�h�̎��͕ϊ����s��Ȃ�
#if( _DEBUG  )
    #include "CONVERTER/CONVERT_MA.h"
    #include "CONVERTER/fileUtil.h"
#endif

void createAssets() 
{
#if( _DEBUG )
    CONVERT_MA convertMa;
    //�K�w���f��
    convertMa.fbxToTree(
        "AssetsOrigin/tank/tank.fbx", //���̓t�@�C����
        "AssetsOrigin/tank/tank.txt", //�o�̓t�@�C����
        "Assets/textures/tank/"); //�e�N�X�`���ۑ��t�H���_��
    //�A�j���[�V����
    convertMa.fbxToAnim(
        "AssetsOrigin/tank/tank.fbx", //���̓t�@�C����
        "AssetsOrigin/tank/tank_move.txt");//�o�́B�g���q���Ƃ������O���A�j���[�V�������ƂȂ�B

    //�K�w�Ȃ��̃��f��(BATCH)�ł�fbxToTree�ŕϊ�
    convertMa.fbxToTree(
        "AssetsOrigin/saikoro/saikoro.fbx", 
        "AssetsOrigin/saikoro/saikoro.txt", 
        "Assets/textures/saikoro/");

    //��L�̃f�[�^��Assets.txt�ɂ܂Ƃ߂�
    const char* assetsFileName = "Assets/Assets.txt";
    delFile(assetsFileName);
    addFile(assetsFileName, "AssetsOrigin/saikoro/saikoro.txt");
    addFile(assetsFileName, "AssetsOrigin/tank/tank.txt");
    addFile(assetsFileName, "AssetsOrigin/tank/tank_move.txt");
#endif
}
