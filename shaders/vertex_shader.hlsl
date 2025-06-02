cbuffer TransformationBuffer : register(b0)
{
    
    matrix ModelToWorldMatrix;
    matrix WorldToViewMatrix;
    matrix ProjectionMatrix;
};


struct VSIn
{
    float3 Pos : POSITION;
    float3 Normal : NORMAL;
    float3 Tangent : TANGENT;
    float3 Binormal : BINORMAL;
    float2 TexCoord : TEX;
};

struct PSIn
{
    float4 Pos : SV_Position;
    float3 Normal : NORMAL;
    float2 TexCoord : TEX;
    float3 WorldPos : POSITION_WORLD;
    float3 NormalPos : NORMAL_WORLD;
    float3 TangentWorld : TANGENT;
    float3 BinormalWorld : BINORMAL;
};

//-----------------------------------------------------------------------------------------
// Vertex Shader
//-----------------------------------------------------------------------------------------

PSIn VS_main(VSIn input)
{
   
    //int texScale = 1;   -> sould be moved to pixelShader  
    PSIn output = (PSIn) 0;
    output.WorldPos = mul((float3x3) ModelToWorldMatrix, float4(input.Pos, 1.0f).xyz);
    output.NormalPos = mul((float3x3) ModelToWorldMatrix, input.Normal);
    

    
    // Model->View transformation
    matrix MV = mul(WorldToViewMatrix, ModelToWorldMatrix);

    // Model->View->Projection (clip space) transformation
    // SV_Position expects the output position to be in clip space
    matrix MVP = mul(ProjectionMatrix, MV);
    
    // Perform transformations and send to output
    output.Pos = mul(MVP, float4(input.Pos, 1));
    output.Normal = normalize(mul(ModelToWorldMatrix, float4(input.Normal, 0)).xyz);
    output.TexCoord = input.TexCoord; // * texScale;
    
    // Perform TBN and send output
    output.TangentWorld = mul(input.Tangent, (float3x3) ModelToWorldMatrix);
    output.BinormalWorld = mul(input.Binormal, (float3x3) ModelToWorldMatrix);
    output.NormalPos = mul(input.Normal, (float3x3) ModelToWorldMatrix);
    
    return output;
}