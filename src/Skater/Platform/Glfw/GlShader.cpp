//
// Created by connor on 1/3/26.
//

#include "GlShader.h"

#include <iostream>

#include "glad/glad.h"

namespace Skater {
    GlShader::GlShader(const uint8_t *vertexSrc, const uint8_t *fragmentSrc) {
        GLint success;
        GLchar infoLog[512];

        const uint32_t v = glCreateShader(GL_VERTEX_SHADER);

        const auto vsrc = reinterpret_cast<const char *>(vertexSrc);
        glShaderSource(v, 1, &vsrc, nullptr);
        glCompileShader(v);

        glGetShaderiv(v, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(v, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << "\n";
        }

        const uint32_t f = glCreateShader(GL_FRAGMENT_SHADER);

        const auto fsrc = reinterpret_cast<const char *>(fragmentSrc);
        glShaderSource(f, 1, &fsrc, nullptr);
        glCompileShader(f);

        glGetShaderiv(f, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(f, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << "\n";
        }

        _shaderId = glCreateProgram();
        glAttachShader(_shaderId, v);
        glAttachShader(_shaderId, f);
        glLinkProgram(_shaderId);

        glGetProgramiv(_shaderId, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(_shaderId, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << "\n";
        }

        glDeleteShader(v);
        glDeleteShader(f);
    }

    GlShader::~GlShader() {
        glDeleteProgram(_shaderId);
    }

    void GlShader::Bind() const {
        glUseProgram(_shaderId);
    }

    void GlShader::Unbind() const {
        glUseProgram(0);
    }

    void GlShader::SetInt(const std::string &name, const int value) {
        const GLint location = glGetUniformLocation(_shaderId, name.c_str());
        glProgramUniform1i(_shaderId, location, value);
    }

    void GlShader::SetIntArray(const std::string &name, int *values, const uint32_t count) {
        const GLint location = glGetUniformLocation(_shaderId, name.c_str());
        glProgramUniform1iv(_shaderId, location, static_cast<GLint>(count), values);
    }

    void GlShader::SetFloat(const std::string &name, const float value) {
        const GLint location = glGetUniformLocation(_shaderId, name.c_str());
        glProgramUniform1f(_shaderId, location, value);
    }

    void GlShader::SetFloat2(const std::string &name, const Vector2 &value) {
        const GLint location = glGetUniformLocation(_shaderId, name.c_str());
        glProgramUniform2f(_shaderId, location, value.X, value.Y);
    }

    void GlShader::SetFloat3(const std::string &name, const Vector3 &value) {
        const GLint location = glGetUniformLocation(_shaderId, name.c_str());
        glProgramUniform3f(_shaderId, location, value.X, value.Y, value.Z);
    }

    void GlShader::SetFloat4(const std::string &name, const Vector4 &value) {
        const GLint location = glGetUniformLocation(_shaderId, name.c_str());
        glProgramUniform4f(_shaderId, location, value.X, value.Y, value.Z, value.W);
    }

    void GlShader::SetMatrix4(const std::string &name, const Matrix4 &value) {
        const GLint location = glGetUniformLocation(_shaderId, name.c_str());
        glProgramUniformMatrix4fv(_shaderId, location, 1, GL_TRUE, value.Elements);
    }
}
