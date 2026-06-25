#Shader"Paint4D/Post"
#Properties
[Hide]GBuffer_BaseColor("BaseColor",Texture2D) = 0
[Hide]GBuffer_Normal("Normal",Texture2D) = 1
#Properties
#Vertex
in vec3 aPos;
in vec3 aNormal;
in vec3 aUV;

layout(std140,binding=0) uniform GlobalParam
{
    mat4 MVP_V;
    mat4 MVP_P;
};

layout(std430, binding = 2) buffer MaterialParameters {
    float params[];
};

struct MeshBatch{
    mat4 modelMatrix;
    vec4 materialInstanceID;
};
layout(std430, binding = 1) buffer MeshBatchBuffer {
    MeshBatch batchInfo[];
};

out vec3 OUT_col;
out vec3 OUT_nor;
out vec3 OUT_uv;

uniform mat4 Matrix4x4_M;

void main() {
    uint instanceID = gl_InstanceID;
    mat4 MVP_M = batchInfo[instanceID].modelMatrix;
    OUT_nor = aNormal;
    OUT_uv = aUV;
    OUT_col=vec3(params[0],params[1],params[2]);
    vec4 vertexPos =  Matrix4x4_M * vec4(aPos,1.0f);

    gl_Position = vec4(vertexPos.xy,0.0f, 1.0f);
}
#Vertex
#Fragment

in vec3 OUT_col;
in vec3 OUT_nor;
in vec3 OUT_uv;

uniform sampler2D GBuffer_BaseColor;
uniform sampler2D GBuffer_Normal;

out vec4 outColor0;
void main() {
    float l = clamp(dot(OUT_nor,normalize(vec3(1,1,0))),0.3,1.0);
    vec4 col = texture(GBuffer_BaseColor,OUT_uv.xy);
    outColor0 = col;
}
#Fragment
