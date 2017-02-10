#include "W3_DataCache.h"
#include <iostream>


W3_DataCache W3_DataCache::_instance = W3_DataCache();

W3_DataCache::W3_DataCache() : _owner(0), _bufferID(0)
{

}

void W3_DataCache::setOwner(scene::ISkinnedMesh* owner)
{
    _owner = owner;
}

void W3_DataCache::clear()
{
    _owner = 0;
    _bones.clear();
    _vertices.clear();
}

void W3_DataCache::addBoneEntry(core::stringc name, core::matrix4 boneOffset)
{
    _bones.push_back(BoneEntry(name, boneOffset));
}

void W3_DataCache::addVertexEntry(u32 boneID, u16 meshBufferID, u32 vertexID, f32 strenght)
{
    _vertices.push_back(VertexSkinningEntry(boneID, _bufferID + meshBufferID, vertexID, strenght));
}

void W3_DataCache::apply()
{
    if (_owner == 0)
        return;

    for (u32 i = 0; i < _vertices.size(); ++i)
    {
        VertexSkinningEntry entry = _vertices[i];

        // Check if it's a valid entry
        if (    entry._boneID >= _bones.size()
            ||  entry._meshBufferID >= _owner->getMeshBufferCount()
            ||  entry._vertexID >= _owner->getMeshBuffer(entry._meshBufferID)->getVertexCount())
        {
            std::cout << "Fail to skin : the vertex entry is not valid." << std::endl;
            continue;
        }


        s32 jointID = _owner->getJointNumber(_bones[entry._boneID]._name.c_str());
        if (jointID == -1)
        {
            std::cout << "Fail to skin : joint not found." << std::endl;
            continue;
        }

        scene::ISkinnedMesh::SJoint* joint = _owner->getAllJoints()[jointID];
        scene::ISkinnedMesh::SWeight* weight = _owner->addWeight(joint);
        weight->buffer_id = entry._meshBufferID;
        weight->vertex_id = entry._vertexID;
        weight->strength = entry._strenght;
    }

    // To debug
    //skin();
}

void W3_DataCache::skin()
{
    buildSkinnedVertexArray();
    for (u32 i = 0; i < _bones.size(); ++i)
    {
        BoneEntry bone = _bones[i];

        scene::ISkinnedMesh::SJoint* joint = _owner->getAllJoints()[_owner->getJointNumber(bone._name.c_str())];
        if (joint == 0)
        {
            std::cout << "Error, no joint" << std::endl;
            continue;
        }

        skinJoint(joint, bone);
    }
    applySkinnedVertexArray();
}

// Adapted from http://sourceforge.net/p/assimp/discussion/817654/thread/5462cbf5
void W3_DataCache::skinJoint(scene::ISkinnedMesh::SJoint* joint, BoneEntry bone)
{
    const core::matrix4 boneOffset = bone._offsetMatrix;
    const core::matrix4 boneMat = joint->GlobalMatrix * boneOffset; //* InverseRootNodeWorldTransform;

    for (u32 i = 0; i < joint->Weights.size(); ++i)
    {
        const scene::ISkinnedMesh::SWeight weight = joint->Weights[i];
        const u16 bufferId = weight.buffer_id;
        const u32 vertexId = weight.vertex_id;

        core::vector3df sourcePos = _owner->getMeshBuffer(bufferId)->getPosition(vertexId);
        core::vector3df sourceNorm = _owner->getMeshBuffer(bufferId)->getNormal(vertexId);
        core::vector3df destPos, destNormal;
        boneMat.transformVect(destPos, sourcePos);
        boneMat.rotateVect(destNormal, sourceNorm);

        _skinnedVertex[bufferId][vertexId].Moved = true;
        _skinnedVertex[bufferId][vertexId].Position += destPos * weight.strength;
        _skinnedVertex[bufferId][vertexId].Normal += destNormal * weight.strength;
    }
}

void W3_DataCache::buildSkinnedVertexArray()
{
    _skinnedVertex.clear();

    _skinnedVertex.resize(_owner->getMeshBufferCount());
    for (u32 j = 0; j < _owner->getMeshBufferCount(); ++j)
    {
        const scene::IMeshBuffer* buffer = _owner->getMeshBuffer(j);
        _skinnedVertex[j].resize(buffer->getVertexCount());
    }
}

void W3_DataCache::applySkinnedVertexArray()
{
    for (u32 j = 0; j < _owner->getMeshBufferCount(); ++j)
    {
        scene::IMeshBuffer* buffer = _owner->getMeshBuffer(j);
        for (u32 i = 0; i < buffer->getVertexCount(); ++i)
        {
            if (_skinnedVertex[j][i].Moved)
            {
                buffer->getPosition(i) = _skinnedVertex[j][i].Position;
                buffer->getNormal(i) = _skinnedVertex[j][i].Normal;
            }
        }
    }

    _skinnedVertex.clear();
}
