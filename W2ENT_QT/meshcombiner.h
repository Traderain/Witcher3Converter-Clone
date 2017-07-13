#ifndef MESHCOMBINER
#define MESHCOMBINER

#include <ISceneManager.h>

using namespace irr;

void combineMeshes(scene::ISkinnedMesh* newMesh, scene::IAnimatedMesh *addition, bool preserveBones);
scene::ISkinnedMesh* copySkinnedMesh(scene::ISceneManager* smgr, scene::IAnimatedMesh* meshToCopy, bool preserveBones);


#endif // MESHCOMBINER

