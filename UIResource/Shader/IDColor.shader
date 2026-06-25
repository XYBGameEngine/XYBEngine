#Shader"Paint4D/IDColor"
#Properties
#Properties
#Vertex
in vec3 aPos;
in vec3 aNormal;
in vec3 aColor;
in vec3 aUV;

layout(std140,binding=0) uniform GlobalParam
{
    mat4 MVP_V;
    mat4 MVP_P;
};

struct MeshBatch{
    mat4 modelMatrix;
    vec4 materialInstanceID;
};
layout(std430, binding = 1) buffer MeshBatchBuffer {
    MeshBatch batchInfo[];
};

out vec3 OUT_nor;
out vec3 OUT_col;
out vec3 OUT_uv;
void main() {
    uint instanceID = gl_InstanceID;
    mat4 MVP_M = batchInfo[instanceID].modelMatrix;
    mat4 _MVP =  MVP_P * MVP_V * MVP_M;
    OUT_nor = aNormal;
    OUT_uv = aUV;
    OUT_col = aColor;
    gl_Position =_MVP*vec4(aPos, 1.0);
}
#Vertex
#Fragment
layout(location = 0) out vec4 outColor0;
layout(location = 1) out vec4 outColor1;
layout(location = 2) out vec4 outColor2;
layout(location = 3) out vec4 outColor3;

in vec3 OUT_col;
in vec3 OUT_nor;
in vec3 OUT_uv;
void main() {
    float l = clamp(dot(OUT_nor,normalize(vec3(1,1,0))),0.3,1.0);
    outColor0 = vec4(OUT_col, 1.0);
    outColor1 = vec4(OUT_nor.xyz,1.0);
    outColor2 = vec4(OUT_uv.xyz,1.0);
    outColor3 = vec4(1,0,0,1.0);
}
#Fragment
