#define _
#ifdef _
#include "libOne.h"
#include "CONTAINER/CONTAINER.h"
#include "CONTAINER/BATCH.h"
#include "CONTAINER/TREE.h"
#include "SHADER/LAMBERT.h"
#include "createAssets.h"
void gmain() {
    window(1920, 1080, full);
    hideCursor();
    
    int img = loadImage("assets\\gorilla.png");
    
    createAssets();

    CONTAINER* c = new CONTAINER("assets\\Assets.txt");
    BATCH* b = c->batch("saikoro");
    TREE* t = new TREE(c->treeOrigin("test"));
    ANIMATION* Animation1 = c->animation("test_move");
    t->setAnimation(Animation1);
    float rad = 0;
    float radB = 0;

    SHADER* shader = new LAMBERT;
    MATRIX world, view, proj;
    VECTOR camPos(0, 1, 7), lookat(0, 1, 0), up(0, 1, 0);
    view.camera(camPos, lookat, up);
    proj.pers(3.14f / 4, width / height, 1, 100);
    VECTOR lightPos(0.5f, 0.7f, 1);
    float ambient = 0.0f;
    COLOR diffuse(1, 1, 1, 1);

    while (notQuit) {
        if (isPress(KEY_D))rad += 0.017f;
        if (isPress(KEY_A))rad -= 0.017f;

        radB += 0.017f;

        clear();
        print(rad);

        //3D Graphics------------------------------------------------
        shader->setProjView(proj * view);
        shader->setLightPosition(lightPos);
        shader->setLightAmbient(ambient);
        shader->setDiffuse(diffuse);

        world.identity();
        world.mulTranslate(2, 0, 0);
        world.mulRotateY(radB);
        world.mulRotateZ(radB*0.3f);
        world.mulScaling(0.5f, 0.5f, 0.5f);
        b->draw(shader, world);

        world.identity();
        world.mulRotateY(rad);
        t->update(world);
        t->draw(shader);

        //2D Graphics------------------------------------------------
        strokeWeight(10);

        fill(255, 0, 0);
        rect(0, 100, 100, 100);
        rect(100, 100, 100, 100);
        rect(200, 100, 100, 100);

        image(img, 200, 100, 0, 0.18f);

        fill(0, 0, 255);
        circle(350, 150, 100);

        fill(255);
        textSize(100);
        text("Œ¶‘z", 0, 200);

        line(0, 220, 400, 220);
    }
    delete t;
    delete c;
}
#endif