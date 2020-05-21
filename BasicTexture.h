#pragma once
#include<glad/glad.h>
#include<string>

class BasicTexture
{
public:
    GLuint  ID;
    BasicTexture() = default;
    BasicTexture(const std::string& path);
    ~BasicTexture();
    void loadTexture(const std::string& path);
    void bindTexture();
};