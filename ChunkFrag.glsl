#version 330 core
in vec2 TexCoords;
out vec4  FragColor;

uniform sampler2D texSampler;

void main()
{
	vec4 fragColor = texture(texSampler,TexCoords);
	if(fragColor.a < 0.1)		discard;
	FragColor = fragColor;
}