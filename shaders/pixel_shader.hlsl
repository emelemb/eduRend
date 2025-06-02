
Texture2D textureDiffuse : register(t0);

//cbuffer CameraAndLightBuffer : register(b1)
//{
//    float4 cameraPos; 
//    float4 lightPos;
//    float4 lightCol; 
//};

cbuffer LightCameraBuffer : register(b0)
{
    float4 CameraPos;
    float4 LightPos;
};

cbuffer MaterialBuffer : register(b1)
{
    float4 AmbientColor;
    float4 DiffuseColor;
    float4 SpecularColor;
};

SamplerState textureSampler : register(s0);


struct PSIn
{
	float4 Pos  : SV_Position;
	float3 Normal : NORMAL;
	float2 TexCoord : TEX;
    float3 WorldPos : POSITION_WORLD;
    float3 NormalWorld : NORMAL_WORLD;
};

//-----------------------------------------------------------------------------------------
// Pixel Shader
//-----------------------------------------------------------------------------------------

float4 PS_main(PSIn input) : SV_Target
{
    float3 N = normalize(input.Normal);
    float3 L = normalize(LightPos.xyz - input.WorldPos);
    float3 V = normalize(CameraPos.xyz - input.WorldPos);
    float3 R = reflect(-L, N);
    
    float3 ambientTerm = AmbientColor.xyz;
    float diff = max(dot(L, N), 0.0f);
    float3 diffuseTerm = DiffuseColor.xyz * diff;
    float spec = pow(max(dot(R, V), 0.0f), SpecularColor.a);
    float3 specularTerm = SpecularColor.xyz * spec;
    
    float4 diffuseTexture = textureDiffuse.Sample(textureSampler, input.TexCoord);
    float4 textureColor;

    float3 finalColor = ambientTerm + diffuseTerm + specularTerm;
    return float4(diffuseTexture.xyz, 1.0f);
    
    
    
}