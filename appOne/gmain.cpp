#include "libOne.h"
#include "CONTAINER/CONTAINER.h"
#include "CONTAINER/BATCH.h"
#include "CONTAINER/TREE.h"
#include "SHADER/LAMBERT.h"
#include "createAssets.h"

void gmain() 
{
    window(1920, 1080, full);
    hideCursor();
    
    createAssets();
    //load assets
    CONTAINER* c = new CONTAINER("assets/Assets.txt");
    //set assets
    BATCH* batch = c->batch("saikoro");
    TREE* tree = new TREE(c->treeOrigin("tank"));
    ANIMATION* anim = c->animation("tank_move");
    tree->setAnimation(anim);
    float rad = 0;
    //create shader
    SHADER* shader = new LAMBERT;
    MATRIX world, view, proj;
    VECTOR camPos(0, 0, 7), lookat(0, 0, 0), up(0, 1, 0);
    proj.pers(3.14f / 4, width / height, 1, 100);
    VECTOR lightPos(0.5f, 0.7f, 1);
    float ambient = 0.2f;
    COLOR diffuse(1, 1, 1, 1);
    float camRadX = 0.3f;
    float camRadY = 0.6f;
    float camRadius = 5;

    while (notQuit) 
    {
        clear(160,128,128);
        //control camera
        if (isPress(KEY_J))camRadY -= 0.005f;
        if (isPress(KEY_L))camRadY += 0.005f;
        if (isPress(KEY_I))camRadX += 0.005f;
        if (isPress(KEY_K))camRadX -= 0.005f;
        if (isPress(KEY_U))camRadius -= 0.005f;
        if (isPress(KEY_O))camRadius += 0.005f;
        camPos.x = Sin(camRadY) * Cos(camRadX) * camRadius;
        camPos.y = Sin(camRadX) * camRadius;
        camPos.z = Cos(camRadY) * Cos(camRadX) * camRadius;
        view.camera(camPos, lookat, up);
        //set shader
        shader->setProjView(proj * view);
        shader->setLightPosition(lightPos);
        shader->setLightAmbient(ambient);
        shader->setDiffuse(diffuse);
        //batch model
        world.identity();
        world.mulTranslate(0, 0, 0);
        world.mulRotateY(rad);
        world.mulRotateZ(rad * 0.3f);
        world.mulScaling(0.2f, 0.2f, 0.2f);
        rad += 0.08f;
        batch->draw(shader, world);
        //tree model
        world.identity();
        world.mulTranslate(0, 0, 0);
        tree->update(world);
        tree->draw(shader);
    }

    delete shader;
    delete tree;
    delete c;
}
