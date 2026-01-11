//
// Created by connor on 1/10/26.
//

#include "include/soloud.h"

#include "Skater/Audio/AudioEngine.h"

namespace Skater {
    namespace {
        SoLoud::Soloud Engine;
    }

    namespace AudioEngine {
        void Init() {
            Engine.init();
        }

        void Destroy() {
            Engine.deinit();
        }

        void Play(AudioStream *stream, unsigned int &audioHandle) {
            audioHandle = Engine.play(stream->GetSource());
        }

        void Stop(const unsigned int audioHandle) {
            Engine.stop(audioHandle);
        }

        void SetVolume(const unsigned int audioHandle, const float volume) {
            Engine.setVolume(audioHandle, volume);
        }

        void SetLoop(const unsigned int audioHandle, const bool loop) {
            Engine.setLooping(audioHandle, loop);
        }

        void SetProtect(const unsigned int audioHandle, const bool protect) {
            Engine.setProtectVoice(audioHandle, protect);
        }

    }
}
