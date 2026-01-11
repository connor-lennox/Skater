//
// Created by connor on 1/10/26.
//

#pragma once

namespace Skater {
    class AudioStream;

    class AudioStreamInstance {
    public:
        AudioStreamInstance() : AudioStreamInstance(nullptr) {}
        explicit AudioStreamInstance(AudioStream *parent) : _parent(parent) {}

        void Play();
        void Stop();

        void SetStream(AudioStream *stream);
        void SetVolume(float volume);
        void SetLoop(bool loop);
        void SetProtect(bool protect);
    private:
        AudioStream *_parent;
        bool _playing = false;
        unsigned int _audioHandle = 0;

        float _volume = 1.0;
        bool _loop = false;
        bool _protect = false;
    };
}
