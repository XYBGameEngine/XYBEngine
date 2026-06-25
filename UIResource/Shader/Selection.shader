#Shader"Paint4D/Selection"
#Properties
#Properties
#Vertex
in vec3 aPos;
in vec3 aNormal;
in vec3 aUV;
in vec3 aColor;

layout(std140,binding=0) uniform GlobalParam
{
    mat4 MVP_V;
    mat4 MVP_P;
};

struct MeshBatch{
    mat4 modelMatrix;
    vec4 materialInstanceID;
};
layout(std430, binding = 1) buffer MeshBatchBuffer
{
    MeshBatch batchInfo[];
};

out vec3 OUT_col;
flat out ivec3 OUT_id;

void main() {
    uint instanceID = uint(gl_BaseInstance) + uint(gl_InstanceID);

    int _matInstanceID = int(batchInfo[instanceID].materialInstanceID.x);
    int _selectedOnlyID = int(batchInfo[instanceID].materialInstanceID.y);

    mat4 MVP_M = batchInfo[instanceID].modelMatrix;
    mat4 _MVP =  MVP_P * MVP_V * MVP_M;
    OUT_col = aColor;
    OUT_id = ivec3(_selectedOnlyID,_selectedOnlyID,_selectedOnlyID);
    gl_Position = _MVP * vec4(aPos, 1.0);
}
#Vertex
#Fragment
layout(location = 0) out vec4 outColor0;
layout(location = 1) out vec4 outColor1;

in vec3 OUT_col;
flat in ivec3 OUT_id;

void main() {
    outColor0 = vec4(OUT_col, 1.0);
    outColor1 = vec4(OUT_id, 1);
}
#Fragment

