//
// Created by connor on 1/3/26.
//

#include "Skater/Resources/ResourceDatabase.h"

#include <fstream>

#include "Skater/Renderer/Texture.h"

#include "stb_image.h"
#include "Skater/Audio/AudioStream.h"

namespace Skater {
    Texture *ResourceDatabase::LoadTexture(const std::string &filename) {
        if (_textureCache.contains(filename)) {
            return _textureCache.at(filename);
        }

        int x, y, n;
        const auto imageData = stbi_load(filename.c_str(), &x, &y, &n, 0);

        const auto imageFormat = n == 4 ? ImageFormat::RGBA : ImageFormat::RGB;

        Texture* res = Texture::Create(imageData, x, y, TextureSpecification(imageFormat, FilterMode::Nearest, WrapMode::Repeat));
        _textureCache[filename] = res;

        return res;
    }

    Texture *ResourceDatabase::LoadTextureFromBytes(uint8_t bytes[], const uint32_t len) {
        int x, y, n;
        const auto imageData = stbi_load_from_memory(bytes, len, &x, &y, &n, 0);
        const auto imageFormat = n == 4 ? ImageFormat::RGBA : ImageFormat::RGB;

        Texture* res = Texture::Create(imageData, x, y, TextureSpecification(imageFormat, FilterMode::Nearest, WrapMode::Repeat));
        return res;
    }

    FontSystem *ResourceDatabase::LoadFontSystem(const std::string &filename) {
        if (_fontSystemCache.contains(filename)) {
            return _fontSystemCache.at(filename);
        }

        std::ifstream ifs(filename, std::ios::binary|std::ios::ate);
        const std::ifstream::pos_type pos = ifs.tellg();
        const auto buf = new char[pos];

        ifs.seekg(0, std::ios::beg);
        ifs.read(buf, pos);
        ifs.close();

        const auto fontSystem = new FontSystem(reinterpret_cast<uint8_t*>(buf));
        _fontSystemCache[filename] = fontSystem;

        return fontSystem;
    }

    FontSystem * ResourceDatabase::LoadFontSystemFromBytes(uint8_t bytes[]) {
        return new FontSystem(bytes);
    }

    AudioStream * ResourceDatabase::LoadAudioStream(const std::string &filename) {
        if (_audioStreamCache.contains(filename)) {
            return _audioStreamCache.at(filename);
        }

        const auto wav = new Wav();
        wav->load(filename.c_str());

        const auto audioStream = new AudioStream(wav);
        _audioStreamCache[filename] = audioStream;

        return audioStream;
    }

    AudioStream * ResourceDatabase::LoadAudioStreamFromBytes(uint8_t bytes[], const uint32_t len) {
        const auto wav = new Wav();
        wav->loadMem(bytes, len, true, true);

        const auto audioStream = new AudioStream(wav);
        return audioStream;
    }
}
