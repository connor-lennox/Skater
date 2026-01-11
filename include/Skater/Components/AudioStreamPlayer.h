//
// Created by connor on 1/10/26.
//

#pragma once
#include "Skater/Audio/AudioStreamInstance.h"
#include "Skater/Core/Component.h"

namespace Skater {
    class AudioStreamPlayer final : public Component {
    public:
        AudioStreamPlayer();
        ~AudioStreamPlayer() override;

        void SetAudioStream(AudioStream *audioStream);

        void Play();
        void Stop();

        void SetVolume(const float volume) { _audioInstance.SetVolume(volume); }
        void SetLoop(const bool loop) { _audioInstance.SetLoop(loop); }
        void SetProtect(const bool protect) { _audioInstance.SetProtect(protect); }
    private:
        AudioStreamInstance _audioInstance;
    };
}
