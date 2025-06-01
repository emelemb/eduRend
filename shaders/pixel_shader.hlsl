
Texture2D texDiffuse : register(t0);

cbuffer CameraAndLightBuffer : register(b1)
{
    float4 cameraPos; 
    float4 lightPos;
    float4 lightCol; 
};


struct PSIn
{
	float4 Pos  : SV_Position;
	float3 Normal : NORMAL;
	float2 TexCoord : TEX;
};

//-----------------------------------------------------------------------------------------
// Pixel Shader
//-----------------------------------------------------------------------------------------

float4 PS_main(PSIn input) : SV_Target
{

}