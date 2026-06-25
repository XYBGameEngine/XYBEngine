#Shader"Paint4D/Selection"
#Properties
[]_Color("Color",Float3)=0
#Properties
#Vertex
in vec3 Pos;

layout(std140,binding=0) uniform GlobalParam
{
    mat4 MVP_V;
    mat4 MVP_P;
};
void main() {
    mat4 _MVP =  MVP_P * MVP_V;
    gl_Position = _MVP * vec4(Pos, 1.0);
}
#Vertex
#Fragment
layout(location = 0) out vec4 outColor0;
uniform vec3 _Color;
void main() {
    outColor0 = vec4(_Color,1.0f);
}
#Fragment

