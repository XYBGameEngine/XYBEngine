#Shader"Paint4D/Selection"
#Properties
#Properties
#Vertex
in vec3 Pos;
in vec4 Color;

layout(std140,binding=0) uniform GlobalParam
{
    mat4 MVP_V;
    mat4 MVP_P;
};
struct MeshBatch{
    mat4 modelMatrix;
};
layout(std430, binding = 1) buffer MeshBatchBuffer {
    MeshBatch batchInfo[];
};

void main() {
    uint instanceID = uint(gl_BaseInstance) + uint(gl_InstanceID);
    mat4 MVP_M = batchInfo[instanceID].modelMatrix;
    mat4 _MVP =  MVP_P * MVP_V * MVP_M;
    gl_Position = _MVP * vec4(Pos, 1.0);
}
#Vertex
#Fragment
layout(location = 0) out vec4 outColor0;
layout(std140,binding=1) uniform GizmosGlobalParam
{
    vec4 GizmosColor;
};

void main() {
    outColor0 = GizmosColor;
}
#Fragment

