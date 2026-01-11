//
// Created by connor on 1/10/26.
//

#pragma once
#include "AudioStream.h"

namespace Skater {
    namespace AudioEngine {
        void Init();
        void Destroy();

        void Play(AudioStream *stream, unsigned int &audioHandle);
        void Stop(unsigned int audioHandle);

        void SetVolume(unsigned int audioHandle, float volume);
        void SetLoop(unsigned int audioHandle, bool loop);
        void SetProtect(unsigned int audioHandle, bool protect);
    };
}
