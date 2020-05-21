#include<stb/stb_image.h>
#include "BasicTexture.h"
#include<iostream>

BasicTexture::BasicTexture(const std::string& path)
{
	loadTexture(path);
}

BasicTexture::~BasicTexture()
{
	glDeleteTextures(1, &ID);
	ID = 0;
}

void BasicTexture::loadTexture(const std::string& path)
{
	//stbi_set_flip_vertically_on_load(true); 
	std::string filePath = ".\\res\\" + path + ".png";
	int width, height, nrComponents;
	unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &nrComponents, 0);
	if (data)
	{
		glGenTextures(1, &ID);
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, ID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		//glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);	//使用Mipmap会造成地平面远景变黑...不清楚原因
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Texture " << path << " failed to loat at path:" << filePath << std::endl;
		stbi_image_free(data);
	}
}

void BasicTexture::bindTexture()
{
	glBindTexture(GL_TEXTURE_2D, ID);
}
