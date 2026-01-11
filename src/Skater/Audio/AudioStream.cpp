//
// Created by connor on 1/10/26.
//

#include "Skater/Audio/AudioStream.h"

#include "Skater/Audio/AudioEngine.h"

namespace Skater {
    void AudioStreamInstance::Play() {
        if (_parent == nullptr) {
            return;
        }

        AudioEngine::Play(_parent, _audioHandle);

        AudioEngine::SetVolume(_audioHandle, _volume);
        AudioEngine::SetLoop(_audioHandle, _loop);
        AudioEngine::SetProtect(_audioHandle, _protect);

        _playing = true;
    }

    void AudioStreamInstance::Stop() {
        if (_parent == nullptr) {
            return;
        }

        AudioEngine::Stop(_audioHandle);
        _playing = false;
        _audioHandle = 0;
    }

    void AudioStreamInstance::SetStream(AudioStream *stream) {
        Stop();
        _parent = stream;
    }

    void AudioStreamInstance::SetVolume(const float volume) {
        _volume = volume;

        if (_playing) {
            AudioEngine::SetVolume(_audioHandle, _volume);
        }
    }

    void AudioStreamInstance::SetLoop(const bool loop) {
        _loop = loop;

        if (_playing) {
            AudioEngine::SetLoop(_audioHandle, _loop);
        }
    }

    void AudioStreamInstance::SetProtect(const bool protect) {
        _protect = protect;

        if (_playing) {
            AudioEngine::SetProtect(_audioHandle, _protect);
        }
    }


    AudioStream::~AudioStream() {
        delete _source;
    }

    AudioStreamInstance *AudioStream::CreateInstance() {
        return new AudioStreamInstance(this);
    }

    Wav &AudioStream::GetSource() const {
        return *_source;
    }

    float AudioStream::GetLength() const {
        return static_cast<float>(_source->getLength());
    }
}
