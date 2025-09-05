Texture2D texDiffuse : register(t0);
Texture2D texNormal : register(t1);

SamplerState textureSampler : register(s0);


struct PSIn
{
    float4 Pos : SV_Position;
    float3 Normal : NORMAL;
    float2 TexCoord : TEX;
    float3 WorldPos : POSITION_WORLD;
    float3 Tangent : TANGENT;
    float3 Binormal : BINORMAL;
};

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

//-----------------------------------------------------------------------------------------
// Pixel Shader
//-----------------------------------------------------------------------------------------

float4 PS_main(PSIn input) : SV_Target
{
	// Debug shading #1: map and return normal as a color, i.e. from [-1,1]->[0,1] per component
	// The 4:th component is opacity and should be = 1
 //return float4(input.Normal*0.5+0.5, 1);
	
	// Debug shading #2: map and return texture coordinates as a color (blue = 0)
    //return float4(input.TexCoord, 0, 1);
	
    float3x3 TBN = float3x3(normalize(input.Tangent), normalize(input.Binormal), normalize(input.Normal));
    
    float3 normalTS = texNormal.Sample(textureSampler, input.TexCoord).rgb;
    normalTS = normalize(normalTS * 2.0f - 1.0f);
    

  
    float3 N = normalize(input.Normal);
    float3 L = normalize(LightPos.xyz - input.WorldPos);
    float3 V = normalize(CameraPos.xyz - input.WorldPos);
    float3 R = reflect(-L, N);
    
    float2 scaleUV = input.TexCoord * 2.5f; // Make texture not alignned 
    float4 diffuseText = texDiffuse.Sample(textureSampler, input.TexCoord);
    //float4 diffuseText = texDiffuse.Sample(textureSampler, input.TexCoord);
    
    float3 ambientTerm = AmbientColor.xyz;
    float diff = max(dot(L, N), 0.0f);
    float3 diffuseTerm = (DiffuseColor.xyz * diff) * diffuseText.rgb;
    float spec = pow(max(dot(R, V), 0.0f), SpecularColor.a);
    float3 specularTerm = SpecularColor.xyz * spec;
    
    float3 finalColor = ambientTerm + diffuseTerm + specularTerm;
    return float4(finalColor, 1.0f);
    

    //return diffuseText;
    
    //// Rend 4
    //float3x3 TBN = float3x3(normalize(input.Tangent), normalize(input.Binormal), normalize(input.Normal));
    
    ////Samble and unpack
    //float3 normalTS = texNormal.Sample(textureSampler, input.TexCoord).rgb;
    //normalTS = normalize(normalTS * 2.0f - 1.0f);
    
    ////Transform from tangent to world
    //float3 N = normalize(mul(normalTS, TBN));
    
    //float4 diffuse_texture = texDiffuse.Sample(textureSampler, input.TexCoord);
    //float3 normal_texture = (texNormal.Sample(textureSampler, input.TexCoord).xyz) * 2 - 1;
     
    //N = mul(TBN, normal_texture);
    
    //float3 L = normalize(LightPos.xyz - input.WorldPos.xyz);
    //float3 R = reflect(-L, N);
    //float3 V = normalize(CameraPos.xyz - input.WorldPos.xyz);
    
    //float4 lambert_diffuse = max(dot(N, L), 0);
    //float4 specular_highlight = max(pow(abs(dot(R, V)), /*shininess*/1), 0);
    
    //float4 ambient_component = AmbientColor;
    //float4 diffuse_component = DiffuseColor * lambert_diffuse * diffuse_texture;
    //float4 specular_component = SpecularColor * specular_highlight;
    
    //float4 phong_illumination = ambient_component + diffuse_component + specular_component;

    //return float4(phong_illumination.xyz, 1.0);
}